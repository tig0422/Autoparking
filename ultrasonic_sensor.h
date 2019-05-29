const int forward_trig_pin = 11;
const int forward_echo_pin = 12;

const int side_trig_pin1 = 3;
const int side_echo_pin1 = 2;

const int side_trig_pin2 = 9;
const int side_echo_pin2 = 8;

const int backward_trig_pin = 10;
const int backward_echo_pin = 13;



long forward_sensor(){
  digitalWrite(forward_trig_pin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(forward_trig_pin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(forward_trig_pin, LOW);

  long duration = pulseIn(forward_echo_pin, HIGH);
  long distance = (duration/2) / 29.1;
  delay(100);
  return distance;
  
}


long side1_sensor(){
  digitalWrite(side_trig_pin1, LOW);  
  delayMicroseconds(2); 
  digitalWrite(side_trig_pin1, HIGH);
  delayMicroseconds(10); 
  digitalWrite(side_trig_pin1, LOW);

  long duration = pulseIn(side_echo_pin1, HIGH);
  long distance = (duration/2) / 29.1;
  delay(100);
  return distance;
  
  }    



long side2_sensor(){
  digitalWrite(side_trig_pin2, LOW);  
  delayMicroseconds(2); 
  digitalWrite(side_trig_pin2, HIGH);
  delayMicroseconds(10); 
  digitalWrite(side_trig_pin2, LOW);

  long duration = pulseIn(side_echo_pin2, HIGH);
  long distance = (duration/2) / 29.1;
  delay(100);
  return distance;  
}


long backward_sensor(){
  digitalWrite(backward_trig_pin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(backward_trig_pin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(backward_trig_pin, LOW);

  long duration = pulseIn(backward_echo_pin, HIGH);
  long distance = (duration/2) / 29.1;
  delay(100);
  return distance;  
}
