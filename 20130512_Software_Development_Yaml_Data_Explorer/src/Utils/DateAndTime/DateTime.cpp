#ifndef _UTILS_DATE_AND_TIME_DATE_TIME_CPP_
#define _UTILS_DATE_AND_TIME_DATE_TIME_CPP_
#include <time.h>
#include <string>
#include <cstdio>
#include <iomanip>
#include "Date.cpp"
#include "Time.cpp"
#include "DateTime.h"
using namespace Utils::DateAndTime;

DateTime::DateTime() : Date(),Time() {};
DateTime::DateTime(short const year, short const month, short const day, short const hour, short const minute, short const second, int const microsecond, short const utcHourOffset, short const utcMinuteOffset) :
  Date(year, month, day),
  Time(hour, minute, second, microsecond, utcHourOffset, utcMinuteOffset){};
DateTime::~DateTime(){};

bool DateTime::operator==(const DateTime& dateTime) const{
  return Date::operator==(dateTime) && Time::operator==(dateTime);
}
bool DateTime::operator==(DateTime*& dateTime) const{
	Date* dateTimeAsDate = dynamic_cast<Date*>(dateTime);
	Time* dateTimeAsTime = dynamic_cast<Time*>(dateTime);
  return ((Date*) this)->operator==(dateTimeAsDate) && ((Time*) this)->operator==(dateTimeAsTime);
}
bool DateTime::operator!=(const DateTime& dateTime) const{
  return !(this->operator==(dateTime));
}
bool DateTime::operator!=(DateTime*& dateTime) const{
  return !(this->operator==(dateTime));
}
bool DateTime::operator>(const DateTime& dateTime) const{
	return Date::operator>(dateTime) || (Date::operator==(dateTime) && Time::operator>(dateTime));
}
bool DateTime::operator>(DateTime*& dateTime) const{
	Date* dateTimeAsDate = dynamic_cast<Date*>(dateTime);
	Time* dateTimeAsTime = dynamic_cast<Time*>(dateTime);
	return ((Date*) this)->operator>(dateTimeAsDate) || (((Date*) this)->operator==(dateTimeAsDate) &&  ((Time*) this)->operator>(dateTimeAsTime));
}
bool DateTime::operator<(const DateTime& dateTime) const{
	return Date::operator<(dateTime) || (Date::operator==(dateTime) && Time::operator<(dateTime));
}
bool DateTime::operator<(DateTime*& dateTime) const{
	Date* dateTimeAsDate = dynamic_cast<Date*>(dateTime);
	Time* dateTimeAsTime = dynamic_cast<Time*>(dateTime);
	return ((Date*) this)->operator<(dateTimeAsDate) || (((Date*) this)->operator==(dateTimeAsDate) &&  ((Time*) this)->operator<(dateTimeAsTime));
}
bool DateTime::operator>=(const DateTime& dateTime) const{
	return !(this->operator<(dateTime));
}
bool DateTime::operator>=(DateTime*& dateTime) const{
	return !(this->operator<(dateTime));
}
bool DateTime::operator<=(const DateTime& dateTime) const{
	return !(this->operator>(dateTime));
}
bool DateTime::operator<=(DateTime*& dateTime) const{
	return !(this->operator>(dateTime));
}

std::string DateTime::format(std::string const format) const {
  std::stringstream formatted;
  std::string dateResult;
  for (int i = 0; i < format.size(); i++){
  	dateResult = this->Date::formatFor(format[i]);
  	if(dateResult.length() == 1 && dateResult[0] == format[i])
  		formatted << this->Time::formatFor(format[i]);
  	else
  		formatted << dateResult;
  }
  return formatted.str();
}

DateTime* DateTime::now(){
  DateTime* dateTime = new DateTime();
  time_t timenow;
  time(&timenow);
  struct tm *current;
  current = gmtime(&timenow);
  long minute_count_global = ((((current->tm_year * 12) + current->tm_mon) * 31 + current->tm_mday) * 24 + current->tm_hour) * 60 + current->tm_min;
  current = localtime(&timenow);
  long minute_count_local = ((((current->tm_year * 12) + current->tm_mon) * 31 + current->tm_mday) * 24 + current->tm_hour) * 60 + current->tm_min;

  dateTime->setYear(current->tm_year+1900);
  dateTime->setMonth(current->tm_mon+1);
  dateTime->setDay(current->tm_mday);
  dateTime->setHour(current->tm_hour);
  dateTime->setMinute(current->tm_min);
  dateTime->setSecond(current->tm_sec);
  dateTime->setMicrosecond(0);

  dateTime->setUTCHourOffset((minute_count_local - minute_count_global) / 60);
  dateTime->setUTCMinuteOffset((minute_count_local - minute_count_global) % 60);
  return dateTime;
}

void DateTime::loadFromString(std::string const value, std::string const format){
  this->Date::loadFromString(value, format);
  this->Time::loadFromString(value, format);
}
double DateTime::toHours() const {
  return (this->Date::toHours() - 24 + this->Time::toHours());
}
#endif