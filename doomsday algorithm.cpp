#include <iostream>
#include <math.h>
using namespace std;

int DOOMS_ZERO= 3; //doomsday do ano zero 

int doomsday( int year){
    int century, doomsCentury,centCentury, dooms,centYear;
    century = (int)(year/100); 
    doomsCentury = (((century%4)*5) + DOOMS_ZERO )%7; 
    centYear =year-century*100;
    dooms = (centYear%28%4) + ((int)(centYear/4)*5); 
    dooms = (dooms + doomsCentury)%7;
 return dooms;
}

int weekday(int day,int  month, int  year){
    int dooms,ref=0;
    dooms = doomsday(year);
    if((year%4 == 0) && (year%100!=0)){ //is a leap year
        int doomsdays[]={32,29,0,4,9,6,11,8,5,10,7,12};
        ref = doomsdays[month-1];
    }
    else{
        int doomsdays[]={31,28,0,4,9,6,11,8,5,10,7,12};
        ref = doomsdays[month-1];
    }

    if((ref-day)>0){

        return ((7-(abs(ref-day)%7))+ dooms)%7;
    }
    else{

        return (abs(ref-day) + dooms)%7;
    }    
}

int main()
{
    const char *day[]={"sabado","domingo","segunda","terca","quarta","quinta","sexta"};

    printf("%s",day[weekday(28,1,2022)]);
    return 0;
}