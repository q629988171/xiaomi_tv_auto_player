/**
 * @Author: Allen
 * @Description: 小米电视开机自动播放《萌鸡小队》
 * @File: msketch_feb21b.ino
 * @Version: 1.0.1
 * @Date: 2021/4/28 16:21
 */


#include "DigiKeyboard.h"

#define KEY_ARROW_DOWN 0x51


void setup() {
  /**
   * When the HIDIOT first starts, it sometimes misses the first key press. 
   * Using DigiKeyboard.sendKeyStroke(0) makes it send a key stroke that the computer won’t print.
   */
  DigiKeyboard.sendKeyStroke(0);

  sleep(1);
  
  keyPressed(KEY_ARROW_DOWN);
  delay(1000);
  keyPressed(KEY_ENTER);
  
  delay(9000);
  keyPressed(KEY_ENTER);
  
  sleep(1);
  keyPressed(KEY_ENTER);
}

void loop() {
  // put your main code here, to run repeatedly:

}

/**
 * @Description: 按下键盘上的按键
 * @param keyStroke
 * @return none
 */
void keyPressed(byte keyStroke){
  DigiKeyboard.sendKeyStroke(keyStroke);
  delay(100);
  // called whenever a pressed key is released on a connected USB keyboard.
  DigiKeyboard.sendKeyStroke(0);
}


/**
 * @Description: 暂停程序指定为参数的时间量（以分钟为单位）。
 * @param m: the number of minutes to pause. Allowed data types: unsigned long.
 * @return none
 */
void sleep(unsigned long m){
  for(int i = 1; i <= 6 * m; i++) {
    delay(1000*10);
  }
}
