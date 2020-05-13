#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <DHT.h>
#include <SimpleTimer.h>

#define FIREBASE_HOST "robot-terbang-sensordht11.firebaseio.com"
#define FIREBASE_AUTH "IgnOuvLkofBnDHFR7LUCDbcrIBm23kJZx6lQhXAa"
#define WIFI_SSID "wifi-testing"
#define WIFI_PASSWORD "arDY1234"

#define LED1 D1
#define LED2 D2

DHT dht(D4, DHT11);
SimpleTimer timer;

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  digitalWrite(LED1,0);
  digitalWrite(LED2,0);

  Serial.println("\n\n===================");
  Serial.println("Live Youtube #1 IoT");
  Serial.println("Firebase + ESP8266 + Arduino");
  Serial.println("Ardy Seto Priambodo");
  Serial.println("\n\n===================");
  delay(1000);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.setInt("LED1-Status",0);
  Firebase.setInt("LED2-Status",0);
  delay(2000);

  timer.setInterval(5000, sendDHT11);
}

void loop() {
  timer.run();

  if(Firebase.getInt("LED1-Status")) {
    Serial.println("LED1 ON");
    digitalWrite(LED1,HIGH);
  }
  else {
    Serial.println("LED1 OFF");
    digitalWrite(LED1,LOW);
  }

  if (Firebase.getInt("LED2-Status")) {
    Serial.println("LED2 ON");
    digitalWrite(LED2,HIGH);
  }
  else {
    Serial.println("LED2 OFF");
    digitalWrite(LED2,LOW);
  }
  
  if(Firebase.failed()) {
    Serial.print("Setting /number failed:");
    Serial.println(Firebase.error());
    return;
  }
  Serial.println(" ");
  delay(1000);
}

void sendDHT11() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  Serial.println("Send Humidity and Temperature to Firebase");
  Serial.println("Humidity(%): " + String(h));
  Serial.println("Temperature (*C): " + String(t));
  Firebase.setFloat("DHT11-Humidity", h);
  Firebase.setFloat("DHT11-Temperature", t);
  Serial.println(" ");
}
