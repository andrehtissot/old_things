#ifndef _UTILS_DATE_AND_TIME_TIME_H_
#define _UTILS_DATE_AND_TIME_TIME_H_

namespace Utils {
  namespace DateAndTime {
    class Time {
      private:
        short hour;
        short minute;
        short second;
        int microsecond;
        short utcHourOffset;
        short utcMinuteOffset;

      public:
        Time(short const hour, short const minute, short const second, int const microsecond, short const utcHourOffset, short const utcMinuteOffset);
        Time();
        virtual ~Time();
        const short getHour() const;
        void setHour(short const hour);
        const short getFixedHour() const;
        const short getMinute() const;
        void setMinute(short const minute);
        const short getFixedMinute() const;
        const short getSecond() const;
        void setSecond(short const second);
        const int getMicrosecond() const;
        void setMicrosecond(int const microsecond);
        const short getUTCHourOffset() const;
        void setUTCHourOffset(short const utcHourOffset);
        const short getUTCMinuteOffset() const;
        void setUTCMinuteOffset(short const utcMinuteOffset);
        bool operator==(const Time& time) const;
        bool operator==(Time*& time) const;
        bool operator!=(const Time& time) const;
        bool operator!=(Time*& time) const;
        bool operator>(const Time& time) const;
        bool operator>(Time*& time) const;
        bool operator<(const Time& time) const;
        bool operator<(Time*& time) const;
        bool operator>=(const Time& time) const;
        bool operator>=(Time*& time) const;
        bool operator<=(const Time& time) const;
        bool operator<=(Time*& time) const;
        virtual std::string format(std::string const format) const;
        virtual void loadFromString(std::string const value, std::string const format);
        virtual double toHours() const;
        static Time* now();

      protected:
        std::string formatFor(char const keyLetter) const;
    };
  }
}
#endif