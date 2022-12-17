#include "Wire.h"

#define I2C_DEV_ADDR 0x55

uint32_t i = 0;
int x = 0;
int LED1 = 6;
int LED2 = 7;
void Request(){
  Wire.print(i++);
  Wire.print(" Packets.");
  Serial.println("onRequest");
}

void Receive(int len){
  Serial.println("onReceive:  " + len);
  while(Wire.available()){
   x = Wire.read();
  }
  Serial.println();
}

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  
  Serial.begin(115200);
  //Serial.setDebugOutput(true);
  Wire.onReceive(Receive);
  Wire.onRequest(Request);
  Wire.begin((uint8_t)I2C_DEV_ADDR);

#if CONFIG_IDF_TARGET_ESP32
  char message[64];
  snprintf(message, 64, "%u Packets.", i++);
  Wire.slaveWrite((uint8_t *)message, strlen(message));
#endif
}
void LightLED() {
  if(x == 13) {
    digitalWrite(LED1, HIGH);
    delay(500);
    digitalWrite(LED1, LOW);
  } else if (x == 14) {
    digitalWrite(LED2, HIGH);
    delay(500);
    digitalWrite(LED2, LOW);
  } 
  x = 0;
}
void loop() {
  LightLED();
}
