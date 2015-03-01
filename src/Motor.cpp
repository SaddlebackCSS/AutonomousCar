/*
 * PWM.cpp  Created on: 29 Apr 2014
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

#include "../include/Motor.h"
#include "../include/util.h"
#include <cstdlib>

namespace exploringBB {

Motor::Motor(string pinName) {
	this->name = pinName;
	this->path = PWM_PATH + this->name + "/";
	this->analogFrequency = 50;
	this->analogMax = 3.3;
}

int Motor::setPeriod(unsigned int period_ns){
	return write(this->path, PWM_PERIOD, period_ns);
}

unsigned int Motor::getPeriod(){
	return atoi(read(this->path, PWM_PERIOD).c_str());
}

float Motor::period_nsToFrequency(unsigned int period_ns){
	float period_s = (float)period_ns/1000000000;
	return 1.0f/period_s;
}

unsigned int Motor::frequencyToPeriod_ns(float frequency_hz){
	float period_s = 1.0f/frequency_hz;
	return (unsigned int)(period_s*1000000000);
}

int Motor::setFrequency(float frequency_hz){
	return this->setPeriod(this->frequencyToPeriod_ns(frequency_hz));
}

float Motor::getFrequency(){
	return this->period_nsToFrequency(this->getPeriod());
}

int Motor::setDutyCycle(unsigned int duty_ns){
	return write(this->path, PWM_DUTY, duty_ns);
}

int Motor::setDutyCycle(float percentage){
	if ((percentage>100.0f)||(percentage<0.0f)) return -1;
	unsigned int period_ns = this->getPeriod();
	float duty_ns = period_ns * (percentage/100.0f);
	this->setDutyCycle((unsigned int) duty_ns );
	return 0;
}

unsigned int Motor::getDutyCycle(){
	return atoi(read(this->path, MOTOR_DUTY).c_str());
}

float Motor::getDutyCyclePercent(){
	unsigned int period_ns = this->getPeriod();
	unsigned int duty_ns = this->getDutyCycle();
	return 100.0f * (float)duty_ns/(float)period_ns;
}

int Motor::setPolarity(PWM::POLARITY polarity){
	return write(this->path, MOTOR_POLARITY, polarity);
}

void Motor::invertPolarity(){
	if (this->getPolarity()==Motor::ACTIVE_LOW) this->setPolarity(Motor::ACTIVE_HIGH);
	else this->setPolarity(Motor::ACTIVE_LOW);
}

Motor::POLARITY Motor::getPolarity(){
	if (atoi(read(this->path, MOTOR_POLARITY).c_str())==0) return Motor::ACTIVE_LOW;
	else return Motor::ACTIVE_HIGH;
}

int Motor::calibrateAnalogMax(float analogMax){ //must be between 3.2 and 3.4
	if((analogMax<3.2f) || (analogMax>3.4f)) return -1;
	else this->analogMax = analogMax;
	return 0;
}

int Motor::analogWrite(float voltage){
	if ((voltage<0.0f)||(voltage>3.3f)) return -1;
	this->setFrequency(this->analogFrequency);
	this->setPolarity(Motor::ACTIVE_LOW);
	this->setDutyCycle((100.0f*voltage)/this->analogMax);
	return this->run();
}

int Motor::run(){
	return write(this->path, MOTOR_RUN, 1);
}

bool Motor::isRunning(){
	string running = read(this->path, MOTOR_RUN);
	return (running=="1");
}

int Motor::stop(){
	return write(this->path, MOTOR_RUN, 0);
}

PWM::~PWM() {}

} /* namespace exploringBB */
