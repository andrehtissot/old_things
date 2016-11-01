#ifndef _UTILS_DATE_AND_TIME_TIME_CPP_
#define _UTILS_DATE_AND_TIME_TIME_CPP_

#include <time.h>
#include <string>
#include <cstdio>
#include <iomanip>
#include <stdlib.h>
#include <cctype>
#include "Time.h"
using namespace Utils::DateAndTime;

Time::Time() {
  this->hour = 
  this->minute = 
  this->second = 
  this->microsecond = 
  this->utcHourOffset = 
  this->utcMinuteOffset = 0;
};

Time::Time(short const hour, short const minute, short const second, int const microsecond, short const utcHourOffset, short const utcMinuteOffset){
  this->hour = hour;
  this->minute = minute;
  this->second = second;
  this->microsecond = microsecond;
  this->utcHourOffset = utcHourOffset;
  this->utcMinuteOffset = utcMinuteOffset;
};

Time::~Time(){}

const short Time::getHour() const{
  return this->hour;
}
void Time::setHour(short const hour){
  this->hour = hour;
}
const short Time::getFixedHour() const{
  return this->hour + this->utcHourOffset;
}
const short Time::getMinute() const{
  return this->minute;
}
void Time::setMinute(short const minute){
  this->minute = minute;
}
const short Time::getFixedMinute() const{
  return this->minute + this->utcMinuteOffset;
}
const short Time::getSecond() const{
  return this->second;
}
void Time::setSecond(short const second){
  this->second = second;
}
const int Time::getMicrosecond() const{
  return this->microsecond;
}
void Time::setMicrosecond(int const microsecond){
  this->microsecond = microsecond;
}
const short Time::getUTCHourOffset() const{
  return this->utcHourOffset;
}
void Time::setUTCHourOffset(short const utcHourOffset){
  this->utcHourOffset = utcHourOffset;
}
const short Time::getUTCMinuteOffset() const{
 return this->utcMinuteOffset;
}
void Time::setUTCMinuteOffset(short const utcMinuteOffset){
  this->utcMinuteOffset = utcMinuteOffset;
}

bool Time::operator==(const Time& otherTime) const{
  Time* timePointer = const_cast<Time*>(&otherTime);
  return this->operator==(timePointer);
}
bool Time::operator==(Time*& otherTime) const{
  return this->getFixedHour() == otherTime->getFixedHour() && this->getFixedMinute() == otherTime->getFixedMinute() && this->getSecond() == otherTime->getSecond();
}
bool Time::operator!=(const Time& otherTime) const{
  return !(this->operator==(otherTime));
}
bool Time::operator!=(Time*& otherTime) const{
  return !(this->operator==(otherTime));
}
bool Time::operator>(const Time& otherTime) const{
  Time* timePointer = const_cast<Time*>(&otherTime);
  return this->operator>(timePointer);
}
bool Time::operator>(Time*& otherTime) const{
  return this->getFixedHour() > otherTime->getFixedHour() || this->getFixedMinute() > otherTime->getFixedMinute() || this->getSecond() > otherTime->getSecond();
}
bool Time::operator<(const Time& otherTime) const{
  Time* timePointer = const_cast<Time*>(&otherTime);
  return this->operator<(timePointer);
}
bool Time::operator<(Time*& otherTime) const{
  return this->getFixedHour() < otherTime->getFixedHour() || this->getFixedMinute() < otherTime->getFixedMinute() || this->getSecond() < otherTime->getSecond();
}
bool Time::operator>=(const Time& otherTime) const{
  return !(this->operator<(otherTime));
}
bool Time::operator>=(Time*& otherTime) const{
  return !(this->operator<(otherTime));
}
bool Time::operator<=(const Time& otherTime) const{
  return !(this->operator>(otherTime));
}
bool Time::operator<=(Time*& otherTime) const{
  return !(this->operator>(otherTime));
}

std::string Time::format(std::string const format) const {
  std::stringstream formatted;
  for (int i = 0; i < format.size(); i++)
    formatted << this->formatFor(format[i]);
  return formatted.str();
}

std::string Time::formatFor(char const keyLetter) const {
  std::stringstream stream;
  stream << std::setfill('0');
  switch(keyLetter){
    case 'H':
      stream << std::setw(2) << this->getHour(); break;
    case 'i':
      stream << std::setw(2) << this->getMinute(); break;
    case 's':
      stream << std::setw(2) << this->getSecond(); break;
    case 'u':
      stream << this->getMicrosecond(); break;
    case 'P':
      if(this->getUTCHourOffset() || this->getUTCMinuteOffset() < 0)
        stream << '-' << std::setw(2) << -this->getUTCHourOffset();
      else
        stream << '+' << std::setw(2) << this->getUTCHourOffset();
      if(this->getUTCMinuteOffset() < 0)
        stream << ':' << std::setw(2) << -this->getUTCMinuteOffset();
      else
        stream << ':' << std::setw(2) << this->getUTCMinuteOffset();
      break;
    default:
      stream << keyLetter;
  }
  return stream.str();
}

Time* Time::now() {
  Time* timePointer = new Time();
  time_t timenow;
  time(&timenow);
  struct tm *current;
  current = gmtime(&timenow);
  long minute_count_global = ((((current->tm_year * 12) + current->tm_mon) * 31 + current->tm_mday) * 24 + current->tm_hour) * 60 + current->tm_min;
  current = localtime(&timenow);
  long minute_count_local = ((((current->tm_year * 12) + current->tm_mon) * 31 + current->tm_mday) * 24 + current->tm_hour) * 60 + current->tm_min;

  timePointer->hour = current->tm_hour;
  timePointer->minute = current->tm_min;
  timePointer->second = current->tm_sec;
  timePointer->microsecond = 0;

  timePointer->utcHourOffset = ((minute_count_local - minute_count_global) / 60);
  timePointer->utcMinuteOffset = (minute_count_local - minute_count_global) % 60;
  return timePointer;
}

void Time::loadFromString(std::string const value, std::string const format){
  int offset = 0;
  int microseconds = 0;
  int microsecond_skipped_steps = 0;
  int utcSignal = 1;
  int utcSignalOffset = 1;
  for (int i = 0; i < format.size(); i++){
    switch(format[i]){
      case 'Y':
        offset+=4;
        break;
      case 'm':
      case 'd':
        offset+=2;
        break;
      case 'H':
        this->setHour(atoi(value.substr(offset, 2).c_str()));
        offset+=2;
        break;
      case 'i':
        this->setMinute(atoi(value.substr(offset, 2).c_str()));
        offset+=2;
        break;
      case 's':
        this->setSecond(atoi(value.substr(offset, 2).c_str()));
        offset+=2;
        break;
      case 'u':
        microseconds = 0;
        microsecond_skipped_steps = offset;
        for(; microsecond_skipped_steps < value.size(); microsecond_skipped_steps++){
          if(isdigit(value.c_str()[microsecond_skipped_steps])){
            microseconds = (microseconds * 10) + atoi(value.substr(microsecond_skipped_steps, 1).c_str());
          } else
            break;
        }
        this->setMicrosecond(microseconds);
        offset = microsecond_skipped_steps;
        break;
      case 'P':
        utcSignal = value.at(offset) == '-' ? -1 : 1;
        utcSignalOffset = (utcSignal == -1 || value.at(offset) == '+') ? 1 : 0;
        this->setUTCHourOffset(atoi(value.substr(offset+utcSignalOffset, 3).c_str()) * utcSignal);
        this->setUTCMinuteOffset(atoi(value.substr(offset+3+utcSignalOffset, 2).c_str()) * utcSignal);
        offset+=6;
        break;
      default:
        offset++;
    }
  }
}

double Time::toHours() const{
  return (this->getFixedMinute() + ((this->getSecond() + ((double) this->getMicrosecond() / 1000)) / 60)) / 60 + this->getFixedHour();
}
#endif