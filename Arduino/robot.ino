#include<Servo.h>
#include<NewPing.h>


    // Setup for the ultrasonic sensor.
#define trigger A0
#define echo A1

NewPing sensor(trigger,echo,400);

    // Setting the base positions for all the motors.
Servo servo1;
int bp1=130;

Servo servo2;
int bp2=60;

Servo servo3;
int bp3=100;

Servo servo4;
int bp4=105;

Servo servo5;
int bp5=65;

Servo servo6;
int bp6=105;

Servo servo7;
int bp7=70;

Servo servo8;
int bp8=90;

Servo servo9;
int bp9=85;

Servo servo10;
int bp10=105;

Servo servo11;
int bp11=90;

Servo servo12;
int bp12=60;

    // On running setup the robot comes to its standard or base position.
void setup() {
  // For ultrasonic sensor
  Serial.begin(9600);
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);

  servo1.attach(1);
  servo2.attach(2);
  servo3.attach(3);
  servo4.attach(4);
  servo5.attach(5);
  servo6.attach(6);
  servo7.attach(7);
  servo8.attach(8);
  servo9.attach(9);
  servo10.attach(10);
  servo11.attach(11);
  servo12.attach(12);

  servo1.write(bp1);
  servo2.write(bp2);
  servo3.write(bp3);
  servo4.write(bp4);
  servo5.write(bp5);
  servo6.write(bp6);
  servo7.write(bp7);
  servo8.write(bp8);
  servo9.write(bp9);
  servo10.write(bp10);
  servo11.write(bp11);
  servo12.write(bp12);
  
}

    // Function whic brings the robot to it's base position
void base_pos(){
  servo1.write(bp1);
  servo2.write(bp2);
  servo3.write(bp3);
  servo4.write(bp4);
  servo5.write(bp5);
  servo6.write(bp6);
  servo7.write(bp7);
  servo8.write(bp8);
  servo9.write(bp9);
  servo10.write(bp10);
  servo11.write(bp11);
  servo12.write(bp12);
  }

    // Function which holds the up servos still
 void stay_still(){
  servo1.write(bp1);
  servo2.write(bp2);
  servo3.write(bp3);
  servo4.write(bp4);
  servo5.write(bp5);
  servo6.write(bp6);
  }

    // Function for one cycle of walking
void walk(){
  int angle = 50;
  int time_delay = 8;

  for(int i=5;i>=0;i--){
      stay_still();
      servo7.write(bp7+i);
      servo9.write(bp9-i);
      servo11.write(bp11+i);
      servo8.write(bp8+i);
      servo10.write(bp10+i);
      servo12.write(bp12-i);
      delay(time_delay);
      }

  for(int i=5;i<angle;i++){
    stay_still();
    servo8.write(bp8-i);
    servo10.write(bp10-i);
    servo12.write(bp12+i);  
    delay(time_delay);
  }

  for(int i=angle;i>=5;i--){
    stay_still();
    servo8.write(bp8-i);
    servo10.write(bp10-i);
    servo12.write(bp12+i);  
    delay(time_delay);
  }

  for(int i=5;i>=0;i--){
      stay_still();
      servo8.write(bp8-i);
      servo10.write(bp10-i);
      servo12.write(bp12+i);
      servo7.write(bp7-i);
      servo9.write(bp9+i);
      servo11.write(bp11-i);
      delay(time_delay);
    }

  for(int i=5;i<angle;i++){
    stay_still();
    servo7.write(bp7+i);
    servo9.write(bp9-i);
    servo11.write(bp11+i);
    delay(time_delay);
  }

  for(int i=angle;i>=5;i--){
    stay_still();
    servo7.write(bp7+i);
    servo9.write(bp9-i);
    servo11.write(bp11+i);
    delay(time_delay);
  }
}

    // Function to bend the robot towards right for dance.
void bend_right(){
   int angle = 30;
   int time_delay = 8;  
   for(int i=0;i<angle;i++){
    stay_still();
    servo8.write(bp8+i);
    servo10.write(bp10+i);
    servo12.write(bp12+i);  
    delay(time_delay);
  }

  for(int i=0;i<angle;i++){
    stay_still();
    servo8.write(bp8+angle);
    servo10.write(bp10+angle);
    servo12.write(bp12+angle);
    servo7.write(bp7+i);
    servo9.write(bp9+i);
    servo11.write(bp11+i);
    delay(time_delay);
  }

  for(int i=angle;i>=0;i--){
    stay_still();
    servo7.write(bp7+i);
    servo9.write(bp9+i);
    servo11.write(bp11+i);
    servo8.write(bp8+i);
    servo10.write(bp10+i);
    servo12.write(bp12+i);  
    delay(time_delay);
  }

  base_pos();
}

    // Function to bend the robot towards left for dance.
void bend_left(){
  int angle = 30;
   int time_delay = 8;  
   for(int i=0;i<angle;i++){
    stay_still();
    servo8.write(bp8-i);
    servo10.write(bp10-i);
    servo12.write(bp12-i);  
    delay(time_delay);
  }

  for(int i=0;i<angle;i++){
    stay_still();
    servo8.write(bp8-angle);
    servo10.write(bp10-angle);
    servo12.write(bp12-angle);
    servo7.write(bp7-i);
    servo9.write(bp9-i);
    servo11.write(bp11-i);
    delay(time_delay);
  }

  for(int i=angle;i>=0;i--){
    stay_still();
    servo7.write(bp7-i);
    servo9.write(bp9-i);
    servo11.write(bp11-i);
    servo8.write(bp8-i);
    servo10.write(bp10-i);
    servo12.write(bp12-i);  
    delay(time_delay);
  }

  base_pos();

}

    // Function for making the robot dance N times.
void dance(int N){
  for(int i=0;i<N;i++){
      bend_right();
      bend_left();
    }
  
}

    // Function which turns the robot left.
void turn_left(){

  int angle = 50;
  int time_delay = 8;

  for(int i=0;i<angle;i++){
    stay_still();
    servo8.write(bp8-i);
    servo10.write(bp10-i);
    servo12.write(bp12-i);  
    delay(time_delay);
  }

  for(int i=angle;i>=0;i--){
    stay_still();
    servo8.write(bp8-i);
    servo10.write(bp10-i);
    servo12.write(bp12-i);  
    delay(time_delay);
  }

  for(int i=0;i<angle;i++){
    stay_still();
    servo7.write(bp7-i);
    servo9.write(bp9-i);
    servo11.write(bp11-i);
    delay(time_delay);
  }

  for(int i=angle;i>=0;i--){
    stay_still();
    servo7.write(bp7-i);
    servo9.write(bp9-i);
    servo11.write(bp11-i);
    delay(time_delay);
  }

}

		// Function which returns the distance of the object from the robot.
float CheckDistance(){
  float duration,distance;
  duration = sensor.ping();
  distance = (duration / 2) * 0.0343;
  return distance;
}

	// The main body of the program.
		// If the obstacle is at a distance gretaer	than 20 then walk.
		// If not check if the obstacle is less than 5cm. If so then dance.
		// Else turn until there is no obstacle in the front.

void loop() {
  float dist = CheckDistance();

  if (dist > 20)
    walk();

  else{
    if (dist < 5)
      dance(3);

     else{
      turn_left();
      turn_left();   
     }
    } 
}