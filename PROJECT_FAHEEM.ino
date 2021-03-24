#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>
char auth[] = "8P0b93PvroRFeTVLQvmpyE_3SQomuMqR";
char ssid[] = "Pi Home";
char pass[] = "Pihome@7560";

const int TOUCH_BUTTON_PIN = D0;  // Input pin for touch state
 
// Global Variables
int buttonState = 0;             // Variable for reading button
int ledPin = 12;
int inputPin = 13; 
int val = 0;
int Status =14; 
int sensor =3;
#define IR D1
bool ir;

void setup() 
{
  Serial.begin(9600);
   Blynk.begin(auth, ssid, pass);
  // Configure button pin as input 
  pinMode(D0, INPUT);
  pinMode(D6, OUTPUT);
  pinMode(D1, INPUT);
  pinMode(D7, OUTPUT);
   pinMode(D2, INPUT);
  pinMode(D5, OUTPUT);  }
 
void loop() 
{
   Blynk.run();
  // Read the state of the capacitive touch board
  buttonState = digitalRead(D0);
 
  // If a touch is detected, turn on the LED
  if (buttonState == HIGH) 
  {
    digitalWrite(D6, HIGH);
  } 
  else 
  {
    digitalWrite(D6, LOW);
  }
  { 
   val = digitalRead(D1); // read input value 
   if (val == HIGH)
   { // check if the input is HIGH
      digitalWrite(D7, LOW); // turn LED OFF   
   } 
   else 
   { 
      digitalWrite(D7, HIGH); // turn LED ON 
   } 
}
long state = digitalRead(D2);
    if(state == HIGH) {
      digitalWrite (D5, HIGH);
      Serial.println("Motion detected!");
      delay(1000);
    }
    else {
      digitalWrite (D5, LOW);
      Serial.println("Motion absent!");
      delay(1000);
      Blynk.notify("T==> Motion detected");
      }
void getPirValue(void)
{
  pirValue = digitalRead(pirPin);
  if (pirValue) 
  { 
    Serial.println("==> Motion detected");
    Blynk.notify("T==> Motion detected");  
  }
  digitalWrite(ledPin, pirValue);
}
      Blynk.run();
}
