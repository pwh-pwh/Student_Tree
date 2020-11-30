//
// Created by PWH on 2020/9/26.
//

#ifndef STUDENT_HEALTH_SYSTEM_DATE_H
#define STUDENT_HEALTH_SYSTEM_DATE_H
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;
class Date {

public:
    int year;
    int month;
    int day;
    Date(int year,int month,int day):year(year),month(month),day(day){

    }
    Date(){

    }
    friend ostream& operator<<(ostream& out,Date& date);

};


#endif //STUDENT_HEALTH_SYSTEM_DATE_H
