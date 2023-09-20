
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

    screen* mainScreen = new screen(SCREEN_TITLE, SCREEN_WIDTH, SCREEN_HEIGHT);
    swarm *mySwarm = new swarm(PARTICLES_NUMBER);
    
    Uint32 colorR = (1.0*rand()/RAND_MAX) * 255;
    Uint32 colorG = (1.0*rand()/RAND_MAX) * 255;
    Uint32 colorB = (1.0*rand()/RAND_MAX) * 255;
    Uint32 color = (1.0*rand()/RAND_MAX) * 255;
    cout<<colorR<<" "<<colorG<<" "<<colorB<<endl;
    // Uint8 colorR = 255;
    // Uint8 colorG = 255;
    // Uint8 colorB = 255;
    int i = 0;
    while(true)
    {   
        //  Uint8 color = SDL_GetTicks();
        //  Uint8 colorR = 1+sin(color*0.001)*128;
        //  Uint8 colorG = 1+sin(color*0.001)*128;;
        //  Uint8 colorB = 1+sin(color*0.001)*128;
        //  color++;
        //  int colorG = SDL_GetTicks();
        //  colorG = 1+sin(colorG*0.001)*128;

        //  int colorB = SDL_GetTicks();
        //  colorB = 1+sin(colorB*0.001)*128;
        
        
        // mainScreen->clear();
        mySwarm->update();
        for(int i=0; i<mySwarm->getCount(); i++)
        {
            mainScreen->setPixel(mySwarm->getIndexParticle(i).getXposition()*mainScreen->getWidth(),
                                 mySwarm->getIndexParticle(i).getYposition()*mainScreen->getHieght(),
                                 colorR,colorG,colorB);
        }
        
        
        mainScreen->boxBlur();
        mainScreen->update();
        
        if(mainScreen->eventProcess() ==false)
        {
            break;
        } 
    }
    
    mainScreen->close();
    return 0;
}
