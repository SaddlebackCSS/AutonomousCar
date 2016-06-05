#include "../include/GPIO.h"
#include "../include/PWM.h"
#include <unistd.h>
using namespace exploringBB;
using namespace std;

int main() 
{
	// Center duty value for both steering and motor
	unsigned int CENTER = 1500000;
	
	// max values for steering
	unsigned int RIGHT_MAX = 1202000;
	unsigned int LEFT_MAX = 1740000;
	
	// DO NOT use this for steering (unless you want a broken car). 
	// MOTOR USE ONLY.
	unsigned int PWM_MAX = 2000000;
	unsigned int PWM_MIN = 1000000;
	
	GPIO esc_switch(60);
	PWM car_steering("car_steering.16");
	PWM car_motor("car_motor.17");
	
	// Initialize steering and motor duties
	car_steering.setDutyCycle(CENTER);
	car_motor.setDutyCycle(CENTER);
	
	// Arm the electronic speed controller (ESC)
	esc_switch.setDirection(OUTPUT);
	esc_switch.setValue(HIGH);
	usleep(2000000); // wait for 2 seconds
	
	// Car steering / motor control test.
	for(int i = 0; i < 3; i++){
		car_steering.setDutyCycle(RIGHT_MAX); // turn wheels all the way right
		usleep(500000); // wait 1/2 second
		car_steering.setDutyCycle(CENTER); // turn wheels to center
		
		// Go forward
		car_motor.setDutyCycle((unsigned int)(1700000));
		usleep(500000);
		
		// brake
		car_motor.setDutyCycle((unsigned int)(CENTER - 300000));
		
		car_steering.setDutyCycle(LEFT_MAX); // turn wheels all the way left
		usleep(500000);
		car_steering.setDutyCycle(CENTER); // back to center
		usleep(500000);
}
	
	return 0;
}
