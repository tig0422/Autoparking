// 왼쪽 바퀴 - 전후진
const int DIRA = 4;                   // Motor A Direction (A 회전방향)
const int PWMA = 5;                  // Motor A PWM (A 속도)

// 오른쪽 바퀴 - 전후진

const int DIRB = 7;                   // Motor B Direction  (B 회전방향)
const int PWMB = 6;                  // Motor B PWM (B 속도)


void go_forward(int l, int r) {
  // 전진
  // 왼쪽 전진
  digitalWrite(DIRA, HIGH);  
  analogWrite(PWMA, l);
  // 오른쪽 전진
  digitalWrite(DIRB, HIGH);  
  analogWrite(PWMB, r);

  
  
}
//ex) go_forward(100,100,2000) 이면 2초 전진.
//ex) go_forward(80,200,2000) 이면 2초 좌회전.

void go_backward(int l, int r) {
  // 전진
  // 왼쪽 후진
  digitalWrite(DIRA, LOW);  
  analogWrite(PWMA, l);
  // 오른쪽 후진
  digitalWrite(DIRB, LOW);  
  analogWrite(PWMB, r);

   
  
}
//ex) go_backward(100,100,2000) 이면 2초 후진.


void stop(int t){
    // 정지
  // 왼쪽 정지
  digitalWrite(DIRA, LOW); 
  analogWrite(PWMA, 0);
  // 오른쪽 정지
  digitalWrite(DIRB, LOW); 
  analogWrite(PWMB, 0);
  
  delay(t);
}
// stop(2000) 이면 2초 정지.

  
