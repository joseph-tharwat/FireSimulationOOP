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

        SDL_Window* m_window;
        SDL_Renderer* m_renderer;
        SDL_Texture* m_texture;
    public:
        screen(char windowName[], int WindowWidth, int WindowHieght);
        ~screen();

        void show();
        void clear();
        void update();
        void close();
        bool eventProcess();

        void setPixel(int x, int y, char R, char B, char G);
        void getPixel(int x, int y);

        int getWidth();
        int getHieght();
};


#endif