/**
 * Author:  Ethan Slattery
 * Created: 22DEC2015
 *
 * Modified By: nobody yet!
 * Modified Date: :)
 *
 * Quicrun ESC control library (based on the Quicrun1060 brushed ESC)
 */
#include "QuicrunESC.h"

QuicrunESC::QuicrunESC(int motorPin, int relayPin)
{
  // Attach the motor control servo and set to neutral
  _motorPin = motorPin;
  _relayPin = relayPin;
  _motor.attach(_motorPin);
  _motor.write(NEUTRAL_THROTTLE);

  // Set the relay pin to output and initialize to low.
  pinMode(_relayPin, OUTPUT);
  digitalWrite(_relayPin, LOW);
}

/** Arms the ESC.
 * As per ESC documents, 2sec of neutral throttle at power on will arm the ESC.
 * ESC will beep 2x for a 2S battery and then emit one long beep when armed.
 */
void QuicrunESC::arm()
{
  digitalWrite(_relayPin, HIGH);
  delay(2000);
}

/**
 *
 */
void QuicrunESC::forward(int percent)
{

}
/**
 *
 */
void QuicrunESC::reverse(int percent)
{

}

/// Slams on the brakes!
void QuicrunESC::brake()
{

}

/// Disarms the ESC and sets throttle to neutral.
void QuicrunESC::powerOff()
{
  digitalWrite(_relayPin, LOW);
  _motor.write(NEUTRAL_THROTTLE);
}
