/**
 * @Author: Allen
 * @Description: 小米电视开机自动播放历史视频
 * @File: msketch_feb21b.ino
 * @Version: 1.0.3
 * @Date: 2021/4/28 16:21
 */


#include "DigiKeyboard.h"

#define KEY_ARROW_DOWN 0x51


void setup() {
  // Notice the L
  unsigned long seconds = 1000L;
  unsigned long minutes = seconds * 60;
  /**
   * When the HIDIOT first starts, it sometimes misses the first key press. 
   * Using DigiKeyboard.sendKeyStroke(0) makes it send a key stroke that the computer won’t print.
   */
  DigiKeyboard.sendKeyStroke(0);
  
  // 等开机广告(一分钟)
  delay(minutes);
  // 按向下键和确认键(中间隔1秒)
  keyDownEnter(1000);
  
  // 等切换画面(一分钟)
  delay(minutes);
  // 按向下键和确认键(中间隔1秒)
  keyDownEnter(1000);
  
  // 等待响应(1分钟)
  delay(minutes);
  // 按播放键
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
 * @Description: 按向下键, 延迟指定时间（以毫秒为单位）, 最后按确认键。
 * @param ms: the number of milliseconds to pause. Allowed data types: unsigned long.
 * @return none
 */
void keyDownEnter(unsigned long ms){
  keyPressed(KEY_ARROW_DOWN);
  delay(ms);
  keyPressed(KEY_ENTER);
}
