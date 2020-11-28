#include <Servo.h>
#include <Arduino.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo gripper;



int servo1_pos = 100;
int servo2_pos = 50;
int servo3_pos = 50;
int gripper_pos = 90;


bool move_servo1_positive = true;
bool move_servo2_positive = true;
bool move_servo3_positive = true;
bool move_gripper_poitive = true;

void goHome()
{
  servo1.write(100);
  servo2.write(50);
  servo3.write(50);
  gripper.write(90);
}

//--------------------------------------------------------------------------------------------------------------------------------------
/*the moveToPosition method is a method to move the Servos smooth to the new positions
  after a movement the value of the servo is saved in the variable servo[number]_pos (f.e. servo1_pos)
*/
void moveToPosition(int servo1_value, int servo2_value, int servo3_value, int gripper_value, int speed)
{
  if(servo1_value>servo1_pos)             //if the movement of the first servo is poitive
  {
    for(int i = servo1_pos; i<=servo1_value; i++)
    {
      servo1.write(i);
      servo1_pos = i;
      delay(7);
    }
  }
  else
  {
    for(int i = servo1_pos; i>=servo1_value; i--)
    {
      servo1.write(i);
      servo1_pos = i;
      delay(7);
    }
  }
  if (servo2_value>servo2_pos) {
    for (int i = servo2_pos; i<=servo2_value; i++) {
      servo2.write(i);
      servo2_pos = i;
      delay(speed);
    }
  }
  else
  {
    for(int i = servo2_pos; i>=servo2_value; i--)
    {
      servo2.write(i);
      servo2_pos = i;
      delay(speed);
    }
  }
  if (servo3_value>servo3_pos) {
    for (int i = servo3_pos; i<=servo3_value; i++) {
      servo3.write(i);
      servo3_pos = i;
      delay(speed);
    }
  }
  else
  {
    for(int i = servo3_pos; i>=servo3_value; i--)
    {
      servo3.write(i);
      servo3_pos = i;
      delay(speed);
    }
  }
  delay(120);
gripper.write(gripper_value);
delay(120);


}

void take()
{
  moveToPosition(100, 100, 90, 120, 5);
  moveToPosition(100,100, 45, 120, 5);
  moveToPosition(100, 170, 45, 5, 5);
  moveToPosition(105, 100, 90, 5, 5);
}
void greenMovement()
{
  moveToPosition(8, 180, 50, 90, 5);
  moveToPosition(8, 90, 90, 90, 5);
  moveToPosition(100, 50, 50, 90, 5);

}

void redMovement()
{
  moveToPosition(60, 180, 50, 90, 5);
  moveToPosition(60, 90, 90, 90, 5);
  moveToPosition(100, 50, 50, 90, 5);
}
void blueMovement()
{
  moveToPosition(135, 180, 50, 90, 5);
  moveToPosition(135, 90, 90, 90, 5);
  moveToPosition(100, 50, 50, 90, 5);
}
void yellowMovement()
{
  moveToPosition(180, 180, 50, 90, 5);
  moveToPosition(180, 90, 90, 90, 5);
  moveToPosition(100, 50, 50, 90, 5);
}
