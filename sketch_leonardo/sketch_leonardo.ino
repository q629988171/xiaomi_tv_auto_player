/**
 * @Author: Allen
 * @Description: 小米电视开机自动播放《萌鸡小队》
 * @File: sketch_leonardo.ino
 * @Version: 1.0.1
 * @Date: 2021/4/28 16:21
 */
 
#include <Keyboard.h>


void setup() {
  Serial.begin(9600);
  //start keyboard communication
  Keyboard.begin();
  for(int i = 1; i <= 4; i++) {
    delay(1000*10);
  }
  //send a keystroke
  sendKeyStroke(KEY_DOWN_ARROW);
  delay(1000);
  sendKeyStroke(KEY_RETURN);
  delay(3000);
  sendKeyStroke(KEY_RETURN);
  delay(5000);
  sendKeyStroke(KEY_RETURN);  
  //end keyboard communication
  Keyboard.end();
}

void loop() {
  //do nothing
}

/**
 * @Description: 按下键盘上的按键
 * @param keyStroke
 * @return none
 */
void sendKeyStroke(byte keyStroke){
  Keyboard.press(keyStroke);
  delay(100);
  Keyboard.release(keyStroke);
}
