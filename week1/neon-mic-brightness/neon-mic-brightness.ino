/*
 * LIGHT UP NEON IN PROPORTION TO SOUND

 neon transformer on digital 11~
 microphone on analog 0

 microphone could be https://www.adafruit.com/products/1063 or https://www.adafruit.com/products/1713
 */

int mic = 0; // microphone on analog 0

int neon = 11;           // the pin that the neon transformer is attached to
int brightness = 0;    // how bright the neon will be

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(neon, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {

  // read sound level from mic for 50 milliseconds
  const int sampleTime = 50;
  unsigned long startTime = millis();

  unsigned int peakToPeak = 0, signalMin = 1024, signalMax = 0;

  while (millis() - startTime < sampleTime) {
    unsigned int sample = analogRead(mic);
 
    if (sample > 1023) {
      // ignore spurious input
    }
    
    else if (sample < signalMin) {
      signalMin = sample;
    }

    else if (sample > signalMax) {
      signalMax = sample;
    }
  }

  // since sample is from 0 to 1023, the largest possible peak difference is 1023
  peakToPeak = signalMax - signalMin;

  // brightness is 0 to 255 so divide by 4
  
  // set the brightness of neon controller
  brightness = peakToPeak / 4;
  analogWrite(neon, brightness);

}

