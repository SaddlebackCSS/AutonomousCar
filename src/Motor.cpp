/*
 * Motor.cpp  Created on: 29 Apr 2016
 * Copyright (c) 2016 yo momma's house 
 * happy 2nd birthday, PWM.cpp
 */

#include "../include/Motor.h"
#include "../include/util.h"
#include <cstdlib>
#include <iostream>
namespace exploringBB
{

    Motor::Motor():PWM("car_motor.17"),esc_switch(60), PWM_MAX(2000000), PWM_MIN(1000000) 
    {
        std::cout << "motor constructor" << std::endl;
        init();
    }

    void Motor::init()
    {
        std::cout << "running init function" << std::endl;
        unsigned int CENTER = 1500000;
        setDutyCycle(CENTER);
        esc_switch.setDirection(OUTPUT);
        esc_switch.setValue(HIGH);
        usleep(2000000);
        std::cout << "done waiting! :D" << std::endl;
    }

    void Motor::move(int percent)
    {
        // If the value is invalid DO NOTHING
        if( percent < -100 || percent > 100){ return; }
        
        unsigned int CENTER = 1500000;
        unsigned int SCALE  = 500000;
        unsigned int duty = static_cast<unsigned int>(CENTER + (SCALE * (percent / 100.0)));
        
        std::cout << "duty : " << duty << std::endl;
        setDutyCycle(duty);
    }

    Motor::~Motor() 
    {
        esc_switch.setValue(LOW);
    }

} /* namespace exploringBB */
