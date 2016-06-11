#include "../include/GPIO.h"
#include "../include/Motor.h"
#include "../include/Steering.h"
#include <unistd.h>
#include <iostream>
using namespace exploringBB;
using namespace std;

int main() 
{
    cout << "trying to make a motor\n";
    Motor carMotor;
    Steering carSteering;
    usleep(2000000);
    carSteering.steer(50);
    carMotor.move(15);
    usleep(2000000);
    cout << "done waiting... in main\n";
    return 0;
}
