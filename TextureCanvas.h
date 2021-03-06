#ifndef TXCANVAS
#define TXCANVAS

#include <vector>
#include <iostream>
//#include <GL/glut.h>
#include <QtOpenGL/QGLWidget>
#include <QtOpenGL/QGLWidget>
#include "BasicTypes.h"

using namespace std;

class textureTile{
public:
    int width;
    int height;
    GLuint tex_id;
    vector< unsigned char > data;
    textureTile(int w, int h) {
        width = w;
        height = h;
    }
};


class TextureCanvas{
public:

    TextureCanvas();
    TextureCanvas(vector<color>& pixels, int width, bool raggedEdge = false);
    ~TextureCanvas();
    void init(int w = 1, bool raggedEdge = false);
    void display();
    static int const maxSaneWidth = 4000;
    bool ragged;
    int getMaxSize();
    
private:
    int max_size;
    int checkForDisplayDriver();
    void loadPixelsToCard(vector<color>& pixels, int w);
    void createEmptyTiles(int canvas_width, int canvas_height, int max_size);
    void createDisplayList();
    void drawTextureSquare();
    point2D grid_position(int i, int width, int height, int max_size );
    GLuint loadTexture(textureTile& tile);

    point get_position(int index);
    void paint_square(point position, color c);
    void textureFreeRender();

    bool useTextures;
    GLuint displayList;
    int width;
    int height;
    vector< vector< textureTile > > canvas;
    vector<color> colors;
};

#endif

