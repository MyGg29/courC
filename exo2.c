//Credit to Rodolphe for the idea;


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct date_ {
    int day;
    int month;
    int year;
} date;

int isLeapYear(int year);
int isEqual(date firstDate, date secDate); 
date addOne(date myDate); 

int daysPerMonths[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

date addOne(date myDate) {
    int daysInThisMonth;    
    myDate.day += 1;
    if(isLeapYear(myDate.year) && myDate.month == 2) {
        //index are scuffed because array start w/ 0 and dates w/ 1
        daysInThisMonth = daysPerMonths[myDate.month - 1] + 1;
    }
    else {
        daysInThisMonth = daysPerMonths[myDate.month - 1];
    }
    if(myDate.day >= daysInThisMonth) {
        myDate.day = 0;
        myDate.month += 1;
    }
    if(myDate.month > 12) {
        myDate.month = 1;
        myDate.year += 1;
    }

    return myDate;
}
int isEqual(date firstDate, date secDate) {
    if(firstDate.day == secDate.day &&
        firstDate.month == secDate.month &&
        firstDate.year == secDate.year) {
        
        return 1;
    }
    else {
        return 0;
    }
}
int isLeapYear(int year) {
    if((year % 4 == 0 && year % 100 != 0)||(year % 400 == 0)) {
        return 1;
    }
    else {
        return 0;
    }
}


int main(int argc, char* argv[]){
    date firstDate = {1,2,2001};
    date secDate = {1,12,2008};
    int daysBetween = 0;
    while(!isEqual(firstDate, secDate)) {
        firstDate = addOne(firstDate);
        daysBetween += 1;
        //printf("%d",firstDate.month);
    }
    printf("%d",daysBetween);
    return 0;
}
