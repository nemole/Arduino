// must connect leds to pins 3, 5, 6, 9, 10, 11 in that order

const int ledPins[] = {3, 5, 6, 9, 10, 11};

const int period = 500;

int value;
int currPin = 0;
long timer = 0;
int direct = 1;
int check = 0;

void setup() {
  for (int i = 0; i < sizeof(ledPins); i++) {
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  timer = millis();
  value = 128 + 127 * cos(2 * PI / period * timer);
  Serial.print("vlaue: ");
  Serial.println(value);
  analogWrite(ledPins[currPin], value);
  if (value > 250) {
    check = 1;
  }
  Serial.println(currPin);
  if (value < 2 && check) {
    analogWrite(ledPins[currPin], 0);
    currPin += direct;
    if (currPin == 0 || currPin == 5) {
      direct = direct * -1;
    }
    check = 0;
  }
  
}
