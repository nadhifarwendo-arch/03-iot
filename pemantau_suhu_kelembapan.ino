#include <DHT.h>

// Contoh untuk ESP32 + sensor DHT22.
#define DHTPIN 4
#define DHTTYPE DHT22
#define LED_PIN 2
#define TEMP_LIMIT 30.0
#define HUMIDITY_LIMIT 80.0

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  dht.begin();
  Serial.println("Sistem Pemantauan Suhu dan Kelembapan IoT");
}

void loop() {
  delay(2000); // DHT22 tidak dibaca terlalu cepat.
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Gagal membaca sensor. Periksa kabel dan tipe sensor.");
    digitalWrite(LED_PIN, LOW);
    return;
  }

  Serial.print("Suhu: "); Serial.print(temperature); Serial.print(" C | ");
  Serial.print("Kelembapan: "); Serial.print(humidity); Serial.println(" %");

  bool warning = (temperature >= TEMP_LIMIT) || (humidity >= HUMIDITY_LIMIT);
  digitalWrite(LED_PIN, warning ? HIGH : LOW);
  if (warning) Serial.println("PERINGATAN: Ambang suhu/kelembapan terlampaui!");
}
