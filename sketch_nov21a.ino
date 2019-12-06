#include <string.h>

#include <SPI.h>
#include <WiFiNINA.h>

/* We need objects to handle WiFi connectivity
 */
WiFiClient wifi_client ;
 
/* In which pins is my buttons plugged? */
#define POTENTIOMETER_PIN A4 // TODO: uncomment this line if the potentiometer is connected to analogic pin 4, or adapt...
//#define POTENTIOMETER_PIN 3 // TODO: uncomment this line if the potentiometer is connected to digital pin 3, or adapt...

// TODO: you probably need to add a line here for the button pin....

#define BUTTON_PIN 4


/* And associated variables to tell:
 *  1. which WiFi network to connect to
 *  2. what are the MQTT broket IP address and TCP port
 */
const char* wifi_ssid     = "lab-iot-1"; // changed
const char* wifi_password = "lab-iot-1"; // changed
 int status= WL_IDLE_STATUS;
/* Some variables to handle measurements. */
IPAddress server(192,168,1,131); 
int potentiometerValue;
int buttonState = 0;         // variable for reading the pushbutton status


uint32_t t0, t ;

/* Time between displays. */
#define DELTA_T 1000


void setup() {
  // monitoring via Serial is always nice when possible
  Serial.begin(9600) ;
  delay(100) ;
  Serial.println("Initializing...\n") ;
  // check for the WiFi module:
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("Communication with WiFi module failed!");
    // don't continue
    while (true);
  }

  String fv = WiFi.firmwareVersion();
  if (fv < "1.0.0") {
    Serial.println("Please upgrade the firmware");
  }

  // attempt to connect to Wifi network:
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(wifi_ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(wifi_ssid, wifi_password);

    // wait 10 seconds for connection:
    delay(10);
  }
  Serial.println("Connected to wifi");


  // initialize the Potentiometer and button pin as inputs:
  pinMode(BUTTON_PIN, INPUT);
  pinMode(POTENTIOMETER_PIN, INPUT);

  // Time begins now!
  t0 = t = millis() ;
}

void loop() {

  t = millis() ;
  if ( (t - t0) >= DELTA_T ) {
    t0 = t ;

    // read the states:
    buttonState = digitalRead(BUTTON_PIN);
     potentiometerValue = digitalRead(POTENTIOMETER_PIN); // TODO: uncomment this line if it is digital
   // potentiometerValue = analogRead(POTENTIOMETER_PIN); // TODO; uncomment this line if it is analog
    Serial.print("potentiometer value: ");
    Serial.print(potentiometerValue);

    Serial.print(" ; button value: ");
    Serial.println(buttonState);
   
    if ( status != WL_CONNECTED)
    {
      Serial.print(" Failed ");

    }
    else
    {
      Serial.print("connected  ");
      if(buttonState ==1)
        {
        Serial.println("button pressed");
//        wifi_client.println("PUT /api/0KX7DYkM6LgQ2rDmuF3zr94QY5TrsYLAqWmeIGQN/lights/13/state HTTP/1.0");
//        wifi_client.println("Host:  192.168.1.131");
//        wifi_client.println("");
//          wifi_client.print("{\"on\":true}");                         
//        //wifi_client.println("Connection: close");
//        //wifi_client.println("Content-Type: application/x-www-form-urlencoded");
//        //wifi_client.println("Content-Length: 10\r\n");
//       if (wifi_client.println() == 0) {
//          Serial.println(F("Failed to send request"));
//          //return;
//        }
        if (wifi_client.connect(server, 80)) {
            Serial.println("connected to server");
            // Make a HTTP request:
            wifi_client.println("PUT /api/0KX7DYkM6LgQ2rDmuF3zr94QY5TrsYLAqWmeIGQN/lights/15/state HTTP/1.1");
            wifi_client.println("Host: 192.168.1.131");
            wifi_client.println("");
            wifi_client.println("{\"on\":true}");   
           // wifi_client.println("Connection: close");
            wifi_client.println();                     
          }
          
           // Check HTTP status
          char status[32] = {0};
          wifi_client.readBytesUntil('\r', status, sizeof(status));
          Serial.println(status);
        }
    }

    // TODO: adapt this program to connect to the WiFi and send the HTTP request to the Philips Hue here.
    // WARNING: send at most one HTTP request per second !!! and only if it makes sense, i.e., if the values did not change too much.

  }
}
