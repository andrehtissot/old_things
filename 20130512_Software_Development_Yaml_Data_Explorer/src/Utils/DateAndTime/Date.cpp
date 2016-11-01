#ifndef _UTILS_DATE_AND_TIME_DATE_CPP_
#define _UTILS_DATE_AND_TIME_DATE_CPP_
#include <time.h>
#include <string>
#include <sstream>
#include <cstdio>
#include <iomanip>
#include <stdlib.h>
#include "Date.h"
using namespace Utils::DateAndTime;

Date::Date() {
  this->year = 0;
  this->month = this->day = 1;
};

Date::Date(short const year, short const month, short const day) {
  this->year = year;
  this->month = month;
  this->day = day;
};

Date::~Date(){}

const short Date::getYear() const{
  return this->year;
}

void Date::setYear(short const year){
  this->year = year;
}

const short Date::getMonth() const{
  return this->month;
}

void Date::setMonth(short const month){
  this->month = month;
}

const short Date::getDay() const{
  return this->day;
}

void Date::setDay(short const day){
  this->day = day;
}
bool Date::operator==(const Date& date) const{
  Date* datePointer = const_cast<Date*>(&date);
  return this->operator==(datePointer);
}
bool Date::operator==(Date*& date) const{
  return this->getYear() == date->getYear() && this->getMonth() == date->getMonth() && this->getDay() == date->getDay();
}
bool Date::operator!=(const Date& date) const{
  return !(this->operator==(date));
}
bool Date::operator!=(Date*& date) const{
  return !(this->operator==(date));
}
bool Date::operator>(const Date& date) const{
  Date* datePointer = const_cast<Date*>(&date);
  return this->operator>(datePointer);
}
bool Date::operator>(Date*& date) const{
  return this->getYear() > date->getYear() || this->getMonth() > date->getMonth() || this->getDay() > date->getDay();
}
bool Date::operator<(const Date& date) const{
  Date* datePointer = const_cast<Date*>(&date);
  return this->operator<(datePointer);
}
bool Date::operator<(Date*& date) const{
  return this->getYear() < date->getYear() || this->getMonth() < date->getMonth() || this->getDay() < date->getDay();
}
bool Date::operator>=(const Date& date) const{
  return !(this->operator<(date));
}
bool Date::operator>=(Date*& date) const{
  return !(this->operator<(date));
}
bool Date::operator<=(const Date& date) const{
  return !(this->operator>(date));
}
bool Date::operator<=(Date*& date) const{
  return !(this->operator>(date));
}

std::string Date::format(std::string format) const {
  std::stringstream formatted;
  for (int i = 0; i < format.size(); i++)
    formatted << this->formatFor(format[i]);
  return formatted.str();
}

std::string Date::formatFor(char const keyLetter) const {
  std::stringstream stream;
  stream << std::setfill('0');
  switch(keyLetter){
    case 'Y':
      stream << std::setw(4) << this->getYear(); break;
    case 'm':
      stream << std::setw(2) << this->getMonth(); break;
    case 'd':
      stream << std::setw(2) << this->getDay(); break;
    default:
      stream << keyLetter;
  }
  return stream.str();
}

Date* Date::today(){
  Date* date = new Date();
  time_t timenow;
  time(&timenow);
  struct tm *current;
  current = localtime(&timenow);
  date->year = current->tm_year+1900;
  date->month = current->tm_mon+1;
  date->day = current->tm_mday;
  return date;
}

void Date::loadFromString(std::string const value, std::string const format){
  int offset = 0;
  int microsecond_skipped_steps = 0;
  for (int i = 0; i < format.size(); i++){
    switch(format[i]){
      case 'H':
      case 'i':
      case 's':
        offset+=2;
        break;
      case 'P':
        offset+=6;
        break;
      case 'u':
        microsecond_skipped_steps = offset;
        for(; microsecond_skipped_steps < value.size(); microsecond_skipped_steps++)
          if(!isdigit(value.c_str()[microsecond_skipped_steps]))
            break;
        offset = microsecond_skipped_steps;
        break;
      case 'Y':
        this->setYear(atoi(value.substr(offset, 4).c_str()));
        offset+=4;
        break;
      case 'm':
        this->setMonth(atoi(value.substr(offset, 2).c_str()));
        offset+=2;
        break;
      case 'd':
        this->setDay(atoi(value.substr(offset, 2).c_str()));
        offset+=2;
        break;
      default:
        offset++;
    }
  }
}

double Date::toHours() const {
  int* monthDays = new int[12];
  monthDays[0] = 31; monthDays[1] = 28; monthDays[2] = 31; monthDays[3] = 30;
  monthDays[4] = 31; monthDays[5] = 30; monthDays[6] = 31; monthDays[7] = 31;
  monthDays[8] = 30; monthDays[9] = 31; monthDays[10] = 30; monthDays[11] = 31;

  double total = (this->getYear() * 365 + this->getDay()) * 24;
  
  for(short m = this->getMonth() - 2; m >= 0; m--)
    total += monthDays[m] * 24;

  //If the month is after february and this is a leap year, adds a day
  if(this->getMonth() > 2 && (this->getYear() % 400 == 0 || (this->getYear() % 4 == 0 && this->getYear() % 100 != 0)))
    total += 24;

  //Count passed leap years days
  total += (((int) ((this->getYear() - 1) / 4)) - ((int) ((this->getYear() - 1) / 100)) + ((int) ((this->getYear() - 1) / 400))) * 24;

  delete [] monthDays;
  return total;
}

#endif