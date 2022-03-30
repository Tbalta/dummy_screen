#pragma once

#include "../screen.h"
#include <cstdlib>
#include "../tcp_client/tcp_client.h"


class dummy_display : public Screen
{
private:
    tcp_client client_;

public:
    dummy_display(size_t width, size_t height, std::string ip, std::string port);
    ~dummy_display();
    void drawLine(int x0, int y0, int x1, int y1) override;
    void drawVLine(int x0, int y0, int y1) override;
    void setColor(int r, int g, int b) override;
    void setColor(int color) override;
    void fillRect(int x, int y, int w, int h) override;
    void clear() override;
    void begin() override; // init the screen with the width and height.
};