/*
  Reaction Test

  A light emitting diode (LED) connected to digital pin 13 will turn on randomly 
  between 3 and 6 seconds and will be turned off when the button connected to pin 7 is pressed. 
  The time between the light turning on and the button press will show on the serial monitor as the reaction time.
  The purpose of this program is to test your reflexes! Look out for comments on how your reaction time is progressing!

  The circuit:
  - LED attached from pin 13 to ground with 10K resistor
  - pushbutton attached to pin 7 from +5V
  - 10K resistor attached to pin 7 from ground

  created May 26 2020
  by Kazza Topp-Nguyen
*/

int led = 13;                                   //setting up led variable
int button = 7;                                 // setting up button variable

unsigned long start;                            // start is a variable for number storage
unsigned long timeend;                          // timeend is a variable for number storage
unsigned long timediff;                         // timediff is a variable for number storage

              
void setup() {                                  // the setup function runs once when you press reset or power the board
 
  Serial.begin(9600);                           //starts serial monitor
  pinMode(led, OUTPUT);                         //sets digital pin 13 as output
  pinMode(button, INPUT);                       //sets digital pin 7 as input
}

void loop() {                                   // the loop function runs over and over again forever

  digitalWrite(led, LOW);                       // turn the LED off by making the voltage LOW
  delay(random(3000, 6000));                    // wait for random time between 3 and 6 seconds
  digitalWrite(led, HIGH);                      // turn the LED on (HIGH is the voltage level)
  start = millis();                             // set start equal to number of milliseconds since led turned on
  while(digitalRead(button)==LOW)               // wait for button to be pressed


  timeend = millis();                           // set timeend equal to number of milliseconds since button pressed
  timediff = timeend - start;                   // set timediff equal to time since prgoram started minus the time the led turned on
  Serial.print("Your reaction time: ");         // prints the words "Your reaction time: "
  Serial.print(timediff/1000.0);                // prints the reaction time in seconds
  Serial.println(" seconds");                   // prints the word " seconds" and the ln moves cursor to next line

  if(timediff > 500) {                          // if the reaction time is greater than .5 seconds 
  Serial.println(" Too slow!");}                // print in the serial monitor " Too slow!" and move cursor to next line
  else if( timediff <= 500 & timediff > 300) {  // if the reaction time is between .5 and .3 seconds
  Serial.println("Better luck next time!");}    // print in the serial monitor "Better luck next time!" and move cursor to next line
  else if( timediff <= 300 & timediff > 230) {  // if the reaction time is between .3 and .23 seconds
  Serial.println("Still too slow!");}           // print in the serial monitor "Still too slow!" and move cursor to next line
  else if( timediff <= 230 & timediff > 200) {  // if the reaction time is between .23 and .2 seconds
  Serial.println("Good, but not great!");}      // print in the serial monitor "Good, but not great!" and move cursor to next line
  else if( timediff <= 200 & timediff > 180) {  // if the reaction time is between .2 and .18 seconds
  Serial.println("You're getting there!");}     // print in the serial monitor "You're getting there!" and move cursor to next line
  else if( timediff <= 180 & timediff > 160) {  // if the reaction time is between .18 and .16 seconds
  Serial.println("Well done!");}                // print in the serial monitor "Well done!" and move cursor to next line
  if (timediff <= 160) {                        // if the reaction time is less than .16 seconds
  Serial.println("New record!");}               // print in the serial monitor "New record!" and move cursor to next line
}
