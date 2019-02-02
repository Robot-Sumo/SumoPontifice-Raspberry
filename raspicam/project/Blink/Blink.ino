/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/
const int led_Rpin = 10;
const int led_Gpin = 11;
const int led_Bpin = 12;

const int buzzer_pin = 9;
const int dur = 20;
int selector = 0;

enum colores
{
rojo,
verde,
azul,
amarillo,
turquesa,
morado,
blanco,
off
};

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(led_Rpin, OUTPUT);
  pinMode(led_Gpin, OUTPUT);
  pinMode(led_Bpin, OUTPUT);
  pinMode(buzzer_pin, OUTPUT);
  selector = 0;
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(buzzer_pin, HIGH);
  delay(1);
  digitalWrite(buzzer_pin, LOW);
    
  ledColor(off);
  delay(80);
  ledColor(amarillo);
  delay(10);
 
  


  
  
  
                       // wait for a second
}



void ledColor(int color)
{
    switch(color)
    {
        case azul :
            digitalWrite(led_Rpin, LOW);
            digitalWrite(led_Gpin, LOW);
            digitalWrite(led_Bpin, HIGH);
            break;
        case rojo:
            digitalWrite(led_Rpin, HIGH);
            digitalWrite(led_Gpin, LOW);
            digitalWrite(led_Bpin, LOW); 
            break;
        case morado:
            digitalWrite(led_Rpin, HIGH);
            digitalWrite(led_Gpin, LOW);
            digitalWrite(led_Bpin, HIGH);
            break;
        case turquesa:
            digitalWrite(led_Rpin, LOW);
            digitalWrite(led_Gpin, HIGH);
            digitalWrite(led_Bpin, HIGH);
            break;
        case blanco:
            digitalWrite(led_Rpin, HIGH);
            digitalWrite(led_Gpin, HIGH);
            digitalWrite(led_Bpin, HIGH);
            break;
        case amarillo:
            digitalWrite(led_Rpin, HIGH);
            digitalWrite(led_Gpin, HIGH);
            digitalWrite(led_Bpin, LOW);
            break;
        case verde:
            digitalWrite(led_Rpin, LOW);
            digitalWrite(led_Gpin, HIGH);
            digitalWrite(led_Bpin, LOW);
            break;
        case off:
            digitalWrite(led_Rpin, LOW);
            digitalWrite(led_Gpin, LOW);
            digitalWrite(led_Bpin, LOW);
            break;


    }
    
}
