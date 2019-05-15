
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <String.h>
// Cấu hình.
#define FIREBASE_HOST "myhome-5be82.firebaseio.com"  
#define FIREBASE_AUTH "qITObbLPwIPcPCsu3xsZLUCJ7ukRHriez4YNzNQI"
#define WIFI_SSID "Ip"
#define WIFI_PASSWORD "11111111"

void setup() {
  Serial.begin(115200);

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
}
char temp[2];
 // lưu tín hiệu đến

String n0,n1,n2,n3,n4,n5,n6,n7,n8,n9;
//int m1=0,m2=0,m3=0,m4=0,m5=0,m6=0,m7=0,x=0,c1=1;
char tmp[22];
//int a= 1, b= 2;
String arrnew[20]={"0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"};
char msg[3] ;
void loop() {
 if(Serial.available()>0)
 {     
                while (Serial.available()<3) {}                     // nhan het 3 ki tu vao Serial
                   
                for(int n=0; n<3; n++)                              // dua 3 ki tu do vao msg theo FIFO(first in first out)
                 { msg[n]= Serial.read();}
                 
                if (String(msg[0])==String("["))
                 {
                  //Serial.println(msg);
                  for (int i=0; i<2; i++)
                  {
                   temp[i] = msg[i+1];
                  }
                  Firebase.setString("Nhiet_Do",temp);
                  //Serial.println(temp);
                   // Kiểm tra lỗi
                   if (Firebase.failed())
                   {
                    Serial.print("[FAIL]");
                    Serial.println(Firebase.error()); 
                    return;
                   }
                  }
                    
//                  else if(strcmp(msg,"ON1")==0)
//                  {
//                      // Thêm chuỗi
//                      Firebase.setString("Den_Phong_Bep", "1");
//                    
//                      // Kiểm tra lỗi
//                      if (Firebase.failed())
//                      {
//                      Serial.print("[FAIL]");
//                      Serial.println(Firebase.error()); 
//                      return;
//                      }
//                   //  Serial.println(msg);
//                      delay(100);
//                  }
//                  else if (strcmp(msg,"OF1")==0)
//                  {
//                      // Thêm chuỗi
//                      Firebase.setString("Den_Phong_Bep", "0");
//                   
//                      // Kiểm tra lỗi
//                      if (Firebase.failed())
//                      {
//                      Serial.print("[FAIL]");
//                      Serial.println(Firebase.error()); 
//                      return;
//                      }
//                   // Serial.println(msg);
//                      delay(100);
//                  }
                  else if(strcmp(msg,"ON2")==0)
                  {
                      // Thêm chuỗi
                      Firebase.setString("Den_Phong_Ngu_1", "1");
                      
                      // Kiểm tra lỗi
                      if (Firebase.failed())
                      {
                      Serial.print("[FAIL]");
                      Serial.println(Firebase.error()); 
                      return;
                      }
                   //  Serial.println(msg);
                      delay(100);
                  }
                  else if (strcmp(msg,"OF2")==0)
                  {
                      // Thêm chuỗi
                      Firebase.setString("Den_Phong_Ngu_1", "0");
                      
                      // Kiểm tra lỗi
                      if (Firebase.failed())
                      {
                      Serial.print("[FAIL]");
                      Serial.println(Firebase.error()); 
                      return;
                      }
                   // Serial.println(msg);
                      delay(100);
                  }
                  else if(strcmp(msg,"ON3")==0)
                  {
                      // Thêm chuỗi
                      Firebase.setString("Quat_Phong_Ngu_1", "1");
                      
                      // Kiểm tra lỗi
                      if (Firebase.failed())
                      {
                      Serial.print("[FAIL]");
                      Serial.println(Firebase.error()); 
                      return;
                      }
                   //  Serial.println(msg);
                      delay(100);
                  }
                  else if (strcmp(msg,"OF3")==0)
                  {
                      // Thêm chuỗi
                      Firebase.setString("Quat_Phong_Ngu_1", "0");
                      
                      // Kiểm tra lỗi
                      if (Firebase.failed())
                      {
                      Serial.print("[FAIL]");
                      Serial.println(Firebase.error()); 
                      return;
                      }
                   // Serial.println(msg);
                      delay(100);
                  }
                  else if(strcmp(msg,"ON4")==0)
                  {
                      // Thêm chuỗi
                      Firebase.setString("Den_Phong_Khach", "1");
                    
                      // Kiểm tra lỗi
                      if (Firebase.failed())
                      {
                      Serial.print("[FAIL]");
                      Serial.println(Firebase.error()); 
                      return;
                      }
                   //  Serial.println(msg);
                      delay(100);
                  }
                  else if (strcmp(msg,"OF4")==0)
                  {
                      // Thêm chuỗi
                      Firebase.setString("Den_Phong_Khach", "0");
                    
                      // Kiểm tra lỗi
                      if (Firebase.failed())
                      {
                      Serial.print("[FAIL]");
                      Serial.println(Firebase.error()); 
                      return;
                      }
                   // Serial.println(msg);
                      delay(100);
                  }
                  else if(strcmp(msg,"ON5")==0)
                  {
                      // Thêm chuỗi
                      Firebase.setString("Den_Phong_Ngu_2", "1");
                     
                      // Kiểm tra lỗi
                      if (Firebase.failed())
                      {
                      Serial.print("[FAIL]");
                      Serial.println(Firebase.error()); 
                      return;
                      }
                   //  Serial.println(msg);
                      delay(100);
                  }
                  else if (strcmp(msg,"OF5")==0)
                  {
                      // Thêm chuỗi
                      Firebase.setString("Den_Phong_Ngu_2", "0");
                     
                      // Kiểm tra lỗi
                      if (Firebase.failed())
                      {
                      Serial.print("[FAIL]");
                      Serial.println(Firebase.error()); 
                      return;
                      }
                   // Serial.println(msg);
                      delay(100);
                  }
                  else if(strcmp(msg,"ON6")==0)
                  {
                      // Thêm chuỗi
                      Firebase.setString("Quat_Phong_Bep", "1");
                     
                      // Kiểm tra lỗi
                      if (Firebase.failed())
                      {
                      Serial.print("[FAIL]");
                      Serial.println(Firebase.error()); 
                      return;
                      }
                   //  Serial.println(msg);
                      delay(100);
                  }
                  else if (strcmp(msg,"OF6")==0)
                  {
                      // Thêm chuỗi
                      Firebase.setString("Quat_Phong_Bep", "0");
                 
                      // Kiểm tra lỗi
                      if (Firebase.failed())
                      {
                      Serial.print("[FAIL]");
                      Serial.println(Firebase.error()); 
                      return;
                      }
                   // Serial.println(msg);
                      delay(100);
                  }
                  else if(strcmp(msg,"ON7")==0)
                  {
                      // Thêm chuỗi
                      Firebase.setString("Quat_Phong_Ngu_2", "1");
                   
                      // Kiểm tra lỗi
                      if (Firebase.failed())
                      {
                      Serial.print("[FAIL]");
                      Serial.println(Firebase.error()); 
                      return;
                      }
                   //  Serial.println(msg);
                      delay(100);
                  }
                  else if (strcmp(msg,"OF7")==0)
                  {
                      // Thêm chuỗi
                      Firebase.setString("Quat_Phong_Ngu_2", "0");
                      
                      // Kiểm tra lỗi
                      if (Firebase.failed())
                      {
                      Serial.print("[FAIL]");
                      Serial.println(Firebase.error()); 
                      return;
                      }
                     // Serial.println(msg);
                      delay(100);
                  }
                  else if (strcmp(msg,"OPC")==0)
                  {
                      // Thêm chuỗi
                      Firebase.setString("Cua_Chinh", "1");
                      
                      // Kiểm tra lỗi
                      if (Firebase.failed())
                      {
                      Serial.print("[FAIL]");
                      Serial.println(Firebase.error()); 
                      return;
                      }
                     // Serial.println(msg);
                      delay(100);
                  }
                  else if (strcmp(msg,"CLC")==0)
                  {
                      // Thêm chuỗi
                      Firebase.setString("Cua_Chinh", "0");
                      
                      // Kiểm tra lỗi
                      if (Firebase.failed())
                      {
                      Serial.print("[FAIL]");
                      Serial.println(Firebase.error()); 
                      return;
                      }
                     // Serial.println(msg);
                      delay(100);
                  }
                  else if (strcmp(msg,"OPS")==0)
                  {
                      // Thêm chuỗi
                      Firebase.setString("Cua_Sau", "1");
                      
                      // Kiểm tra lỗi
                      if (Firebase.failed())
                      {
                      Serial.print("[FAIL]");
                      Serial.println(Firebase.error()); 
                      return;
                      }
                     // Serial.println(msg);
                      delay(100);
                  }
                  else if (strcmp(msg,"CLS")==0)
                  {
                      // Thêm chuỗi
                      Firebase.setString("Cua_Sau", "0");
                      
                      // Kiểm tra lỗi
                      if (Firebase.failed())
                      {
                      Serial.print("[FAIL]");
                      Serial.println(Firebase.error()); 
                      return;
                      }
                     // Serial.println(msg);
                      delay(100);
                  }
                  else if (strcmp(msg,"WHG")==0)
                  {
                      // Thêm chuỗi
                      Firebase.setString("Khi_Gas", "1");
                      Serial.println(msg);

                      // Kiểm tra lỗi
                      if (Firebase.failed())
                      {
                      Serial.print("[FAIL]");
                      Serial.println(Firebase.error()); 
                      return;
                      }
                     // Serial.println(msg);
                      delay(100);
                  }
                  else if (strcmp(msg,"NHG")==0)
                  {
                      // Thêm chuỗi
                      Firebase.setString("Khi_Gas", "0");
                      Serial.println(msg);

                      // Kiểm tra lỗi
                      if (Firebase.failed())
                      {
                      Serial.print("[FAIL]");
                      Serial.println(Firebase.error()); 
                      return;
                      }
                     // Serial.println(msg);
                      delay(100);
                  }
                  else if (strcmp(msg,"WHF")==0)
                  {
                      // Thêm chuỗi
                      Firebase.setString("Lua", "1");
                      
                      // Kiểm tra lỗi
                      if (Firebase.failed())
                      {
                      Serial.print("[FAIL]");
                      Serial.println(Firebase.error()); 
                      return;
                      }
                     // Serial.println(msg);
                      delay(100);
                  }
                  else if (strcmp(msg,"NHF")==0)
                  {
                      // Thêm chuỗi
                      Firebase.setString("Lua", "0");
                      
                      // Kiểm tra lỗi
                      if (Firebase.failed())
                      {
                      Serial.print("[FAIL]");
                      Serial.println(Firebase.error()); 
                      return;
                      }
                     // Serial.println(msg);
                      delay(100);
                  }
                  else if (strcmp(msg,"WAT")==0)
                  {
                      // Thêm chuỗi
                      Firebase.setString("Bao_Trom", "1");
                      
                      // Kiểm tra lỗi
                      if (Firebase.failed())
                      {
                      Serial.print("[FAIL]");
                      Serial.println(Firebase.error()); 
                      return;
                      }
                     // Serial.println(msg);
                      delay(100);
                  }
                  else if (strcmp(msg,"SAT")==0)
                  {
                      // Thêm chuỗi
                      Firebase.setString("Bao_Trom", "0");
                      
                      // Kiểm tra lỗi
                      if (Firebase.failed())
                      {
                      Serial.print("[FAIL]");
                      Serial.println(Firebase.error()); 
                      return;
                      }
                     // Serial.println(msg);
                      delay(100);
                  }
                  else if (strcmp(msg,"WAF")==0)
                  {
                      // Thêm chuỗi
                      Firebase.setString("Bao_Chay", "1");
                      
                      // Kiểm tra lỗi
                      if (Firebase.failed())
                      {
                      Serial.print("[FAIL]");
                      Serial.println(Firebase.error()); 
                      return;
                      }
                     // Serial.println(msg);
                      delay(100);
                  }
                  else if (strcmp(msg,"SAF")==0)
                  {
                      // Thêm chuỗi
                      Firebase.setString("Bao_Chay", "0");
                      
                      // Kiểm tra lỗi
                      if (Firebase.failed())
                      {
                      Serial.print("[FAIL]");
                      Serial.println(Firebase.error()); 
                      return;
                      }
                     // Serial.println(msg);
                      delay(100);
                  }
                   else if(strcmp(msg,"ON1")==0)
                  {
                      // Thêm chuỗi
                      Firebase.setString("Den_Phong_Bep", "1");
                    
                      // Kiểm tra lỗi
                      if (Firebase.failed())
                      {
                      Serial.print("[FAIL]");
                      Serial.println(Firebase.error()); 
                      return;
                      }
                    //Serial.println(msg);
                      delay(100);
                  }
                  else if (strcmp(msg,"OF1")==0)
                  {
                      // Thêm chuỗi
                      Firebase.setString("Den_Phong_Bep", "0");
                   
                      // Kiểm tra lỗi
                      if (Firebase.failed())
                      {
                      Serial.print("[FAIL]");
                      Serial.println(Firebase.error()); 
                      return;
                      }
                    //Serial.println(msg);
                      delay(100);
                  }
               
               
}
else
{            
             n0 = Firebase.getString("Den_Phong_Ve_Sinh");
             //Serial.println(n0);
             n1 = Firebase.getString("Den_Phong_Bep");
             //Serial.println(n1);
             n2 = Firebase.getString("Den_Phong_Ngu_1");
             //Serial.println(n2);
             n3 = Firebase.getString("Quat_Phong_Ngu_1");
             //Serial.println(n3);
             n4 = Firebase.getString("Den_Phong_Khach");
             //Serial.println(n4);
             n5 = Firebase.getString("Den_Phong_Ngu_2");
             //Serial.println(n5);
             n6 = Firebase.getString("Quat_Phong_Bep");
             //Serial.println(n6);
             n7 = Firebase.getString("Quat_Phong_Ngu_2");
             //Serial.println(n7);
             n8 = Firebase.getString("Cua_Chinh");
             //Serial.println(n8);
             n9 = Firebase.getString("Cua_Sau");
             //Serial.println(n9);
             arrnew[0]= n0;
             arrnew[1]= n1;
             arrnew[2]= n2;
             arrnew[3]= n3;
             arrnew[4]= n4;
             arrnew[5]= n5;
             arrnew[6]= n6;
             arrnew[7]= n7;
             arrnew[8]= n8;
             arrnew[9]= n9;


             //Serial.println(String(arrnew[0])!=String(arrnew[7]));
             //delay(500);
             
             for (int i=0; i<10; i++)
             {
              if((String(arrnew[i])!=String(arrnew[i+10]))&&(String(arrnew[i])==String(1)))
              {
               //Serial.println("a");
               sprintf(tmp,"B%d" ,i);
               Serial.write(tmp);
               arrnew[i+10]=arrnew[i];
               continue;
              }
              else if((String(arrnew[i])!=String(arrnew[i+10]))&&(String(arrnew[i])==String(0)))
              {
               sprintf(tmp,"T%d" ,i);
               Serial.write(tmp);
               arrnew[i+10]=arrnew[i];
               continue;
              }
              delay(20);
              }

//             arrnew[7]= arrnew[0];
//             arrnew[8]= arrnew[1];
//             arrnew[9]= arrnew[2];
//             arrnew[10]= arrnew[3];
//             arrnew[11]= arrnew[4];
//             arrnew[12]= arrnew[5];
//             arrnew[13]= arrnew[6];
             
              
}             
          
 /*
  // Lấy giá trị
  Serial.print("number: ");
  Serial.println(Firebase.getFloat("number"));
  delay(1000);
 */


}
