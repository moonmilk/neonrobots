/*
 NEON PULSATION RATE CONTROLLED BY POTENTIOMETER

 neon transformer on digital 11~
 
 potentiometer (variable resistor) connected to analog 0
 ...or any other analog signal on analog 0. For example:
  distance sensor https://www.adafruit.com/products/1031
  photosensor (brightness) https://www.adafruit.com/products/161

 Based on Fade example from Arduino IDE.
 */

int pot = 0; // potentiometer on analog 0

int neon = 11;           // the pin that the neon transformer is attached to
int brightness = 0;    // how bright the neon should be
int fadeAmount = 1;    // how fast to fade in or out

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(neon, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // set neon brightness:
  analogWrite(neon, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
  }

  // read value of potentiometer and turn it into a delay between about 1 and 50 milliseconds
  int a = analogRead(pot);
  int delayTime = 1 + (a / 20);
  
  delay(delayTime);
}

