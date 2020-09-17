/*
 * @Auth: lionelzhang
 * @Date: 2020-08-27 19:16:12
 * @LastEditors: lionelzhang
 * @LastEditTime: 2020-09-10 19:32:29
 * @Description: 
 */
#include "test_json_pack.h"
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"
#include "rapidjson/prettywriter.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "unistd.h"
#include "base.h"
#define rdtsc_64(val) do {\
    unsigned int __a,__d; \
    __asm__ __volatile__("rdtsc" : "=a" (__a), "=d" (__d)); \
    (val) = (((unsigned long long)__d)<<32) | (__a); \
} while(0)

namespace nm_test_json_pack
{
    #define WLOGDEBUG
    //#define WLOGDEBUG printf

        bool _maple_acc_pack(uint64_t qwUserID, const char* pcszOpenID, const char* pcszUserName,
        int32_t nZoneAreaID, int32_t nLevel, uint32_t dwLastLoginTime, 
        int32_t nClientPlatform, int32_t nClass, int32_t nEncrypt_type, char* pBuff, int32_t& dwLen)
    {
        
        int32_t nAreaID = 1234;
        int32_t nServerGroup = 4312;
        char pszAccUData[128] = { 0 };
        int32_t nClientTime = (int)time(NULL);
        
        rapidjson::Document headDoc;

        rapidjson::StringBuffer strBufHead;
        rapidjson::PrettyWriter<rapidjson::StringBuffer> headWriter(strBufHead);
        //rapidjson::PrettyWriter
        rapidjson::Document bodyDoc;
        rapidjson::StringBuffer strBufBody;
        rapidjson::PrettyWriter<rapidjson::StringBuffer> bodyWriter(strBufBody);
        rapidjson::Value userData(rapidjson::kObjectType);

        snprintf(pszAccUData, sizeof(pszAccUData), "%d", nClass);

        headDoc.SetObject();

        headDoc.AddMember("gameid", 123123, headDoc.GetAllocator());
        headDoc.AddMember("encrypt_type", nEncrypt_type, headDoc.GetAllocator());
        headDoc.AddMember("client_time", nClientTime, headDoc.GetAllocator());
        headDoc.AddMember("asyncid", 0/*TODO*/, headDoc.GetAllocator());

        headDoc.Accept(headWriter);
        
        bodyDoc.SetObject();
        
        bodyDoc.AddMember("gamekey", rapidjson::StringRef("asdf"), bodyDoc.GetAllocator());
        bodyDoc.AddMember("client_time", nClientTime, bodyDoc.GetAllocator());
        bodyDoc.AddMember("msg_type", rapidjson::StringRef("user_acc_report"), bodyDoc.GetAllocator());

        userData.AddMember("uid", rapidjson::StringRef(pcszOpenID), bodyDoc.GetAllocator());
        userData.AddMember("plat_id", nAreaID, bodyDoc.GetAllocator());
        userData.AddMember("zone_id", nServerGroup, bodyDoc.GetAllocator());
        userData.AddMember("role_id", qwUserID, bodyDoc.GetAllocator());
        userData.AddMember("role_name", rapidjson::StringRef(pcszUserName), bodyDoc.GetAllocator());
        userData.AddMember("role_level", nLevel, bodyDoc.GetAllocator());
        userData.AddMember("login_time", dwLastLoginTime, bodyDoc.GetAllocator());
        userData.AddMember("acc_udata", rapidjson::StringRef(pszAccUData), bodyDoc.GetAllocator());

        bodyDoc.AddMember("userdata", userData, bodyDoc.GetAllocator());
        
        bodyDoc.Accept(bodyWriter);

        std::string jsonBody;
        std::string jsonHead;
        std::string jsonMsg;
        jsonBody = strBufBody.GetString();
        jsonHead = strBufHead.GetString();
        //jsonMsg = jsonHead + jsonBody;;
        jsonMsg = jsonBody;
        size_t msg_len;
        msg_len = jsonMsg.size();
        const char* msg;
        msg = jsonMsg.c_str();

        if (nEncrypt_type == 0)
        {
            strcpy(pBuff, msg);
        
        }

        WLOGDEBUG("maple acc pack json: %s\n", pBuff);

        return true;
    }
    bool _maple_acc_unpack(const char* pBuff, int32_t dwLen){
        rapidjson::Document headDoc;
        //printf("%d\n", strchr("asdf}", '}'));
        headDoc.Parse(pBuff); //, strchr(pBuff, '}') - pBuff +1);
        printf("pBuff: %s\n", pBuff);
        if(headDoc.HasParseError()){
            printf("err: %s\n", headDoc.GetParseError());
        }
        for(auto it = headDoc.GetObject().begin(); it != headDoc.GetObject().end(); it++){
            printf("member name: %s\n", it->name.GetString());
            //printf("member value: %s\n", it->value.GetString());
        }
        if(headDoc.HasMember("client_time")){
            printf("client_time: %d\n", headDoc["client_time"].GetInt());
        }
        if(headDoc.HasMember("userdata")){
            auto userdata = headDoc["userdata"].GetObject();
            for(auto it = userdata.begin(); it != userdata.end(); it++){
                printf("member name: %s type: %d\n", it->name.GetString(), it->value.GetType());
                if(it->value.IsString())
                    printf("member value: %s\n", it->value.GetString());
                else if(it->value.IsInt())
                    printf("member value: %d\n", it->value.GetInt());
            }
            
        }
        
        //fprintf(stdout, "name: %s\n", headDoc["client_time"].GetString());
        return true;
    }

    void test(){
        char pBuff[1024];
        int32_t len;
        unsigned long long before;
        rdtsc_64(before);
        
        printnow();
        //for(int i = 0; i< 100000; i++)
            _maple_acc_pack(123, "openid", "name", 1, 2, 123, 1, 1, 0, pBuff, len);
        printnow();
        unsigned long long after ;
        rdtsc_64(after);
        printf("cost : %llu\n", after - before);
        //printf("pBuff: %s\n", pBuff);
        _maple_acc_unpack(pBuff, len);
    }
}