#include <Arduino.h>
 
//koneksi sensor suhu
#define SUHU1 A0
#define SUHU2 A1
#define SUHU3 A2
//variabel nilai data terbesar
uint8_t datamax = 0;
//variabel hasil konversi
uint16_t dataT1 = 10, dataT2 = 11, dataT3 = 12; 



void setup() {
  Serial.begin(115200);
}

void loop() {
  dataT1 = analogRead(A0);
  dataT2 = analogRead(A1);
  dataT3 = analogRead(A2);
  
  // =====================================================================
  datamax = dataT1;
  if (datamax < dataT2 )
  {
    datamax = dataT2;
  }
  if (datamax < dataT3) 
  {
    datamax = dataT3;
  }
  Serial.println("T1=["+String(dataT1)+"],T2=["+String(dataT2)+"], T3=["+String(dataT3)+"], nilai sensor terbesar: "+String(datamax));
  // =====================================================================
  delay(500);
}