/*
    Autor: Yasin Boulahya Chairi
    Asignatura: Tecnología de Computadores - UNIR
    Actividad 2 Simon Dice en Arduino
    Descripcion: Simon Dice en Arduino con 6 botones y 3 LEDs opcion Multijugador
*/

//Include libreria para manejar pantalla LCD
#include <Adafruit_LiquidCrystal.h>
Adafruit_LiquidCrystal lcd_1(0);

int color1 = 0;
int color2 = 0;
int color3 = 0;
int color4 = 0;
int color5 = 0;
int color6 = 0;
int color7 = 0;
int color8 = 0;

void setup()
{
  lcd_1.begin(16, 2);
  pinMode(5, INPUT);
  pinMode(11, OUTPUT);
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
    tone(11, 165, 200); // tono 40 (E3 = 165 Hz)
    digitalWrite(4, HIGH);
    delay(1000); // Esperar 1000 milisegundos
    digitalWrite(4, LOW);
  }

  if (digitalRead(6) == HIGH && color1 == 0) {
    color1 = 3;
    tone(11, 220, 200); // tono 45 (A3 = 220 Hz)
    digitalWrite(3, HIGH);
    delay(1000); // Esperar 1000 milisegundos
    digitalWrite(3, LOW);
  }

  if (digitalRead(7) == HIGH && color1 == 0) {
    color1 = 2;
    tone(11, 294, 200); // tono 50 (D4 = 294 Hz)
    digitalWrite(2, HIGH);
    delay(1000); // Esperar 1000 milisegundos
    digitalWrite(2, LOW);
  }

  if (digitalRead(5) == HIGH && color2 == 0) {
    color2 = 4;
    tone(11, 165, 200); // tono 40 (E3 = 165 Hz)
    digitalWrite(4, HIGH);
    delay(1000); // Esperar 1000 milisegundos
    digitalWrite(4, LOW);
  }

  if (digitalRead(6) == HIGH && color2 == 0) {
    color2 = 3;
    tone(11, 220, 200); // tono 45 (A3 = 220 Hz)
    digitalWrite(3, HIGH);
    delay(1000); // Esperar 1000 milisegundos
    digitalWrite(3, LOW);
  }

  if (digitalRead(7) == HIGH && color2 == 0) {
    color2 = 2;
    tone(11, 294, 200); // tono 50 (D4 = 294 Hz)
    digitalWrite(2, HIGH);
    delay(1000); // Esperar 1000 milisegundos
    digitalWrite(2, LOW);
  }

  if (digitalRead(5) == HIGH && color3 == 0) {
    color3 = 4;
    tone(11, 165, 200); // tono 40 (E3 = 165 Hz)
    digitalWrite(4, HIGH);
    delay(1000); // Esperar 1000 milisegundos
    digitalWrite(4, LOW);
  }

  if (digitalRead(6) == HIGH && color3 == 0) {
    color3 = 3;
    tone(11, 220, 200); // tono 45 (A3 = 220 Hz)
    digitalWrite(3, HIGH);
    delay(1000); // Esperar 1000 milisegundos
    digitalWrite(3, LOW);
  }

  if (digitalRead(7) == HIGH && color3 == 0) {
    color3 = 2;
    tone(11, 294, 200); // tono 50 (D4 = 294 Hz)
    digitalWrite(2, HIGH);
    delay(1000); // Esperar 1000 milisegundos
    digitalWrite(2, LOW);
  }
  
  if (digitalRead(5) == HIGH && color4 == 0) {
    color4 = 4;
    tone(11, 165, 200); // tono 40 (E3 = 165 Hz)
    digitalWrite(4, HIGH);
    delay(1000); // Esperar 1000 milisegundos
    digitalWrite(4, LOW);
  }

  if (digitalRead(6) == HIGH && color4 == 0) {
    color4 = 3;
    tone(11, 220, 200); // tono 45 (A3 = 220 Hz)
    digitalWrite(3, HIGH);
    delay(1000); // Esperar 1000 milisegundos
    digitalWrite(3, LOW);
  }

  if (digitalRead(7) == HIGH && color4 == 0) {
    color4 = 2;
    tone(11, 294, 200); // tono 50 (D4 = 294 Hz)
    digitalWrite(2, HIGH);
    delay(1000); // Esperar 1000 milisegundos
    digitalWrite(2, LOW);
  }
  
  if (digitalRead(8) == HIGH && color5 == 0) {
    color5 = 4;
    tone(11, 165, 200); // tono 40 (E3 = 165 Hz)
    digitalWrite(4, HIGH);
    delay(1000); // Esperar 1000 milisegundos
    digitalWrite(4, LOW);
  }

  if (digitalRead(9) == HIGH && color5 == 0) {
    color5 = 3;
    tone(11, 220, 200); // tono 45 (A3 = 220 Hz)
    digitalWrite(3, HIGH);
    delay(1000); // Esperar 1000 milisegundos
    digitalWrite(3, LOW);
  }

  if (digitalRead(10) == HIGH && color5 == 0) {
    color5 = 2;
    tone(11, 294, 200); // tono 50 (D4 = 294 Hz)
    digitalWrite(2, HIGH);
    delay(1000); // Esperar 1000 milisegundos
    digitalWrite(2, LOW);
  }
  
  if (digitalRead(8) == HIGH && color6 == 0) {
    color6 = 4;
    tone(11, 165, 200); // tono 40 (E3 = 165 Hz)
    digitalWrite(4, HIGH);
    delay(1000); // Esperar 1000 milisegundos
    digitalWrite(4, LOW);
  }

  if (digitalRead(9) == HIGH && color6 == 0) {
    color6 = 3;
    tone(11, 220, 200); // tono 45 (A3 = 220 Hz)
    digitalWrite(3, HIGH);
    delay(1000); // Esperar 1000 milisegundos
    digitalWrite(3, LOW);
  }

  if (digitalRead(10) == HIGH && color6 == 0) {
    color6 = 2;
    tone(11, 294, 200); // tono 50 (D4 = 294 Hz)
    digitalWrite(2, HIGH);
    delay(1000); // Esperar 1000 milisegundos
    digitalWrite(2, LOW);
  }
 
  if (digitalRead(8) == HIGH && color7 == 0) {
    color7 = 4;
    tone(11, 165, 200); // tono 40 (E3 = 165 Hz)
    digitalWrite(4, HIGH);
    delay(1000); // Esperar 1000 milisegundos
    digitalWrite(4, LOW);
  }

  if (digitalRead(9) == HIGH && color7 == 0) {
    color7 = 3;
    tone(11, 220, 200); // tono 45 (A3 = 220 Hz)
    digitalWrite(3, HIGH);
    delay(1000); // Esperar 1000 milisegundos
    digitalWrite(3, LOW);
  }

  if (digitalRead(10) == HIGH && color7 == 0) {
    color7 = 2;
    tone(11, 294, 200); // tono 50 (D4 = 294 Hz)
    digitalWrite(2, HIGH);
    delay(1000); // Esperar 1000 milisegundos
    digitalWrite(2, LOW);
  }
  
  if (digitalRead(8) == HIGH && color8 == 0) {
    color8 = 4;
    tone(11, 165, 200); // tono 40 (E3 = 165 Hz)
    digitalWrite(4, HIGH);
    delay(1000); // Esperar 1000 milisegundos
    digitalWrite(4, LOW);
  }

  if (digitalRead(9) == HIGH && color8 == 0) {
    color8 = 3;
    tone(11, 220, 200); // tono 45 (A3 = 220 Hz)
    digitalWrite(3, HIGH);
    delay(1000); // Esperar 1000 milisegundos
    digitalWrite(3, LOW);
  }

  if (digitalRead(10) == HIGH && color8 == 0) {
    color8 = 2;
    tone(11, 294, 200); // tono 50 (D4 = 294 Hz)
    digitalWrite(2, HIGH);
    delay(1000); // Esperar 1000 milisegundos
    digitalWrite(2, LOW);
  }
  
  delay(100);

  if (color1 != 0 && 
     (color2 != 0 && 
     (color3 != 0 && 
     (color4 != 0 && 
     (color5 != 0 && 
     (color6 != 0 && 
     (color7 != 0 && 
      color8 != 0))))))) {
    if (color1 == color5 && (color2 == color6 && (color3 == color7 && color4 == color8))) {
      tone(11, 1661, 200); // tono 80 (G#6 = 1661 Hz)
      digitalWrite(4, HIGH);
      delay(200); 
      tone(11, 2217, 200); // tono 85 (C#7 = 2217 Hz)
      digitalWrite(3, HIGH);
      delay(200); 
      tone(11, 2960, 500); // tono 90 (F#7 = 2960 Hz)
      digitalWrite(2, HIGH);
      delay(500); 
      digitalWrite(2, LOW);
      delay(200); 
      digitalWrite(3, LOW);
      delay(200); 
      digitalWrite(4, LOW);

      
      Serial.println("Sucuencia bien hecha!!");
      lcd_1.print("CORRECTO!");

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

      tone(11, 92, 200); // tono 30 (F#2 = 92 Hz)
      Serial.println("Secuencia mal hecha!");
      Serial.println("Empieza de nuevo!");
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