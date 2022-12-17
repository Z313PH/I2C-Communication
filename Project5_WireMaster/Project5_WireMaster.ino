#include "Wire.h"

#define I2C_DEV_ADDR 0x55

uint32_t i = 0;
int btn1 = 14; // red btn
int btn2 = 13; // white btn
void setup() {
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  Wire.begin();
}

void loop() {


  //Write message to the slave
  Wire.beginTransmission(I2C_DEV_ADDR);
  //Wire.printf("Hello World! %u", i++);
 
  if (digitalRead (btn1) == HIGH) {
     Wire.write(btn1);
  }

 if (digitalRead (btn2) == HIGH) {
     Wire.write(btn2);
  }

  uint8_t error = Wire.endTransmission(true);
  Serial.printf("endTransmission: %u\n", error);
  
  //Read 16 bytes from the slave
  uint8_t bytesReceived = Wire.requestFrom(I2C_DEV_ADDR, 16);
  Serial.printf("requestFrom: %u\n", bytesReceived);
  if((bool)bytesReceived){ //If received more than zero bytes
    uint8_t temp[bytesReceived];
    Wire.readBytes(temp, bytesReceived);
    log_print_buf(temp, bytesReceived);
  }
}
