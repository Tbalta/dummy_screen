#pragma once

#include "../display.h"
#include <cstdlib>
#include "../tcp_client/tcp_client.h"


class dummy_display : public Display
{
private:
    size_t witdth;
    size_t height;
    tcp_client client;

public:
    dummy_display(size_t width, size_t height, std::string ip, std::string port);
    ~dummy_display();
    void drawLine(int x0, int y0, int x1, int y1) override;
    void setColor(int r, int g, int b) override;
    void setColor(int color) override;
    void fillRect(int x, int y, int w, int h) override;
    void clear() override;
};