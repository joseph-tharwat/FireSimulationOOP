
//to compile without any error
//g++ main.cpp -lmingw32 -lSDL2main -lSDL2

#include<iostream>
#include "include\SDL.h"

using namespace std;

int main(int argc, char* argv[])
{
    int windowWidth = 500;
    int windowHieght = 600;


    if(SDL_Init(SDL_INIT_VIDEO)<0)
    {
        return -1;
    }
    
    SDL_Window* my_window = SDL_CreateWindow("fire",
                                      SDL_WINDOWPOS_UNDEFINED,
                                      SDL_WINDOWPOS_UNDEFINED,
                                      windowWidth,
                                      windowHieght,
                                      SDL_WINDOW_SHOWN);
    if(my_window == NULL)
    {
        return -2;
    }   
    bool quiteFlage=false; 
    SDL_Event event;

    SDL_Renderer *my_renderer = SDL_CreateRenderer(my_window,
                                                   -1,
                                                   SDL_RENDERER_PRESENTVSYNC);
    SDL_Texture *my_texture = SDL_CreateTexture(my_renderer,
                                                SDL_PIXELFORMAT_RGBA8888,
                                                SDL_TEXTUREACCESS_STATIC,
                                                windowWidth,
                                                windowHieght);

    int *buffer = new int[windowWidth*windowHieght];
    memset(buffer, 255, windowWidth*windowHieght*sizeof(int));
    
    SDL_UpdateTexture(my_texture, NULL, buffer, windowWidth*sizeof(int));
    SDL_RenderClear(my_renderer);
    SDL_RenderCopy(my_renderer, my_texture,NULL,NULL);
    SDL_RenderPresent(my_renderer);

    while(quiteFlage == false)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                quiteFlage = true;   
            }
        }

    }

    SDL_DestroyTexture(my_texture);
    SDL_DestroyRenderer(my_renderer);
    SDL_DestroyWindow(my_window);
    SDL_Quit();
    cout<<"hello"<<endl;
    return 0;
}
