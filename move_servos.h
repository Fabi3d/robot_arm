#include <Servo.h>
#include <Arduino.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo gripper;



int servo1_pos = 90;
int servo2_pos = 90;
int servo3_pos = 90;
int gripper_pos = 90;

bool move_servo1_positive = true;
bool move_servo2_positive = true;
bool move_servo3_positive = true;
bool move_gripper_poitive = true;

void goHome()
{
  servo1.write(90);
  servo2.write(90);
  servo3.write(90);
  gripper.write(90);
}

//--------------------------------------------------------------------------------------------------------------------------------------
//the moveToPosition method is a method to move the Servos smooth to the new positions
void moveToPosition(int servo1_value, int servo2_value, int servo3_value, int gripper_value, int speed)
{
  if(servo1_value>servo1_pos)             //if the movement of the first servo is poitive
  {
    for(int i = servo1_pos; i<=servo1_value; i++)
    {
      servo1.write(i);
      servo1_pos = i;
    //  Serial.println(i);
      delay(speed);
    }
  }
  else
  {
    for(int i = servo1_pos; i>=servo1_value; i--)
    {
      servo1.write(i);
      servo1_pos = i;
      //Serial.println(i);
      delay(speed);
    }
  }
  if (servo2_value>servo2_pos) {
    for (int i = servo2_pos; i<=servo1_value; i++) {
      servo2.write(i);
      servo2_pos = i;
    //  Serial.println(i);
      delay(speed);
    }
  }
  else
  {
    for(int i = servo2_pos; i>=servo2_value; i--)
    {
      servo2.write(i);
      servo2_pos = i;
    //  Serial.println(i);
      delay(speed);
    }
  }
}
