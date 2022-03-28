#include "tcp_client.h"
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <cstring>
#include <iostream>

void tcp_client::bind()
{
    addrinfo hints, *p;
    std::memset(&hints, 0, sizeof(hints));
    hints.ai_family   = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags    = AI_PASSIVE;

    int gAddRes = getaddrinfo(ip_.c_str(), port_.c_str(), &hints, &p);
    if (gAddRes != 0) {
        std::cerr << gai_strerror(gAddRes) << "\n";
        return;
    }

    if (p == NULL) {
        std::cerr << "No addresses found\n";
        return;
    }

    // socket() call creates a new socket and returns it's descriptor
    sockFD_ = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
    if (sockFD_ == -1) {
        std::cerr << "Error while creating socket\n";
        return;
    }

    // Note: there is no bind() call as there was in Hello TCP Server
    // why? well you could call it though it's not necessary
    // because client doesn't necessarily has to have a fixed port number
    // so next call will bind it to a random available port number

    // connect() call tries to establish a TCP connection to the specified server
    int connectR = connect(sockFD_, p->ai_addr, p->ai_addrlen);
    if (connectR == -1) {
        close(sockFD_);
        std::cerr << "Error while connecting socket\n";
        return;
    }
    connected_ = true;
    freeaddrinfo(p);

}


void tcp_client::Send(std::string msg)
{
    if (!connected_) {
        std::cerr << "Not connected\n";
        return;
    }
    auto bytes_sent = send(sockFD_, msg.c_str(), msg.size(), 0);
    if (bytes_sent == -1) {
        std::cerr << "Error while sending bytes\n";
        return;
    }
}

void tcp_client::disconnect()
{
    if (!connected_) {
        std::cerr << "Not connected\n";
        return;
    }
    close(sockFD_);
    connected_ = false;
}


tcp_client::tcp_client(std::string ip, std::string port)
{
    ip_ = ip;
    port_ = port;
}

// close the connection
tcp_client::~tcp_client()
{
    disconnect();
}
