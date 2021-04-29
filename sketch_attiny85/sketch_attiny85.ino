#include "DigiKeyboard.h"

#define KEY_ARROW_DOWN 0x51


void setup() {
  /**
   * When the HIDIOT first starts, it sometimes misses the first key press. 
   * Using DigiKeyboard.sendKeyStroke(0) makes it send a key stroke that the computer won’t print.
   */
  DigiKeyboard.sendKeyStroke(0);

  for(int i = 1; i <= 5; i++) {
    delay(1000*30);
  }
  keyPressed(KEY_ARROW_DOWN);
  delay(100);
  keyPressed(KEY_ENTER);
}

void loop() {
  // put your main code here, to run repeatedly:

}
  