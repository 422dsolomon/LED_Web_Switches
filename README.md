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
- Go to apps and choose web app
- Then in save the Firebase SDK script
- Put this in the <a href = "https://github.com/422dsolomon/LED_Web_Switches/blob/main/HTML%20and%20JavaScript/public/index.html">index.html</a>

