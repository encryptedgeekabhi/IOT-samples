

#include <Wire.h>
#include <SoftwareSerial.h>

 //FOR BT CONNECTON
SoftwareSerial mySerial(0, 1);//RX,TX


unsigned int vhh;// last hour 
unsigned int vmm;// last minute stord
unsigned int vss;// last second stord
unsigned int pm;
unsigned int icall; // call sensor
unsigned int imsg;// msg sensor




unsigned int rtoggle=0; // real time toggle







void setup()   {                
  mySerial.begin(38400);
Serial.begin(9600);
  
 Serial.println("Enabling watch");
  
 
 
  
  delay(2000);

}

void loop() {
  // put your main code here, to run repeatedly:

// loop when the device is not connected with bluetooth 
while(rtoggle!=0)
{
//increase the time for watch
   if(vss>=60)
 {
   vmm++;
   vss=0;
 }
 if(vmm>=60)
 {
  vhh++;
  vmm=0;
 }
 if(vhh>24)
 {
  vhh=1;
 }

  //current time in the string 
  String hh = String(vhh);
  
  String mm = String(vmm);
  
  String ss = String(vss);


  /*the current am or pm 
  String spm;
  if(pm==1)
  {
    spm="PM";
  }
  else
  {
    spm="AM";
  }*/
  // all the information into one string to display on screen.
  String myTime = hh+":"+mm;
  
  
  
  Serial.println(myTime); 
  delay(1000);
  vss++;
  
  

  if(mySerial.available()>0)
  {
    rtoggle=0;
  }
}

// loop when the device is connected with the bluetooth
while(mySerial.available()>0){
 

 
  String hh =  mySerial.readStringUntil(':');
  
  String mm =  mySerial.readStringUntil(':');
  
  String ss =  mySerial.readStringUntil(':');
  
  String bcall = mySerial.readStringUntil(':');
  
  String call = mySerial.readStringUntil('\0');

  String idata = mySerial.readStringUntil('\0');

  


 // convert the strings to integer values
  
  String myTime = hh+":"+mm;
  
  vhh = hh.toInt();
  vmm = mm.toInt();
  vss = ss.toInt();
  icall = bcall.toInt();
   


  


 if(icall==1)
  {
  
  Serial.println(call +" Calling");
  
  delay(5000);
  
  }
  
  
  else 
  {
 
//  Serial.println(myTime);
  
  delay(1000);
  }
  
}

rtoggle = 1;

}
