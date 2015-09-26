/*
 * BLINK RATE CONTROLLED BY KEYBOARD
 * 
 adafruit 4 key keyboard on d2(common) and d3-6(keys)
 
 keyboard: https://www.adafruit.com/products/1332
 
 neon transformer on 11
 This example code is in the public domain.
 */

int neon = 11;           // the pin that the neon transformer is attached to
int brightness = 0;    // how bright the neon should be

// keyboard pins
int keyCommon = 2; 
int key1 = keyCommon+2; // NOTE KEYS ARE NOT IN ORDER!
int key2 = keyCommon+1;
int key3 = keyCommon+4;
int key4 = keyCommon+3;

// timer
unsigned long lastBlinkTime = 0;

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(neon, OUTPUT);

  // declare pin 2 to be an output to power the 4 keys
  pinMode(keyCommon, OUTPUT);
  digitalWrite(keyCommon, 0);

  // and the 4 key inputs are inputs
  pinMode(key1, INPUT_PULLUP);
  pinMode(key2, INPUT_PULLUP);
  pinMode(key3, INPUT_PULLUP);
  pinMode(key4, INPUT_PULLUP);
}

// the loop routine runs over and over again forever:
void loop() {
  int timeDelay = 0;
  
  
  // check the 4 key inputs - if any is pressed, it will be connected to pin 2 which will make it LOW
  // if not pressed, it will be connected to nothing, so the PULLUP will make it HIGH
  
  if (digitalRead(key1) == LOW) {
    timeDelay = 100;
  }
  else if (digitalRead(key2) == LOW) {
    timeDelay = 200;
  }
  else if (digitalRead(key3) == LOW) {
    timeDelay = 300;
  }
  else if (digitalRead(key4) == LOW) {
    timeDelay = 400;
  }

  else {
    // no keys presed
    timeDelay = 100000;
  }

  // is it time to blink yet?
  unsigned long elapsedTime = millis() - lastBlinkTime;
  if (elapsedTime > timeDelay) {
    lastBlinkTime = millis();

    // if on, turn off, and vice versa
    if (brightness > 0) brightness = 0;
    else brightness = 255;
  }
  

  // send brightness to neon transformer
  analogWrite(neon, brightness);

}

