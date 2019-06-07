#include "moving.h"
#include "ultrasonic_sensor.h"


const int horn_pin = 17; // A3 부저
void setup() {
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

  //부저 핀
  pinMode(horn_pin, OUTPUT);

  Serial.begin(9600);

  Serial.println("Basic setup complete");
}

void loop() {
  int parking_mode;
  /****************************주차공간 찾기******************************/
  while (side1_sensor() <= 10) { //앞쪽 사이드센서가 일정거리 이하인 동안 전진
    go_forward(80, 80);
  }

  while (side2_sensor() <= 10) { // 뒤쪽 사이드센서가 일정거리 이하인 동안 전진
    go_forward(80, 80);
  }

  float prev_time = millis();//뒤쪽 사이드센서가 주차공간 진입시 시간측정

  while (side2_sensor() > 10) { //앞쪽 사이드센서가 일정거리 이상인동안 전진
    go_forward(80, 80);
  }

  while (side2_sensor() > 10) { //뒤쪽 사이드센서가 일정거리 이상인동안 전진
    go_forward(80, 80);
  }
  float curr_time = millis();//뒤쪽 사이드센서가 주차공간 벗어났을 때 시간측정
  delay(750);
  stop(1000);
  
  float total_time = curr_time - prev_time; //총 걸린시간
  stop(1000);
  while(1)Serial.println(total_time);

  if(total_time > 4000){ //동영상보니까 5~6초는 가던데 일단 4초부터 시작해서 점점 늘려가며 테스트
    parking_mode = 1;
  }else parking_mode = 0;
  
  if(parking_mode == 1){
  /***************************평행주차 시작******************************/
    while (backward_sensor()>24) { //뒤로 우회전 이건 센서켜고 모의주차하면서 센서값을 찍어봐야,,
      go_backward(250, 80);
    }

    stop(1000);
    while(backward_sensor()>5){
      go_backward(80,250);
    }

    /*****************************주차 마무리******************************/
    while (abs(side1_sensor() - side2_sensor()) > 2) { //사이드 센서의 거리차가 일정수치 이상일 동안 반복
      go_forward(200, 80); //앞으로 우회전 조금씩
    }
    stop(1000);
  
    while (abs(forward_sensor() - backward_sensor()) > 2) { // 앞뒤 거리차가 일정이상 동안 반복
      if (forward_sensor() > backward_sensor()) go_forward(80, 80);
      else go_backward(80, 80);
    }
    stop(1000);
    while (1); //loop문 빠져나가는 건 없는 것 같아서 여기서 무한정지
  }//Parking_mode가 1일 때 수행
  else ;//아니면 경고음울리고 다시 주차공간 탐색하러 전진
  stop(1000);

}

void buzz() { //1초 동안 부저를 울리는 함수
  digitalWrite(horn_pin, HIGH);
  delay(1000);
  digitalWrite(horn_pin, LOW);
}
