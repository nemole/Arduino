
//enter the pins that you are using to connect to leds in the pin list


int pin_list[] = {2,3,4,5,6,7};
int max_num, curr_num, s  = 0;



void setup() {
  s = sizeof(pin_list)/sizeof(int);
  max_num = pow(2, s) - 1;
  for (int i = 0; i < s; i++) {
    pinMode(pin_list[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  Serial.println(curr_num);
  for (int i = 0; i < s; i++) {
    digitalWrite(pin_list[i], getBit(curr_num, i));
  }
  curr_num++;
  if (curr_num > max_num) {
    curr_num = 0;
  }
  delay(250);
}

int getBit(int num, int bit_num) { //rightmost bit is 0th bit
  int out = 0;
  out = bit(bit_num) & num;
  out = bitRead(out, bit_num);
  return out;
}
