//Created 11/2/2021
//This code reads values from 10K Ohm thermistor and then coverts the readings into Celsius and Fahrenheit temperature readings


//Websites used for reference:
//    https://www.circuitbasics.com/arduino-thermistor-temperature-sensor-tutorial/
//    https://www.circuitbasics.com/how-to-set-up-an-lcd-display-on-an-arduino/



#include <LiquidCrystal.h>


//Setting Variables:
const int thermistorPin = 0; //Calling out the pin # that the thermistor is plugged into
const float R = 10; //resistor value used in circuit [kOhms]
const float B = 3950;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Setting up the pins on the Arduino
float C;
float F;


//Convert ADC value to Celsius 
float getTempC(float val){
  
  //Convert ADC value into resistor value  
  float Rt = R/((1023.0/val)-1.0);

  //Convert resistor value into Temperature
  float T0 = 23.1 + 273.15;
  float R0 = 10; //kOhms

  float T = ((1/T0) + (1/B)*log(Rt/R0));
  T = 1/T;
  T = T - 273.15; //Celsius
  Serial.print(T);
  Serial.println(" °C");

  return (T);
  }

//Convert Celsius to Fahrenheit
float degC2degF(float T){

  float Far = (T*(9.0/5.0)) + 32.0;

  Serial.print(Far);
  Serial.println(" °F");
  
  return (Far);
  }


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  lcd.begin(16, 2);  // Setting up the LCD with the columns and rows
  lcd.clear();       // Clears any text on LCD display 

  lcd.setCursor(0,0);
  lcd.print("Thermometer");
  delay(1000);
  lcd.clear();

}

void loop() {
  // put your main code here, to run repeatedly:
  
  //Reading ADC value
  float val = analogRead(thermistorPin);

  //Calculating temperature values
  C = getTempC(val);
  F = degC2degF(C);

  //Displaying to LCD screen
  lcd.setCursor(0,0);
  lcd.print(C);
  lcd.print(" deg C");
  lcd.setCursor(0, 1); // Writing text onto the second line now
  lcd.print(F);
  lcd.print(" deg F");
  delay(1000);
  lcd.clear();
  

}
