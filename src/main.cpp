#include <Arduino.h>
// koneksi sensor suhu
#define SUHU1 A0
#define SUHU2 A1
#define SUHU3 A2

// buat strukture yg dimiliki oleh sebuah sensor
struct tempSensor_t
{
  uint8_t koneksi_sensor;
  String sensorName;
  uint16_t conversion_data;
};

tempSensor_t sensT1, sensT2, sensT3;

void setup()
{
  Serial.begin(115200);
  // kita isi dulu spek masing-masing sensor
  sensT1.sensorName = "sensorT1";
  sensT1.koneksi_sensor = SUHU1;
  sensT2.sensorName = "sensorT2";
  sensT2.koneksi_sensor = SUHU2;
  sensT3.sensorName = "sensorT3";
  sensT3.koneksi_sensor = SUHU3;
}

void loop()
{
  // konversi 3 data analog menjadi digital
  sensT1.conversion_data =  map(analogRead(sensT1.koneksi_sensor), 0, 1023, 0, 100);
  sensT2.conversion_data =  map(analogRead(sensT2.koneksi_sensor), 0, 1023, 0, 100);
  sensT3.conversion_data =  map(analogRead(sensT3.koneksi_sensor), 0, 1023, 0, 100);


  tempSensor_t sensMax;
  // =====================================================================
  sensMax = sensT1;
  if (sensMax.conversion_data < sensT2.conversion_data)
  {
    sensMax = sensT2;
  }
  if (sensMax.conversion_data < sensT3.conversion_data)
  {
    sensMax = sensT3;
  }
  Serial.println("T1=[" + String(sensT1.conversion_data) + "],T2=[" + String(sensT2.conversion_data) + "],T3=[" + String(sensT3.conversion_data) + "],nilai sensor terbesar: " + sensMax.sensorName +"["+String(sensMax.conversion_data)+"]");
  // =====================================================================
  delay(500);
}