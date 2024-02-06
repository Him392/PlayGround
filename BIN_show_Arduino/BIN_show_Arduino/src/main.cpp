#include <Arduino.h>

int seg_pin_a = 5;
int seg_pin_b = 6;
int seg_pin_c = 7;
int seg_pin_d = 2;
int seg_pin_e = 3;
int seg_pin_f = 4;
int seg_pin_g = 8;

void show_num(int num);
void show_bin(int decimal);

void setup() {
  Serial.begin(9600);
}

void loop() {
  while (!Serial.available()) {}
  int num = Serial.read()-48;//ASCII码转数字
  if (num < 0 || num > 9) {
    Serial.println("ERROR");
    return;
  }
  Serial.println(num);
  show_num(num);
  delay(500);
  show_num(-1);
  delay(50);
  show_bin(num);
  show_num(num);
  delay(500);
  show_num(-1);
}
void show_num(int num){
  switch (num)
  {
  case -1:
    digitalWrite(seg_pin_a, LOW);
    digitalWrite(seg_pin_b, LOW);
    digitalWrite(seg_pin_c, LOW);
    digitalWrite(seg_pin_d, LOW);
    digitalWrite(seg_pin_e, LOW);
    digitalWrite(seg_pin_f, LOW);
    digitalWrite(seg_pin_g, LOW);
    break;
  case 0:
    digitalWrite(seg_pin_a, HIGH);
    digitalWrite(seg_pin_b, HIGH);
    digitalWrite(seg_pin_c, HIGH);
    digitalWrite(seg_pin_d, HIGH);
    digitalWrite(seg_pin_e, HIGH);
    digitalWrite(seg_pin_f, HIGH);
    digitalWrite(seg_pin_g, LOW);
    break;
  case 1:
    digitalWrite(seg_pin_a, LOW);
    digitalWrite(seg_pin_b, HIGH);
    digitalWrite(seg_pin_c, HIGH);
    digitalWrite(seg_pin_d, LOW);
    digitalWrite(seg_pin_e, LOW);
    digitalWrite(seg_pin_f, LOW);
    digitalWrite(seg_pin_g, LOW);
    break;
  case 2:
    digitalWrite(seg_pin_a, HIGH);
    digitalWrite(seg_pin_b, HIGH);
    digitalWrite(seg_pin_c, LOW);
    digitalWrite(seg_pin_d, HIGH);
    digitalWrite(seg_pin_e, HIGH);
    digitalWrite(seg_pin_f, LOW);
    digitalWrite(seg_pin_g, HIGH);
    break;
  case 3:
    digitalWrite(seg_pin_a, HIGH);
    digitalWrite(seg_pin_b, HIGH);
    digitalWrite(seg_pin_c, HIGH);
    digitalWrite(seg_pin_d, HIGH);
    digitalWrite(seg_pin_e, LOW);
    digitalWrite(seg_pin_f, LOW);
    digitalWrite(seg_pin_g, HIGH);
    break;
  case 4:
    digitalWrite(seg_pin_a, LOW);
    digitalWrite(seg_pin_b, HIGH);
    digitalWrite(seg_pin_c, HIGH);
    digitalWrite(seg_pin_d, LOW);
    digitalWrite(seg_pin_e, LOW);
    digitalWrite(seg_pin_f, HIGH);
    digitalWrite(seg_pin_g, HIGH);
    break;
  case 5:
    digitalWrite(seg_pin_a, HIGH);
    digitalWrite(seg_pin_b, LOW);
    digitalWrite(seg_pin_c, HIGH);
    digitalWrite(seg_pin_d, HIGH);
    digitalWrite(seg_pin_e, LOW);
    digitalWrite(seg_pin_f, HIGH);
    digitalWrite(seg_pin_g, HIGH);
    break;
  case 6:
    digitalWrite(seg_pin_a, HIGH);
    digitalWrite(seg_pin_b, LOW);
    digitalWrite(seg_pin_c, HIGH);
    digitalWrite(seg_pin_d, HIGH);
    digitalWrite(seg_pin_e, HIGH);
    digitalWrite(seg_pin_f, HIGH);
    digitalWrite(seg_pin_g, HIGH);
    break;
  case 7:
    digitalWrite(seg_pin_a, HIGH);
    digitalWrite(seg_pin_b, HIGH);
    digitalWrite(seg_pin_c, HIGH);
    digitalWrite(seg_pin_d, LOW);
    digitalWrite(seg_pin_e, LOW);
    digitalWrite(seg_pin_f, LOW);
    digitalWrite(seg_pin_g, LOW);
    break;
  case 8:
    digitalWrite(seg_pin_a, HIGH);
    digitalWrite(seg_pin_b, HIGH);
    digitalWrite(seg_pin_c, HIGH);
    digitalWrite(seg_pin_d, HIGH);
    digitalWrite(seg_pin_e, HIGH);
    digitalWrite(seg_pin_f, HIGH);
    digitalWrite(seg_pin_g, HIGH);
    break;
  case 9:
    digitalWrite(seg_pin_a, HIGH);
    digitalWrite(seg_pin_b, HIGH);
    digitalWrite(seg_pin_c, HIGH);
    digitalWrite(seg_pin_d, HIGH);
    digitalWrite(seg_pin_e, LOW);
    digitalWrite(seg_pin_f, HIGH);
    digitalWrite(seg_pin_g, HIGH);
    break;
  }
}
void show_bin(int decimal) {
  int binary[4] = {0,0,0,0}; // 将数组初始化为0
  switch (decimal)
  {
  case 0:
    break;
  case 1:
    binary[0] = 1;
    break;
  case 2:
    binary[1] = 1;
    break;
  case 3:
    binary[0] = 1;
    binary[1] = 1;
    break;
  case 4:
    binary[2] = 1;
    break;
  case 5:
    binary[0] = 1;
    binary[2] = 1;
    break;
  case 6:
    binary[1] = 1;
    binary[2] = 1;
    break;
  case 7:
    binary[0] = 1;
    binary[1] = 1;
    binary[2] = 1;
    break;
  case 8:
    binary[3] = 1;
    break;
  case 9:
    binary[0] = 1;
    binary[3] = 1;
    break;
  default:
    break;
  }

  for (int j = 3; j >= 0; j--) {
    Serial.print(binary[j]);
    show_num(binary[j]);
    delay(500);
    show_num(-1);
    delay(50);
  }
}