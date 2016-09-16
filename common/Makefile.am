SUBDIRS = json
noinst_PROGRAMS = tcpserver tcpclient log configfile
tcpserver_SOURCES = tcpserver.cpp 
#tcpserver_CPPFLAGS = -std=c++0x
tcpclient_SOURCES = tcpclient.cpp 
#tcpclient_CPPFLAGS = -std=c++0x
log_SOURCES = log.cpp
configfile_SOURCES = configfile.cpp
DEFS += -D_GNU_SOURCE
INCLUDES = -I$(top_srcdir)/include -std=c++0x
export INCLUDES
