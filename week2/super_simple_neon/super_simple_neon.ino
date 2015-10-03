
const int NEON1 = 11;  // transformer 1 is on pin 11
const int NEON2 = 5;   // transformer 2 is on pin 5

int brightness1 = 0;  // brightness of neon 1 
int upOrDown1 = +1; // +1 means go up in brightness, and -1 means go down


void setup() {
  // put your setup code here, to run once:

  // both these pins should be outputs
  pinMode(NEON1, OUTPUT);
  pinMode(NEON2, OUTPUT);

  // turn both outputs on
  digitalWrite(NEON1, 1);   // 1 means on and 0 means off
  digitalWrite(NEON2, HIGH); // HIGH means on (SAME AS 1) and LOW means off
}

void loop() {
  analogWrite(NEON1, brightness1);

  brightness1 = brightness1 + upOrDown1;

  if (brightness1 > 255) {
    brightness1 = 255;
    upOrDown1 = -1;
  }
  if (brightness1 < 0) {
    brightness1 = 0;
    upOrDown1 = +1;   // +1 and 1 are the same thing
  }

  if (upOrDown1 == +1) {
    digitalWrite(NEON2, 1);
  }
  else {
    digitalWrite(NEON2, 0);
  }

  

  delay(5);
}
