#include "./buffer.hpp"
#include <math.h>
#include <time.h> 

void drawNoisyRect(int posX, int posY, int w, int h, Color c, Buffer& buffer) {
    srand (time(NULL));
    for (int y = posY; y < h + posY; y++)
    {
        for (int x = posX; x < w + posX; x++)
        {
            Color newColor = {0,0,0};
            if(c.r > 0) newColor.r = rand() % c.r + 1;
            if(c.g > 0) newColor.g = rand() % c.g + 1;
            if(c.b > 0) newColor.b = rand() % c.b + 1;
            buffer.data[x][y] = newColor;
        }
    }
}

int main()
{   
    Buffer buffer(1920, 1080);

    int rectW = buffer.width / 4;
    int rectH = buffer.height / 4;

    std::vector<Color> colors = {{255,0,0}, {0,255,0}, {255,255,0}, {0,0,255}, {255,0,255}, {0,255,255}};

    for (int y = 0, cnt = 0; y < buffer.height; y+=rectH)
    {
        for (int x = 0; x < buffer.width; x+=rectW)
        {
            drawNoisyRect(x,y,rectW, rectH, colors[cnt % colors.size()], buffer);
            cnt++;
        }
    }

    buffer.exportPPM("rects.ppm");


    return EXIT_SUCCESS;
}