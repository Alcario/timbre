#include <DS3231.h>
#include <TimeLib.h>

//Definimos el objeto rtc
DS3231 rtc(SDA, SCL);

//Configuramos los pines a utilizar como salida
#define LED 13
#define timbre 12

//Definimos los tiempos en que tocaremos el timbre
#define recreo 3000
#define cambioHora 1700

void setup() {
  //Inicializamos el reloj
  rtc.begin();

  // Inicializa el puerto serie
  Serial.begin(9600);

  // Configuramos los pines
  pinMode(timbre, OUTPUT);
  pinMode(LED, OUTPUT);

  //Configuramos el estado inicial de las salidas
  digitalWrite(timbre, LOW);
  digitalWrite(LED, LOW);
}

void loop() {
  // Obtiene la hora actual del RTC
  Time now = rtc.getTime();
  
  // Comprueba si la fecha está entre lunes y viernes
  if (((int)(now.dow)) >= 1 && ((int) (now.dow)) <= 5){
    activarTimbre(7, 25, now, 1);
    activarTimbre(8, 10, now, 0);
    activarTimbre(8, 50, now, 1);
    activarTimbre(9, 5, now, 1);
    activarTimbre(9, 45, now, 0);
    activarTimbre(10, 25, now, 0);
    activarTimbre(11, 5, now, 1);
    activarTimbre(11, 15, now, 1);
    activarTimbre(11, 55, now, 0);
    activarTimbre(12, 35, now, 1);
    activarTimbre(13, 0, now, 1);
    activarTimbre(13, 40, now, 0);
    activarTimbre(14, 20, now, 1);
    activarTimbre(14, 25, now, 1);
    activarTimbre(15, 5, now, 0);
    activarTimbre(15, 45, now, 1);
    activarTimbre(15, 50, now, 1);
    activarTimbre(16, 30, now, 0);
  }
  //Mostramos el dato obtenido del RTC en formato DD/MM/AAAA -- HH:MM:SS
  Serial.println(String(now.date) + "/" + String(now.dow) + "/" + String(now.year) + " -- " + String(now.hour) + ":" + String(now.min) + ":" + String(now.sec));
  
  delay(500);
}

void activarTimbre(int hora, int minuto, Time now, bool estado){

  //Vemos si corresponde "Recreo" o "Cambio de Hora"
  if(estado){
    if(((int) (now.hour)) == hora && ((int) now.min) == minuto && ((int) now.sec) < 3){  //si es la hora deseada se activa el timbre durante el tiempo establecido en la variable recreo
          digitalWrite(timbre, HIGH); // Activa la salida 7
          digitalWrite(LED, HIGH); // Activa la salida 7
          delay(recreo);
          digitalWrite(timbre, LOW); // Activa la salida 7
          digitalWrite(LED, LOW); // Activa la salida 7
          Serial.println("Tocando");

    }
  }else if(((int) (now.hour)) == hora && ((int) now.min) == minuto && ((int) now.sec) < 3){  //si es la hora deseada se activa el timbre durante el tiempo establecido en la variable cambioHora
          digitalWrite(timbre, HIGH); // Activa la salida 7
          digitalWrite(LED, HIGH); // Activa la salida 7
          delay(cambioHora);
          digitalWrite(timbre, LOW); // Activa la salida 7
          digitalWrite(LED, LOW); // Activa la salida 7
          Serial.println("Tocando");
          delay(cambioHora);
  }
}