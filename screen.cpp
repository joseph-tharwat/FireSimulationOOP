
#include "screen.h"


screen::screen(char windowName[], int windowWidth, int windowHieght)
{
    width = windowWidth;
    hieght = windowHieght;
    m_window = SDL_CreateWindow(windowName,
                                SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED,
                                windowWidth,
                                windowHieght,
                                SDL_WINDOW_SHOWN);

    m_renderer = SDL_CreateRenderer(m_window,
                                    -1,
                                    SDL_RENDERER_PRESENTVSYNC);

    m_texture = SDL_CreateTexture(m_renderer,
                                    SDL_PIXELFORMAT_RGBA8888,
                                    SDL_TEXTUREACCESS_STATIC,
                                    windowWidth,
                                    windowHieght);

    buffer = new int[windowWidth*windowHieght];
    
}

screen::~screen()
{
    close();
}
void screen::clear()
{
    memset(buffer, 0, width*hieght*sizeof(int));
}
void screen::update()
{   
    SDL_UpdateTexture(m_texture, NULL, buffer, width*sizeof(int));
    SDL_RenderClear(m_renderer);
    SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
    SDL_RenderPresent(m_renderer);
}

bool screen::eventProcess()
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        if(event.type == SDL_QUIT)
        {
            return false;
        }
    }
    return true;
}

void screen::close()
{
    SDL_DestroyTexture(m_texture);
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

void screen::setPixel(int x, int y, char R, char B, char G)
{
    if(x<0 || x>width || y<0 || y>hieght)
    {
        return;
    }

    int color = R<<24;
    color = color + B<<16;
    color = color + G<<8;
    color = color + 0xFF;
    buffer[width*y+x] = color;
}

void screen::getPixel(int x, int y)
{

}

int screen::getWidth()
{   
    return width;
}

int screen::getHieght()
{
    return hieght;
}


