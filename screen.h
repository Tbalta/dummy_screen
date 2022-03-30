#pragma once
#include <cstddef>

class Screen
{
protected:
    size_t width_;
    size_t height_;
public:   
    // Compatibility function do nothing
    // virtual void begin() = 0;
    // void setFixedFont(auto ssd1306xled_font6x8) = 0;

    // clear screen
    virtual void clear() = 0;

    virtual void drawLine(int x0, int y0, int x1, int y1) = 0;
    virtual void setColor(int r, int g, int b) = 0;
    virtual void setColor(int color) = 0;
    virtual void fillRect(int x, int y, int w, int h) = 0;
    Screen(size_t width, size_t height) : width_(width), height_(height){};

};