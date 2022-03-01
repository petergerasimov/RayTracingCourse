#include <vector>
#include <iostream>
#include <fstream>

struct Color
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

typedef std::vector<std::vector<Color>> Matrix;

class Buffer
{
private:
    int maxColor = 255;
public:
    int width = 0;
    int height = 0;
    Matrix data;

    Buffer(int width, int height) : width(width), height(height)
    {
        std::vector<Color> col(height, {0, 0, 0});
        for (int i = 0; i < width; i++)
        {
            data.push_back(col);
        }
    }

    void print()
    {
        for (int y = 0; y < this->height; y++)
        {
            for (int x = 0; x < this->width; x++)
            {
                std::cout << (int)this->data[x][y].r << " ";
            }
            std::cout << std::endl;
        }
    }

    void exportPPM(std::string filename)
    {
        std::ofstream ppmFileStream(filename, std::ios::out | std::ios::binary);
        ppmFileStream << "P3\n";
        ppmFileStream << this->width << " " << this->height << "\n";
        ppmFileStream << this->maxColor << "\n";

        for (int y = 0; y < this->height; y++)
        {
            for (int x = 0; x < this->width; x++)
            {
                ppmFileStream << (int)this->data[x][y].r << " "
                              << (int)this->data[x][y].g << " " 
                              << (int)this->data[x][y].b << " " 
                              << "\t";
            }
            ppmFileStream << "\n";
        }

        ppmFileStream.close();
    }
};