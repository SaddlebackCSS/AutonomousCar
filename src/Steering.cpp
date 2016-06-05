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

    Steering::Steering():PWM("car_steering.16"),esc_switch(60), RIGHT_MAX(1202000), LEFT_MAX(1740000) 
    {
    }

    void Steering::init()
    {
    }

    void Steering::steer(int percent)
    {
    }

    Steering::~Steering() 
    {
    }

} /* namespace exploringBB */
