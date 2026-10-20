# 03 — IoT: Pemantauan Suhu dan Kelembapan

## Studi kasus
ESP32 membaca suhu dan kelembapan dari DHT22. LED menyala saat suhu mencapai 30°C atau kelembapan mencapai 80%. Nilai ambang hanya contoh dan perlu disesuaikan dengan penggunaan nyata.

## Komponen dan sambungan
- ESP32
- Sensor DHT22
- LED bawaan board (contoh GPIO 2, tergantung board) atau LED eksternal dengan resistor
- DHT22 VCC → 3V3, GND → GND, DATA → GPIO 4

## Menjalankan
1. Instal Arduino IDE dan dukungan board ESP32.
2. Instal library **DHT sensor library** oleh Adafruit (beserta library dependensinya jika diminta).
3. Buka `pemantau_suhu_kelembapan.ino`, pilih board dan port ESP32, lalu upload.
4. Buka Serial Monitor pada `115200 baud`.

## Konsep yang dipelajari
Sensor sebagai input, mikrokontroler sebagai pemroses, LED sebagai output/aktuator, pembacaan berkala, dan aturan ambang. Contoh ini belum mengirim data ke internet/cloud.

## Pengembangan lanjutan
Tambahkan MQTT atau dashboard web untuk memantau data dari jarak jauh. Jangan gunakan perangkat ini sebagai alat keselamatan atau pengendali proses kritis tanpa validasi dan perlindungan yang sesuai.
