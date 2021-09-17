#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
BlynkTimer timer;


#define trigPin 16
#define  echoPin 17

#define red 18
#define yellow 19
#define green 21


 
int flag = 0;


float duration, distance;

char ssid[] = "Redmi"; //wifi name
char pass[] = "kumar123"; // wifi password
char auth[] = "ZmbzytIJ29fP9g7rbbnJCCKRe10MApcy";  //bynlk auth token



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);

pinMode(green, OUTPUT);
pinMode(yellow, OUTPUT);
pinMode(red, OUTPUT);



 WiFi.begin(ssid, pass);
 Blynk.config(auth);
}

void loop() {
  // put your main code here, to run repeatedly:
 if (WiFi.status() != WL_CONNECTED)
  {
   Serial.println("Not Connected");
   WiFi.disconnect();
   delay(1000);
   WiFi.reconnect();
   delay(2000);
   
  }
  else
  {
   Blynk.run();
   
  }

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);
 
 Blynk.virtualWrite(V2  , distance);

 if(distance <=40){
  digitalWrite(green,HIGH);
 }
 else{
  digitalWrite(green,LOW);
 }

 if(distance <=110){
  digitalWrite(yellow,HIGH);
 }
 else{
  digitalWrite(yellow,LOW);
 }
 
 if(distance <=170){
  digitalWrite(red,HIGH);
 }
 else{
  digitalWrite(red,LOW);
 }


}
