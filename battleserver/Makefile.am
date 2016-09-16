noinst_PROGRAMS = battleserver
battleserver_SOURCES = battleserver.cpp 
battleserver_LDADD = $(top_srcdir)/common/tcpserver.o $(top_srcdir)/common/log.o $(top_srcdir)/pb/netmessage.pb.o $(top_srcdir)/common/configfile.o
battleserver_LDFLAGS = -L/usr/local/lib -L$(top_srcdir)/lib -D_GNU_SOURCE -luv -lpthread -lssl -lcrypto -lprotobuf -lhiredis
INCLUDES = -I$(top_srcdir)/include -I/usr/local/include --std=c++0x
export INCLUDES
