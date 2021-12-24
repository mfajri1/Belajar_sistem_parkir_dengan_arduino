#include "SPI.h"
#include "DMD.h"
#include "TimerOne.h"
#include "SystemFont5x7.h"
#include "Arial_black_16.h"
#include "Time.h"
#include <Arial_Black_16_ISO_8859_1.h>
#include <Servo.h>
#include <DFPlayer_Mini_Mp3.h>

#define DISPLAYS_ACROSS 2
#define DISPLAYS_DOWN 1
DMD dmd( DISPLAYS_ACROSS , DISPLAYS_DOWN);

int buzzer = 12;
int smasuk = 35;
int skeluar = 37;

Servo portal;
Servo portal1;
int pos = 62; 
int pos1 = 40; 
int a = 0;
int b = 0;

const int UltrasonikTrig1 = 23;
const int UltrasonikEcho1 = 25;

const int UltrasonikTrig2 = 27;
const int UltrasonikEcho2 = 29;

const int UltrasonikTrig3 = 31;
const int UltrasonikEcho3 = 33;

void ScanDMD()
{
  dmd.scanDisplayBySPI();
  //dmd1.scanDisplayBySPI();
}

void setup() {
  Serial.begin(9600);
  Serial2.begin (9600); 
  Timer1.initialize( 4000 );
  Timer1.attachInterrupt( ScanDMD );
  dmd.clearScreen( true );
  dmd.selectFont(SystemFont5x7);
  portal.attach(A9);
  portal1.attach(A8);
  portal.write(pos); 
  portal1.write(pos1); 
  
  pinMode(UltrasonikTrig1, OUTPUT);
  pinMode(UltrasonikTrig2, OUTPUT);
  pinMode(UltrasonikTrig3, OUTPUT);
  pinMode(buzzer, OUTPUT);

  pinMode(UltrasonikEcho1, INPUT);
  pinMode(UltrasonikEcho2, INPUT);
  pinMode(UltrasonikEcho3, INPUT);
  pinMode(smasuk, INPUT);
  pinMode(skeluar, INPUT);

  mp3_set_serial (Serial2);  //set Serial for DFPlayer-mini mp3 module 
  mp3_set_volume (25);
  delay(100);
  mp3_play (1);

  judul();
  delay(500);
  nama();
  
}

long duration1, duration2, duration3 ; 
long inchi1, inchi2, inchi3;
long cm1, cm2, cm3 ;

// mulai program
void loop()
{
proses() ;
}


void mulai1() {
a = digitalRead(smasuk);
b = digitalRead(skeluar);
   if (a == LOW) {
     mp3_play (9);
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
    delay(5000);
    portal.write(pos);
    proses();
  }
  else {
    digitalWrite(buzzer, LOW);
    awal();
  }
  mulai1();
}


void blk(){
  digitalWrite(buzzer, HIGH);
  delay(500);
  digitalWrite(buzzer, LOW);
  delay(500);
}

