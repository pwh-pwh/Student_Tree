#ifndef STUDENT_HEALTH_SYSTEM_STUDENT_H
#define STUDENT_HEALTH_SYSTEM_STUDENT_H
//ѧ�š��������������ڡ��Ա�����״��
#include <iostream>
#include <cstring>
#include "Date.h"
using namespace std;
class Student {
public:
    int id;
    string name;
    Date birthday;
    int gender; //1Ϊ�У�2ΪŮ
    string health;
    Student(int id,string name,Date birthday,int gender,string health):id(id),name(name),health(health),birthday(birthday){

    }
    Student(){}
    void toString(){
        cout<<"ѧ�� ��"<<id<<"  "<<"���� ��"<<name<<" "<<"����״�� ��"
            <<health<<" ���� ��"<<birthday<<" �Ա� ��";
        if(gender==1){
            cout<<"��"<<endl;
        }else{
            cout<<"Ů"<<endl;
        }
    }
    void input(){
        cout<<"��ֱ�����ѧ�š���������������(��ʽΪ�� �� ��)���Ա�(1Ϊ�У�2ΪŮ)������״�����ѿո�ָ���"<<endl;
        
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

