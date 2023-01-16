/*
    Autor: Yasin Boulahya Chairi
    Asignatura: Tecnología de Computadores - UNIR
    Actividad 2 Simon Dice en Arduino
    Descripcion: Simon Dice en Arduino con 6 botones y 3 LEDs opcion Multijugador
*/

//Include libreria para manejar pantalla LCD
#include <Adafruit_LiquidCrystal.h>
Adafruit_LiquidCrystal lcd_1(0);

//Definimos las notas en el sistema internacional y sus frecuencias:
#define NOTA_B0  31
#define NOTA_C1  33
#define NOTA_CS1 35
#define NOTA_D1  37
#define NOTA_DS1 39
#define NOTA_E1  41
#define NOTA_F1  44
#define NOTA_FS1 46
#define NOTA_G1  49
#define NOTA_GS1 52
#define NOTA_A1  55
#define NOTA_AS1 58
#define NOTA_B1  62
#define NOTA_C2  65
#define NOTA_CS2 69
#define NOTA_D2  73
#define NOTA_DS2 78
#define NOTA_E2  82
#define NOTA_F2  87
#define NOTA_FS2 93
#define NOTA_G2  98
#define NOTA_GS2 104
#define NOTA_A2  110
#define NOTA_AS2 117
#define NOTA_B2  123
#define NOTA_C3  131
#define NOTA_CS3 139
#define NOTA_D3  147
#define NOTA_DS3 156
#define NOTA_E3  165
#define NOTA_F3  175
#define NOTA_FS3 185
#define NOTA_G3  196
#define NOTA_GS3 208
#define NOTA_A3  220
#define NOTA_AS3 233
#define NOTA_B3  247
#define NOTA_C4  262
#define NOTA_CS4 277
#define NOTA_D4  294
#define NOTA_DS4 311
#define NOTA_E4  330
#define NOTA_F4  349
#define NOTA_FS4 370
#define NOTA_G4  392
#define NOTA_GS4 415
#define NOTA_A4  440
#define NOTA_AS4 466
#define NOTA_B4  494
#define NOTA_C5  523
#define NOTA_CS5 554
#define NOTA_D5  587
#define NOTA_DS5 622
#define NOTA_E5  659
#define NOTA_F5  698
#define NOTA_FS5 740
#define NOTA_G5  784
#define NOTA_GS5 831
#define NOTA_A5  880
#define NOTA_AS5 932
#define NOTA_B5  988
#define NOTA_C6  1047
#define NOTA_CS6 1109
#define NOTA_D6  1175
#define NOTA_DS6 1245
#define NOTA_E6  1319
#define NOTA_F6  1397
#define NOTA_FS6 1480
#define NOTA_G6  1568
#define NOTA_GS6 1661
#define NOTA_A6  1760
#define NOTA_AS6 1865
#define NOTA_B6  1976
#define NOTA_C7  2093
#define NOTA_CS7 2217
#define NOTA_D7  2349
#define NOTA_DS7 2489
#define NOTA_E7  2637
#define NOTA_F7  2794
#define NOTA_FS7 2960
#define NOTA_G7  3136
#define NOTA_GS7 3322
#define NOTA_A7  3520
#define NOTA_AS7 3729
#define NOTA_B7  3951
#define NOTA_C8  4186
#define NOTA_CS8 4435
#define NOTA_D8  4699
#define NOTA_DS8 4978

#define BUZZER_PIN 11

int color1 = 0;
int color2 = 0;
int color3 = 0;
int color4 = 0;
int color5 = 0;
int color6 = 0;
int color7 = 0;
int color8 = 0;

int pines[3] = {5, 6, 7};
int colores[3] = {4,3,2};
int notasBuzzer[3] = {NOTA_E3, NOTA_A3, NOTA_D4};


//Reproduce sonido ACERTAR cada vez que el jugador finaliza una secuencia con exito
void reproduceSonidoAcierto() {
    tone(BUZZER_PIN, NOTA_E4);
    delay(150);
    tone(BUZZER_PIN, NOTA_G4);
    delay(150);
    tone(BUZZER_PIN, NOTA_E5);
    delay(150);
    tone(BUZZER_PIN, NOTA_C5);
    delay(150);
    tone(BUZZER_PIN, NOTA_D5);
    delay(150);
    tone(BUZZER_PIN, NOTA_G5);
    delay(150);
    noTone(BUZZER_PIN);
}

void gameOver() {
    Serial.print("Game over!");
    delay(200);

    //Reproduce el sonido Wah-Wah-Wah-Wah cuando no aciertas
    tone(BUZZER_PIN, NOTA_DS5);
    delay(300);
    tone(BUZZER_PIN, NOTA_D5);
    delay(300);
    tone(BUZZER_PIN, NOTA_CS5);
    delay(300);
    for (byte i = 0; i < 10; i++) {
        for (int pitch = -10; pitch <= 10; pitch++) {
        tone(1, NOTA_C5 + pitch);
        delay(5);
        }
    }
    noTone(BUZZER_PIN);
    delay(500);
}

void leeBotones1(){
  for(int i=0; i<=3; i++){
    if (digitalRead(pines[i]) == HIGH && colores[i] != 0) {
      colores[i]; //color1 = 4;
      tone(BUZZER_PIN, notasBuzzer[i], 200);
      digitalWrite(colores[i], HIGH);
      delay(1000);
      digitalWrite(colores[i], LOW);
    }
  }
}



void setup()
{
  lcd_1.begin(16, 2);
  pinMode(5, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, INPUT);
  pinMode(3, OUTPUT);
  pinMode(7, INPUT);
  pinMode(2, OUTPUT);

  Serial.begin(9600);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
}

void loop()
{
  if (digitalRead(5) == HIGH && color1 == 0) {
    color1 = 4;
    tone(BUZZER_PIN, NOTA_E3, 200);
    digitalWrite(4, HIGH);
    delay(1000);
    digitalWrite(4, LOW);
  }

  if (digitalRead(6) == HIGH && color1 == 0) {
    color1 = 3;
    tone(BUZZER_PIN, NOTA_A3, 200);
    digitalWrite(3, HIGH);
    delay(1000); 
    digitalWrite(3, LOW);
  }

  if (digitalRead(7) == HIGH && color1 == 0) {
    color1 = 2;
    tone(BUZZER_PIN, NOTA_D4, 200); 
    digitalWrite(2, HIGH);
    delay(1000); 
    digitalWrite(2, LOW);
  }

  if (digitalRead(5) == HIGH && color2 == 0) {
    color2 = 4;
    tone(BUZZER_PIN, NOTA_E3, 200); 
    digitalWrite(4, HIGH);
    delay(1000); 
    digitalWrite(4, LOW);
  }

  if (digitalRead(6) == HIGH && color2 == 0) {
    color2 = 3;
    tone(BUZZER_PIN, NOTA_A3, 200); 
    digitalWrite(3, HIGH);
    delay(1000); 
    digitalWrite(3, LOW);
  }

  if (digitalRead(7) == HIGH && color2 == 0) {
    color2 = 2;
    tone(BUZZER_PIN, NOTA_D4, 200);
    digitalWrite(2, HIGH);
    delay(1000); 
    digitalWrite(2, LOW);
  }

  if (digitalRead(5) == HIGH && color3 == 0) {
    color3 = 4;
    tone(BUZZER_PIN, NOTA_E3, 200);
    digitalWrite(4, HIGH);
    delay(1000); 
    digitalWrite(4, LOW);
  }

  if (digitalRead(6) == HIGH && color3 == 0) {
    color3 = 3;
    tone(BUZZER_PIN, NOTA_A3, 200); 
    digitalWrite(3, HIGH);
    delay(1000); 
    digitalWrite(3, LOW);
  }

  if (digitalRead(7) == HIGH && color3 == 0) {
    color3 = 2;
    tone(BUZZER_PIN, NOTA_D4, 200); 
    digitalWrite(2, HIGH);
    delay(1000);
    digitalWrite(2, LOW);
  }
  
  if (digitalRead(5) == HIGH && color4 == 0) {
    color4 = 4;
    tone(BUZZER_PIN, NOTA_E3, 200); 
    digitalWrite(4, HIGH);
    delay(1000); 
    digitalWrite(4, LOW);
  }

  if (digitalRead(6) == HIGH && color4 == 0) {
    color4 = 3;
    tone(BUZZER_PIN, NOTA_A3, 200);
    digitalWrite(3, HIGH);
    delay(1000); 
    digitalWrite(3, LOW);
  }

  if (digitalRead(7) == HIGH && color4 == 0) {
    color4 = 2;
    tone(BUZZER_PIN, NOTA_D4, 200); 
    digitalWrite(2, HIGH);
    delay(1000); 
    digitalWrite(2, LOW);
  }
  
  if (digitalRead(8) == HIGH && color5 == 0) {
    color5 = 4;
    tone(BUZZER_PIN, NOTA_E3, 200); 
    digitalWrite(4, HIGH);
    delay(1000); 
    digitalWrite(4, LOW);
  }

  if (digitalRead(9) == HIGH && color5 == 0) {
    color5 = 3;
    tone(BUZZER_PIN, NOTA_A3, 200); 
    digitalWrite(3, HIGH);
    delay(1000); 
    digitalWrite(3, LOW);
  }

  if (digitalRead(10) == HIGH && color5 == 0) {
    color5 = 2;
    tone(BUZZER_PIN, NOTA_D4, 200); 
    digitalWrite(2, HIGH);
    delay(1000); 
    digitalWrite(2, LOW);
  }
  
  if (digitalRead(8) == HIGH && color6 == 0) {
    color6 = 4;
    tone(BUZZER_PIN, NOTA_E3, 200); 
    digitalWrite(4, HIGH);
    delay(1000); 
    digitalWrite(4, LOW);
  }

  if (digitalRead(9) == HIGH && color6 == 0) {
    color6 = 3;
    tone(BUZZER_PIN, NOTA_A3, 200); 
    digitalWrite(3, HIGH);
    delay(1000); 
    digitalWrite(3, LOW);
  }

  if (digitalRead(10) == HIGH && color6 == 0) {
    color6 = 2;
    tone(BUZZER_PIN, NOTA_D4, 200); 
    digitalWrite(2, HIGH);
    delay(1000); 
    digitalWrite(2, LOW);
  }
 
  if (digitalRead(8) == HIGH && color7 == 0) {
    color7 = 4;
    tone(BUZZER_PIN, NOTA_E3, 200); 
    digitalWrite(4, HIGH);
    delay(1000); 
    digitalWrite(4, LOW);
  }

  if (digitalRead(9) == HIGH && color7 == 0) {
    color7 = 3;
    tone(BUZZER_PIN, NOTA_A3, 200); 
    digitalWrite(3, HIGH);
    delay(1000); 
    digitalWrite(3, LOW);
  }

  if (digitalRead(10) == HIGH && color7 == 0) {
    color7 = 2;
    tone(BUZZER_PIN, NOTA_D4, 200); 
    digitalWrite(2, HIGH);
    delay(1000); 
    digitalWrite(2, LOW);
  }
  
  if (digitalRead(8) == HIGH && color8 == 0) {
    color8 = 4;
    tone(BUZZER_PIN, NOTA_E3, 200); 
    digitalWrite(4, HIGH);
    delay(1000); 
    digitalWrite(4, LOW);
  }

  if (digitalRead(9) == HIGH && color8 == 0) {
    color8 = 3;
    tone(BUZZER_PIN, NOTA_A3, 200); 
    digitalWrite(3, HIGH);
    delay(1000); 
    digitalWrite(3, LOW);
  }

  if (digitalRead(10) == HIGH && color8 == 0) {
    color8 = 2;
    tone(BUZZER_PIN, NOTA_D4, 200); 
    digitalWrite(2, HIGH);
    delay(1000); 
    digitalWrite(2, LOW);
  }
  
  delay(100);

  if (color1 != 0 && (color2 != 0 && (color3 != 0 && (color4 != 0 && (color5 != 0 && (color6 != 0 && (color7 != 0 && color8 != 0))))))) {
    if (color1 == color5 && (color2 == color6 && (color3 == color7 && color4 == color8))) {
      tone(BUZZER_PIN, NOTA_F5, 200); 
      digitalWrite(4, HIGH);
      delay(200); 
      tone(BUZZER_PIN, NOTA_G5, 200); 
      digitalWrite(3, HIGH);
      delay(200); 
      tone(BUZZER_PIN, NOTA_A5, 600);
      digitalWrite(2, HIGH);
      delay(500); 
      digitalWrite(2, LOW);
      delay(200); 
      digitalWrite(3, LOW);
      delay(200); 
      digitalWrite(4, LOW);	

      
      Serial.println("Sucuencia bien hecha!!");
      lcd_1.print("CORRECTO!");
      reproduceSonidoAcierto();

      //Resetea las variables para la siguiente partida
      color1 = 0;
      color2 = 0;
      color3 = 0;
      color4 = 0;
      color5 = 0;
      color6 = 0;
      color7 = 0;
      color8 = 0;

      lcd_1.setCursor(0, 0);
       //Limpia pantalla LCD
      lcd_1.print("                                      ");
      lcd_1.setCursor(0, 0);
    } else {

      tone(11, 92, 200); 
      Serial.println("Secuencia mal hecha!");
      Serial.println("Empieza de nuevo!");
      gameOver();
      lcd_1.print("MAL!");

      //Resetea las variables para la siguiente partida
      color1 = 0;
      color2 = 0;
      color3 = 0;
      color4 = 0;
      color5 = 0;
      color6 = 0;
      color7 = 0;
      color8 = 0;
      lcd_1.setCursor(0, 0);
      //Limpia pantalla LCD
      lcd_1.print("                                      ");
      lcd_1.setCursor(0, 0);
    }
  }
  delay(200);
}
