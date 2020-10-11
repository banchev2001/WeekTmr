 Files description:
 ================================================================================
 * DS3231_datasheet.pdf - Data sheet of DS3231 RTCC
 * DS3231_Library_Documentation.pdf - Library documentation by Henning Karlsen
 * RTC_DS3231_LCD_Test.ino - Main source code of the project - using Arduino IDE
 * /libraries/DS3231 contain Henning Karlsen free library with examples
 * /libraries/WeekTimerLibrary/ contain Stoian Banchev library for WeekTimer object 
 
 Board: Arduino nano
 
 Project Conception:
 ================================================================================
 The board have two timers with three layers. Each timer have output. Timer1 
 drives Output-1 (pin 14), Timer2 drives Output-2 (pin 15). Every lyer of timers 
 are connected in "OR" logic to output. Every layer have three settings "On time", "Off time" and 
 Day of week scheme.
 
 Logic Diagram:
 ================================================================================
 
 Timer1, Layer1 ---|
 Timer1, Layer2 ---|-|OR|-Output1 (pin 14)
 Timer1, Layer3 ---|
 
 Timer2, Layer1 ---|
 Timer2, Layer2 ---|-|OR|-Output2 (pin 15)
 Timer2, Layer3 ---|

 Timer settings:
 ==================================================================================
 Days: Days in week in wich timer work,  contain seven fields for every day of week.
 On Time: Hour and minutes of the day that timer start.
 Off Time: Hour and minutes of the day that timer stop.