#include "../include/GPIO.h"
#include "../include/Motor.h"
#include <unistd.h>
#include <iostream>
using namespace exploringBB;
using namespace std;

int main() 
{
    cout << "trying to make a motor\n";
    Motor carMotor;
    carMotor.move(25);
    usleep(2000000);
    carMotor.move(0);
    cout << "done waiting... in main\n";
	return 0;
}
