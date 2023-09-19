
#include "swarm.h"

#include<iostream>

swarm::swarm(int particlesNumber)
{
    particlesCount = particlesNumber;
    particlesArray = new particles[particlesNumber];
}

swarm::~swarm()
{
    delete [] particlesArray;
}

int swarm::getCount()
{
    return particlesCount;
}

void swarm::update()
{
    for(int i=0; i< particlesCount; i++)
    {
        particlesArray[i].update();
    }
}

particles* swarm::getParticles()
{
    return particlesArray;   
}

particles swarm::getIndexParticle(int index)
{
    return particlesArray[index];
}

