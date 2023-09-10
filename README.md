# timbre
Timbre automático controlado por Arduino 

----------------------------------------------------------------------------------------

**Descripción:**

El proyecto "Sistema de Control de Timbre y Monitoreo de Hora con Arduino" se enfoca en la creación de un sistema que controla un timbre y monitorea la hora actual utilizando un módulo de reloj en tiempo real (RTC). El sistema se encarga de activar el timbre en momentos específicos del día, como recreos y cambios de hora, en un entorno escolar.

----------------------------------------------------------------------------------------

**Características Principales:**

Módulo RTC: Utiliza el módulo DS3231 para mantener un registro preciso de la hora y la fecha actual.

Control de Timbre: Activa y desactiva un timbre a través de un relé conectado al pin de salida del Arduino.

Programación Horaria: El sistema permite programar eventos de timbre en momentos específicos del día para recreos y cambios de hora.

Indicador Visual: Un LED conectado al Arduino proporciona una indicación visual cuando se activa el timbre.

----------------------------------------------------------------------------------------

**Funcionamiento:**

El sistema monitorea constantemente la hora actual a través del módulo RTC. Durante los días laborables (de lunes a viernes), se programan eventos de timbre en momentos como el inicio y el final de clases, recreos y cambios de hora. Cuando llega la hora de uno de estos eventos, el sistema activa el timbre durante un período de tiempo determinado y enciende el indicador visual (LED). Después de completar la tarea, el timbre se desactiva automáticamente.

----------------------------------------------------------------------------------------

**Configuración:**

En la primera conección se carga el archivo "configHora.ino" para que se tome la hora de la computadora.

Ya para dejar configurado el timbre se utiliza el segundo archivo, donde por medio del DS3231 obtenemos la hora y en función de si es un recreo o cambio de hora se toca el timbre en tiempos distintos
