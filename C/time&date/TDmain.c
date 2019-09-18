#include<stdio.h>
#include<stdlib.h>
#include"TD.h"

int main()
{
    int option = 0, DateOption = 0, TimeOption = 0;
    int hour,min,sec,format,day,mon,year,sumDays;
    while (option != -1)
    {
        printf("press 1 for Date \n");
        printf("press 2 for Time \n");
        printf("press -1 to exit \n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
        {   
            date_t *d1; 
            date_t *d2;
            DateOption = 0;
            d1 = Create_Date();
            
            if(d1==NULL)
                {break;}
            while (DateOption != -1)
            {
                printf("\npress 3 to create another date \n");
                printf("press 4 to add second date to first \n");
                printf("press 5 to update the first date \n");
                printf("press 6 to get the year \n");
                printf("press 7 to get the month \n");
                printf("press 8 to get the day \n");
                printf("press 9 to know if year is leap \n");
                printf("press -1 to exit \n");
                scanf("%d", &DateOption);
                switch (DateOption)
                {
                case 3:
                {   
                    
                    d2 = Create_Date();


                }
                break;
                case 4:
                {   
                    AddDate(d1,d2);
                }
                break;
                case 5:
                {
                    UpdateDate(d1);
                }
                break;
                case 6:
                {
                    printf("%d\n", getYear(d1));
                }
                break;
                case 7:
                {
                    printf("%d\n", getMonth(d1));
                }
                break;
                case 8:
                {
                    printf("%d\n", getDay(d1));
                }
                break;
                case 9:
                {
                    if(ifLeapYear(d1))
                    {   
                        printf("the year is leap\n");
                    }
                    else
                    {
                        printf(" year is not leap\n");
                    }
                    
                }   
                break;
                default:
                    break;
                }
            }
            free(d1);
            free(d2);
            
        }
       /* case 2:
      {
            cTime_t *time1;
            cTime_t *time2;
            time1 = malloc(sizeof(cTime_t));
            time2 = malloc(sizeof(cTime_t));
            printf("enter an hour ");
            scanf("%d", &hour);
            printf("enter an minutes ");
            scanf("%d", &min);
            printf("enter an seconds ");
            scanf("%d", &sec);
            updateT(time1, hour, min, sec);
            TimeOption=0;
            while (TimeOption != -1)
            {
                printf("\npress 3 to create another time \n");
                printf("press 4 to add second time to first \n");
                printf("press 5 to update the first date \n");
                printf("press 6 to get the year \n");
                printf("press 7 to get the month \n");
                printf("press 8 to get the day \n");
                printf("press 9 to know if year is leap \n");
                printf("press -1 to exit \n");
                scanf("%d", &DateOption);
                switch (TimeOption)
                {
                case 3:
                {   
                    
                    d2 = Create_Date();


                }
                break;
                case 4:
                {   
                    AddDate(d1,d2);
                }
                break;
                case 5:
                {
                    UpdateDate(d1);
                }
                break;
                case 6:
                {
                    printf("%d\n", getYear(d1));
                }
                break;
                case 7:
                {
                    printf("%d\n", getMonth(d1));
                }
                break;
                case 8:
                {
                    printf("%d\n", getDay(d1));
                }
                break;
                case 9:
                {
                    if(ifLeapYear(d1))
                    {   
                        printf("the year is leap\n");
                    }
                    else
                    {
                        printf(" year is not leap\n");
                    }
                    
                }   
                break;
                default:
                    break;
                }
            }
            printf("enter a format to print 1 or 2 ");
            scanf("%d", &format);
            printTime(time1, format);
            printf("the hour is: %d\n", getHour(time1));
            printf("the minutes are: %d\n", getMin(time1));
            printf("the seconds are: %d\n", getSec(time1));
            printf("now create one more time and add this time to the last time\n ");
            printf("enter an hour ");
            scanf("%d", &hour);
            printf("enter an minutes ");
            scanf("%d", &min);
            printf("enter an seconds ");
            scanf("%d", &sec);
            updateT(time2, hour, min, sec);
            add(time1, time2);
            printTime(time1, format);

        }*/
        }
    }
    return 0;
}

                   