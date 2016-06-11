/*
 * Steering.cpp  Created on: 5 June 2016 
 */

#include "../include/Steering.h"
#include "../include/util.h"
#include <cstdlib>
#include <iostream>
namespace exploringBB
{

    Steering::Steering():PWM("car_steering.16"), RIGHT_MAX(1202000), LEFT_MAX(1740000), CENTER(1471000)
    {
        // run initialization
        init();
    }

    void Steering::init()
    {
        std::cout << "setting wheels to center...\n";
        // set wheels to center
        setDutyCycle(CENTER);
        std::cout << "steering module inititalized.\n";
    }

    void Steering::steer(int percent)
    {
        // If value is out of bounds, do nothing.
        if( percent < -100 || percent > 100) { return; }

        unsigned int SCALE = 269000;
        unsigned int duty = static_cast<unsigned int>(CENTER + (SCALE * (percent / 100.0)));

        std::cout << "steering duty: " << duty << std::endl;
        if(duty >= RIGHT_MAX && duty <= LEFT_MAX)
        {
            setDutyCycle(duty);
        }
    }

    Steering::~Steering() 
    {
        setDutyCycle(CENTER);
    }

} /* namespace exploringBB */
