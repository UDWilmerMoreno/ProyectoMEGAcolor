#include <Arduino.h>
int R = 33;
int G = 35;
int B = 37;
const int s0 = 22;
const int s1 = 24;
const int s2 = 34;
const int s3 = 36;
const int out = 32;

byte countRed = 0;
byte countGreen = 0;
byte countBlue = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(out, INPUT);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  digitalWrite(s0, HIGH);
  digitalWrite(s1, HIGH);
}

void getColor()
{
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  countRed = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  digitalWrite(s3, HIGH);
  countBlue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  digitalWrite(s2, HIGH);
  countGreen = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
}

void loop()
{
  getColor();
  if (countRed < countBlue && countGreen > 100 && countRed < 80)
  {
    Serial.println("Rojo");
    digitalWrite(R, LOW);
    digitalWrite(G, HIGH);
    digitalWrite(B, HIGH);
  }
  else if (countBlue < countRed && countBlue < countGreen)
  {
    Serial.println("Azul");
    digitalWrite(R, HIGH);
    digitalWrite(G, HIGH);
    digitalWrite(B, LOW);
  }
  else if (countGreen < countRed && countGreen < countBlue)
  {
    Serial.println("Verde");
    digitalWrite(R, HIGH);
    digitalWrite(G, LOW);
    digitalWrite(B, HIGH);
  }
  else
  {
    Serial.println("Sin color");
    digitalWrite(R, HIGH);
    digitalWrite(G, HIGH);
    digitalWrite(B, HIGH);
  }
  delay(300);
}