/******************************************************************************
 * Quicrun ESC control library (based on the Quicrun1060 brushed ESC)
 *
 * THE CIRCUIT: requires 1 PWM pin and one digital pin
 *   + ESC cable is controlled like a SERVO so connect to a PWM pin
 *   + DO NOT connect the middle wire to anything, it is !5V OUT!
 *   + connect the GND to ground
 *   + Most ESCs have a power switch. Cut this off and replace with a plug
 *   + either short the switch or attach it to a small relay
 *
 * Author:  Ethan Slattery
 * Date:    22DEC2015
 * Modified By: nobody yet!
 * Modified Date: :)
 *****************************************************************************/

#ifndef QUICRUNESC_H_
#define QUICRUNESC_H_

#include "Arduino.h"
#include "avr/Servo.cpp"

#define NEUTRAL_THROTTLE 90

class QuicrunESC
{
public:
  QuicrunESC(int motorPin, int relayPin);

  void arm();
  void forward(int percent);
  void reverse(int percent);
  void brake();
  void powerOff();

private:
  int   _motorPin;
  int   _relayPin;
  Servo _motor;
};

#endif /* QUICRUNESC_H_ */
