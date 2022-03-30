#include <cstring>
#include <iostream>
#include <string>
#include "dummy_display/dummy_display.h"

#include "tcp_client/tcp_client.h"

int main(int argc, char *argv[])
{

    dummy_display dis(800, 600, "localhost", "10002");
    dis.begin();
    dis.setColor(0xFF0000);
    dis.drawLine(0, 0, 100, 100);
    dis.fillRect(100, 100, 100, 100);
    dis.drawVLine(10, 10, 50);

    while (1);
    
    return 0;
}