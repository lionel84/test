PROJECT(main)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fPIC -std=c++11 -lhiredis -levent -lcurl -lpthread -lssl -lcrypto -luv -Wunused-function -fpermissive")
CMAKE_MINIMUM_REQUIRED(VERSION 2.6) 
LINK_DIRECTORIES(/usr/local/lib)

ADD_SUBDIRECTORY(hiredishelp)
include_directories(rapidjson)
include_directories(hiredishelp)
ADD_SUBDIRECTORY(coroutine)
include_directories(coroutine)
AUX_SOURCE_DIRECTORY(. DIR_SRCS)
ADD_EXECUTABLE(main ${DIR_SRCS}  )
TARGET_LINK_LIBRARIES( main hiredishelp coroutine uv)
