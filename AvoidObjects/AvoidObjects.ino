#include <Servo.h>
#include "motor.h"
#include "sonar.h"

Servo neck;

const int left_ang = 168;
const int front_ang = 98;
const int right_ang = 28;

const int time_90 = 390;
const int time_180 = 750;
const int time_10cm =220;

void setup() {
  //Инициализируем дальномер Trig = 13, Echo = 12.
  Sonar_init(13,12);
  //Инициализируем сервомотор,управление портом номер 9
  neck.attach(14);
  //На данный момент у меня микроконтроллер не подключен к устройству
  setup_motor_system(2, 3 ,4 ,5)
  _stop();
}

void loop() {
  


}
