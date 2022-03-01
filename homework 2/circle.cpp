#include "./buffer.hpp"
#include <math.h>

float dist(float ax, float ay, float bx, float by)
{
    return sqrtf((bx - ax)*(bx - ax) + (by - ay)*(by - ay));
}

int main()
{   
    const Color green = Color{0,255,0};

    Buffer buffer(1920, 1080);

    float origX = buffer.width / 2.0;
    float origY = buffer.height / 2.0;
    float radius = 100;

    for (int y = 0; y < buffer.height; y++)
    {
        for (int x = 0; x < buffer.width; x++)
        {
            if(dist(x,y,origX,origY) <= radius) {
                buffer.data[x][y] = green;
            }
        }
    }

    buffer.exportPPM("circle.ppm");


    return EXIT_SUCCESS;
}