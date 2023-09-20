#ifndef PARTICLES_H
#define PARTICLES_H

#include <stdlib.h>

class particles
{
private:
    double x;
    double y;
    double speed;
    double direction;
    // double xSpeed;
    // double ySpeed;
private: 
    void init();
public:
    particles(bool random = false);
    particles(double xx, double yy);
    ~particles();
    
    void update();

    double getXposition();
    double getYposition();
};

#endif 



