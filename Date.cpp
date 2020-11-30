//
// Created by CH on 2020/11/19.
//

#include "Date.h"
ostream& operator<<(ostream& out,Date& date){
    out<<date.year<<" "<<date.month<<" "<<date.day;
    return out;
}