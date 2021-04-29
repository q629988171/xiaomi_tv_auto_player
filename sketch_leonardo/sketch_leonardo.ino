#include <Keyboard.h>

int i = 0;

void setup() {
  Serial.begin(9600);
  //start keyboard communication
  Keyboard.begin();
  for(i = 1; i <= 4; i++) {
    delay(1000*30);
  }
  //send a keystroke
  sendKeyStroke(KEY_DOWN_ARROW);
  delay(2000);
  sendKeyStroke(KEY_RETURN);
  //end keyboard communication
  Keyboard.end();
}

void loop() {
  //do nothing
}

void sendKeyStroke(byte keyStroke){
  Keyboard.press(keyStroke);
  delay(100);
  Keyboard.release(keyStroke);
}
