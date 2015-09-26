// neon candle

// neon transformer on digital pin 11~
const int neon = 11;

void setup() {
  pinMode(neon, OUTPUT);
}

void loop() {
  int brightness = random(180,255);

  analogWrite(neon, brightness);

  int pause = random(10,50);
  delay(pause);
}

