#pragma once


#include <cstdlib>
#include <string>

class tcp_client
{
private:
    std::string ip_;
    std::string port_;
    int sockFD_;
    bool connected_;
public:
    tcp_client(std::string ip, std::string port);
    ~tcp_client();
    void bind();
    void Send(std::string msg);
    void disconnect();
};