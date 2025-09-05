#include <Wire.h>
#include "Adafruit_SHT31.h"

Adafruit_SHT31 sht31 = Adafruit_SHT31();

void setup() {
  Serial.begin(115200);
  while (!Serial) delay(10);

  if (!sht31.begin(0x44)) {   // Dirección I2C por defecto: 0x44
    Serial.println("No se encontró el sensor SHT31");
    while (1) delay(1);
  }
}

void loop() {
  float temp = sht31.readTemperature();
  float hum  = sht31.readHumidity();

  if (!isnan(temp) && !isnan(hum)) {
    // Imprime en formato CSV -> Temperatura, Humedad
    Serial.print(temp, 2);
    Serial.print(",");
    Serial.println(hum, 2);
  } else {
    Serial.println("Error leyendo el sensor");
  }

  delay(1000); // espera 1 segundo
}
