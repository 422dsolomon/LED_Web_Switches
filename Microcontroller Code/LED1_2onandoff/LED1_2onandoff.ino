#include <Arduino.h>
#if defined(ESP32)
  #include <WiFi.h>
#elif defined(ESP8266)
  #include <ESP8266WiFi.h>
#endif
#include <Firebase_ESP_Client.h>

//Provide the token generation process info.
#include "addons/TokenHelper.h"
//Provide the RTDB payload printing info and other helper functions.
#include "addons/RTDBHelper.h"

// Insert your network credentials
#define WIFI_SSID "MAKERSPACE"
#define WIFI_PASSWORD "12345678"

#define DATABASE_URL "https://esp32-led-7f940-default-rtdb.firebaseio.com"
#define API_KEY "AIzaSyA9lU2wZuMzjj69MrLptpI-iZ8Qko3JE3s"

// Insert Authorized Email and Corresponding Password
#define USER_EMAIL "Dsolomon@college.harvard.edu"
#define USER_PASSWORD "Sololebow1"

//Define Firebase Data object
FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

unsigned long sendDataPrevMillis = 0;
String fireString_1 = "";                                          // led status received from firebase
String fireString_2 = "";
int ledpin1 = 25;
int ledpin2 = 26;
bool signupOK = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();
  // Assign the user sign in credentials
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;

  /* Assign the api key (required) */
  config.api_key = API_KEY;

  /* Assign the RTDB URL (required) */
  config.database_url = DATABASE_URL;

  /* Sign up */
  if (Firebase.signUp(&config, &auth, "", "")) {
    Serial.println("ok");
    signupOK = true;
  }
  else {
    Serial.printf("%s\n", config.signer.signupError.message.c_str());
  }

  /* Assign the callback function for the long running token generation task */
  config.token_status_callback = tokenStatusCallback; //see addons/TokenHelper.h

  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);

  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
  // Firebase.RTDB.setString(&fbdo, "LED_STATUS/LED_STATUS_1", "ON");
  // Firebase.RTDB.setString(&fbdo, "LED_STATUS/LED_STATUS_2", "ON");   
}

void loop() {
   if (Firebase.ready() && signupOK && (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0)) {
    sendDataPrevMillis = millis();
    if (Firebase.RTDB.getString(&fbdo, "LED_STATUS/LED_STATUS_1")) {
      if (fbdo.dataType() == "string") {
        fireString_1 = fbdo.stringData();
        Serial.println(fireString_1);
      }
    }
    else {
      Serial.println(fbdo.errorReason());
    }
    
    if (Firebase.RTDB.getString(&fbdo, "LED_STATUS/LED_STATUS_2")) {
      if (fbdo.dataType() == "string") {
        fireString_2 = fbdo.stringData();
        Serial.println(fireString_2);
      }
    }
    else {
      Serial.println(fbdo.errorReason());
    }

    if (fireString_1 == "ON") {                    // compare the input of led status received from firebase
        Serial.println("Led Turned ON");
        digitalWrite(ledpin1, HIGH);                // make output led ON
      }
    else if (fireString_1 == "OFF") {              // compare the input of led status received from firebase
        Serial.println("Led Turned OFF");
        digitalWrite(ledpin1, LOW);                 // make output led OFF
      }
    
    if (fireString_2 == "ON") {                    // compare the input of led status received from firebase
        Serial.println("Led Turned ON");
        digitalWrite(ledpin2, HIGH);                // make output led ON
      }
    else if (fireString_2 == "OFF") {              // compare the input of led status received from firebase
        Serial.println("Led Turned OFF");
        digitalWrite(ledpin2, LOW);                 // make output led OFF
      }
        
  }

}
