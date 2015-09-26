/*
NEON BRIGHTNESS CONTROLLED BY POTENTIOMETER
 
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

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(neon, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of pin 9:
  brightness = analogRead(pot) / 4;
  analogWrite(neon, brightness);

}

