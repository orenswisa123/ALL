#ifndef FUNCTIONS_TD
#define FUNCTIONS_TD

typedef struct{
    int day;
    int month;
    int year;
}date_t;

typedef struct{
    int sec;
    int min;
    int hour;
}cTime_t;

date_t* UpdateDate(date_t *d1);
void AddDate(date_t *d1,date_t *d2);
date_t* Create_Date();
int getDay(date_t *d1);
int getMonth(date_t *d1);
int getYear(date_t *d1);
void printdate(date_t *d1);
int ifLeapYear(date_t * d1);


cTime_t * update(cTime_t * time,int hour,int min,int sec); 
void printTime(cTime_t * time,int format);
int getHour(cTime_t * time);
int getMin(cTime_t * time);
int getSec(cTime_t * time);
cTime_t * add(cTime_t * time1,cTime_t * time2);

#endif


