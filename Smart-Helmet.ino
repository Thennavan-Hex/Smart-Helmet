/* 
  Sketch generated by the Arduino IoT Cloud Thing "Untitled"
  https://create.arduino.cc/cloud/things/cc3e180c-0c17-4e88-bfde-2b91c3977d8f 

  Arduino IoT Cloud Variables description
Device ID0c2807d6-e770-40b2-8f1b-c22ee7bf3ce0
Secret Key
PClYQGCzwmcwwXUVd0#WO#rTa
  The following variables are automatically generated and updated when changes are made to the Thing

  int gas;
  int humidity;
  int temperature;
  bool buzzer;
  bool gas2;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/

#include "thingProperties.h"
 #include "DHT.h"  
 DHT dht2(2,DHT11); 
 int gassensor = 4;
 int buzzeer = 3;
void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  pinMode(gassensor,INPUT);
  pinMode(buzzer,OUTPUT);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  temperature=dht2.readTemperature();
  humidity= dht2.readHumidity();
  gas=analogRead(A0);
  gas2=digitalRead(gassensor);
  if(buzzer==true)
  {
    digitalWrite(buzzeer,HIGH);
  }
  else
  {
    digitalWrite(buzzeer,LOW);
  }
}


/*
  Since Temperature is READ_WRITE variable, onTemperatureChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onTemperatureChange()  {
  // Add your code here to act upon Temperature change
}

/*
  Since Humidity is READ_WRITE variable, onHumidityChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onHumidityChange()  {
  // Add your code here to act upon Humidity change
}

/*
  Since Gas is READ_WRITE variable, onGasChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onGasChange()  {
  // Add your code here to act upon Gas change
}

/*
  Since Gas2 is READ_WRITE variable, onGas2Change() is
  executed every time a new value is received from IoT Cloud.
*/
void onGas2Change()  {
  // Add your code here to act upon Gas2 change
}


/*
  Since Buzzer is READ_WRITE variable, onBuzzerChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onBuzzerChange()  {
  // Add your code here to act upon Buzzer change
}