#include "../include/GPIO.h"
#include <unistd.h>
using namespace exploringBB;
using namespace std;
int main() 
{
	GPIO esc_switch(60);
	
	// Arm the electronic speed controller (ESC)
	esc_switch.setDirection(OUTPUT);
	esc_switch.setValue(HIGH);
	usleep(2000000);
	
	return 0;
}
