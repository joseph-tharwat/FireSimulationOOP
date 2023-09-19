
#include "screen.h"
#include<iostream>

using namespace std;

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
    blurBuffer = new int[windowWidth*windowHieght];
    
    memset(buffer, 0, width*hieght*sizeof(int));
    memset(blurBuffer, 0, width*hieght*sizeof(int));
}

screen::~screen()
{
    close();
}
void screen::clear()
{
    memset(buffer, 0, width*hieght*sizeof(int));
    memset(blurBuffer, 0, width*hieght*sizeof(int));
}

void screen::boxBlur()
{
    int* temp = buffer;
    buffer = blurBuffer;   
    blurBuffer = temp;

    for(int y = 1; y<hieght-1; y++)
    {
        for(int x = 1; x<width-1; x++)
        {
            ////get the average color around the pixel 
            /*
             *0 0 0
             *0 1 0
             *0 0 0 
            */
           
            unsigned int totalRed = 0;
            unsigned int totalGreen = 0;
            unsigned int totalBlue = 0;

            unsigned int totalColor = 0;
            for(int rows=-1; rows<=1; rows++)
            {
                for(int cols=-1; cols<=1; cols++)
                {   
                    totalColor = getPixelBoxBlur(x+cols, y+rows);
            
                    totalRed = totalRed + (Uint8)(totalColor >> 24);
                    totalGreen = totalGreen + (Uint8)(totalColor >> 16);
                    totalBlue = totalBlue + (Uint8)(totalColor >> 8);         
                }
            }
            Uint8 red = totalRed/9;
            Uint8 green = totalGreen/9;  
            Uint8 blue = totalBlue/9;
            // setPixel(x,y, totalColor/9);
            setPixel(x, y, red, green, blue);
        }
    }
}

// void screen::boxBlur() {
// 	// Swap the buffers, so pixel is in m_buffer2 and we are drawing to m_buffer1.
// 	int *temp = buffer;
// 	buffer = blurBuffer;
// 	blurBuffer = temp;

// 	for(int y=0; y<hieght; y++) {
// 		for(int x=0; x<width; x++) {

// 			/*
// 			 * 0 0 0
// 			 * 0 1 0
// 			 * 0 0 0
// 			 */

// 			int redTotal=0;
// 			int greenTotal=0;
// 			int blueTotal=0;

// 			for(int row=-1; row<=1; row++) {
// 				for(int col=-1; col<=1; col++) {
// 					int currentX = x + col;
// 					int currentY = y + row;

// 					if(currentX >= 0 && currentX < width && currentY >= 0 && currentY < hieght) {
// 						Uint32 color = blurBuffer[currentY*width + currentX];

// 						Uint8 red = color >> 24;
// 						Uint8 green = color >> 16;
// 						Uint8 blue = color >> 8;

// 						redTotal += red;
// 						greenTotal += green;
// 						blueTotal += blue;
// 					}
// 				}
// 			}

// 			Uint8 red = redTotal/9;
// 			Uint8 green = greenTotal/9;
// 			Uint8 blue = blueTotal/9;

// 			setPixel(x, y, red, green, blue);
// 		}
// 	}
// }

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
    delete [] buffer;
    delete [] blurBuffer;
    SDL_DestroyTexture(m_texture);
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

void screen::setPixel(int x, int y, Uint8 R, Uint8 G, Uint8 B)
{
    if(x<0 || x>width || y<0 || y>hieght)   
    {
        return;
    }

    int color = R<<24;
    color = color + G<<16;
    color = color + B<<8;
    color = color + 0xFF;//alpha
    buffer[width*y+x] = color;
}

void screen::setPixel(int x, int y,int color)
{
    if(x<0 || x>width || y<0 || y>hieght)
    {
        return;
    }
    setPixel(x, y,  color>>24,
                    color>>16,
                    color>>8 );
    // buffer[width*y+x] = color;
}


int screen::getPixel(int x, int y)
{
    return buffer[width*y+x];
}

unsigned int screen::getPixelBoxBlur(int x, int y)
{
    return blurBuffer[width*y+x];   
}

int screen::getWidth()
{   
    return width;
}

int screen::getHieght()
{
    return hieght;
}


