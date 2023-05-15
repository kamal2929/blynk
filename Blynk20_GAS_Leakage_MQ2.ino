
#define BLYNK_TEMPLATE_ID "TMPL2FWjDmBwv"
#define BLYNK_TEMPLATE_NAME "Gas Leakage Alert"
#define BLYNK_AUTH_TOKEN "6XK14D9MsUlxY_6Ogk0ggHB-J__CCVTN"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

 
char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "2929";  // Enter your wifi name
char pass[] = "12345678o";  // Enter your wifi password
int smokeA0 =A0;
int data = 0;
int sensorThres = 100;


BlynkTimer timer;

void sendSensor(){
 
 int data = analogRead(smokeA0);
 Blynk.virtualWrite(V0, data);
  Serial.print("Pin A0: ");
  Serial.println(data);


  if(data > 200)     // Change the Trashold value
  {
    Blynk.email("kamala.20it@kongu.edu", "Alert", "Gas Leakage Detected!");
    Blynk.logEvent("gas_alert","Gas Leakage Detected");
  }
}

void setup(){
  pinMode(smokeA0, INPUT);
   Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  //dht.begin();
  timer.setInterval(2500L, sendSensor);
}

void loop(){
  Blynk.run();
  timer.run();
}
