/*
 * NEON CANDLE EXTINGUISHED BY BLOWING ON MICROPHONE
 */

// neon transformer on digital pin 11~
const int neon = 11;

// microphone on analog pin 0
// microphone could be https://www.adafruit.com/products/1063 or https://www.adafruit.com/products/1713
const int mic = 0;

// keep track of brightness of neon
int brightness = 0;


void setup() {
  pinMode(neon, OUTPUT);
}

// 0 if candle is burning, otherwise what time was candle extinguished
unsigned long extinguishTime = 0;

void loop() {
  if (extinguishTime == 0) {
    // candle is burning normally: random brightness to neon
    brightness = random(180,255);
  }
  else {
    // candle extinguished!
    brightness = 0;

    // if it's been more than 2 seconds, light up again
    if (millis() - extinguishTime > 2000) extinguishTime = 0;
  }

  analogWrite(neon, brightness);    

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

  if (peakToPeak > 950) {
    extinguishTime = millis();
  }
}

