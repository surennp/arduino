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
  _stop();
  int Dist_left, Dist_right, Dist_front;
  //Для поворота части тела на какую-то сторону используем инициализированную часть тела в нашем случае шею(neck) и поворачиваем направо--
  neck.write(left_ang);
  delay(150);
  //Записываем расстояние до препятствия слева.
  Dist_left = Sonar(400);
  neck.write(front_ang);
  delay(150);
  Dist_front = Sonar(400);
  neck.write(right_ang);
  delay(150);
  Dist_right = Sonar(400);
  neck.write(left_ang);
  if((Dist_left> Dist_front) && (Dist_left > Dist_right))
  {
    left();//поворот длится 5 секунд
    delay(time_90)
    if(Dist_left >10)
    {
      forward();
      delay(time_10cm)
    }
  }
  else
  {
    if( Dist_right> Dist_front)
    {
      right();
      delay(time_90);
      if(Dist_right >10)
      {
        forward();
        delay(time_10cm);
      }
    }
  }
  else
  {
    if(Dist_front > 10)
    {
      forward();
      delay(time_10cm);
    }
    else{
      right();
      delay(time_180);
    }
  }

}
