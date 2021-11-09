#include<LiquidCrystal.h>
  LiquidCrystal lcd(5,18,19,21,22,23);
#include "WiFi.h"
#include "WiFiClient.h"

#include <HTTPClient.h> 

const char* ssid = "MDD";
const char* password =  "MDD123456";
String Link,Link1;
HTTPClient http,http1,http2,http3,http4;
String getstatus;

WiFiClient client;

double counter=0;
  int entry=33;
  int exiit=32;
  int c=0;
  int n=0;
  int no_of_person;
  
  int number_count = 0;
  int count = 0;
  
  int stp=25;
  int m1=26;
  int m2=27;
  int m3=12;
  int m4=4;
  int SA=11;
String St="Nothing";
  
  void setup() 
{
   Serial.begin(115200);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println("Connected to the WiFi network");
 
  //FOR monitor
  // mySerial.begin(9600);  // FOR LCD
   lcd.begin(16,2);
  pinMode(entry,INPUT); 
  pinMode(exiit,INPUT);
  pinMode(stp,INPUT);
//  
  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(m3,OUTPUT);
  pinMode(m4,OUTPUT);
  lcd.setCursor(0,0);
  lcd.print("Smart Public   ");
  lcd.setCursor(0,1);
  lcd.print("Transport System  ");
   
  delay(500);


  http4.begin("https://mahavidyalay.in/AcademicDevelopment/ServerDemo/Led6.php?status=-----");  //Specify destination for HTTP request
   Serial.println("Data Send Succesfully to Cloud");
   http4.addHeader("Content-Type", "text/plain");             //Specify content-type header
   int http2ResponseCode = http4.POST("post from 32s");   //Send the actual POST request
    String response = http4.getString();                       //Get the response to the request
 
    //Serial.println(httpResponseCode);   //Print return code
    //Serial.println(response);           //Print request answer
   http4.end();  //Free resources

   

  
  }
  
  void loop() 
  {

Link= "http://mdbelectrosoft.in/MDBES/Workshop.php?unit=8";
    http.begin(Link);     //Specify request destination
  
  int httpCode = http.GET();            //Send the request
  String payload = http.getString();    //Get the response payload
 
   //Print HTTP return code
  Serial.print("Data= "); 
  Serial.println(payload); 

int myvalue=payload.toInt();
  Serial.println(myvalue);
  
    if(myvalue==9)
    {//////////////Motor ON/////////////////////
      digitalWrite(m1,1);
    digitalWrite(m2,0);
    digitalWrite(m3,1);
    digitalWrite(m4,0);
    Serial.println("ghum rhi");
    }
else if(myvalue==1)
{//////////////Motor OFF/////////////////////
  digitalWrite(m1,0);
    digitalWrite(m2,0);
    digitalWrite(m3,0);
    digitalWrite(m4,0);
    Serial.println("ruk gai");
    }

    else if(myvalue==2)
    {/////////////////////Seat Availability///////////////////////////
      String Sa=String(SA);
                                    
                                     http1.begin("http://mdbelectrosoft.in/MDBES/Workshop.php?unit=9&sensor="+Sa);
                                     Serial.println("Data Send Succesfully to Cloud");
   http1.addHeader("Content-Type", "text/plain");             //Specify content-type header
   int http1ResponseCode = http1.POST("post from 32s");   //Send the actual POST request
    String response1 = http1.getString();                       //Get the response to the request
 
    //Serial.println(httpResponseCode);   //Print return code
    //Serial.println(response);           //Print request answer
   http1.end();  //Free resources


/////////to change ata of button//////////////////////////
   http3.begin("http://mdbelectrosoft.in/MDBES/Workshop.php?unit=8&sensor=7");
                                     Serial.println("Data Send Succesfully to Cloud");
   http3.addHeader("Content-Type", "text/plain");             //Specify content-type header
   int http3ResponseCode = http3.POST("post from 32s");   //Send the actual POST request
    String response3 = http3.getString();                       //Get the response to the request
 
    //Serial.println(httpResponseCode);   //Print return code
    //Serial.println(response);           //Print request answer
   http3.end();  //Free resources



   
      }

      else if(myvalue==3)
      {////////////////current station/////////////////////
        String CS=String(St);
        http2.begin("https://mahavidyalay.in/AcademicDevelopment/ServerDemo/Led5.php?status="+CS);  //Specify destination for HTTP request
   Serial.println("Data Send Succesfully to Cloud");
   http2.addHeader("Content-Type", "text/plain");             //Specify content-type header
   int http2ResponseCode = http2.POST("post from 32s");   //Send the actual POST request
    String response = http2.getString();                       //Get the response to the request
 
    //Serial.println(httpResponseCode);   //Print return code
    //Serial.println(response);           //Print request answer
   http2.end();  //Free resources

    
    /////////to change data of button//////////////////////////
    http3.begin("http://mdbelectrosoft.in/MDBES/Workshop.php?unit=8&sensor=7");
    Serial.println("Data Send Succesfully to Cloud");
   http3.addHeader("Content-Type", "text/plain");             //Specify content-type header
   int http3ResponseCode = http3.POST("post from 32s");   //Send the actual POST request
    String response3 = http3.getString();                       //Get the response to the request
 
    //Serial.println(httpResponseCode);   //Print return code
    //Serial.println(response);           //Print request answer
   http3.end();  //Free resources
        }

        else if(myvalue==4)
      {////////////////current station/////////////////////
        
        http4.begin("https://mahavidyalay.in/AcademicDevelopment/ServerDemo/Led6.php?status=SeatReaserved");  //Specify destination for HTTP request
   Serial.println("Data Send Succesfully to Cloud");
   http4.addHeader("Content-Type", "text/plain");             //Specify content-type header
   int http2ResponseCode = http4.POST("post from 32s");   //Send the actual POST request
    String response = http4.getString();                       //Get the response to the request
 
    //Serial.println(httpResponseCode);   //Print return code
    //Serial.println(response);           //Print request answer
   http4.end();  //Free resources
   SA=SA-1;

    
    /////////to change data of button//////////////////////////
    http3.begin("http://mdbelectrosoft.in/MDBES/Workshop.php?unit=8&sensor=7");
    Serial.println("Data Send Succesfully to Cloud");
   http3.addHeader("Content-Type", "text/plain");             //Specify content-type header
   int http3ResponseCode = http3.POST("post from 32s");   //Send the actual POST request
    String response3 = http3.getString();                       //Get the response to the request
 
    //Serial.println(httpResponseCode);   //Print return code
    //Serial.println(response);           //Print request answer
   http3.end();  //Free resources
        }

      
  
   
   if(digitalRead(stp)==0)
     {Serial.println(digitalRead(stp));
      if(n==0)
        {          
        
         lcd.begin(16,2);
         lcd.clear();
         lcd.setCursor(0,0);
         lcd.print("KATHORA ROAD        ");
         Serial.println("KATHORA ROAD");
         St=("KathoraRoad");
         lcd.setCursor(0,1);
         lcd.print("                     ");
         while(digitalRead(stp)==0);
         delay(4000);
        
         lcd.begin(16,2);
         lcd.setCursor(0,0);
         lcd.print("KATHORA ROAD        ");
         lcd.setCursor(0,1);
         lcd.print("NX PRPCET AMT ");
         Serial.println("NEXT STOP PRPCET AMT");
         n=1;
         }
         }
             
  if(digitalRead(stp)==0)
    {
    if(n==1)
      {
     
      lcd.begin(16, 2);
      lcd.setCursor(0,0);
      lcd.print("COLLEGE ARRIVED");
      St=("College");
      Serial.println("PRPCET AMT ARRIVED ");
      
      lcd.setCursor(0,1);
      lcd.print("                     ");
      while(digitalRead(stp)==0);
      
      delay(2000);
 
      n=2;
      }
      }
  
  if(digitalRead(stp)==0)
    {
    if(n==2)
      {
       
       lcd.begin(16, 2);
       lcd.setCursor(0,0);
       lcd.print("LEAVING PRPCET    ");
       Serial.println("LEAVING PRPCET AMRAVATI ");
       St=("LeavingPRPCET");
       lcd.setCursor(0,1);
       lcd.print("                     ");
       while(digitalRead(stp)==0);
       
       
       
       
       
      
       lcd.begin(16, 2);
       lcd.setCursor(0,1);
       lcd.print("NXT ST. KATHORA");
       Serial.println("NEXT ST. KATHORA ROAD");
       
       n=3;
       }
       }
         
  if(digitalRead(stp)==0)
    {
    if(n==3)
      {
       
       lcd.begin(16, 2);
       lcd.setCursor(0,0);
       lcd.print("KATHORA ROAD");
       Serial.println("KATHORA ROAD");
       St=("KathoraRoad");
       
       lcd.setCursor(0,1);
       lcd.print("                  ");
       n=3;
       }
       }
    
    ////for counting person
  if(digitalRead(entry)==1)
    {
     while(digitalRead(entry)==1);
     c=c+1;
    
//       if(c >= 11)
//       {
//        digitalWrite(A3,1);
//        
//        delay(2000);
//        digitalWrite(A3,0);
       
       }
     no_of_person=c;
      SA=11-no_of_person;
     Serial.print("no_of_person = ");
     Serial.println(no_of_person);
     lcd.begin(16, 2);
     lcd.setCursor(0,0);
     lcd.print("No of prsn=       ");
     lcd.setCursor(13,0);
     lcd.print(no_of_person);
     lcd.setCursor(0,1);
     //lcd.print("                    ");
      }
    
  ////////////// decreament counter
  if(digitalRead(exiit)==1)
    {
      Serial.println(A5);
      if(c>0)////  avoid negative number of persons
      {
      while(digitalRead(exiit)==1);
      c=c-1;
      no_of_person=c;
      SA=11-no_of_person;
      Serial.print("no_of_person = ");
      Serial.println(no_of_person);
      lcd.begin(16, 2);
      lcd.setCursor(0,0);
      lcd.print("No of prsn=          ");
      lcd.setCursor(13,0);
      lcd.print(no_of_person);
      lcd.setCursor(0,1);
      }
      }
Serial.println();
Serial.println();
    Serial.print("SA=");
    Serial.println(SA);
    Serial.println();
Serial.println();

Serial.println("St=");
Serial.println(St);
    
  
counter=counter+1;
if(counter==100)
{
  http4.begin("https://mahavidyalay.in/AcademicDevelopment/ServerDemo/Led6.php?status=-----");  //Specify destination for HTTP request
   Serial.println("Data Send Succesfully to Cloud");
   http4.addHeader("Content-Type", "text/plain");             //Specify content-type header
   int http2ResponseCode = http4.POST("post from 32s");   //Send the actual POST request
    String response = http4.getString();                       //Get the response to the request
 
    //Serial.println(httpResponseCode);   //Print return code
    //Serial.println(response);           //Print request answer
   http4.end();  //Free resources

   counter=0;
  }

  Serial.print("myvalue=");
  Serial.println(myvalue);
  
  }
   
