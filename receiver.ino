#include <WiFi.h>

const char* ssid = "SSID";
const char* password = "PASSWORD";
const char* host = "192.168.xx.xx"; // Replace with the server's IP address
const uint16_t port = 80;

void setup() {
  Serial.begin(115200);
  
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi...");

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
  Serial.println(WiFi.localIP());
}

void loop() {
  Serial.print("Connecting to ");
  Serial.print(host);
  Serial.print(':');
  Serial.println(port);

  WiFiClient client;

  if (!client.connect(host, port)) {
    Serial.println("Connection to host failed");
    delay(2000);
    return;
  }

  Serial.println("Connected to server");
  
  // Send data to the server
  String message = "Hello from ESP32 Client";
  client.println(message);
  Serial.print("Sent: ");
  Serial.println(message);

  // Wait for a response from the server
  while (client.connected() && !client.available()) {
    delay(10);
  }
  
  String response = client.readStringUntil('\n');
  Serial.print("Received: ");
  Serial.println(response);

  client.stop();
  Serial.println("Disconnected from server");

  delay(5000); // Send a message every 5 seconds
}
