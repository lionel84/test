/*
 * @Auth: lionelzhang
 * @Date: 2020-08-27 11:23:46
 * @LastEditors: lionelzhang
 * @LastEditTime: 2020-12-07 17:03:23
 * @Description: 
 */
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "unistd.h"
#include <stdio.h>
 #include <string.h>
 #include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <fcntl.h>
#include<sys/types.h>
#include<sys/wait.h>
#include <curl/curl.h>
//#include <arpa.inet.h>
namespace nm_socket_test{
  /*
    static void setnonblocking(int sockfd)
{
    int flag = 0; //fcntl(sockfd, F_GETFL, 0);
    if (flag < 0) 
    {
        //Perror("fcntl F_GETFL fail");
        return;
    }
    if (fcntl(sockfd, F_SETFL, flag | O_NONBLOCK) < 0) 
    {
        //Perror("fcntl F_SETFL fail");
    }
} 
*/
static int wait_on_socket(curl_socket_t sockfd, int for_recv, long timeout_ms)
{
  struct timeval tv;
  fd_set infd, outfd, errfd;
  int res;

  tv.tv_sec = timeout_ms / 1000;
  tv.tv_usec= (timeout_ms % 1000) * 1000;

  FD_ZERO(&infd);
  FD_ZERO(&outfd);
  FD_ZERO(&errfd);

  FD_SET(sockfd, &errfd); /* always check for error */

  if(for_recv)
  {
    FD_SET(sockfd, &infd);
  }
  else
  {
    FD_SET(sockfd, &outfd);
  }

  /* select() returns the number of signalled sockets or -1 */
  res = select(sockfd + 1, &infd, &outfd, &errfd, &tv);
  return res;
}
curl_socket_t opensocket (void *clientp,
                            curlsocktype purpose,
                            struct curl_sockaddr *address)
{
	address->socktype = SOCK_DGRAM;
	//address->protocol = IPPROTO_UDP;
	address->protocol = 0;
	return socket(address->family, address->socktype, address->protocol);
}

void test_send_curl(void)
{
  CURL *curl;
  CURLcode res;
  /* Minimalistic http request */
  const char *request = "hello\n";
  curl_socket_t sockfd; /* socket */
  long sockextr;
  size_t iolen;
  curl_off_t nread;

  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "127.0.0.1:9999");
    curl_easy_setopt(curl, CURLOPT_OPENSOCKETFUNCTION, opensocket);
    /* Do not do the transfer - only connect to host */
    curl_easy_setopt(curl, CURLOPT_CONNECT_ONLY, 1L);
    res = curl_easy_perform(curl);

    if(CURLE_OK != res)
    {
      printf("Error: %s\n", strerror(res));
      return ;
    }

    /* Extract the socket from the curl handle - we'll need it for waiting.
     * Note that this API takes a pointer to a 'long' while we use
     * curl_socket_t for sockets otherwise.
     */
    res = curl_easy_getinfo(curl, CURLINFO_LASTSOCKET, &sockextr);

    if(CURLE_OK != res)
    {
      printf("Error: %s\n", curl_easy_strerror(res));
      return ;
    }

    sockfd = sockextr;

    /* wait for the socket to become ready for sending */
    if(!wait_on_socket(sockfd, 0, 60000L))
    {
      printf("Error: timeout.\n");
      return ;
    }

    puts("Sending request.");
    /* Send the request. Real applications should check the iolen
     * to see if all the request has been sent */
    res = curl_easy_send(curl, request, strlen(request), &iolen);

    if(CURLE_OK != res)
    {
      printf("Error: %s\n", curl_easy_strerror(res));
      return ;
    }
    puts("Reading response.");

    /* read the response */
    for(;;)
    {
      char buf[1024];

      //wait_on_socket(sockfd, 1, 60000L);
      res = curl_easy_recv(curl, buf, 1024, &iolen);

      if(CURLE_OK != res)
      {
          printf("wait\n");
          sleep(1);
        continue;
      }

      nread = (curl_off_t)iolen;

      printf("Received %" CURL_FORMAT_CURL_OFF_T " bytes. msg: %s\n", nread, buf);
    }

    /* always cleanup */
    curl_easy_cleanup(curl);
  }
  return ;
}
    void send_test()
    {
        int		nSockHandle;
        nSockHandle = socket(AF_INET, SOCK_DGRAM, 0);
        struct sockaddr_in net_addr;
        memset(&net_addr, 0, sizeof(net_addr));
        net_addr.sin_family = AF_INET;
        net_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
        net_addr.sin_port = htons(9999);

        char send_buf[1024];
        sprintf(send_buf, "%s\n", "hello");
        int ssize = sendto(nSockHandle, send_buf, strlen(send_buf)+1, 0, (struct sockaddr*)&net_addr, sizeof(net_addr));
        printf("send size: %d\n", ssize);

        char recv_buf[1024];
        socklen_t net_addr_len = sizeof(net_addr);
        int rsize = 0;
        while(true){
            rsize = recvfrom(nSockHandle, recv_buf, 1024, 0, (struct sockaddr*)&net_addr, &net_addr_len);
            if(rsize <= 0){
                printf("wait\n");
                sleep(1);
                continue;
            }
            printf("rsize: %d errno %d\n", rsize, errno);
            if(rsize > 0)
                printf("%s\n", recv_buf);
        }
    }

    void recv_test()
    {
      //CURLINFO_ACTIVESOCKET
      //CURLINFO_COOKIELIST
        int32_t		nSockHandle;
        nSockHandle = socket(AF_INET, SOCK_DGRAM, 0);
        printf("nSockHandle: %d\n", nSockHandle);
        struct sockaddr_in local_addr;

        memset(&local_addr, 0, sizeof(local_addr));
        local_addr.sin_family = AF_INET;
        local_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
        local_addr.sin_port = htons(9999);
        bind(nSockHandle,  (struct sockaddr*)&local_addr, sizeof(local_addr));

        while(true){
            static char recv_buf[1024];
            struct sockaddr_in net_addr;
            
            socklen_t net_addr_len = sizeof(net_addr);
            int rsize = recvfrom(nSockHandle, recv_buf, 1024, 0,  (struct sockaddr*)&net_addr, &net_addr_len);
            printf("rsize: %d\n", rsize);
            printf("net_addr sin_family: %d\n", ntohs(net_addr.sin_family));
            printf("net_addr s_addr: %d\n", ntohs(net_addr.sin_addr.s_addr));
            printf("net_addr port: %d\n", ntohs(net_addr.sin_port));
            printf("%s\n", recv_buf);
            char send_buf[1024];
            sprintf(send_buf, "%s\n", "success");
            printf("strlen(cb): %d\n", strlen(send_buf));
            int ssize = 0; 
            printf("wait 5\n");
            sleep(5);
            ssize = sendto(nSockHandle, send_buf, strlen(send_buf)+1, 0, (struct sockaddr*)&net_addr, sizeof(net_addr));
            printf("send size: %d errno: %d\n", ssize, errno);
            sleep(1);
            printf("wait\n");
        }
    }
}