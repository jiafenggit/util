//
// Created by hujianzhe on 16-12-1.
//

#ifndef	UTIL_CPP_NIO_TCPLISTEN_NIO_OBJECT_H
#define	UTIL_CPP_NIO_TCPLISTEN_NIO_OBJECT_H

#include "nio_object.h"

namespace Util {
class TcplistenNioObject : public NioObject {
public:
	TcplistenNioObject(FD_t sockfd, int domain);

	bool bindlisten(unsigned short port, REACTOR_ACCEPT_CALLBACK cbfunc, size_t arg = 0) { return bindlisten(NULL, port, cbfunc, arg); }
	bool bindlisten(const char* ip, unsigned short port, REACTOR_ACCEPT_CALLBACK cbfunc, size_t arg = 0);
	bool bindlisten(const struct sockaddr_storage* saddr, REACTOR_ACCEPT_CALLBACK cbfunc, size_t arg = 0);

private:
	virtual int sendv(IoBuf_t* iov, unsigned int iovcnt, struct sockaddr_storage* saddr = NULL) { return -1; }
	virtual int read(void);
	int onRead(unsigned char* buf, size_t len, struct sockaddr_storage* from) { return 0; }

private:
	REACTOR_ACCEPT_CALLBACK m_cbfunc;
	size_t m_arg;
};
}

#endif
