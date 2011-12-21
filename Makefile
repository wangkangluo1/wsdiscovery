# Makefile for the WS Discovery library
#
default: all

PWD			:= $(shell pwd)
MODULE_DIR		:= $(word 2, $(subst /unit_test/private/, ,$(PWD)))
PRIVATE_DIR		:= $(shell echo ./$(MODULE_DIR)|sed 's/\/[0-9a-zA-Z_]*/\/../g' )
AMBABUILD_TOPDIR	:= $(PWD)/$(PRIVATE_DIR)/../..
MODULE_NAME		:= "WS Discovery"
LINK_FLAG	       := -L $(AMBABUILD_TOPDIR)/prebuild/lib -lpthread

export AMBABUILD_TOPDIR

include $(AMBABUILD_TOPDIR)/build/unit_test/common.mk

UNIT_TEST_LDFLAG	?= $(AMBARELLA_LDFLAGS)
UNIT_TEST_CFLAG	?= $(AMBARELLA_CFLAGS) -g -O0 -Wall

CC = $(AMBA_MAKEFILE_V)$(CROSS_COMPILE)g++ -g -DWITH_NONAMESPACES
ar = $(AMBA_MAKEFILE_V)$(CROSS_COMPILE)ar

GSOAP_ROOT=../gsoap-2.8/gsoap
WSNAME = ws
INCLUDE = -I/usr/local/include/ -I./../uuid/ -I../gsoap-2.8/gsoap/ -I../gsoap-2.8/gsoap/import -L../uuid/
SERVER_OBJS = soapC.o stdsoap2.o soapClient.o soapServer.o $(WSNAME)server.o -luuid

all: server

server: $(SERVER_OBJS)
	$(CC) $(INCLUDE) $(UNIT_TEST_CFLAG) -o $(WSNAME)server $(SERVER_OBJS)
	

stdsoap2.o:$(GSOAP_ROOT)/stdsoap2.c
	$(CC) -c $(UNIT_TEST_CFLAG) $(INCLUDE) $(GSOAP_ROOT)/stdsoap2.c

soapC.o:soapC.cpp
	$(CC) -c $(UNIT_TEST_CFLAG) $(INCLUDE) soapC.cpp

soapClient.o:soapClient.cpp
	$(CC) -c $(UNIT_TEST_CFLAG) $(INCLUDE) soapClient.cpp

soapServer.o:soapC.cpp
	$(CC) -c $(UNIT_TEST_CFLAG) $(INCLUDE) soapServer.cpp

.c.o:
	$(CC) -c $(UNIT_TEST_CFLAG) $(INCLUDE) $<

clean:
	rm -f *.o  $(WSNAME)server
