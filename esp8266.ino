#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <String.h>

#include <Ticker.h>
String n1, n2, n3;
int m1, m2, m3;
int n_1, n_2, n_3;
int MSB_status = 6, LSB_status = 38;
int MSB_sensor, LSB_sensor;
Ticker Timer1;

  // put your setup code here, to run once:
#define WIFI_SSID "0000" // Ten wifi 
#define WIFI_PASSWORD "xxxxxxxx" // Mat khau wifi
//#define WIFI_SSID "Moi Truong Dong Duong" // Ten wifi 
//#define WIFI_PASSWORD "32106789" // Mat khau wifi
#define FIREBASE_HOST "lvtn-6ea7e.firebaseio.com" // Database url (Firebase Google)
#define FIREBASE_AUTH "QXw95ncWASmzCMcPXU0EJOgLbjp0XlDhczcBJQxr" // Ma xac minh

//String Str;
void setup() {
  Serial.begin(9600);

  // Két nối wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  delay(500);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  delay(500);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Timer1.attach_ms(1000, Interrupt);
}
void Interrupt() {
      Serial.println("g");
    }

void serialEvent() {
    Timer1.detach();
    while (Serial.available()) {
      ReceiveData();
      if (Serial.read() == '\n')
        break;
    }
    if ((MSB_sensor == 4) && (LSB_sensor == 15)) {
     if(m1 == 1) Firebase.setString("den_q1", "1");
     else  Firebase.setString("den_q1", "0");
     if(m2 == 1) Firebase.setString("den_q2", "1");
     else  Firebase.setString("den_q2", "0");
     if(m3 == 1) Firebase.setString("den_q3", "1");
     else  Firebase.setString("den_q3", "0");
    }

    Timer1.attach_ms(1000, Interrupt);
}

void loop() {
  n1 = Firebase.getString("den_1");
  n2 = Firebase.getString("den_2");
  n3 = Firebase.getString("den_3");
  Serial.println(n1.toInt());
  Serial.println(n2.toInt());
  Serial.println(n3.toInt());
  n_1 = n1.toInt();
  n_2 = n2.toInt();
  n_3 = n3.toInt();
//n_1 = 1;
//n_2 = 0;
//n_3 = 1;
    Serial.write("s");
    SendStatus(MSB_status, n_1, n_2, n_3, LSB_status);
    while (Serial.available()) {
    serialEvent();
  }     
}

void ReceiveData() {
  MSB_sensor  = Serial.read();
  m1  = Serial.read();
  m2  = Serial.read();
  m3  = Serial.read();
  LSB_sensor  = Serial.read();
}

void SendStatus(int MSB_status, int n_1, int n_2, int n_3, int LSB_status){
  Serial.write(MSB_status);
  Serial.write(n_1);
  Serial.write(n_2);
  Serial.write(n_3);
  Serial.write(LSB_status);
}
