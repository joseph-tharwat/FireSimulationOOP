
#include "particles.h"
#include <math.h>

//if not random, start in the middle of the screen
particles::particles(bool random)
{
    init();
    // if(random == true)
    // {
    //     x = ((1.0*rand())/RAND_MAX);
    //     y = ((1.0*rand())/RAND_MAX);
    // }
    // else
    // {
    //     x = 0.5;
    //     y = 0.5;
    // }
    // speed = 0.1 * ((2.0*rand())/RAND_MAX -1);
    // speed = speed * speed;
    // direction = 2 * M_PI * ((1.0*rand())/RAND_MAX);
}

void particles::init()
{  
    x = 0.5;
    y = 0.5;
    speed = 0.1 * ((2.0*rand())/RAND_MAX -1);
    speed = speed * speed;
    direction = 2 * M_PI * ((1.0*rand())/RAND_MAX);
}

particles::particles(double xx, double yy)
{
    x = xx;
    y = yy;
}

void particles::update()
{
    direction = direction + 0.01;
    x = x + speed * cos(direction);
    y = y + speed * sin(direction);
    if(x >= 1 || x <= -1)
    {   
        init();
        // x = x - speed * cos(direction); 
        // speed = -speed;
    }
    if(y >= 1 || y <= -1)
    {
        init();
        // y = y - speed * sin(direction);
        // speed = -speed;
    }
}

double particles::getXposition()
{
    return x;
}

double particles::getYposition()
{
    return y;
}


particles::~particles()
{
    
}