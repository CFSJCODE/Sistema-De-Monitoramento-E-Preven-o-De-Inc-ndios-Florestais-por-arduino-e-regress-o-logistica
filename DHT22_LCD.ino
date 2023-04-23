

// Inclui a biblioteca referente ao funcionamento do display LCD
#include <LiquidCrystal.h>

// Inclui a biblioteca referente ao funcionamento do módulo DHT22
#include <DHT.h>

// Define os pinos de conexão do display LCD
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

// Define o pino utilizado na conexão do módulo DHT22
#define DHTPIN 13

// Define o tipo de sensor como sensor DHT22
#define DHTTYPE DHT22

// Cria uma instância do objeto LiquidCrystal
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Cria uma instância do objeto DHT
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Inicia a comunicação com o monitor serial
  Serial.begin(9600);

  // Inicia a comunicação com o display LCD
  lcd.begin(16, 2);

  // Inicia a comunicação com o sensor DHT22
  dht.begin();
}

void loop() {
  // Aguarda 2 segundos para a próxima leitura
  delay(2000);

  // Realiza a leitura dos dados do sensor DHT22
  float umidade = dht.readHumidity();
  float temperaturaC = dht.readTemperature();
  float temperaturaF = dht.readTemperature(true);

  // Verifica se os dados da leitura são válidos
  if (isnan(umidade) || isnan(temperaturaC) || isnan(temperaturaF)) {
    Serial.println("Falha ao ler o sensor DHT22!");
    return;
  }

  // Imprime os dados do sensor no monitor serial
  Serial.print("Umidade: ");
  Serial.print(umidade);
  Serial.print("%\t");
  Serial.print("Temperatura: ");
  Serial.print(temperaturaC);
  Serial.print(" °C\t");
  Serial.print(temperaturaF);
  Serial.println(" °F");

  // Imprime os dados do sensor no display LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Umidade: ");
  lcd.print(umidade);
  lcd.print("%");
  lcd.setCursor(0, 1);
  lcd.print("Temperatura: ");
  lcd.print(temperaturaC);
  lcd.print(" C");
}
