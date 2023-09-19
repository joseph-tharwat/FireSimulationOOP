
#ifndef SWARM_H
#define SWARM_H

#include "particles.h"

class swarm
{
    private:
        particles* particlesArray;
        int particlesCount;
    public:
        swarm(int particlesNumber);
        ~swarm();

        void update();
        int getCount();
        particles *getParticles();
        particles getIndexParticle(int index);
};


#endif
