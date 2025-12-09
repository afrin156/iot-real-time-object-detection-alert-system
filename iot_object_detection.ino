#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define ultrasonic sensor pins
#define trigPin 7
#define echoPin 6

// Define buzzer pin
#define buzzerPin 8

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  lcd.init();
  lcd.backlight();
  Serial.begin(9600);

  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Tech Trends");
  delay(2000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Target Distance:");
}

void loop()
{
  long duration;
  int distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.print(" cm");

  if (distance > 0 && distance <= 20) {
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(buzzerPin, LOW);
  }

  delay(250);
}
