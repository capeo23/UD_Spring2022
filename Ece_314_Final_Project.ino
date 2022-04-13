//Standard PWM DC control
int E1 = 5;     //M1 Speed Control
int E2 = 6;     //M2 Speed Control
int M1 = 4;    //M1 Direction Control
int M2 = 7;    //M1 Direction Control

///For previous Romeo, please use these pins.
//int E1 = 6;     //M1 Speed Control
//int E2 = 9;     //M2 Speed Control
//int M1 = 7;    //M1 Direction Control
//int M2 = 8;    //M1 Direction Control
int turnSpeed = 200;

void stop(void)                    //Stop
{
  digitalWrite(E1, LOW);
  digitalWrite(E2, LOW);
}
void advance(char a, char b)         //Move forward
{
  analogWrite (E1, a);     //PWM Speed Control
  digitalWrite(M1, HIGH);
  analogWrite (E2, b);
  digitalWrite(M2, HIGH);
}
void back_off (char a, char b)         //Move backward
{
  analogWrite (E1, a);
  digitalWrite(M1, LOW);
  analogWrite (E2, b);
  digitalWrite(M2, LOW);
}
void turn_L (char a, char b)            //Turn Left
{
  analogWrite (E1, a);
  digitalWrite(M1, LOW);
  analogWrite (E2, b);
  digitalWrite(M2, HIGH);
}
void turn_R (char a, char b)            //Turn Right
{
  analogWrite (E1, a);
  digitalWrite(M1, HIGH);
  analogWrite (E2, b);
  digitalWrite(M2, LOW);
}
void setup(void)
{
  int i;
  for (i = 4; i <= 7; i++)
    pinMode(i, OUTPUT);
  Serial.begin(115200);      //Set Baud Rate
  Serial.println("Run bluethooth control");
}
void loop(void)
{
  if (Serial.available()) {
    char val = Serial.read();
    if (val != -1)
    {
      switch (val)
      {
        case 'a'://Move Forward
          advance (255, 255);  //move forward in max speed
          Serial.println("Move Fowrard");
          break;
        case 'c'://Move Backward
          Serial.println("Move Backward");
          back_off (255, 255);  //move back in max speed
          break;
        case 'd'://Turn Left
          Serial.println("Turn Left");
          turn_L (turnSpeed, turnSpeed);
          break;
        case 'b'://Turn Right
          Serial.println("Turn Right");
          turn_R (turnSpeed, turnSpeed);
          break;
        case 'e':
          Serial.println("Stop");
          stop();
          break;

          case 'A'://Move Forward
          advance (255, 255);  //move forward in max speed
          Serial.println("Move Fowrard");
          break;
        case 'C'://Move Backward
          Serial.println("Move Backward");
          back_off (255, 255);  //move back in max speed
          break;
        case 'D'://Turn Left
          Serial.println("Turn Left");
          turn_L (turnSpeed, turnSpeed);
          break;
        case 'B'://Turn Right
          Serial.println("Turn Right");
          turn_R (turnSpeed, turnSpeed);
          break;
        case 'E':
          Serial.println("Stop");
          stop();
          break;
      }
    }
    else stop();
  }
}
