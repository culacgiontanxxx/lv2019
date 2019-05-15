#include <String.h>
#define led1 22
#define led2 24
#define led3 26
//#include <OneWire.h>
//#include <DallasTemperature.h>
//#include <TimerOne.h>
int MSB_send = 4, LSB_send = 15, MSB_status, LSB_status;
char a1, a2, a3; 
int b1, b2, b3;
//int a[3];
//const int pushButton[] ={23,25,27};
//int pushed[] ={0,0,0};// status of each buttons
//int relayStatus[] ={HIGH,HIGH,HIGH};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial2.begin(9600);
  pinMode(led1, OUTPUT);
  digitalWrite(led1, HIGH);
  pinMode(led2, OUTPUT);
  digitalWrite(led2, HIGH);
  pinMode(led3, OUTPUT);
  digitalWrite(led3, HIGH);
}

void loop() {
  a1 = 1;
  a2 = 0;
  a3 = 1;
  while (Serial3.available()) {
  char content = (char)Serial3.read();
  if (content == 'g') {
      Send_Data();   
    } 
    else if (content == 's') {
      Receive_Status();
        if ((MSB_status == 6) && (LSB_status == 38)) {
          if ( b1 == 0) {
          digitalWrite(led1, LOW);
          Serial.println("den 1 sang");
          }
          else if ( b1 == 1) {
          digitalWrite(led1, HIGH);
          Serial.println("den 1 tat");
          }
          else if ( b2 == 0) {
          digitalWrite(led2, LOW);
          Serial.println("den 2 sang");
          }
          else if ( b2 == 1){
          digitalWrite(led2, HIGH);
          Serial.println("den 2 tat");
          }
          else if ( b3 == 0) {
          digitalWrite(led3, LOW);
          Serial.println("den 3 sang");
          }
          else if ( b3 == 1){
          digitalWrite(led3, HIGH);
          Serial.println("den 3 tat");
          }
        }
      }
 }  
       
  /*for(int i=0; i<3; i++)
  {
     int  val = digitalRead(pushButton[i]);   
    if(val == HIGH && relayStatus[i] == LOW){
  
      pushed[i] = 1-pushed[i];
      delay(100);
    }// if   

  relayStatus[i] = val;

      if(pushed[i] == HIGH){
        //Serial.print(relayNames[i]);
        //Serial.println(" ON");
        //digitalWrite(relayPin[i], LOW);
        a[i]=0;
        //Serial.println(a[i]);
      }else{
        //Serial.print(relayNames[i]);
        //Serial.println(" OFF");
        //digitalWrite(relayPin[i], HIGH);
        a[i]=1;
        //Serial.println(a[i]);
      }// else   
 
  }// fo

  a1 = a[0];
  a2 = a[1];
  a3 = a[2];*/
}

void Receive_Status() {
  MSB_status = Serial2.read();
  b1 = Serial2.read();
  b2 = Serial2.read();
  b3 = Serial2.read();
  LSB_status = Serial2.read();

}

void Send_Data() {
  Serial2.write(MSB_send);
  Serial2.write(a1);
  Serial2.write(a2);
  Serial2.write(a3);
  Serial2.write(LSB_send);

}
