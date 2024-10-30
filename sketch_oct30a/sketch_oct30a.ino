#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inicializa la pantalla LCD I2C (dirección 0x27, 16 columnas y 2 filas)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pines de los sensores infrarrojos
const int sensor1Pin = 2; // Sensor que suma 200
const int sensor2Pin = 3; // Sensor que suma 500
const int sensor3Pin = 4; // Sensor que suma 1000

// Variable para contar el total
int total = 0;

void setup() {
  // Iniciar la pantalla LCD
  lcd.begin(16,2);
  lcd.backlight(); // Enciende la retroiluminación del LCD
  
  // Configurar los pines de los sensores como entrada
  pinMode(sensor1Pin, INPUT);
  pinMode(sensor2Pin, INPUT);
  pinMode(sensor3Pin, INPUT);

  // Iniciar el monitor serial
  Serial.begin(9600);
  Serial.println("Contador de monedas inicializado.");
  
  // Mostrar mensaje inicial en el LCD
  lcd.print("Total:");
}

void loop() {
  // Comprobar cada sensor
  if (digitalRead(sensor1Pin) == LOW) {
    total += 200;
    delay(100); // Espera para evitar múltiples conteos
  }
  if (digitalRead(sensor2Pin) == LOW) {
    total += 500;
    delay(100);
  }
  if (digitalRead(sensor3Pin) == LOW) {
    total += 1000;
    delay(1000);
  }

  // Mostrar el total en el LCD
  lcd.setCursor(0, 1); // Mover el cursor a la segunda línea
  lcd.print(total); // Mostrar el total
  lcd.print("   "); // Espacios para limpiar

  // Mostrar el total en el monitor serial
  Serial.print("Total: ");
  Serial.println(total);

  // Añadir un pequeño retraso para estabilizar la lectura
  delay(100);
}

