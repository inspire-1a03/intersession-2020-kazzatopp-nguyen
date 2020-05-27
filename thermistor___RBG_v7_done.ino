/*
  Thermistor with RGB LED

  A red blue green light emitting diode (RGB LED) will change colour according to the temperature 
  read by the thermistor connected to analog pin 0. When the thermistor detects a temperature below 22°C, 
  the RBG LED emits white from pins 9, 10, and 11. When the temperature is between 22°C and 28°C, 
  the RBG LED emits green from pin 10. When the temperature is between 28°C and 30°C, the RBG LED emits yellow 
  from pins 10, 11, and medium-pitch sound sound will play from the buzzer. When the temperature is above 30°C, 
  the RBG LED emits red from pin 11, and a high-pitch sound will play from the buzzer.

  If you are unable to get a temperature above 30°C, try heating up the thermistor with your fingers!

  created May 26 2020
  by Kazza Topp-Nguyen
*/

#include <math.h>

#define ThermistorPIN 0                 // Analog Pin 0

float vcc = 4.91;                       // only used for display purposes, if used
                                        // set to the measured Vcc.
float pad = 9850;                       // balance/pad resistor value, set this to
                                        // the measured resistance of your pad resistor
float thermr = 10000;                   // thermistor nominal resistance

float Thermistor(int RawADC) {
  long Resistance;  
  float Temp;  // Dual-Purpose variable to save space.

  Resistance=pad*((1024.0 / RawADC) - 1);
  Temp = log(Resistance); // Saving the Log(resistance) so not to calculate  it 4 times later
  Temp = 1 / (0.001129148 + (0.000234125 * Temp) + (0.0000000876741 * Temp * Temp * Temp));
  Temp = Temp - 273.15;  // Convert Kelvin to Celsius                      

  // BEGIN- Remove these lines for the function not to display anything
  //Serial.print("ADC: ");
  //Serial.print(RawADC);
  //Serial.print("/1024");                           // Print out RAW ADC Number
  //Serial.print(", vcc: ");
  //Serial.print(vcc,2);
  //Serial.print(", pad: ");
  //Serial.print(pad/1000,3);
  //Serial.print(" Kohms, Volts: ");
  //Serial.print(((RawADC*vcc)/1024.0),3);  
  //Serial.print(", Resistance: ");
  //Serial.print(Resistance);
  //Serial.print(" ohms, ");
  // END- Remove these lines for the function not to display anything

  // Uncomment this line for the function to return Fahrenheit instead.
  //temp = (Temp * 9.0)/ 5.0 + 32.0;                  // Convert to Fahrenheit
  return Temp;                                        // Return the Temperature
}
 
int redPin = 11;
int greenPin = 10;
int bluePin = 9;
 
void setup()
{
  Serial.begin(115200);                               // starts serial monitor
  pinMode(redPin, OUTPUT);                            // sets digital pin 11 as output
  pinMode(greenPin, OUTPUT);                          // sets digital pin 10 as output
  pinMode(bluePin, OUTPUT);                           // sets digital pin 9 as output
}
 
void loop()
{
  float temp;
  temp=Thermistor(analogRead(ThermistorPIN));         // read ADC and  convert it to Celsius
  Serial.print("Celsius: ");
  Serial.print(temp,1);                               // display Celsius
  Serial.println("");  

if(temp > 30) {                                       // if the temperature is above 30°C
setColor(255, 0, 0);                                  // the RBG LED will emit red
tone(8, 700,1000);}                                   // and high-pitch sound will play from the buzzer

else if(temp > 28 & temp < 30){                       // if the temperature is between 28°C and 30°C
setColor(255, 200, 0);                                // the RBG LED will emit yellow
tone(8, 262,1000);}                                   // and medium-pitch sound sound will play from the buzzer

else if(temp > 22 & temp < 28){                       // if the temperature is between 22°C and 28°C
setColor(0, 255, 0);}                                 // the RBG LED will emit green 

else {setColor(255, 255, 255);}                       // if the temperature is below 22°C, the the RBG LED will emit white
  
delay(1000);                                          // wait 1 second
}
 
void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
