#include <WiFi.h>
#include <WiFiUdp.h>

const char* ssid = "SSID";
const char* password = "PASSWORD";

const int localUdpPort = 4210;

WiFiUDP udp;
char incomingPacket[255];

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

  udp.begin(localUdpPort);
  Serial.printf("Now listening on UDP port %d\n", localUdpPort);
}

void loop() {
  int packetSize = udp.parsePacket();
  if (packetSize) {
    int len = udp.read(incomingPacket, 255);
    if (len > 0) {
      incomingPacket[len] = 0; // Null-terminate the received packet
    }
    Serial.printf("Received: %s\n", incomingPacket);
  }
  delay(10);
}
