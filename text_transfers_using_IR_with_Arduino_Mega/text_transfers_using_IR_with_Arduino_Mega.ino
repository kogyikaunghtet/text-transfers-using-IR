#include <IRremote.h>
#include <PS2Keyboard.h>
#include <LiquidCrystal_I2C.h>
#define I2C_ADDR 0x27
#define BACKLIGHT_PIN 3
#define En_pin 2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7
char getting;
char show;
LiquidCrystal_I2C  lcd(I2C_ADDR, En_pin, Rw_pin, Rs_pin, D4_pin, D5_pin, D6_pin, D7_pin);
const int DataPin = 18;
const int IRQpin =  19;
PS2Keyboard keyboard;
IRsend irsend;
int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;
char c;
String data;
int col = 0, row = 0;
void setup() {
  lcd.begin (20, 4);
  lcd.setBacklightPin(BACKLIGHT_PIN, NEGATIVE);
  lcd.setBacklight(LOW);
  keyboard.begin(DataPin, IRQpin, PS2Keymap_US);
  Serial.begin(9600);
  irrecv.enableIRIn();
}
void loop() {
  if (keyboard.available()>0){
    delay (1);
    c = keyboard.read();
    irsend.sendSony(c,12);
  }
    if (irrecv.decode(&results)) {
      char getting = results.value;
      Serial.println(getting);
      if (results.value == 13) {
        delay (200);
        lcd.clear();
        col = 0;
        row = 0;
      }
      if (results.value == 97) {
        show = 'a';
      }
      if (results.value == 98) {
        show = 'b';
      }
      if (results.value == 99) {
        show = 'c';
      }
      if (results.value == 100) {
        show = 'd';
      }
      if (results.value == 101) {
        show = 'e';
      }
      if (results.value == 102) {
        show = 'f';
      }
      if (results.value == 103) {
        show = 'g';
      }
      if (results.value == 104) {
        show = 'h';
      }
      if (results.value == 105) {
        show = 'i';
      }
      if (results.value == 106) {
        show = 'j';
      }
      if (results.value == 107) {
        show = 'k';
      }
      if (results.value == 108) {
        show = 'l';
      }
      if (results.value == 109) {
        show = 'm';
      }
      if (results.value == 110) {
        show = 'n';
      }
      if (results.value == 111) {
        show = 'o';
      }
      if (results.value == 112) {
        show = 'p';
      }
      if (results.value == 113) {
        show = 'q';
      }
      if (results.value == 114) {
        show = 'r';
      }
      if (results.value == 115) {
        show = 's';
      }
      if (results.value == 116) {
        show = 't';
      }
      if (results.value == 117) {
        show = 'u';
      }
      if (results.value == 118) {
        show = 'v';
      }
      if (results.value == 119) {
        show = 'w';
      }
      if (results.value == 120) {
        show = 'x';
      }
      if (results.value == 121) {
        show = 'y';
      }
      if (results.value == 122) {
        show = 'z';
      }
      if (results.value == 65) {
        show = 'A';
      }
      if (results.value == 66) {
        show = 'B';
      }
      if (results.value == 67) {
        show = 'C';
      }
      if (results.value == 68) {
        show = 'D';
      }
      if (results.value == 69) {
        show = 'E';
      }
      if (results.value == 70) {
        show = 'F';
      }
      if (results.value == 71) {
        show = 'G';
      }
      if (results.value == 72) {
        show = 'H';
      }
      if (results.value == 73) {
        show = 'I';
      }
      if (results.value == 74) {
        show = 'J';
      }
      if (results.value == 75) {
        show = 'K';
      }
      if (results.value == 76) {
        show = 'L';
      }
      if (results.value == 77) {
        show = 'M';
      }
      if (results.value == 78) {
        show = 'N';
      }
      if (results.value == 79) {
        show = 'O';
      }
      if (results.value == 80) {
        show = 'P';
      }
      if (results.value == 81) {
        show = 'Q';
      }
      if (results.value == 82) {
        show = 'R';
      }
      if (results.value == 83) {
        show = 'S';
      }
      if (results.value == 84) {
        show = 'T';
      }
      if (results.value == 85) {
        show = 'U';
      }
      if (results.value == 86) {
        show = 'V';
      }
      if (results.value == 87) {
        show = 'W';
      }
      if (results.value == 88) {
        show = 'X';
      }
      if (results.value == 89) {
        show = 'Y';
      }
      if (results.value == 90) {
        show = 'Z';
      }
      if (results.value == 63) {
        show = '?';
      }
      if (results.value == 33) {
        show = '!';
      }
      if (results.value == 64) {
        show = '@';
      }
      if (results.value == 35) {
        show = '#';
      }
      if (results.value == 36) {
        show = '$';
      }
      if (results.value == 37) {
        show = '%';
      }
      if (results.value == 94) {
        show = '^';
      }
      if (results.value == 38) {
        show = '&';
      }
      if (results.value == 42) {
        show = '*';
      }
      if (results.value == 40) {
        show = '(';
      }
      if (results.value == 41) {
        show = ')';
      }
      if (results.value == 46) {
        show = '.';
      }
      if (results.value == 48) {
        show = '0';
      }
      if (results.value == 49) {
        show = '1';
      }
      if (results.value == 50) {
        show = '2';
      }
      if (results.value == 51) {
        show = '3';
      }
      if (results.value == 52) {
        show = '4';
      }
      if (results.value == 53) {
        show = '5';
      }
      if (results.value == 54) {
        show = '6';
      }
      if (results.value == 55) {
        show = '7';
      }
      if (results.value == 56) {
        show = '8';
      }
      if (results.value == 57) {
        show = '9';
      }
      if (results.value == 32) {
        show = ' ';
      }
      lcd.setCursor (col, row);
      lcd.print (show);
      col++;
      if (row == 3 && col == 20) {
        lcd.clear();
        row = 0;
        col = 0;
      }
      if (col == 20) {
        row ++;
        col = 0;
      }
      irrecv.resume();
    }
    delay(100);
}
