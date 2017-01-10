
//#include <time.h>

#include "Timing_function.h"
#include<malloc.h>


struct timing * Timing_start(  ) //struct timing * timeSTR
{
        struct timing * timeSTR;
        printf(" Timing_start \n");

        timeSTR = ( struct timing *) malloc( sizeof( struct timing ) ) ;


        Timing_init(timeSTR) ;


        timeSTR->start = clock();

        return timeSTR ;
}

void Timing_init(   struct timing * timeSTR )
{
        timeSTR->start = 0;
        timeSTR->finish = 0;
        timeSTR->duration = 0;

        //     Timing_show(timeSTR);

}



int Timing_finish(  struct timing * timeSTR )
{
        printf(" Timing_finish \n");

        timeSTR->finish = clock();

        timeSTR->duration = 0;

        timeSTR->duration = (double)( timeSTR-> finish - timeSTR-> start) / CLOCKS_PER_SEC;

        //     Timing_show(timeSTR);

        return 0;
}

void  Timing_destroy(  struct timing * timeSTR )
{
        free(timeSTR);


}



void Timing_show (   struct timing * timeSTR )
{
        char unit [ ] [10 ] = {{"ms"} , { "s"}, {"min"}, {"hour"}, {"day"}, {"years"} };
        int j = 0;

        int s, min, hour, day;
        int temp;
        double ms;

        temp = timeSTR->duration;

        ms = (timeSTR->duration - temp) * 1000;

        s = temp % 60;

        temp = temp / 60;
        min = temp % 60;

        temp = temp / 60;
        hour = temp % 24;

        temp = temp / 24;
        day = temp % 24;

        //  min = min % 60;
        j = 4;

        if (  day > 0 )
        {
                printf(" %d %s", day, unit [ j]);


        }
        j--;
        if (  hour > 0 )
        {
                printf(" %d %s", hour, unit [ j]);

        }
        j--;
        if (  min > 0 )
        {
                printf(" %d %s",  min, unit [ j]);

        }
        j--;
        if (  s >= 0 )
        {
                printf(" %d %s",  s, unit [ j]);

        }
        j--;
        if (  ms >= 0 )
        {
                printf(" %0.4lf %s",  ms, unit [ j]);

        }


        printf(" \n");
        //     timeSTR->duration ;

}



void dateInit ( struct  Date * day)
{
        day->day = 0;
        day-> year = 0;
        day-> month = 0;
        day-> day = 0;
        day-> hour = 0;
        day-> mins = 0;
        day-> s = 0;
        day-> ms = 0;

}

void dateShow(  struct  Date   date )
{
        char unit [ ] [10 ] = { {"ms"} , { "s"}, {"min"}, {"hour"}, {"day"}, {"mon"} , {"year"} };
        int j = 0;
        j = 6;

        if ( date. year > 0 )
        {
                printf(" %d %s", date. year, unit [ j]);


        }
        j--;

        if ( date.month > 0 )
        {
                printf(" %d %s", date.month, unit [ j]);


        }
        j--;


        if ( date. day > 0 )
        {
                printf(" %d %s", date.day, unit [ j]);


        }
        j--;
        if (  date.hour > 0 )
        {
                printf(" %d %s", date.hour, unit [ j]);

        }
        j--;

        if (  date.mins > 0 )
        {
                printf(" %d %s", date. mins, unit [ j]);

        }
        j--;
        if (date.  s > 0 )
        {
                printf(" %d %s",  date.s, unit [ j]);

        }
        j--;

        if (date.  ms > 0 )
        {
                printf(" %0.2lf %s", date.ms, unit [ j]);

        }


        printf(" \n");

}


int dateCheck( struct  Date    date )
{
        if (date.year < 0)
        {
                printf("  年份 错误\n");
                return -1;
        }

        if (( date.month < 0)  || (date.month > 12))
        {
                printf("  月份 错误\n");
                return -1;
        }

        if (( date.day < 0)  || (date.day >  look_Days_of_leap_years(date.year, date.month)))
        {
                printf("  日 错误\n");
                return -1;
        }

        if (( date.hour < 0)  || (date.hour > 24))
        {
                printf("  小时 错误\n");
                return -1;
        }
        if (( date.mins < 0)  || (date.mins > 12))
        {
                printf("  分钟 错误\n");
                return -1;
        }

        if (( date.s < 0)  || (date.s > 12))
        {
                printf("  秒 错误\n");
                return -1;
        }

        return 0;
}

void dateSet( struct  Date * date  )

{
        dateInit(date);

        printf("设置日期\n");

        printf("  年\n");
        scanf("%d", & date->year);

        printf("  月\n");
        scanf("%d",  & date->month);

        printf("  日\n");
        scanf("%d",   &date->day);

        printf("  小时\n");
        scanf("%d",  & date->hour);

        printf("  分钟\n");
        scanf("%d",   &date->mins);

        dateCheck(*date );

}


int look_Days_of_leap_years(int year, int month)
{
        int Fer = 0;

        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        {
                Fer = 1;

        }
        else
        {
                Fer = 0;
        }

        int days[ 13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        days[2] += Fer;

        return days[month] ;

}


//Get_Difference_between_days
int get_Difference_between_days(  struct Date old, struct Date  now)

{
        int days = 0;
        int y, m, d;

        y = old.year;
        m = old. month;
        d = old.day;

        do
        {

                d++;
                if (d >  look_Days_of_leap_years(y, m))
                {
                        d = d -  look_Days_of_leap_years(y, m);
                        m++;

                }
                if (m > 12)
                {
                        m = m - 12;
                        y++;
                }
                days++;
                if (    ((y == now.year) && (m == now.month) && (d == now. day)) )
                {

                        break ;
                }

        }
        while ( 1 );




        return days;

}


int get_Now_date  (  struct  Date * day)
{
        struct tm *local;
        time_t t;                     // 定义新数据类型存放秒数
        t = time(NULL);
        // 返回从1970年到现在的秒数
        local = localtime(&t);
        //printf("现在北京时间是%ld年%d月%d日%d点%d分%d秒\n",  local->tm_year + 1900, local->tm_mon + 1, local->tm_mday,             local->tm_hour, local->tm_min, local->tm_sec);

        dateInit( day);

        day->year = ( local->tm_year + 1900);
        day->month  = (local->tm_mon + 1);
        day->  day = (local->tm_mday);
        day-> hour = local->tm_hour;
        day-> mins =  local->tm_min;
        day-> s = local->tm_sec;
        day-> ms = 0;


        return 0;
}










int mn ()
{


        struct Date d1 = { 2016, 8, 8};
        struct Date  d2;
        int days = 0;

        get_Now_date(&d2);



        // printf ("\t  %d  %d   %d \n", d1.year, d1.month, d1.day);
        dateShow(d1);
        printf ("到现在\n");
        dateShow(d2);

        //    printf ("到现在\n\t  %d  %d   %d \n", d2.year, d2.month, d2.day);




        days = get_Difference_between_days(d1, d2);
        printf (" 共  %d   天 \n", days);

        dateSet(&d2);

        dateShow(d2);

        printf(  "结束\n");
        return 0;
}











