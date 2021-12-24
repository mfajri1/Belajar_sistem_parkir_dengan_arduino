// proses program

void proses() {
a = digitalRead(smasuk);
b = digitalRead(skeluar);
  if (a == LOW) {
     digitalWrite(buzzer, HIGH);
     portal.write(0);
     delay(500);
     mp3_play (2);
    digitalWrite(buzzer, LOW);
    masuk();
    //delay(500);
    mulai();
  }
   if (b == LOW) {
    digitalWrite(buzzer, HIGH);
     portal.write(0);
     portal1.write(pos);
     delay(500);
    digitalWrite(buzzer, LOW);
    thanks();
     mulai1() ;
  }
  else {
    digitalWrite(buzzer, LOW);
  }
   awal();
  proses();
}


/// mulai programm
void mulai() {  
a = digitalRead(smasuk);
b = digitalRead(skeluar);
   if (b == LOW) {
    digitalWrite(buzzer, HIGH);
    delay(500);
     mp3_play (3);
    digitalWrite(buzzer, LOW);
    delay(5000);
    portal.write(pos);
    bacaultra();
  }
  else {
    digitalWrite(buzzer, LOW);
    awal();
  }
  mulai();
}

// baca ultrasonic

void bacaultra()
{
  awal();
  digitalWrite(UltrasonikTrig1, LOW);
  digitalWrite(UltrasonikTrig1, HIGH);
  
  digitalWrite(UltrasonikTrig2, LOW);
  digitalWrite(UltrasonikTrig2, HIGH);
  
  digitalWrite(UltrasonikTrig3, LOW);
   digitalWrite(UltrasonikTrig3, HIGH);
   
  delayMicroseconds(10);
  
  digitalWrite(UltrasonikTrig1, LOW);
  duration1 = pulseIn(UltrasonikEcho1, HIGH);
  
  digitalWrite(UltrasonikTrig2, LOW);
  duration2 = pulseIn(UltrasonikEcho2, HIGH);
  
  digitalWrite(UltrasonikTrig3, LOW);
  duration3 = pulseIn(UltrasonikEcho3, HIGH);
  
  
  cm1 = microsecondsKeCenti(duration1);
  cm2 = microsecondsKeCenti(duration2);
  cm3 = microsecondsKeCenti(duration3);

  Serial.print("1.Ultrasonik1 : ");
  Serial.print(cm1);
  Serial.print(" cm");
  Serial.print(" || ");
  Serial.print("1.Ultrasonik2 : ");
  Serial.print(cm2);
  Serial.print(" cm");
  Serial.print(" || ");
  Serial.print("1.Ultrasonik3 : ");
  Serial.print(cm3);
  Serial.print(" cm");
  Serial.println();

  if (cm1 < 30){
    portal1.write(160);
    bacaultra1();
    
  }

  delay(100);
  bacaultra();
}

long microsecondsKeCenti(long microseconds)
{
  return microseconds / 29 / 2;
}

// baca ultrasonic untuk parkir
void bacaultra1()
{
 
  digitalWrite(UltrasonikTrig1, LOW);
  digitalWrite(UltrasonikTrig1, HIGH);
  
  digitalWrite(UltrasonikTrig2, LOW);
  digitalWrite(UltrasonikTrig2, HIGH);
  
  digitalWrite(UltrasonikTrig3, LOW);
   digitalWrite(UltrasonikTrig3, HIGH);
   
  delayMicroseconds(10);
  
  digitalWrite(UltrasonikTrig1, LOW);
  duration1 = pulseIn(UltrasonikEcho1, HIGH);
  
  digitalWrite(UltrasonikTrig2, LOW);
  duration2 = pulseIn(UltrasonikEcho2, HIGH);
  
  digitalWrite(UltrasonikTrig3, LOW);
  duration3 = pulseIn(UltrasonikEcho3, HIGH);
  
  
  cm1 = microsecondsKeCenti(duration1);
  cm2 = microsecondsKeCenti(duration2);
  cm3 = microsecondsKeCenti(duration3);

  Serial.print("Ultrasonik1 : ");
  Serial.print(cm1);
  Serial.print(" cm");
  Serial.print(" || ");
  Serial.print("Ultrasonik2 : ");
  Serial.print(cm2);
  Serial.print(" cm");
  Serial.print(" || ");
  Serial.print("Ultrasonik3 : ");
  Serial.print(cm3);
  Serial.print(" cm");
  Serial.println();

  if (cm1 >=6 && cm1 <=10 && cm2 >= 5 && cm2 <=9 && cm3 >=5 && cm3 <=8 ){
    Serial.println("STOP");
     portal1.write(pos1);
    digitalWrite(buzzer, LOW);
     mp3_play (8);
     tampil1();
     delay(3000);
    proses();
  }

  else if (cm1 >=6 && cm1 <=15 && cm2 < 5  && cm3 > 4){
     Serial.println("PARKIR TERLALU KEKIRI");
     portal1.write(pos1);
     digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(buzzer, LOW);
     mp3_play (5);
     delay(3000);
     mp3_play (7);
     delay(4000);
    
  }

  else if (cm1 >=6 && cm1 <=15 && cm2 > 6  && cm3 < 4){
    portal1.write(pos1);
    Serial.println("PARKIR TERLALU KANAN");
    digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(buzzer, LOW);
    mp3_play (4);
     delay(3000);
     mp3_play (7);// modul mp3
     delay(4000);
    
  }

  else if (cm1 <=3 ){
    portal1.write(160);
    Serial.println("PARKIR TERLALU MUNDUR ");
    digitalWrite(buzzer, HIGH);
    mp3_play (6);
    delay(4000);
    digitalWrite(buzzer, LOW);
    
  }

  delay(100);
  bacaultra1();
}

long microsecondsKeCenti1(long microseconds1)
{
  return microseconds1 / 29 / 2;
}
