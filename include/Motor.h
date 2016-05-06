/*
 * PWM.h  Created on: 29 Apr 2014
 * Copyright (c) 2014 Derek Molloy (www.derekmolloy.ie)
 * Made available for the book "Exploring BeagleBone" 
 * See: www.exploringbeaglebone.com
 * Licensed under the EUPL V.1.1
 *
 * This Software is provided to You under the terms of the European 
 * Union Public License (the "EUPL") version 1.1 as published by the 
 * European Union. Any use of this Software, other than as authorized 
 * under this License is strictly prohibited (to the extent such use 
 * is covered by a right of the copyright holder of this Software).
 * 
 * This Software is provided under the License on an "AS IS" basis and 
 * without warranties of any kind concerning the Software, including 
 * without limitation merchantability, fitness for a particular purpose, 
 * absence of defects or errors, accuracy, and non-infringement of 
 * intellectual property rights other than copyright. This disclaimer 
 * of warranty is an essential part of the License and a condition for 
 * the grant of any rights to this Software.
 * 
 * For more details, see http://www.derekmolloy.ie/
 */

#ifndef MOTOR_H_
#define MOTOR_H_
#include "GPIO.h"
#include "PWM.h"

namespace exploringBB{

/**
 * @class Motor
 * @brief A class to control a basic PWM output -- you must know the exact sysfs filename
 * for the PWM output.
 */
class Motor : public PWM {
public:
	Motor();
        void move(int percent);
        void brake();

	~Motor();
private:
    void init();
    GPIO esc_switch;
    const unsigned int PWM_MAX;
    const unsigned int PWM_MIN;
};

} /* namespace exploringBB */

#endif /* MOTOR_H_ */
