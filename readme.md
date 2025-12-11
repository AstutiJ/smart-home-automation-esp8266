# 🏠 Smart Home Automation Using ESP8266

Wi-Fi Based Relay Control System with Web Dashboard

---

## 📌 Overview

This project is a *Smart Home Automation System* built using the *ESP8266 NodeMCU* microcontroller.
It allows users to *control home appliances (lights, fans, etc.)* through a *web interface* that works on any mobile or laptop connected to the Wi-Fi hotspot created by the ESP8266.

The system hosts its own *Wi-Fi Access Point, serves a **web dashboard, and uses **relay modules* to switch appliances ON/OFF.

This project was developed as part of our *AI/ML & IoT Summer Training Program*.

---

## ✨ Features

* 🔌 Control up to *4 appliances*
* 🌐 ESP8266 works as *Wi-Fi Access Point + Web Server*
* 📱 Works on mobile and laptop (no internet required)
* 🧩 Simple HTML/CSS UI hosted on the ESP8266
* ⚡ Real-time response
* 🛠 Beginner-friendly & expandable project

---

## 🛠 Hardware Requirements

* ESP8266 NodeMCU
* 4-Channel Relay Module
* Jumper Wires
* USB Cable (for uploading code)
* Power Supply
* Mobile or Laptop for controlling devices

---

## 📁 Folder Structure


smart-home-automation/
│── README.md
│── SmartHome.ino
│── LICENSE
│── .gitignore
│── images/
│     │── ui.png
│     │── circuit.png
│     │── hardware.jpg
│
└── docs/
      │── project-report.pdf
      │── presentation.pdf
      |── certificate.pdf

---

## 🚀 Getting Started

### 1️⃣ *Install Tools*

* Arduino IDE
* ESP8266 Board package
  (Install via Boards Manager → esp8266 by ESP8266 Community)

### 2️⃣ *Upload Code*

* Select board: *NodeMCU 1.0 (ESP-12E)*
* Connect ESP8266 → Upload

### 3️⃣ *Connect to Wi-Fi AP*

After upload, ESP8266 creates a hotspot:


SSID: SmartHome
Password: 12345678


### 4️⃣ *Open Control Panel*

In your browser, enter:


http://192.168.4.1


You will see the control dashboard with *ON/OFF* buttons for each relay.

---

## 🔧 System Architecture


Mobile/Laptop
      ↓
ESP8266 Wi-Fi Access Point
      ↓
Web Server (Port 80)
      ↓
Relay Module
      ↓
Home Appliances


---

## 🧠 How It Works

* ESP8266 hosts HTML/CSS UI directly from flash memory
* Each button sends an HTTP request:
  /relay1on , /relay1off, etc.
* Server routes control the relay pins (D1, D2, D3, D4)
* Appliances switch ON (LOW) or OFF (HIGH)

---

## 🔮 Future Enhancements

This project can be extended with:

* Google Assistant / Alexa voice control
* Android mobile app
* Cloud automation using Firebase / MQTT
* Scheduling (timer-based operations)
* Sensor integration (temperature, motion, etc.)

---


## 🏅 Why This Project Is Valuable

This project demonstrates skills in:

* IoT hardware programming
* Embedded C++ (Arduino)
* Web server development
* System architecture & UI design
* Real-world problem solving
* Team collaboration

# 🏠 Smart Home Automation Using ESP8266

![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)
![Platform: ESP8266](https://img.shields.io/badge/Platform-ESP8266-blue)
![Language: C++](https://img.shields.io/badge/Language-C++-orange)
![IoT Project](https://img.shields.io/badge/Category-IoT-green)
![Web Server](https://img.shields.io/badge/Module-Web%20Server-purple)
