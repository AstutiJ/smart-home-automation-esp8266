#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// ===== Wi-Fi Access Point Credentials =====
const char* ssid = "SmartHome";
const char* password = "12345678";

// ===== Relay Pin Configuration =====
#define RELAY1 D1
#define RELAY2 D2
#define RELAY3 D3
#define RELAY4 D4

// ===== Create a Web Server on Port 80 =====
ESP8266WebServer server(80);

// ===== Function to Generate the HTML Page =====
void handleRoot() {
  String html = R"rawliteral(
  <!DOCTYPE html>
  <html>
  <head>
    <title>Smart Home Control</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <style>
      body {
        font-family: Arial, sans-serif;
        text-align: center;
        background: linear-gradient(to right, #00c6ff, #0072ff);
        color: white;
        padding-top: 30px;
      }
      h1 {
        margin-bottom: 20px;
      }
      .btn {
        display: inline-block;
        width: 100px;
        margin: 10px;
        padding: 12px;
        border: none;
        border-radius: 25px;
        font-size: 16px;
        font-weight: bold;
        cursor: pointer;
        color: white;
        transition: 0.3s;
      }
      .on {
        background-color: #4CAF50;
      }
      .off {
        background-color: #f44336;
      }
      .btn:hover {
        opacity: 0.8;
      }
      .relay-container {
        background-color: rgba(255, 255, 255, 0.15);
        border-radius: 15px;
        padding: 20px;
        margin: 10px auto;
        width: 80%;
        max-width: 400px;
      }
    </style>
  </head>
  <body>
    <h1>Smart Home Control</h1>

    <div class="relay-container">
      <p>Relay 1</p>
      <a href="/relay1on"><button class="btn on">ON</button></a>
      <a href="/relay1off"><button class="btn off">OFF</button></a>
    </div>

    <div class="relay-container">
      <p>Relay 2</p>
      <a href="/relay2on"><button class="btn on">ON</button></a>
      <a href="/relay2off"><button class="btn off">OFF</button></a>
    </div>

    <div class="relay-container">
      <p>Relay 3</p>
      <a href="/relay3on"><button class="btn on">ON</button></a>
      <a href="/relay3off"><button class="btn off">OFF</button></a>
    </div>

    <div class="relay-container">
      <p>Relay 4</p>
      <a href="/relay4on"><button class="btn on">ON</button></a>
      <a href="/relay4off"><button class="btn off">OFF</button></a>
    </div>

  </body>
  </html>
  )rawliteral";

  server.send(200, "text/html", html);
}

// ===== Relay Control Functions =====
void relay1on()  { digitalWrite(RELAY1, LOW);  server.sendHeader("Location", "/"); server.send(303); }
void relay1off() { digitalWrite(RELAY1, HIGH); server.sendHeader("Location", "/"); server.send(303); }

void relay2on()  { digitalWrite(RELAY2, LOW);  server.sendHeader("Location", "/"); server.send(303); }
void relay2off() { digitalWrite(RELAY2, HIGH); server.sendHeader("Location", "/"); server.send(303); }

void relay3on()  { digitalWrite(RELAY3, LOW);  server.sendHeader("Location", "/"); server.send(303); }
void relay3off() { digitalWrite(RELAY3, HIGH); server.sendHeader("Location", "/"); server.send(303); }

void relay4on()  { digitalWrite(RELAY4, LOW);  server.sendHeader("Location", "/"); server.send(303); }
void relay4off() { digitalWrite(RELAY4, HIGH); server.sendHeader("Location", "/"); server.send(303); }

// ===== Setup Function =====
void setup() {
  Serial.begin(115200);

  // Relay setup
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(RELAY3, OUTPUT);
  pinMode(RELAY4, OUTPUT);

  digitalWrite(RELAY1, HIGH);
  digitalWrite(RELAY2, HIGH);
  digitalWrite(RELAY3, HIGH);
  digitalWrite(RELAY4, HIGH);

  // Start Access Point
  WiFi.softAP(ssid, password);
  Serial.println("Access Point Started!");
  Serial.print("SSID: ");
  Serial.println(ssid);
  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP());

  // Route setup
  server.on("/", handleRoot);
  server.on("/relay1on", relay1on);
  server.on("/relay1off", relay1off);
  server.on("/relay2on", relay2on);
  server.on("/relay2off", relay2off);
  server.on("/relay3on", relay3on);
  server.on("/relay3off", relay3off);
  server.on("/relay4on", relay4on);
  server.on("/relay4off", relay4off);

  server.begin();
  Serial.println("Web server started!");
}

// ===== Loop Function =====
void loop() {
  server.handleClient();
}
