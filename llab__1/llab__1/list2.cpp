#include <iostream>

using namespace std;

enum Month{
    January = 1, February, March, April, May, June, July, Augus, September, October, November, December,
};

class Date{
    
public:
    virtual ~Date(){}
    
    virtual int getDate() ;
    virtual void setDate(int day);
    virtual int getMonth() ;
    virtual void setMonth(int month);
    virtual int getYear() ;
    virtual void setYear(int year);
    
    //вывод
    virtual const char* getString();
};

class StructDate : public Date{
private:
    int day;
    int month;
    int year;
    int hour;
    int minute;
    int second;
public:
    StructDate(int day, int month, int year, int hour, int minute, int second);
    int getDate();
    void setDate(int day);
    int getMonth() ;
    void setMonth(int month);
    int getYear() ;
    void setYear(int year);
};



bool IsLeapYear(int year){
    return year % 4 == 0 &&(year%100 != 0 || year%400 == 0);
}
int getDaysinMonth(int month, int year){
    int monthLenght[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    return monthLenght[month-1]+(month == February && IsLeapYear(year));
}
const char* Date::getString(){
    const char* monthName[] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    char* result = new char[12];
    sprintf(result, "%2d - %s - %4d", getDate(), monthName[getMonth()- 1], getYear());
    return result;
}
void StructDate::setMonth(int month){
    int limit = 0;
    limit = getDaysinMonth(month, year);
    if(day > limit)
        day = limit;
}
void StructDate::setYear(int year){
    if(day == 29 && month == February && !IsLeapYear(year)) day = 28;
}
StructDate::StructDate(int day, int month, int year, int hour, int minute, int second){
    if(day > 31) {
        cout <<"wrong date in day";
        return;
    }
    int limit = 0;
    limit = getDaysinMonth(month, year);
    if(day > limit) {
        cout <<"wrong date in month";
        return;
    }
    if(day == 29 && month == February && !IsLeapYear(year)){
        cout <<"wrong date in year";
        return;
    }
    this->day = day;
    this->month = month;
    this->year = year;
    
    if (hour > 24){
        cout <<"wrong time in hour";
        return;
    }
    if(minute > 60){
        cout <<"wrong time in minute";
        return;
    }
    if(minute > 60){
        cout <<"wrong time in second";
        return;
    }
    this->hour = hour;
    this->minute = minute;
    this->second = second;
}
int main(){
    return 0;
}
