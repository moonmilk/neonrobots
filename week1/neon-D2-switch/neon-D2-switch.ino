/*
 
 Switch neon output based on D2 input
 
 This example code is in the public domain.
 */

int pot = 0; // potentiometer on analog 0
int sw = 2; // switch on digital 2

int led = 11;           // the pin that the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 1;    // how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 11 to be an output:
  pinMode(led, OUTPUT);
  pinMode(sw, INPUT_PULLUP);
}

// the loop routine runs over and over again forever:
void loop() {
  if (digitalRead(sw)) brightness = 255;
  else brightness = 0;
  
  // set the brightness of pin 11:
  analogWrite(led, brightness);

  
}

