#ifndef _UTILS_DATE_AND_TIME_DATE_TIME_H_
#define _UTILS_DATE_AND_TIME_DATE_TIME_H_

namespace Utils {
  namespace DateAndTime {
    class DateTime : public Date, public Time {
      public:
        DateTime();
        DateTime(short const year, short const month, short const day, short const hour, short const minute, short const second, int const microsecond, short const utcHourOffset, short const utcMinuteOffset);
        ~DateTime();
        bool operator==(const DateTime& dateTime) const;
        bool operator==(DateTime*& dateTime) const;
        bool operator!=(const DateTime& dateTime) const;
        bool operator!=(DateTime*& dateTime) const;
        bool operator>(const DateTime& dateTime) const;
        bool operator>(DateTime*& dateTime) const;
        bool operator<(const DateTime& dateTime) const;
        bool operator<(DateTime*& dateTime) const;
        bool operator>=(const DateTime& dateTime) const;
        bool operator>=(DateTime*& dateTime) const;
        bool operator<=(const DateTime& dateTime) const;
        bool operator<=(DateTime*& dateTime) const;
        std::string format(std::string const format) const;
        void loadFromString(std::string const value, std::string const format);
        double toHours() const;
        static DateTime* now();
    };
  }
}
#endif