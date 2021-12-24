//tampilan panel running text

void judul(){
 dmd.clearScreen( true );
 dmd.selectFont(Arial_Black_16_ISO_8859_1);
 dmd.drawMarquee("RANCANGAN PANDUAN PARKIR",24,(32*DISPLAYS_ACROSS)-1,0);
 long start=millis();
 long timer=start;
 boolean ret=false;
 while(!ret){
     if ((timer+40) < millis()) {
       ret=dmd.stepMarquee(-1,0);
       timer=millis();
     }
   } 
}

void nama(){
 dmd.clearScreen( true );
 dmd.selectFont(Arial_Black_16_ISO_8859_1);
 dmd.drawMarquee("M.SYAHPUTRA",12,(32*DISPLAYS_ACROSS)-1,0);
 long start=millis();
 long timer=start;
 boolean ret=false;
 while(!ret){
     if ((timer+40) < millis()) {
       ret=dmd.stepMarquee(-1,0);
       timer=millis();
     }
   } 
}

void tampil1(){
 dmd.clearScreen( true );
 dmd.selectFont(Arial_Black_16_ISO_8859_1);
 dmd.drawMarquee("TERIMAKASIH TELAH PARKIR DENGAN BAIK DAN BENAR",46,(32*DISPLAYS_ACROSS)-1,0);
 long start=millis();
 long timer=start;
 boolean ret=false;
 while(!ret){
     if ((timer+40) < millis()) {
       ret=dmd.stepMarquee(-1,0);
       timer=millis();
     }
   } 
}


void awal(){
dmd.selectFont(Arial_Black_16_ISO_8859_1);
dmd.drawString(6, 0, "PARKIR", 6, GRAPHICS_NORMAL);
delay(1000);
}

void masuk(){
delay(500);
dmd.selectFont(Arial_Black_16_ISO_8859_1);
dmd.drawString(2, 0, "WELCOM", 6, GRAPHICS_NORMAL);
delay(3000);
dmd.clearScreen( true );
}

void thanks(){
delay(500);
dmd.selectFont(Arial_Black_16_ISO_8859_1);
dmd.drawString(2, 0, "THANKS", 6, GRAPHICS_NORMAL);
delay(3000);
dmd.clearScreen( true );
}
