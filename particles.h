#ifndef PARTICLES_H
#define PARTICLES_H

#include <stdlib.h>

class particles
{
private:
    double x;
    double y;
public:
    particles();
    particles(double xx, double yy);
    ~particles();
    
    void update(double speed=0.01);

    double getXposition();
    double getYposition();
};

#endif 



