
//To compile without any error
//g++ main.cpp screen.cpp particles.cpp swarm.cpp -lmingw32 -lSDL2main -lSDL2

#include<iostream>
#include<math.h>
#include<time.h>

#include "include\SDL.h"

#include"main.h"
#include "screen.h"
#include"particles.h"
#include "swarm.h"

using namespace std;

int main(int argc, char* argv[])
{   
    srand(time(NULL));

    screen* mainScreen = new screen("fire simulation", SCREEN_WIDTH, SCREEN_HEIGHT);
    swarm *mySwarm = new swarm(PARTICLES_NUMBER);
    
    int color = 255;
    while(true)
    {   
        // int color = SDL_GetTicks();
        // color = 1+sin(color*0.001)*128;
        
        // for(int i = 0; i < mainScreen->getWidth(); i++)
        // {
        //     for(int j = 0; j < mainScreen->getWidth(); j++)
        //     {
        //         mainScreen->setPixel(i,j,color,color,color);
        //     }
        // }
        mainScreen->clear();
        mySwarm->update(0.001);
        for(int i=0; i<mySwarm->getCount(); i++)
        {
            mainScreen->setPixel(mySwarm->getIndexParticle(i).getXposition()*mainScreen->getWidth(),
                                 mySwarm->getIndexParticle(i).getYposition()*mainScreen->getHieght(),
                                 color,color,color);
        }
        

        mainScreen->update();
        
        if(mainScreen->eventProcess() ==false)
        {
            break;
        } 
    }
    
    mainScreen->close();
    return 0;
}
