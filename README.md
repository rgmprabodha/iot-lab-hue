# iot-lab-hub

### Task 1: Learn about the Philips Hue API

First we connected to the HUE Bridge using the given wifi (lab-iot-1). We ping the Bridge to check the connection with it. Then we created an account in PHILIPS HUE and login to access the HUE API. Then we access the debugger tool in this address: http://<IP_OF_BRIDGE>/debug/clip.html 

We generated key to our username of HUE, then we used our key for later API calls we made. To see all the light IDs we use GET method with typing the URL (/api/<KEY>/lights) and we saw all the lights details. Then we checked lights details by giving its ID using this URL(/api/<KEY>/lights/<ID>). We posted the one light by its device id, then we found out that bulb by changing the status (on/off). Then we changed the color by modifing HUE value. Then we checked the headers and responses by inspecting and checking Network tab, then we tried different API calls using POSTMAN.
  
### Task 2: Control lights from the Arduino

We configured the Arduino according to Appendix A and started the code with Appendix B. The board we use is Arduino MKR WiFi 1010. In our case potentiometer is connected to analogic pin 4, so we defined POTENTIOMETER_PIN as A4 and button was in digital pin 4 so we defined BUTTON_PIN as 4. Then we set wifi_ssid to 'lab-iot-1' and wifi_password to 'lab-iot-1'. We print the values for the buttons and potentiometer in the serial monitor, When they are changed monitor showed us the new values.

WiFiNINA library allows Arduino MKR WiFi 1010 board to asses Wifi. We found WifiWebClient example of WiFiNINA in arduino editor example list on the computer. It explains how to connect to the WiFi and how to make http request by connecting to a server. We followed the example and tried to call HUE LIGHT API to switch On and Off the Hue light which we have selected for testing. 
