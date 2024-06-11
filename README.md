Steps to Upload and Run

Step:1 Set Up WiFi Credentials:
Replace your_SSID and your_PASSWORD in both sketches with your WiFi network's SSID and password.

Receiver IP Address:
Replace 192.168.1.x in the sender sketch with the actual IP address of the receiver ESP32. You can get this IP address from the serial monitor output of the receiver sketch after it connects to the WiFi.

Step:2 Upload Code:

Upload the receiver code to one ESP32.
Upload the sender code to the other ESP32.

Step:3 Open Serial Monitors:

Open the Serial Monitor for both ESP32 devices in the Arduino IDE.

Step:4 Send and Receive Messages:

Type a message into the Serial Monitor of the sender ESP32 and press Enter.
The message should be sent to the receiver ESP32 and displayed in its Serial Monitor.

/*--OUTPUT--*/
Sender::
![Screenshot 2024-06-11 162714](https://github.com/owais8113/UDP_ESP32/assets/127936539/4ef9900b-27db-441b-9e55-94d9547659c8)
Receiver::
![WhatsApp Image 2024-06-11 at 4 27 55 PM](https://github.com/owais8113/UDP_ESP32/assets/127936539/e5af8ab2-d233-42d9-80ce-c39b7431771b)
