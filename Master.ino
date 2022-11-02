#include <Wire.h>
// Define Slave I2C Address
#define SLAVE_ADDR 0x09
// Define Slave answer size
 int reading ; 
void setup() {
  // Initialize I2C communications as Master
  Wire.begin();
  // Setup serial monitor
  Serial.begin(9600);
  Serial.println("I2C Master Demonstration");
}
 
void loop() {
  delay(50);
  Serial.println("Receive data");
  Wire.requestFrom(SLAVE_ADDR,sizeof(int));
  reading = Wire.read();
  Serial.println(reading);
}
