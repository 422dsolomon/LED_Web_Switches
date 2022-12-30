# LED_Web_Switches

This repo contains the code to create a web app that interfaces with Google Firebase to turn on and off 2 seperate LED's attached to a microcontroller board. 

---

For the circuit you will use this schematic

![alt text](https://github.com/422dsolomon/LED_Web_Switches/blob/main/Images/Microcontroller_Circuit.png)

---

<div>
  <p>
    <h3>Firebase</h3>
      Firebase is a set of hosting services for any type of application. It offers NoSQL and real-time hosting of databases, content, social authentication, and notifications, 
      or services, such as a real-time communication server. I am able to send data from the ESP32 to firebase as well as read the firebase from the ESP32. 

      Setting up the firebase database:

      <ol>
        <li>Go to <a href="https://firebase.google.com/">firebase</a> </li>
        <li>Create an account</li>
        <li>Create a new project</li>
        <li>Go to Authentication</li>
        <li>Click get started</li>
        <li>Use Email and Password</li>
        <li>Go to realtime database</li>
        <li>Create realtime database</li>
        <li>Choose test mode, can change later</li>
        <li>Go to apps and choose web app</li>
        <li>Name it and click register</li>
        <li>Then in save the Firebase SDK script</li>
        <li>Put this in the <a href = "https://github.com/422dsolomon/LED_Web_Switches/blob/main/HTML%20and%20JavaScript/public/index.html">index.html</a></li>
      </ol>
  </p>
</div>
