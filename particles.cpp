
#include "particles.h"

particles::particles()
{
    x = ((1.0*rand())/RAND_MAX);
    y = ((1.0*rand())/RAND_MAX);
}

particles::particles(double xx, double yy)
{
    x = xx;
    y = yy;
}


void particles::update(double speed)
{
    x = x + speed * ((2.0*rand())/RAND_MAX -1);
    y = y + speed * ((2.0*rand())/RAND_MAX -1);
    // if(x >= width || x <= 0)
    // {
        
    // }
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