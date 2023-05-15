#include <deprecated.h>
#include <MFRC522.h>
#include <MFRC522Extended.h>
#include <require_cpp11.h>
#include <LiquidCrystal.h>
#include <Wire.h>
#include <SD.h>
#include <SPI.h>
#include <RFID.h>
#define RFID_RST_PIN 9
#define RFID_SS_PIN 10

int say = 0;
RFID rfid(RFID_SS_PIN, RFID_RST_PIN);
const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
#define CSpin 4 
File dosya; 
byte kisi = 0;
byte bir[5] = {68 , 231 , 98 , 251 , 58};
byte iki[5] = {68 , 108 , 97 , 251 , 178};
byte uc[5] = {212 , 58 , 100 , 251 , 113};
byte dort[5] = {180 , 141 , 162 , 251 , 96};
byte serNum[5];
byte data[5];

void setup() {
  Serial.begin(9600);
  pinMode(RFID_RST_PIN, OUTPUT);
  pinMode(RFID_SS_PIN, OUTPUT);
  pinMode(CSpin, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(8, OUTPUT);
  SPI.begin();
  rfid.init();
  lcd.begin(16, 2);
  if (!SD.begin(CSpin)) { 
    lcd.clear();
    lcd.setCursor (0, 0);
    lcd.println(" SD KART TAKILI ");
    lcd.setCursor (0, 1);
    lcd.println(" !!!  DEGIL !!! ");
    delay(2000);
    lcd.clear();
       delay(2000);
    Serial.println("SD Kart YOK");
    return;
  }
  lcd.clear();
  lcd.setCursor (0, 0);
  lcd.println(" PERSONEL TAKIP ");
  lcd.setCursor (0, 1);
  lcd.println("    SISTEMI     ");
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(8, HIGH);
  delay(1000);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(8, LOW);
}
void loop() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  kisi = 0;
  digitalWrite(8, LOW);
  lcd.setCursor (0, 0);
  lcd.println("OGRENCI YOKLAMA SISTEMI");
  lcd.setCursor (0, 1);
  digitalWrite(RFID_SS_PIN, LOW); 
  digitalWrite(CSpin, HIGH); 
  if (rfid.isCard())
  {
    if (rfid.readCardSerial())
    {
      //      Serial.print("Kart bulundu ID: ");
      //      Serial.print(rfid.serNum[0]);
      //      Serial.print(",");
      //      Serial.print(rfid.serNum[1]);
      //      Serial.print(",");
      //      Serial.print(rfid.serNum[2]);
      //      Serial.print(",");
      //      Serial.print(rfid.serNum[3]);
      //      Serial.print(",");
      //      Serial.println(rfid.serNum[4]);
    }
    if (rfid.serNum[0] == bir[0]) {
      if (rfid.serNum[1] == bir[1]) {
        if (rfid.serNum[2] == bir[2]) {
          if (rfid.serNum[3] == bir[3]) {
            if (rfid.serNum[4] == bir[4]) {
              Serial.println("KAYITLI KULLANICI");
              lcd.clear();
              lcd.setCursor (0, 0);
              lcd.println("  Hasan Ilteris Dıncer  ");
              lcd.setCursor (0, 1);
              lcd.println("20060157");
              digitalWrite(8, HIGH);
              digitalWrite(2, LOW);
              digitalWrite(3, HIGH);
              delay(500);
              kisi = 1;  kayit();
            }
          }
        }
      }
    }
    if (rfid.serNum[0] == iki[0]) {
      if (rfid.serNum[1] == iki[1]) {
        if (rfid.serNum[2] == iki[2]) {
          if (rfid.serNum[3] == iki[3]) {
            if (rfid.serNum[4] == iki[4]) {
              Serial.println("KAYITLI KULLANICI");
              digitalWrite(8, HIGH);
              digitalWrite(2, LOW);
              digitalWrite(3, HIGH);
              lcd.clear();
              lcd.setCursor (0, 0);
              lcd.println("Mustafa Enes Ozkan");
              lcd.setCursor (0, 1);
              lcd.println("20060149");
              delay(500);
              kisi = 2; kayit();
            }
          }
        }
      }
    }
    if (rfid.serNum[0] == uc[0]) {
      if (rfid.serNum[1] == uc[1]) {
        if (rfid.serNum[2] == uc[2]) {
          if (rfid.serNum[3] == uc[3]) {
            if (rfid.serNum[4] == uc[4]) {
              Serial.println("KAYITLI KULLANICI");
              digitalWrite(8, HIGH);
              digitalWrite(2, LOW);
              digitalWrite(3, HIGH);
              lcd.clear();
              lcd.setCursor (0, 0);
              lcd.println("Orhan Samı Genc");
              lcd.setCursor (0, 1);
              lcd.println("20060164 ");
              delay(500);
              kisi = 3;  kayit();
            }
          }
        }
      }
    }
    if (rfid.serNum[0] == uc[0]) {
      if (rfid.serNum[1] == uc[1]) {
        if (rfid.serNum[2] == uc[2]) {
          if (rfid.serNum[3] == uc[3]) {
            if (rfid.serNum[4] == uc[4]) {
              Serial.println("KAYITLI KULLANICI");
            digitalWrite(8, HIGH);
              digitalWrite(2, LOW);
              digitalWrite(3, HIGH);
              lcd.clear();
              lcd.setCursor (0, 0);
              lcd.println("Orhan Samı Genc");
              lcd.setCursor (0, 1);
              lcd.println("20060164 ");
              delay(500);
              kisi = 3;  kayit();
            }
          }
        }
      }
    }
              digitalWrite(8, HIGH);
              digitalWrite(3, LOW);
              digitalWrite(2, HIGH);
kayit();
    rfid.halt();
  }
}
void kayit()
{
  digitalWrite(8, LOW);
  digitalWrite(RFID_SS_PIN, HIGH); 
  digitalWrite(CSpin, LOW); 
  dosya = SD.open("DOSYAM.txt", FILE_WRITE); 
  if (SD.exists("DOSYAM.txt")) { //
    Serial.println("KAYIT YAPILDI");
    lcd.setCursor (15, 1);
    lcd.println("+");
    dosya.print("KAYIT :");
    if (kisi == 1)
    {
      dosya.print(" Hasan Ilterıs Dıncer Numara : 20060157   ");
    }
    if (kisi == 2)
    {
      dosya.print(" Mustafa Enes Ozkan  Numara : 20060149  ");
    }
    if (kisi == 3)
    {
      dosya.print(" Orhan Samı Genc Numara : 20060164    ");
    }
    if (kisi == 3)
    {
      dosya.print(" Musa Davut Sağlam Numara : 20060151    ");
    }
    if (kisi == 0)
    {
      dosya.print(" Kayıt Dısı Kart Okutuldu !!!  ");
      kisi = 0;
    }
    dosya.print("Kart ID: ");
    dosya.print(rfid.serNum[0]);
    dosya.print(",");
    dosya.print(rfid.serNum[1]);
    dosya.print(",");
    dosya.print(rfid.serNum[2]);
    dosya.print(",");
    dosya.print(rfid.serNum[3]);
    dosya.print(",");
    dosya.println(rfid.serNum[4]);
    dosya.close(); 
  }
  
    else {
    }
  delay(1000);
}
