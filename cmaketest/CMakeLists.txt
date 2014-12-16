PROJECT(main)

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY("message")

FIND_PATH(
 ZMQ_INCLUDE
 zmq.hpp
 /usr/local/include
 /usr/include
)
if(ZMQ_PATH)
	INCLUDE_DIRECTORIES(${ZMQ_INCLUDE})
else(ZMQ_PATH)
	MESSAGE(FATAL_ERROR "zmq.hpp not found")
endif(ZMQ_PATH)
