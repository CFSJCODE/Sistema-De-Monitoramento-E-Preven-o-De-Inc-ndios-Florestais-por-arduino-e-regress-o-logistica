#include <LiquidCrystal.h>

// Definindo o pino do sensor de chuva
int pinoSensorChuva = 8;

// Inicializando o objeto do display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
// Inicializando a comunicação serial
Serial.begin(9600);

// Inicializando o display
lcd.begin(16, 2);

// Configurando o pino do sensor de chuva como entrada
pinMode(pinoSensorChuva, INPUT);
}

void loop() {
// Lendo o valor do sensor de chuva
int valorSensorChuva = digitalRead(pinoSensorChuva);

// Verificando se há chuva no sensor
if (valorSensorChuva == HIGH) {
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("Sem chuva");
} else {
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("Chuva detectada");
}

// Aguardando 500 milissegundos antes de ler novamente o sensor
delay(500);
}
