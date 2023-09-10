#include <Wire.h>
#include <RTClib.h>

RTC_DS3231 rtc;

void setup() {
  // Inicializa el puerto serie
  Serial.begin(9600);

  // Espera a que el puerto serie se conecte
  while (!Serial) {
    // Espera
  }

  // Inicializa la comunicación I2C
  Wire.begin();

  // Inicializa el RTC
  rtc.begin();

  // Sincroniza la fecha y hora del RTC con la fecha y hora de la computadora
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  Serial.println("RTC configurado correctamente.");
}

void loop() {
  // Obtiene la fecha y hora actual de la computadora
  DateTime now = rtc.now();

  // Muestra la fecha y hora actual en el puerto serie
  Serial.print("Fecha y hora de la computadora: ");
  Serial.print(now.day(), DEC);
  Serial.print("/");
  Serial.print(now.month(), DEC);
  Serial.print("/");
  Serial.print(now.year(), DEC);
  Serial.print(" ");
  Serial.print(now.hour(), DEC);
  Serial.print(":");
  Serial.print(now.minute(), DEC);
  Serial.print(":");
  Serial.print(now.second(), DEC);
  Serial.println();

  // Espera un segundo antes de mostrar la siguiente fecha y hora
  delay(1000);
}