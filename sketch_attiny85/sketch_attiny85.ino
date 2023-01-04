/**
 * @Author: Allen
 * @Description: 小米电视开机自动播放历史视频
 * @File: msketch_feb21b.ino
 * @Version: 1.0.4
 * @Date: 2023/01/03 14:14
 */


#include "DigiKeyboard.h"

#define KEY_ARROW_DOWN 0x51
#define KEY_ESCAPE 0x29


void setup() {
  // Notice the L
  unsigned long seconds = 1000L;
  unsigned long minutes = seconds * 60;
  /**
   * When the HIDIOT first starts, it sometimes misses the first key press. 
   * Using DigiKeyboard.sendKeyStroke(0) makes it send a key stroke that the computer won’t print.
   */
  DigiKeyboard.sendKeyStroke(0);
  
  // 等开机广告(两分钟)
  DigiKeyboard.delay(minutes);
  DigiKeyboard.delay(minutes);

  // ALT+ESC（返回主页并等6秒）
  DigiKeyboard.sendKeyStroke(KEY_ESCAPE, MOD_ALT_LEFT);
  DigiKeyboard.delay(6000);
  
  // 按向下键和确认键(按继续观看3秒后回车)
  DigiKeyboard.sendKeyStroke(KEY_ARROW_DOWN);
  DigiKeyboard.delay(3000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  // 回车(等待9秒后从历史记录中选择首个)
  DigiKeyboard.delay(9000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  
  // 回车(等待12秒后切换当前视频窗口并播放)
  DigiKeyboard.delay(12000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

void loop() {
  // put your main code here, to run repeatedly:

}
