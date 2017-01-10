

/*
#ifndef   bool
#define  bool

#define bool int
#define false 0
#define true 1



#endif // bool
*/



#ifndef TIMING_FUNCTION_H_INCLUDED
#define TIMING_FUNCTION_H_INCLUDED

#include <time.h>




struct timing
{

        clock_t start ;
        clock_t finish;
        double duration;
};

struct Date
{
        int year;
        int month;
        int day;
        int hour;
        int mins;
        int s;
        double ms;



};


struct timing * Timing_start( ) ;

int Timing_finish(struct timing * timeSTR );
void Timing_init(   struct timing * timeSTR );
void Timing_show (struct timing * timeSTR );
void  Timing_destroy(  struct timing * timeSTR );


void dateInit ( struct  Date * day) ;
int look_Days_of_leap_years(int year, int month);

int get_Difference_between_days(  struct Date old, struct Date  now);
void dateSet( struct  Date * date  ) ;
int get_Now_date  (  struct  Date * day);
int dateCheck( struct  Date   date );

#endif // TIMING_FUNCTION_H_INCLUDED
