#include "moving.h"
#include "ultrasonic_sensor.h"


void setup(){
  // 왼쪽 바퀴 초기화
  pinMode(DIRA, OUTPUT);
  digitalWrite(DIRA, LOW);
  analogWrite(PWMA, 0);

  // 오른쪽 바퀴 초기화
  pinMode(DIRB, OUTPUT);
  digitalWrite(DIRB, LOW);
  analogWrite(PWMB, 0); 

  //초음파센서 핀 설정
  pinMode(forward_trig_pin, OUTPUT);
  pinMode(forward_echo_pin, INPUT);
  pinMode(side_trig_pin1, OUTPUT);
  pinMode(side_echo_pin1, INPUT);
  pinMode(side_trig_pin2, OUTPUT);
  pinMode(side_echo_pin2, INPUT);
  pinMode(backward_trig_pin, OUTPUT);
  pinMode(backward_echo_pin, INPUT);

  Serial.begin(9600);

  Serial.println("Basic setup complete");
}

void loop(){
  /*
  float prev_time=0;
  float curr_time=0;
  int parking_mode;

  
  go_forward(100,100,2000);
  
  if(side1_sensor() > 10){
     prev_time = millis();
     break;
  }
  delay(1000);
  
  if(side2_sensor() < 10){
    curr_time = millis();
    break;
  }
    
  if((curr_time-prev_time)*10 > 적정주차공간){//앞으로 움직인 시간 * 초속 10cm 로 거리측정
    parking_mode = 1;
  }

 */     
  go_forward(80,80);//직진
  delay(1000);
  stop(1000);
  go_backward(200,80);//뒤로 우회전
  delay(1000);
  stop(1000);
  go_backward(80,200);//뒤로 좌회전
  delay(1000);
  stop(1000);
  while(abs(side1_sensor() - side2_sensor()) > 1){ //사이드 센서의 거리차가 일정수치 이상일 동안 반복 
    go_forward(80,200);//앞으로 우회전 조금씩            
  }
  delay(1000);
  stop(1000);
  while(abs(forward_sensor() - backward_sensor()) > 1){ // 앞뒤 거리차가 일정이상 동안 반복
    if(forward_sensor() > backward_sensor()) go_forward(80,80);
    else go_backward(80,80);
  }
  
  while(1);//loop문 빠져나가는 건 없는 것 같아서 여기서 무한정지  
  
}
