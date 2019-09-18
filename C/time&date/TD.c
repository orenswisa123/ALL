#include <stdio.h>
#include <stdlib.h>
#include "TD.h"

static int CheckDate(int,int,int);
static char* MonthName(date_t*);


date_t* Create_Date()
{
    date_t *da1;
    int dd,mm,yy,ans=0;
    da1 = malloc(sizeof(date_t*));
    printf("Enter date (DD/MM/YYYY format): ");
    scanf("%d/%d/%d",&dd,&mm,&yy);
    ans=CheckDate(dd,mm,yy);
    if(ans!=0)
    {
        da1->day=dd;
        da1->month=mm;
        da1->year=yy;
        return da1;
    }
    else
    {
        printf("Date is not valid.\n");
        return NULL;
    }
}
void AddDate(date_t *d1,date_t *d2)
{
    int DTA2=d2->day;
    int mdays[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(((d1->year%4==0) && (d1->year%100!=0))||(d1->year%400==0))
    {
        mdays[1]=29;
    }
        d1->day=d1->day+DTA2;
    if( d1->day > mdays[d1->month-1])
    {
        d1->day = d1->day - mdays[d1->month - 1];
        (d1->month)++;
        if (d1->month > 12)
        {
            d1->month = 1;
            (d1->year)++;
        }

    }
    printf("the new date is: ");
    printdate(d1);
}
static int CheckDate(int dd,int mm,int yy)
{
     if(yy>=1900 && yy<=9999)
    {
        /*check month*/
        if(mm>=1 && mm<=12)
        {
            /*check days*/
            if((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12))
            {
                return 1; 
            }
            else if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm==9 || mm==11))
            {
                return 1; 
            }
            else if((dd>=1 && dd<=28) && (mm==2))
            {
                return 1;  
            }
            else if(dd==29 && mm==2 && (yy%400==0 ||(yy%4==0 && yy%100!=0)))
            {
                return 1;  
            }
            else
                
                return 0;
        }
        else
        {
            
            return 0;
        }
    }
    else
    {
        
        return 0;
    }
}

date_t* UpdateDate(date_t *d1)
{
    int dd,mm,yy,ans=0;
    printf("Enter date (DD/MM/YYYY format): ");
    scanf("%d/%d/%d",&dd,&mm,&yy);
    ans=CheckDate(dd,mm,yy);
    if(ans!=0)
    {
        d1->day=dd;
        d1->month=mm;
        d1->year=yy;
        printdate(d1);
        return d1;
    }
    else
    {
        printf("Date is not valid.\n");
        return NULL;
    }
}

void printdate(date_t *d1)
{
    char *Mname=NULL;
    Mname=MonthName(d1);
    printf("Date is : %d/%s/%d\n",d1->day,Mname,d1->year);
    printf("Date is : %d/%d/%d      European\n", d1->day, d1->month, d1->year);
    printf("Date is : %d/%d/%d      American\n", d1->month, d1->day, d1->year);
}
static char* MonthName(date_t *d1)
{
    static char *Mname=NULL; /*month name*/
    char *mday[13]={"Jan","Feb","March","April","May","June","July","Aug","Sep","Oct","Nov","Dec"};
    Mname=mday[d1->month-1];
    return Mname;
}
int getYear(date_t *d1)
{
    return d1->year;
}
int getMonth(date_t *d1)
{
    return d1->month;
}
int getDay(date_t *d1)
{
    return d1->day;
}
int ifLeapYear(date_t * d1)
{
    if (d1 != NULL)
    {
        if (d1->year % 4 == 0)
        {
            return 1;
        }
    }
    return 0;
}


cTime_t * updateT(cTime_t * time,int hour,int min,int sec){
   time->hour=hour;
   time->min=min;
   time->sec=sec;
   return time;

}

void printTime(cTime_t * time,int format){
if (time!=NULL){
  if(format==1){ 
    printf(" %d:%d:%d \n",time->hour,time->min,time->sec);
    
  }else if(format==2){
       
            printf(" %d:%d:%d  %s  \n",time->hour%12,time->min,time->sec,((time->hour)>=12)?"PM":"AM");
       
  }else{
     printf("your format is not good");
  }

}

}

int getHour(cTime_t * time){
 if (time!=NULL){

   return time->hour;
 }
 return 0;
}
int getMin(cTime_t * time){
  if (time!=NULL){

   return time->min;
  }
 return 0;
}
int getSec(cTime_t * time){
 if (time!=NULL){

   return time->sec;
 }
 return 0;
}


cTime_t * add(cTime_t * time1,cTime_t * time2){
  if ((time1!=NULL)&&(time2!=NULL)){

     int secD,minD;
     secD=(time1->sec+time2->sec)/60;
     minD=(time1->min+time2->min+secD)/60;
     time1->sec=(time1->sec+time2->sec)%60;
     time1->min=(time1->min+time2->min+secD)%60;
     time1->hour=(time1->hour+time2->hour+minD)%24;
     
     return time1;

   }
 return NULL;

}
