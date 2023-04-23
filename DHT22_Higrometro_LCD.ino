#include <LiquidCrystal.h>
#include <DHT.h>

#define DHTPIN 13
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

int pinoSensor = A0;
int analogSoloSeco = 400;
int analogSoloMolhado = 150;
int percSoloSeco = 0;
int percSoloMolhado = 100;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int buttonPin = 7;
int buttonState = 0;
int lastButtonState = 0;
int displayState = 0;

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.begin(16, 2);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState != lastButtonState) {
    if (buttonState == LOW) {
      displayState++;
      if (displayState > 1) {
        displayState = 0;
      }
    }
    delay(50);
  }
  lastButtonState = buttonState;

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  int leituraSensor = analogRead(pinoSensor);
  int percentualUmidade = constrain(map(leituraSensor, analogSoloSeco, analogSoloMolhado, percSoloSeco, percSoloMolhado), percSoloSeco, 100);

  if (displayState == 0) {
    Serial.print("Umidade do ar: ");
    Serial.print(humidity);
    Serial.print("%  Temperatura: ");
    Serial.print(temperature);
    Serial.println("C");

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Umidade: ");
    lcd.print(abs(humidity));
    lcd.print("%");
    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(abs(temperature));
    lcd.print("C");
  }
  else {
    Serial.print("Umidade do solo: ");
    Serial.print(percentualUmidade);
    Serial.println("%");

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Solo: ");
    lcd.print(abs(percentualUmidade));
    lcd.print("%");
  }
  delay(500);
}
