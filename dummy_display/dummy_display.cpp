#include "dummy_display.h"


void dummy_display::begin()
{
    std::string msg = "{\"type\":\"init\",\"width\":" + std::to_string(width_) + ",\"height\":" + std::to_string(height_) + "}";
    client_.Send(msg);
}

void dummy_display::drawLine(int x0, int y0, int x1, int y1)
{
    std::string msg = "{\"type\":\"line\",\"x0\":" + std::to_string(x0) + ",\"y0\":" + std::to_string(y0) + ",\"x1\":" + std::to_string(x1) + ",\"y1\":" + std::to_string(y1) + "}";
    client_.Send(msg);
}

void dummy_display::drawVLine(int x0, int y0, int y1)
{
    drawLine(x0, y0, x0, y1);
}

void dummy_display::setColor(int r, int g, int b)
{
    std::string msg = "{\"type\":\"color\",\"r\":" + std::to_string(r) + ",\"g\":" + std::to_string(g) + ",\"b\":" + std::to_string(b) + "}";
    client_.Send(msg);
}

void dummy_display::setColor(int color)
{
    setColor((color >> 16) & 0xFF, (color >> 8)  & 0xFF, color & 0xFF);
}

void dummy_display::fillRect(int x, int y, int w, int h)
{
    std::string msg = "{\"type\":\"fillRect\",\"x\":" + std::to_string(x) + ",\"y\":" + std::to_string(y) + ",\"w\":" + std::to_string(w) + ",\"h\":" + std::to_string(h) + "}";
    client_.Send(msg);
}


void dummy_display::clear()
{
    std::string msg = "{\"type\":\"clear\"}";
    client_.Send(msg);
}

dummy_display::dummy_display(size_t width, size_t height, std::string ip, std::string port)
    : Screen(width, height), client_(ip, port)
{
    client_.bind();
}

dummy_display::~dummy_display()
{
}
