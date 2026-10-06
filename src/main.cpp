#include <Arduino.h>
#include <DHT.h>

// Čidlo DHT11 je připojeno na digitální pin D7
constexpr uint8_t DHT_PIN = 7;
constexpr uint8_t DHT_TYPE = DHT11;

// DHT11 zvládne nové měření nejdříve po 1 s, použijeme 2 s
constexpr unsigned long READ_INTERVAL_MS = 2000;

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();

  Serial.println(F("Arduino UNO R3 - test cidla DHT11 (pin D7)"));
  Serial.println(F("------------------------------------------"));
}

void loop() {
  static unsigned long lastRead = 0;
  unsigned long now = millis();

  if (now - lastRead < READ_INTERVAL_MS) {
    return;
  }
  lastRead = now;

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println(F("Chyba: nepodarilo se nacist data z DHT11!"));
    return;
  }

  float heatIndex = dht.computeHeatIndex(temperature, humidity, false);

  Serial.print(F("Teplota: "));
  Serial.print(temperature, 1);
  Serial.print(F(" °C\tVlhkost: "));
  Serial.print(humidity, 0);
  Serial.print(F(" %\tPocitova teplota: "));
  Serial.print(heatIndex, 1);
  Serial.println(F(" °C"));
}
