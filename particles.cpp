
#include "particles.h"
#include <math.h>

//if not random, start in the middle of the screen
particles::particles(bool random)
{
    if(random == true)
    {
        x = ((1.0*rand())/RAND_MAX);
        y = ((1.0*rand())/RAND_MAX);
    }
    else
    {
        x = 0.5;
        y = 0.5;
    }
    speed = 0.001 * ((2.0*rand())/RAND_MAX -1);
    direction = 2 * M_PI * ((1.0*rand())/RAND_MAX);
}

particles::particles(double xx, double yy)
{
    x = xx;
    y = yy;
}

void particles::update()
{
    x = x + speed * cos(direction);
    y = y + speed * sin(direction);
    if(x >= 1 || x <= -1)
    {   
        x = x - speed * cos(direction); 
        speed = -speed;
    }
    if(y >= 1 || y <= -1)
    {
        y = y - speed * sin(direction);
        speed = -speed;
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