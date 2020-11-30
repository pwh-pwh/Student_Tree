#ifndef STUDENT_HEALTH_SYSTEM_STUDENT_H
#define STUDENT_HEALTH_SYSTEM_STUDENT_H
//学号、姓名、出生日期、性别、身体状况
#include <iostream>
#include <cstring>
#include "Date.h"
using namespace std;
class Student {
public:
    int id;
    string name;
    Date birthday;
    int gender; //1为男，2为女
    string health;
    Student(int id,string name,Date birthday,int gender,string health):id(id),name(name),health(health),birthday(birthday){

    }
    Student(){}
    void toString(){
        cout<<"学号 ："<<id<<"  "<<"姓名 ："<<name<<" "<<"健康状况 ："
            <<health<<" 生日 ："<<birthday<<" 性别 ：";
        if(gender==1){
            cout<<"男"<<endl;
        }else{
            cout<<"女"<<endl;
        }
    }
    void input(){
        cout<<"请分别输入学号、姓名、出生日期(格式为年 月 日)、性别(1为男，2为女)、身体状况（已空格分隔）"<<endl;
        
        cin>>this->id>>this->name>>this->birthday.year
           >>this->birthday.month>>this->birthday.day>>this->gender>>this->health;
    }
bool operator<(Student &s){
    return this->id<s.id;
    }
    bool operator>(Student &s){
        return this->id<s.id;
    }

    bool operator==(Student &s){
        return this->id==s.id;
    }
    void operator=(Student s){
        this->id=s.id;
        this->name=*new string(s.name);
        this->gender=s.gender;
        this->health=*new string(s.health);
        this->birthday=*new Date(s.birthday.year,s.birthday.month,s.birthday.day);

    }



};


#endif //STUDENT_HEALTH_SYSTEM_STUDENT_H

