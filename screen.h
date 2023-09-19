#ifndef SCREEN_H
#define SCREEN_H

#include "include\SDL.h"
#include<string.h>

class screen
{
    private:
        int width;
        int hieght;
        int *buffer;
        int *blurBuffer;

        SDL_Window* m_window;
        SDL_Renderer* m_renderer;
        SDL_Texture* m_texture;
    public:
        screen(char windowName[], int WindowWidth, int WindowHieght);
        ~screen();

        void show();
        void clear();
        void boxBlur();
        void update();
        void close();
        bool eventProcess();

        void setPixel(int x, int y, unsigned char R, unsigned char B, unsigned char G);
        void setPixel(int x, int y,int color);
        int getPixel(int x, int y);
        unsigned int getPixelBoxBlur(int x, int y);

        int getWidth();
        int getHieght();
};


#endif