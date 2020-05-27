By: Kazza Topp-Nguyen

## Day 1: Reflection
<!--
In this section, provide a ~250 word reflection on your first day of the module, and discuss why you're interested in this module and what you hope to take away from it.
-->

Hello World!

Ever since I began university, I kept hearing the words like "coding" and "Python", but I had no idea what they meant. This prompted me to enroll in a free Introduction to Computer Science course on the Harvard Online website. I never kept up with the work and things got in the way. Starting this course today, I finally feel like I am getting the introduction to computer science that I was looking for. Most of the people in the class are also beginning from scratch and the class runs at a pace that I am comfortable with. 

The first day with Markdown was a good introduction because it was simple and easy to follow. Even after one day, I feel as if I am a little bit “in the know” because I can program Github Pages to italicize the words I want italicized. I am really looking forward to working with the package I received of random circuits because it looks like a bunch of random stuff. I am excited that by the end of the week I am going to actually understand what each piece is, what it does, and how I can use them to make something. I am excited to start day 2!

## Day 2: Results
[My Arduino Thermistor RGB Code](https://github.com/inspire-1a03/intersession-2020-kazzatopp-nguyen/blob/master/thermistor___RBG_v7_done.ino)

![A photo of an arduino circuit with a button](images/Button.jpg | width=100 "Arduino Circuit from the Button Example")

My device interprets its surrounding temperature and displays the temperature as a traffic light. At room temperature, between 22°C and 28°C, the RBG LED emits green for GO. When the temperature increases above 28°C, we are entering yellow and CAUTION. Caution also notifies the user with a medium-pitch sound. When the temperature exceeds 30°C, the RBG LED emits red for STOP and the user is met with an extremely annoying high-pitch sound. Below room temperature, or 22°C, the light is white. 

The most challenging part of creating this device was merging the RBG and thermistor sketches. You had to be very cautious of syntax and ensure you had a closed curly bracket for every open curly bracket. I was lucky enough to have a common anode, I could follow Dr. Brodeur and everything was pretty seamless. I was able to manipulate the code to add intermediate temperature readings and add sound from the buzzer. Overall, it was awesome!

## Arduino build-off results

[My Final Project Sketch](https://github.com/inspire-1a03/intersession-2020-kazzatopp-nguyen/blob/master/Reflex_test_v6.ino)

This device tests the user’s reaction times. The light emitting diode (LED) connected to digital pin 13 turns on randomly after 3 to 6 seconds. When the button connected to pin 7 is pressed, this turns off the LED. The time in milliseconds from when the button is pressed minus the time from when the light turns on is displayed in the serial monitor. To make the interface more user friendly, instead of showing just the number in milliseconds, I converted the number to seconds and added words to tell the user what that number means. When the user finishes the first loop they, the serial monitor shows, for example, “Your reaction time: 0.170 seconds!”. Then according to how quick their reaction time was, the next line will either congratulate them on an excellent reaction time or encourage them to keep trying! This occurs on a loop so the user can continually work on their reflexes and see their progress on the serial monitor, as previous times still show. 

This device has become increasingly useful in everyday life, as the majority of people are spending most of their time in isolation and without much external stimulus. This device keeps the user’s reflexes in check, cures boredom, and keeps the brain stimulated!

| Feature | Description | Other Notes |
|:---------:|:-------------:|:-------------:|
|**LED**| Turns on randomly every 3 to 6 seconds and begins the timer| Turns off when button is pressed            |
|**Button**| Turns off the light and stops the timer|When the timer stops the reaction time is sent to the serial monitor|
|**Serial Monitor**| Tells the user their reaction time | Comments are imbedded regarding the reaction time to encourage the user's progress |

```
if(timediff > 500) {                                 // if the reaction time is greater than .5 seconds 
Serial.println(" Too slow!");}                       // print in the serial monitor " Too slow!" and move cursor to next line
else if( timediff <= 500 & timediff > 300) {         // if the reaction time is between .5 and .3 seconds
Serial.println("Better luck next time!");}           // print in the serial monitor "Better luck next time!" and move cursor to next line
```

<iframe width="789" height="444" src="https://www.youtube.com/embed/52CBKDwjjVw" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>


## Final reflection & summary
<!--
In ~300 words:
- Summarize your experience in this module. What you learned, what you liked, what you found challenging.
- Reflect upon your learning and its relevance in your life.
-->

When the form to choose your modules came out on Avenue to learn, I earmarked the “Electronics for the Rest of Us!” module as the highlight of the course. I was not disappointed. I learned so much in such a short period of time and the material was really engaging. 

The most valuable part for me was learning to understand and type code into the Arduino software. I feel that I now have a meaningful base of the concept of “coding”. In high school I was tasked to create a Wikipedia page, so I copy and pasted some code, but I did not learn much and the tutorials online were overwhelming. When I began university, it bothered me when I heard conversations about coding because I would not have anything to add. I tried to watch introduction videos for Computer Science or Python on YouTube, but other things always prioritized finishing them. I feel like I finally have been introduced to coding in the right way.

Though I do not interact with Arduinos or circuit boards in my everyday life, the concepts I learned in this module are valuable to me. I learned how important attention to detail is while coding. Extra focus while writing code can save lots of time in the end because if you get an error code, you need to search for your mistake. Another example is adding comments after a line of code to describe what that line does. This keeps your code organized and readable. These lessons are applicable to everyday life, as often catastrophes can often have been adverted by catching a simple mistake or keeping your work organized. When in person classes begin again, I will remember to keep an organized calendar to avoid any catastrophes. 

I found figuring out how to wire the Arduino and breadboard challenging not as intuitive. Since I am not familiar with electricity, trying to visualize the circuit was difficult and I did not have the same level of curiosity as learning to code. Having said that, I am very glad I had this experience because I felt very lost in the first few days and felt a sense of accomplishment when I could read the comments and wire the Arduino to create built-in examples. 

During this week, I have been looking at electronics from a completely different perspective. While I was playing the video game FIFA, I was imagining how incredibly difficult it would be to make the whole game from “if” and “while” statements. Absolutely mind boggling! I feel like I have been given a small insight into a world that I previously did not know much about, and I want to learn more. Overall, a very productive and fun week!

