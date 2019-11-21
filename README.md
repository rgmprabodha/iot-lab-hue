# iot-lab-hub

### Task 1

First we connected to the HUE Bridge using the given wifi (lab-iot-1). We ping the Bridge to check the connection with it. Then we created an account in PHILIPS HUE and login to access the HUE API. Then we access the debugger tool in this address: http://<IP_OF_BRIDGE>/debug/clip.html 

We generated key to our username of HUE, then we used our key for later API calls we made. To see all the light IDs we use GET method with typing the URL (/api/<KEY>/lights) and we saw all the lights details. Then we checked lights details by giving its ID using this URL(/api/<KEY>/lights/<ID>). We posted the one light by its device id, then we found out that bulb by changing the status (on/off). Then we changed the color by modifing HUE value. Then we checked the headers and responses by inspecting and checking Network tab, then we tried different API calls using POSTMAN.
  
### Task 2
We 
