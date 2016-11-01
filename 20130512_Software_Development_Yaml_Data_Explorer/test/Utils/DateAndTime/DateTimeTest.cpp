#include "../../TestBase.cpp"
#include "../../../src/Utils/DateAndTime/DateTime.cpp"
using namespace Utils::DateAndTime;

class DateTimeTest : public TestBase {
	private:
		DateTime dateTimeAttribute1;
		DateTime dateTimeAttribute2;
	private:
	public:
		DateTimeTest() :
			dateTimeAttribute1(2010, 10, 10, 22, 14, 10, 0, 0, 0),
			dateTimeAttribute2(2010, 10, 10, 22, 14, 10, 0, 0, 0)
			{}
		void testEqualAndDifferent(){
			DateTime* dateTime1 = new DateTime(2010, 10, 10, 22, 14, 10, 0, 0, 0);
			dateTimeAttribute1.setSecond(12);
			if(dateTimeAttribute1 == dateTime1)
				report("The first time was suposed to be different to the second!", __FUNCTION__, __LINE__);
		 	dateTimeAttribute1.setSecond(10);
			if(dateTimeAttribute1 != dateTime1)
				report("The first time was suposed to be equal to the second!", __FUNCTION__, __LINE__);
			dateTimeAttribute2.setSecond(12);
			if(dateTimeAttribute1 == dateTimeAttribute2)
				report("The first time was suposed to be different to the second!", __FUNCTION__, __LINE__);
			dateTimeAttribute2.setSecond(10);
			if(dateTimeAttribute1 != dateTimeAttribute2)
				report("The first time was suposed to be equal to the second!", __FUNCTION__, __LINE__);
			delete(dateTime1);
		}

		void testMoreThan(){
			DateTime* dateTime1 = new DateTime(2010, 10, 10, 22, 14, 10, 0, 0, 0);
			dateTimeAttribute1.setSecond(8);
			if(dateTimeAttribute1 > dateTime1)
				report("The first time was suposed to be more than the second!", __FUNCTION__, __LINE__);
			dateTimeAttribute1.setSecond(10);
			if(dateTimeAttribute1 > dateTime1)
				report("The first time was suposed to be equal to the second!", __FUNCTION__, __LINE__);
			dateTimeAttribute1.setSecond(12);
			if(!(dateTimeAttribute1 > dateTime1))
				report("The first time was suposed to be less than the second!", __FUNCTION__, __LINE__);

			dateTimeAttribute2.setSecond(10);
			dateTimeAttribute1.setSecond(8);
			if(dateTimeAttribute1 > dateTimeAttribute2)
				report("The first time was suposed to be more than the second!", __FUNCTION__, __LINE__);
			dateTimeAttribute1.setSecond(10);
			if(dateTimeAttribute1 > dateTimeAttribute2)
				report("The first time was suposed to be equal to the second!", __FUNCTION__, __LINE__);
			dateTimeAttribute1.setSecond(12);
			if(!(dateTimeAttribute1 > dateTimeAttribute2))
				report("The first time was suposed to be less than the second!", __FUNCTION__, __LINE__);
			delete(dateTime1);
		}

		void testLessThan(){
			DateTime* dateTime1 = new DateTime(2010, 10, 10, 22, 14, 10, 0, 0, 0);
			dateTimeAttribute1.setSecond(12);
			if(dateTimeAttribute1 < dateTime1)
				report("The first time was suposed to be more than the second!", __FUNCTION__, __LINE__);
			dateTimeAttribute1.setSecond(10);
			if(dateTimeAttribute1 < dateTime1)
				report("The first time was suposed to be equal to the second!", __FUNCTION__, __LINE__);
			dateTimeAttribute1.setSecond(8);
			if(!(dateTimeAttribute1 < dateTime1))
				report("The first time was suposed to be less than the second!", __FUNCTION__, __LINE__);

			dateTimeAttribute2.setSecond(10);
			dateTimeAttribute1.setSecond(12);
			if(dateTimeAttribute1 < dateTimeAttribute2)
				report("The first time was suposed to be more than the second!", __FUNCTION__, __LINE__);
			dateTimeAttribute1.setSecond(10);
			if(dateTimeAttribute1 < dateTimeAttribute2)
				report("The first time was suposed to be equal to the second!", __FUNCTION__, __LINE__);
			dateTimeAttribute1.setSecond(8);
			if(!(dateTimeAttribute1 < dateTimeAttribute2))
				report("The first time was suposed to be less than the second!", __FUNCTION__, __LINE__);
			delete(dateTime1);
		}

		void testMoreOrEqualTo(){
			DateTime* dateTime1 = new DateTime(2010, 10, 10, 22, 14, 10, 0, 0, 0);
			dateTimeAttribute1.setSecond(8);
			if(dateTimeAttribute1 >= dateTime1)
				report("The first time was suposed to be more than the second!", __FUNCTION__, __LINE__);
			dateTimeAttribute1.setSecond(10);
			if(!(dateTimeAttribute1 >= dateTime1))
				report("The first time was suposed to be equal to the second!", __FUNCTION__, __LINE__);
			dateTimeAttribute1.setSecond(12);
			if(!(dateTimeAttribute1 >= dateTime1))
				report("The first time was suposed to be less than the second!", __FUNCTION__, __LINE__);

			dateTimeAttribute2.setSecond(10);
			dateTimeAttribute1.setSecond(8);
			if(dateTimeAttribute1 >= dateTimeAttribute2)
				report("The first time was suposed to be more than the second!", __FUNCTION__, __LINE__);
			dateTimeAttribute1.setSecond(10);
			if(!(dateTimeAttribute1 >= dateTimeAttribute2))
				report("The first time was suposed to be equal to the second!", __FUNCTION__, __LINE__);
			dateTimeAttribute1.setSecond(12);
			if(!(dateTimeAttribute1 >= dateTimeAttribute2))
				report("The first time was suposed to be less than the second!", __FUNCTION__, __LINE__);
			delete(dateTime1);
		}

		void testLessOrEqualTo(){
			DateTime* dateTime1 = new DateTime(2010, 10, 10, 22, 14, 10, 0, 0, 0);
			dateTimeAttribute1.setSecond(12);
			if(dateTimeAttribute1 <= dateTime1)
				report("The first time was suposed to be more than the second!", __FUNCTION__, __LINE__);
			dateTimeAttribute1.setSecond(10);
			if(!(dateTimeAttribute1 <= dateTime1))
				report("The first time was suposed to be equal to the second!", __FUNCTION__, __LINE__);
			dateTimeAttribute1.setSecond(8);
			if(!(dateTimeAttribute1 <= dateTime1))
				report("The first time was suposed to be less than the second!", __FUNCTION__, __LINE__);

			dateTimeAttribute2.setSecond(10);
			dateTimeAttribute1.setSecond(12);
			if(dateTimeAttribute1 <= dateTimeAttribute2)
				report("The first time was suposed to be more than the second!", __FUNCTION__, __LINE__);
			dateTimeAttribute1.setSecond(10);
			if(!(dateTimeAttribute1 <= dateTimeAttribute2))
				report("The first time was suposed to be equal to the second!", __FUNCTION__, __LINE__);
			dateTimeAttribute1.setSecond(8);
			if(!(dateTimeAttribute1 <= dateTimeAttribute2))
				report("The first time was suposed to be less than the second!", __FUNCTION__, __LINE__);
			delete(dateTime1);
		}

		void testFormat(){
			DateTime* dateTime1 = new DateTime(2010, 10, 12, 22, 14, 10, 76023, -3, 0);
			reportIfDifferent(dateTime1->format("d/m/Y H:i:s.u P"), "12/10/2010 22:14:10.76023 -03:00", __FUNCTION__, __LINE__);
			delete(dateTime1);
		}

		void testFromString(){
			DateTime* dateTime1 = new DateTime();
			dateTime1->loadFromString("2013-04-06 09:54:51.801376 -02:00", "Y-m-d H:i:s.u P");
			reportIfDifferent(dateTime1->format("d/m/Y H:i:s.u (P)"), "06/04/2013 09:54:51.801376 (-02:00)", __FUNCTION__, __LINE__);
			dateTime1->loadFromString("09:54:51.801376 2013-04-06 -02:00", "H:i:s.u Y-m-d P");
			reportIfDifferent(dateTime1->format("d/m/Y H:i:s.u (P)"), "06/04/2013 09:54:51.801376 (-02:00)", __FUNCTION__, __LINE__);
			dateTime1->loadFromString("2012-11-27 09:12:08 -02:00", "Y-m-d H:i:s P");
			reportIfDifferent(dateTime1->format("Y-m-d H:i:s P"), "2012-11-27 09:12:08 -02:00", __FUNCTION__, __LINE__);
			dateTime1->loadFromString("2012-11-27 09:12:08 -00:30", "Y-m-d H:i:s P");
			reportIfDifferent(dateTime1->format("Y-m-d H:i:s P"), "2012-11-27 09:12:08 -00:30", __FUNCTION__, __LINE__);
			delete(dateTime1);
		}

		void testToHoursFromTime(){
			DateTime* dateTime1 = new DateTime();
			dateTime1->loadFromString("01:00:00.0 00:00", "H:i:s.u P");
			reportIfNotBetween(dateTime1->toHours(), 1.0, 1.0, __FUNCTION__, __LINE__);
			dateTime1->loadFromString("01:20:40.0 00:00", "H:i:s.u P");
			reportIfNotBetween(dateTime1->toHours(), 1.34, 1.35, __FUNCTION__, __LINE__);
			dateTime1->loadFromString("01:20:40.5635 00:00", "H:i:s.u P");
			reportIfNotBetween(dateTime1->toHours(), 1.34, 1.35, __FUNCTION__, __LINE__);
			dateTime1->loadFromString("16:20:40.5635 00:00", "H:i:s.u P");
			reportIfNotBetween(dateTime1->toHours(), 16.34, 16.35, __FUNCTION__, __LINE__);
			dateTime1->loadFromString("16:20:40.5635 04:00", "H:i:s.u P");
			reportIfNotBetween(dateTime1->toHours(), 20.34, 20.35, __FUNCTION__, __LINE__);
			dateTime1->loadFromString("16:20:40.5635 -03:00", "H:i:s.u P");
			reportIfNotBetween(dateTime1->toHours(), 13.34, 13.35, __FUNCTION__, __LINE__);
			dateTime1->loadFromString("16:20:40.5635 +04:30", "H:i:s.u P");
			reportIfNotBetween(dateTime1->toHours(), 20.84, 20.85, __FUNCTION__, __LINE__);
			dateTime1->loadFromString("16:20:40.5635 04:30", "H:i:s.u P");
			reportIfNotBetween(dateTime1->toHours(), 20.84, 20.85, __FUNCTION__, __LINE__);
			dateTime1->loadFromString("16:20:40.5635 -03:40", "H:i:s.u P");
			reportIfNotBetween(dateTime1->toHours(), 12.67, 12.68, __FUNCTION__, __LINE__);
			delete(dateTime1);
		}

		void testToHoursFromDate(){
			DateTime* dateTime1 = new DateTime();
			dateTime1->loadFromString("2017-10-12 24", "Y-m-d H");
			reportIfDifferent(dateTime1->toHours(), 17687496.0, __FUNCTION__, __LINE__);
			dateTime1->setYear(2013);
			reportIfDifferent(dateTime1->toHours(), 17652432.0, __FUNCTION__, __LINE__);
			dateTime1->setYear(2012);
			reportIfDifferent(dateTime1->toHours(), 17643672.0, __FUNCTION__, __LINE__);
			dateTime1->setYear(2011);
			reportIfDifferent(dateTime1->toHours(), 17634888.0, __FUNCTION__, __LINE__);
			DateTime* dateTime2 = new DateTime();
			dateTime2->loadFromString("0000-01-00 24", "Y-m-d H");
			reportIfDifferent(dateTime2->toHours(), 0.0, __FUNCTION__, __LINE__);
			dateTime2->setDay(1);
			reportIfDifferent(dateTime2->toHours(), 24.0, __FUNCTION__, __LINE__);
			dateTime2->setDay(31);
			reportIfDifferent(dateTime2->toHours(), 744.0, __FUNCTION__, __LINE__);
			dateTime2->setDay(1);
			dateTime2->setMonth(2);
			reportIfDifferent(dateTime2->toHours(), 768.0, __FUNCTION__, __LINE__);
			dateTime2->setDay(1);
			dateTime2->setMonth(1);
			dateTime2->setYear(3);
			reportIfDifferent(dateTime2->toHours(), 26304.0, __FUNCTION__, __LINE__);
			dateTime2->setDay(1);
			dateTime2->setMonth(1);
			dateTime2->setYear(4);
			reportIfDifferent(dateTime2->toHours(), 35064.0, __FUNCTION__, __LINE__);
			dateTime2->setDay(1);
			dateTime2->setMonth(3);
			dateTime2->setYear(4);
			reportIfDifferent(dateTime2->toHours(), 36504.0, __FUNCTION__, __LINE__);
			dateTime2->setDay(1);
			dateTime2->setMonth(1);
			dateTime2->setYear(5);
			reportIfDifferent(dateTime2->toHours(), 43848.0, __FUNCTION__, __LINE__);
			dateTime2->setDay(1);
			dateTime2->setMonth(3);
			dateTime2->setYear(5);
			reportIfDifferent(dateTime2->toHours(), 45264.0, __FUNCTION__, __LINE__);
			delete(dateTime1);
			delete(dateTime2);
		}
};

int main(int argc, char* argv[]){
	DateTimeTest* dateTimeTest = new DateTimeTest();
	dateTimeTest->testEqualAndDifferent();
	dateTimeTest->testMoreThan();
	dateTimeTest->testLessThan();
	dateTimeTest->testMoreOrEqualTo();
	dateTimeTest->testLessOrEqualTo();
	dateTimeTest->testFormat();
	dateTimeTest->testFromString();
	dateTimeTest->testToHoursFromTime();
	dateTimeTest->testToHoursFromDate();
	dateTimeTest->testToHoursFromDate();
	delete(dateTimeTest);

	// DateTime* dateTime1 = new DateTime();
	// std::cout << dateTime1->now()->format("d/m/Y H:i:s.u P") << std::endl;
	// delete(dateTime1);
	// DateTime* dateTime2 = new DateTime();
	// std::cout << dateTime2->format("d/m/Y H:i:s.u P") << std::endl;
	// delete(dateTime2);
	// std::cout << DateTime::now()->format("d/m/Y H:i:s.u P") << std::endl;
}
