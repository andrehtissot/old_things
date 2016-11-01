#ifndef _UTILS_DATE_AND_TIME_DATE_H_
#define _UTILS_DATE_AND_TIME_DATE_H_

namespace Utils {
  namespace DateAndTime {
    class Date {
      private:
        short year;
        short month;
        short day;

      public:
        Date();
        Date(short const year, short const month, short const day);
        virtual ~Date();
        const short getYear() const;
        void setYear(short const year);
        const short getMonth() const;
        void setMonth(short const month);
        const short getDay() const;
        void setDay(short const day);
        bool operator==(const Date& date) const;
        bool operator==(Date*& date) const;
        bool operator!=(const Date& date) const;
        bool operator!=(Date*& date) const;
        bool operator>(const Date& date) const;
        bool operator>(Date*& date) const;
        bool operator<(const Date& date) const;
        bool operator<(Date*& date) const;
        bool operator>=(const Date& date) const;
        bool operator>=(Date*& date) const;
        bool operator<=(const Date& date) const;
        bool operator<=(Date*& date) const;
        virtual std::string format(std::string const format) const;
        virtual void loadFromString(std::string const value, std::string const format);
        virtual double toHours() const;
        static Date* today();

      protected:
        std::string formatFor(char const keyLetter) const;
    };
  }
}
#endif