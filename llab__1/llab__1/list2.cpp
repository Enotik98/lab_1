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
    
    //смещение на количество
    virtual Date & addDays(int days = 1);
    virtual Date & subDays(int days = 1);
    virtual Date & addMonths(int months = 1);
    virtual Date & subMonths(int months = 1);
    virtual Date & addYears(int years = 1);
    virtual Date & subYears(int years = 1);
    
    
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
    void getWday(int dat, int month, int year);
    Date & addDays(int day = 1);
    Date & subDays(int day = 1);
    Date & addMonths(int months = 1);
    Date & subMonths(int months = 1);
    Date & addYears(int years = 1);
    Date & subYears(int years = 1);
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

Date & StructDate::addDays(int days){
    if(days < 0) return subDays(-days);
    while(days > 0){
        int monthDays = getDaysinMonth(month, year);
        if(day + days <= monthDays){
            day += days;
            day += days;
            days = 0;
        }else{
            days -= (monthDays - day +1);
            day = 1;
            if(++month > December) {
                month = January;
                year++;
            }
        }
    }
    return *this;
}

Date & StructDate::subDays(int days){
    if(days < 0) return addDays(-days);
    while(days > 0){
        if (days < day){
            day -= days;
            days = 0;
        }else{
            if(--month < January){
                month = December;
                year--;
            }
            days -= day;
            day = getDaysinMonth(month, year);
        }
    }
    return *this;
}

Date & StructDate::addMonths(int months){
    int limit = 0;
    if(month < 0) return subMonths(-month);
    year += months / 12;
    month += months % 12;
    if (month > December){
        month -= 12;
        year ++;
    }
    limit = getDaysinMonth(month, year);
    if(day > limit){
        day = limit;
    }
    return *this;
}

Date & StructDate::subMonths(int months){
    int limit = 0;
    if(months < 0) return addMonths(-months);
    year -= months / 12;
    month -= months % 12;
    if (month  < January){
        month += 12;
        year --;
    }
    limit = getDaysinMonth(months, year);
    if(day > limit){
        day = limit;
    }
    return *this;
}
Date & StructDate::addYears(int years){
    year += years;
    if(day == 29 && month == February && !IsLeapYear(year)){
        day = 28;
    }
    return *this;
}
Date & StructDate::subYears(int years){
    year -= years;
    if(day == 29 && month == February && !IsLeapYear(year)){
        day = 28;
    }
    return *this;
}
void StructDate::getWday(int dat, int month, int year){
    int kodMonth[] = {1,4,4,0,2,5,0,3,6,1,4,6};
    int kodYears = (6 + (year%100) + ((year%100)/4))%7;
    const char* wday [] = {"Saturday", "Sunday", "Monday","Tuesday","Wednesday","Thurthday","Friday"};
    int kodwday = (day + kodMonth[month - 1] + kodYears)%7;
    cout <<day<<"."<<month<<"."<<year<<"--> "<<wday[kodwday];
    
}



int main(){
    return 0;
}

