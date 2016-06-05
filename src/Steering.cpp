/*
 * Steering.cpp  Created on: 29 Apr 2016
 * Copyright (c) 2016 yo momma's house 
 * happy 2nd birthday, PWM.cpp
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
        // set wheels to center
        setDutyCycle(CENTER);
    }

    void Steering::steer(int percent)
    {
        // If value is out of bounds, do nothing.
        if( percent < -100 || percent > 100) { return; }


    }

    Steering::~Steering() 
    {
        setDutyCycle(CENTER);
    }

} /* namespace exploringBB */
