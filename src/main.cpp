/**
 * Author:  Ethan Slattery
 * Created: 22DEC2015
 *
 * Modified By: nobody yet!
 * Modified Date: :)
 *
 * AUTONOMOUS CAR TESTING PROGRAM
 *
 * PARTS: (check schematic for physical setup)
 *   + Two Potentiometers
 *   + One Relay
 *   + Arduino Uno or compatable
 *
 * TESTS:
 *   + Check physical limits of steering servo and adjust macros
 *   + Check direction of motor and switch cable order as necessary
 *   + Check timing of ESC commands for arming and adjust macro as necessary
 *   + Use pots to understand ESC commands and write psuedocode for control lib
 */
#include <Arduino.h>
#include "avr/Servo.cpp"

// SERVO MACROS - UPDATE FROM TESTS
#define STEER_RIGHT 65	 // Physical Limit on right side
#define STEER_LEFT  115  // Physical Limit on left side
#define STEER_RANGE 50   // Range of the steering servo
#define NEUTRAL     90	 // Neutral Position of servos
#define ARM_TIME    2000 // Time to arm the ESC at neutral position

// PIN MACROS
#define PWR_SWITCH  8	// Pin for the ESC power switch control
#define MOTOR_PIN   10  // Pin for the ESC throttle "servo"
#define STEERING    9	// Pin for the steering servo
#define STEER_POT   2	// Pin for the steering testing pot
#define MOTOR_POT   1	// Pin for the motor testing pot
#define PING_PIN    7	// PIN FOR PIN ULTRASONIC SENSOR

long GetDistance(int pingPin);

int main() {
  // Arduino Initialization
  init();

  // Initialize the servo objects
  Servo steering; // The steering servo
  Servo motor;    // The Motor ESC

  // set up Serial library at 9600 bps
  Serial.begin(9600);
  Serial.println("**** AUTONOUMOUS CAR CONTROL TESTING *****");

  // Esc Switch control set to output, and initialized to low
  Serial.println("**** SETUP ESC PIN AND TURN ESC OFF FOR 1 SEC *****");
  pinMode(PWR_SWITCH, OUTPUT);
  digitalWrite(PWR_SWITCH, LOW);
  delay(1000);

  // attaching servo and esc
  Serial.println("**** ATTACH STEERING AND MOTOR *****");
  steering.attach(STEERING);
  steering.write(NEUTRAL);
  motor.attach(MOTOR_PIN);
  motor.write(NEUTRAL);

  // Arm the ESC
  Serial.println("**** ARM ESC - 2 SEC AT NEUTRAL THROTTLE *****");
  digitalWrite(PWR_SWITCH, HIGH);
  delay(2000);

  int  steerVal = 0;
  int  motorVal = 0;
  while(1)
  {
      // Obtain a scaled steering value
      steerVal = (analogRead(STEER_POT) * (STEER_RANGE/1023.0)) + STEER_RIGHT;

      // Obtain a scaled motor value
      motorVal = analogRead(MOTOR_POT) * (180.0/1023.0);

      Serial.print("Steering: ");
      Serial.print(steerVal);
      Serial.print("\tMotor: ");
      Serial.print(motorVal);
      Serial.print("\tDistance: ");
      //Serial.println(GetDistance(PING_PIN));

      steering.write(steerVal);
      motor.write(motorVal);

  }// END OF FOREVER LOOP

  return 0; // BAD NEWS - NEVER HAPPENS (prevents compiler whining)
}

long GetDistance(int pingPin)
{
  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(pingPin, INPUT);
  return pulseIn(pingPin, HIGH) / 74 / 2;
}
