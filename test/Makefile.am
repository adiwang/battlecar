noinst_PROGRAMS = testtcpserver testtcpclient testhiredis
testtcpserver_SOURCES = test_tcpserver.cpp
testtcpclient_SOURCES = test_tcpclient.cpp
testhiredis_SOURCES = example.c
testtcpserver_LDADD = $(top_srcdir)/common/tcpserver.o $(top_srcdir)/common/log.o $(top_srcdir)/pb/netmessage.pb.o
testtcpserver_LDFLAGS = -L/usr/local/lib -D_GNU_SOURCE -luv -lpthread -lssl -lcrypto -lprotobuf
testtcpclient_LDADD = $(top_srcdir)/common/tcpclient.o $(top_srcdir)/common/log.o $(top_srcdir)/pb/netmessage.pb.o
testtcpclient_LDFLAGS = -L/usr/local/lib -D_GNU_SOURCE -luv -lpthread -lssl -lcrypto -lprotobuf
testhiredis_LDFLAGS = -L$(top_srcdir)/lib -lhiredis
INCLUDES = -I$(top_srcdir)/include -I/usr/local/include -I$(top_srcdir)/include/hiredis --std=c++0x
export INCLUDES
