# LED_Web_Switches

This repo contains the code to create a web app that interfaces with Google Firebase to turn on and off 2 seperate LED's attached to a microcontroller board. 

---

For the circuit you will use this schematic

![alt text](https://github.com/422dsolomon/LED_Web_Switches/blob/main/Images/Microcontroller_Circuit.png)

---


## Firebase

Firebase is a set of hosting services for any type of application. It offers NoSQL and real-time hosting of databases, content, social authentication, and notifications, or services, such as a real-time communication server. I am able to send data from the ESP32 to firebase as well as read the firebase from the ESP32. 

Setting up the firebase database:

- Go to <a href="https://firebase.google.com/">firebase</a>
- Create an account
- Go to Authentication
- Click get started
- Use Email and Password
- Go to realtime database
- Create realtime database
- Choose test mode, can change later
- Save the URL
- Go to project settings
- Save Web API Key
- Go to apps and choose web app
- Then in save the Firebase SDK script
- Put this in the <a href = "https://github.com/422dsolomon/LED_Web_Switches/blob/main/HTML%20and%20JavaScript/public/index.html">index.html</a>

---

## Arduino

Then it is time to code the microcontroller that you are using. You should choose one that has connection to wifi, in my case I used the ESP32 chip. 

- Open up Arduino IDE
- Go to Manage Libraries
- Install Firebase Arduino Client Library for ESP8266 and ESP32 by Mobitz
- In the code make sure to include the libraries for Wifi and Firebase_ESP_Client
- When inputing wifi SSID and password, computer must be on the same internet
- Then set your API Key and Database URL which we copied before

---
## VS Code

- Open up the terminal
- Go to the correct directory the in the terminal
- Type firebase init
- Select Realtime database and Hosting by hitting space
- Use existing project, and choose the Firebase project that you created
- Hit enter twice
- Type N twice

---

Another description can be found at this <a href = "https://fab.cba.mit.edu/classes/863.22/Harvard/people/Daniel/Week%2010/week10.html">website</a>
