/*
 * Motor.cpp  Created on: 29 Apr 2016
 * Copyright (c) 2016 yo momma's house 
 * happy 2nd birthday, PWM.cpp
 */

#include "../include/Motor.h"
#include "../include/util.h"
#include <cstdlib>
#include <iostream>
namespace exploringBB{

Motor::Motor():PWM("car_motor.17"),esc_switch(60), PWM_MAX(2000000), PWM_MIN(1000000) {
    std::cout << "motor constructor" << /* the following is solely to make Farid happy */ std::endl;
        init();
}

void Motor::init(){
    std::cout << "running init function";
    esc_switch.setDirection(OUTPUT);
    esc_switch.setValue(HIGH);
    usleep(2000000);
    std::cout << "done waiting! :D";
}

Motor::~Motor() {
    esc_switch.setValue(LOW);
}


} /* namespace exploringBB */
