// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>
#include<IRremote.h>
IRrecv irrecv(11);
decode_results results;

AF_DCMotor motor1(1);
AF_DCMotor motor2(3);

void setup() {
  

  // turn on motor
  motor1.setSpeed(2000);
 Serial.begin(9600);
  
  motor2.setSpeed(2000);
  irrecv.enableIRIn();
}

void loop() {
  
  if(irrecv.decode(&results)){
    
    Serial.println(results.value);
    
    
    if(results.value==16732845 || results.value==1053031451 || results.value==3627676998 || results.value==1232702262)
    {
      
       motor1.run(FORWARD);
       motor2.run(BACKWARD);
      
       motor1.setSpeed(2000);
       motor2.setSpeed(2000); 
       delay(3000);
       motor1.run(RELEASE);
       motor2.run(RELEASE);
       
    }
    if(results.value==16742535 || results.value==4131161687 || results.value==3877639429)
    {
      
       motor1.run(BACKWARD);
       motor2.run(FORWARD);
      
       motor1.setSpeed(2000);
       motor2.setSpeed(2000); 
       delay(3000);
       motor1.run(RELEASE);
       motor2.run(RELEASE);
       
    }
    if(results.value==851901943){ 
      motor2.run(BACKWARD);
      motor2.setSpeed(1000);
      delay(2000);
      motor2.run(RELEASE);
    }
    if(results.value==2721879231 ){
      motor1.run(FORWARD);
      motor1.setSpeed(1000);
      delay(2000);
      motor1.run(RELEASE);
      
    }
    irrecv.resume();
       
  }
}
  
