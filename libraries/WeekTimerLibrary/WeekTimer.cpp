#include "Arduino.h"
#include "WeekTimer.h"
#include "DS3231.h"

/***************************** Public ***************************/
char *WeekTimer::GetWeekPlanStr(){
	
	static char output[] = "-------";
	
	
	if(WeekPlan  & 0x80)output[6] = 'S'; //Test 7th bit of week plan if != 0 then set 6th char of output to S
	else output[6] = '-';
	if(WeekPlan  & 0x40)output[5] = 'S';
	else output[5] = '-';
	if(WeekPlan  & 0x20)output[4] = 'F';
	else output[4] = '-';
	if(WeekPlan  & 0x10)output[3] = 'T';
	else output[3] = '-'; 
	if(WeekPlan  & 0x08)output[2] = 'W';
	else output[2] = '-';
	if(WeekPlan  & 0x04)output[1] = 'T';
	else output[1] = '-';
	if(WeekPlan  & 0x02)output[0] = 'M';
	else output[0] = '-';
	
	//output[7] = '\0';
	
	return (char*)&output; 
	
}

void WeekTimer::EnableWD(int8_t DOW){
	
	WeekPlan |= 1UL << DOW; //Set Bit
	
}

void WeekTimer::DisableWD(int8_t DOW){
	
	WeekPlan &= ~(1UL << DOW); //Clear Bit
}

void WeekTimer::SetWeekPlanStr(const char* WeekPlanStr){
	
	for (int i = 0; i<7; i++){
		
		if (WeekPlanStr[i] != '-') EnableWD(i+1);
		
	}
		
}

int8_t WeekTimer::Check (int8_t DOW, int8_t currentHour, int8_t currentMinutes){
	
	
	if((WeekPlan  & 0x02) && (DOW == MONDAY)){ //IS MONDAY
	
		if ((_CombTime (currentHour, currentMinutes) >= _CombTime (OnHour, OnMinutes)) 
		&& (_CombTime (currentHour, currentMinutes) < _CombTime (OffHour, OffMinutes))) return 1;
	
		else  return 0;
	}
	
	if((WeekPlan  & 0x04) && (DOW == TUESDAY)){ //IS TUESDAY
	
		if ((_CombTime (currentHour, currentMinutes) >= _CombTime (OnHour, OnMinutes)) 
		&& (_CombTime (currentHour, currentMinutes) < _CombTime (OffHour, OffMinutes))) return 1;
	
		else  return 0;
	}
	
	if((WeekPlan  & 0x08) && (DOW == WEDNESDAY)){ //IS WEDNESDAY
	
		if ((_CombTime (currentHour, currentMinutes) >= _CombTime (OnHour, OnMinutes)) 
		&& (_CombTime (currentHour, currentMinutes) < _CombTime (OffHour, OffMinutes))) return 1;
	
		else  return 0;
	}
	
	if((WeekPlan  & 0x10) && (DOW == THURSDAY)){ //IS THURSDAY
	
		if ((_CombTime (currentHour, currentMinutes) >= _CombTime (OnHour, OnMinutes)) 
		&& (_CombTime (currentHour, currentMinutes) < _CombTime (OffHour, OffMinutes))) return 1;
	
		else  return 0;
	}
	
	if((WeekPlan  & 0x20) && (DOW == FRIDAY)){ //IS FRIDAY
	
		if ((_CombTime (currentHour, currentMinutes) >= _CombTime (OnHour, OnMinutes)) 
		&& (_CombTime (currentHour, currentMinutes) < _CombTime (OffHour, OffMinutes))) return 1;
	
		else  return 0;
	}
	
	if((WeekPlan  & 0x40) && (DOW == SATURDAY)){ //IS SATURDAY
	
		if ((_CombTime (currentHour, currentMinutes) >= _CombTime (OnHour, OnMinutes)) 
		&& (_CombTime (currentHour, currentMinutes) < _CombTime (OffHour, OffMinutes))) return 1;
	
		else  return 0;
	}
	
	if((WeekPlan  & 0x80) && (DOW == SUNDAY)){ //IS SUNDAY
	
		if ((_CombTime (currentHour, currentMinutes) >= _CombTime (OnHour, OnMinutes)) 
		&& (_CombTime (currentHour, currentMinutes) < _CombTime (OffHour, OffMinutes))) return 1;
	
		else  return 0;
	}
	
	else  return 0;
		       
}

void WeekTimer::SetOnTime(int8_t Hr, int8_t Min){
	OnHour = Hr;
	OnMinutes = Min;
} 
void WeekTimer::SetOffTime(int8_t Hr, int8_t Min){
	OffHour = Hr;
	OffMinutes = Min;	
}

void WeekTimer:: ValOnTime(void){
	
	if(_CombTime(OnHour,OnMinutes) > _CombTime(OffHour,OffMinutes)){
		
		OnHour = OffHour; OnMinutes = OffMinutes;
		
	}
	
}

void WeekTimer:: ValOffTime(void){
	
	if(_CombTime(OnHour,OnMinutes) > _CombTime(OffHour,OffMinutes)){
		
		OffHour = OnHour; OffMinutes = OnMinutes;
		
	}
	
}
/***************************** Private ***************************/

 int16_t WeekTimer::_CombTime (int8_t Hr, int8_t Min){
	 
	 return ( Hr << 8 | Min); //Merage bytes
	 
 }