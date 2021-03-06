#include <Streaming.h> // SEQUOIA added, necessary for...something
#include <IRDuino.h>

#define IR_VOL_DOWN           0xF8
#define IR_VOL_UP             0x78
#define IR_VOL_MUTE           0x38
#define IR_VOL_REPEAT         0xF0

#define IR_FUNCTION_MINUS     0xDA
#define IR_FUNCTION_BACK      0x3E
#define IR_FUNCTION_PLUS      0x5A
#define IR_FUNCTION_FORWARD   0xDE

#define IR_DISPLAY            0x20
#define IR_HUNDRED_PLUS       0xEE


byte last_vol_key;

void setup()
{
//    Serial.begin(115200);
//    while(!Serial);

    iRduino.begin();
    iRduino.addItem(IR_VOL_DOWN,     vol_down);
    iRduino.addItem(IR_VOL_UP,       vol_up);
    iRduino.addItem(IR_VOL_REPEAT,   vol_repeat);
    iRduino.addItem(IR_VOL_MUTE,     vol_mute);
    iRduino.addItem(IR_HUNDRED_PLUS, play_pause);
    iRduino.addItem(IR_FUNCTION_MINUS, arrow_left);
    iRduino.addItem(IR_FUNCTION_BACK, arrow_up);
    iRduino.addItem(IR_FUNCTION_PLUS, arrow_right);
    iRduino.addItem(IR_FUNCTION_FORWARD, arrow_down);
    iRduino.addItem(IR_DISPLAY, f_key);
    
}

void loop()
{
  iRduino.process();
  delay(100);
}

void presstimes(byte key, int times){
  while(times > 0){
    iRduino.keyPressRelease(key);
    times--;
  }
}

int vol_press_times = 4;

void vol_mute(){
  presstimes(KEY_F10, 1);
}

void arrow_left(){
  presstimes(KEY_LEFT_ARROW, 1);
}
void arrow_up(){
  presstimes(KEY_UP_ARROW, 1);
}
void arrow_right(){
  presstimes(KEY_RIGHT_ARROW, 1);
}
void arrow_down(){
  presstimes(KEY_DOWN_ARROW, 1);
}

void f_key(){
  iRduino.printf("f");
}

void vol_up(){
  last_vol_key = KEY_F12;
  presstimes(KEY_F12, vol_press_times);
}
void vol_down(){
  last_vol_key = KEY_F11;
  presstimes(KEY_F11, vol_press_times);
}
void vol_repeat(){
  if(last_vol_key == KEY_F11 || last_vol_key == KEY_F12){
    presstimes(last_vol_key, vol_press_times);
  }
}
void play_pause(){
  iRduino.printf(" ");
}

