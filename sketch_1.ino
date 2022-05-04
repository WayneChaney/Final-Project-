#include <Wire.h>
#include <SFE_BMP180.h>

SFE_BMP180 bmp180;

void setup() {
  Serial.begin(9600);
  bool working = bmp180.begin();

  if (working) {
    Serial.println("BMP180 code is working ");
  }
}

void loop() {
  char status;
double Temp, Press;
  
  
  bool success = false;

  status = bmp180.startTemperature();

  if (status != 0) {
    delay(2500);
    status = bmp180.getTemperature(Temp);

    if (status != 0) {
      status = bmp180.startPressure(3);

      if (status != 0) {
        delay(status);
        status = bmp180.getPressure(Press, Temp);

        if (status != 0) {
          Serial.print("Pressure: ");
          Serial.print(Press);
          Serial.println(" hPa");

          Serial.print("Temperature: ");
          Serial.print(Temp);
          Serial.println(" C");
        }
      }
    }
  }
}
