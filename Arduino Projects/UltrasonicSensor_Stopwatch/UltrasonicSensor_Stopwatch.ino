//Created 1/19/2022

//This program creates a simple stopwatch that counts up. The time is then displayed in seconds onto an LCD screen.
//An ultrasonic sensor is used as a "finish line" so that when something/someone gets close to the sensor, the timer stops.


//Setup for the LCD
#include <LiquidCrystal.h>


//Code help for ultrasonic sensor taken from: https://www.youtube.com/watch?v=ZejQOX69K5M&ab_channel=HowToMechatronics and previous Cal Poly Aero 321 class code


//Steps for simple filter for Ultrasonic Sensor measurements
// Filter Steps:
//    -for loop which steps through the array storing the values
//       -Each step through loop specifies a new index of the array to store the new measurement value
//       -At the end of the for loop the index is reset to 0 and the new values begin replacing the old values
//    -inner for loop with then sum up the elements of the array with the new value that is stored


//Setting up the pin numbers for the sensor
const int trigPin = 9;
const int echoPin = 10;

//Setup for the LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Setting up the pins on the Arduino and creating lcd object for functions


//Setting up the variables that will be used in the program
long duration; //Variable to store the duration returned by the echoPin
int measurement;  //Variable to store distance reading of Ultrasonic Sensor in function [cm]
int distance;  //Variable to store distance measurement value in main loop [cm]  
//Variables used for simple filtering of ultrasonic sensor measurements
int arrayofValues[10] = {}; //Array that will hold the measurements
int averageSum = 0; //Variable that will store the average sum of the always updating array
int sum = 0; //variable that will hold the array sum values during every iteration of loop
unsigned long startingTime;   //Holds the value when the stopwatch first starts
unsigned long currentTime;    //Holds each time value when stepping through the stopwatch loop
unsigned long stopwatchTime;  //Holds difference in currentTime and startingTime - This is in milliseconds
float displayTime;    //Holds the converted stopwatchTime that will be displayed in seconds
String user_input; // initializes variable that will hold the user input from the serial monitor




//Function to convert the calculated time into seconds and display it to the LCD Display
void timeDisplay (unsigned long watchTime){
  //Converting time into seconds
  displayTime = (float)watchTime / 1000.0;  //Converting time from milliseconds to seconds
  //Serial.println(displayTime);            //Prints Stopwatch time to the Serial Monitor

  //Displaying time on the LCD screen
  lcd.setCursor(0,0);
  lcd.print(displayTime);
  }


//Function to obtain distance reading from the Ultrasonic Sensor
int ultrasonicsensorDistance (){
  //Obtaining distance measurements from the Ultrasonic Sensor
  //Clearing the trigPin before sending out pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

   //Sets the trigPin on HIGH state for 10 micro seconds
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin, LOW);
          
   // Reads the echoPin, returns the sound wave travel time in microseconds
   duration = pulseIn(echoPin, HIGH);
  
   // Calculating the distance [cm]
   measurement = duration*0.034/2;

   return (measurement);
  }




void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);

  //Setup for the Ultrasonic Sensor
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input

  //Setup for the LCD Screen
  lcd.begin(16, 2);  // Setting up the LCD with the columns and rows
  lcd.clear();       // Clears any text on LCD display 

  lcd.setCursor(0,0);
  lcd.print("Write START");
  lcd.setCursor(0, 1); // Writing text onto the second line now
  lcd.print("to begin timer");
  //Serial.println("Write START to Begin Timer");
  delay(2000);  //Delay before starting main loop
  lcd.clear();

}

void loop() {
  // put your main code here, to run repeatedly:

   if(Serial.available()){
    user_input = Serial.readString();
    user_input.trim(); 
    
    //if user types in START, the "stopwatch" will begin counting up
    if(user_input == "START"){
      lcd.clear();                                   //Clearing LCD scrren before going into stopwatch loop
      
      startingTime = millis();                       //Get start time

      while(1){                                      //Until user types "STOP" the timer will keep counting up
        currentTime = millis();                      //Get current time
        stopwatchTime = currentTime - startingTime;  //Calculate the time that has elapsed since the start
        timeDisplay (stopwatchTime);                 //Convert time into seconds and display

        //Creating a filter by always storing 10 points. Once at capacity, old readings discareded to make space for new readings
        for(int i = 0; i < 10; i++){
          distance = ultrasonicsensorDistance();  //Call the self created function that gets the Ultrasonic Sensor measurements

          arrayofValues[i] = distance;
          //for loop to sum up array
          for(int j = 0; j < 10; j++){
            sum = arrayofValues[j] + sum;
          }
          averageSum = sum/10;
          //Serial.print(averageSum);
          //Serial.println(" cm");
          sum = 0; //reset sum variable for the next iteration of summing the array
 
        }
        //Checking to see if something is close to Ultrasonic sensor and should stop timer. Stop point set at 5 cm
        if(averageSum < 5){
          break;         //If something is close enough then break out of loop and stop timer. Timer will reset and restart when user types "START"
            }
      }
    }
  }

}
