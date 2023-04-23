#include <DHT.h> //Inclui a biblioteca DHT
#define DHTPIN 13 //Define o pino do sensor
#define DHTTYPE DHT22 //Define o tipo do sensor

DHT dht(DHTPIN, DHTTYPE); //Inicializa o sensor

void setup() {
  Serial.begin(9600); //Inicia a comunicação serial
  dht.begin(); //Inicia o sensor
}

void loop() {
  delay(2000); //Espera 2 segundos para a leitura
  float humidity = dht.readHumidity(); //Lê a umidade
  float temperature = dht.readTemperature(); //Lê a temperatura em Celsius
  float f = dht.readTemperature(true); //Lê a temperatura em Fahrenheit

  if (isnan(humidity) || isnan(temperature) || isnan(f)) { //Verifica se há leituras inválidas
    Serial.println("Falha ao ler o sensor DHT22!");
    return;
  }

  Serial.print("Umidade: ");
  Serial.print(humidity);
  Serial.print("%\t");
  Serial.print("Temperatura: ");
  Serial.print(temperature);
  Serial.print(" °C\t");
  Serial.print(f);
  Serial.println(" °F");
}
