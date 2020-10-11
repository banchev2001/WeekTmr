/*
  WeekTimer.cpp - Library for Implement a Week Timer function
  Created by S. Banchev, September 8, 2020.
  Released into the public domain.
*/

#ifndef _WEEKTIMER_H_
#define _WEEKTIMER_H_



#include "Arduino.h"

class WeekTimer  
{
public:
    
	/*************************** Vars *****************************************/
	int8_t WeekPlan; //Contain work days in week 1 for On 0 Off LSB don't care MSB is Sunday
    int8_t OnHour; // Contain Hour to on
    int8_t OnMinutes; //Contain Minutes to on
    int8_t OffHour; //Contain Hour to Off
    int8_t OffMinutes; //Contain Minutes to Off
		
	/************************* Input Methods *********************************/
                                                                   //SSFTWTM-  S-F-W-M
    void EnableWD(int8_t DOW); //Turn On Day of week that work timer 11111110 01010101
    void DisableWD(int8_t DOW); //Turn Off Day of week that work timer
	void SetWeekPlanStr(const char* WeekPlanStr); //Set week plan as a string like this "SS--WTM"
    
	void SetOnTime(int8_t Hr, int8_t Min);  //Set On  time with validating
	void SetOffTime(int8_t Hr, int8_t Min); //Set Off time with validating
	
	void ValOnTime(void);  // Validate time On Time
	void ValOffTime(void); // Validate Off Time
	
    /************************* Output Methods ********************************/
	char *GetWeekPlanStr(); // Convert Byte that contain work days in week "WDInWeek" to a string
    int8_t Check (int8_t DOW, int8_t Hour, int8_t Minutes); //Checking When timer to ON and OFF
	
private:

	int16_t _CombTime (int8_t Hr, int8_t Min);//Combine hour and minutes to one variable 
								//nesessery for Check, ValOnTime and ValOffTime methods
 
};

#endif
