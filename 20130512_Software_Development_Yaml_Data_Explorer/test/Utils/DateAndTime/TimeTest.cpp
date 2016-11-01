#include "../../TestBase.cpp"
#include "../../../src/Utils/DateAndTime/Time.cpp"
using namespace Utils::DateAndTime;

class TimeTest : public TestBase {
	private:
		Time timeAttribute1;
		Time timeAttribute2;
	private:
	public:
		TimeTest() :
			timeAttribute1(22, 14, 10, 0, 0, 0),
			timeAttribute2(22, 14, 10, 0, 0, 0)
			{}
		void testEqualAndDifferent(){
			Time* time1 = new Time(22, 14, 10, 0, 0, 0);
			timeAttribute1.setSecond(12);
			if(timeAttribute1 == time1)
				report("The first time was suposed to be different to the second!", __FUNCTION__, __LINE__);
			timeAttribute1.setSecond(10);
			if(timeAttribute1 != time1)
				report("The first time was suposed to be equal to the second!", __FUNCTION__, __LINE__);
			timeAttribute2.setHour(22);
			timeAttribute2.setMinute(14);
			timeAttribute2.setSecond(12);
			if(timeAttribute1 == timeAttribute2)
				report("The first time was suposed to be different to the second!", __FUNCTION__, __LINE__);
			timeAttribute2.setSecond(10);
			if(timeAttribute1 != timeAttribute2)
				report("The first time was suposed to be equal to the second!", __FUNCTION__, __LINE__);
			delete(time1);
		}

		void testMoreThan(){
			Time* time1 = new Time(22, 14, 10, 0, 0, 0);
			timeAttribute1.setSecond(8);
			if(timeAttribute1 > time1)
				report("The first time was suposed to be more than the second!", __FUNCTION__, __LINE__);
			timeAttribute1.setSecond(10);
			if(timeAttribute1 > time1)
				report("The first time was suposed to be equal to the second!", __FUNCTION__, __LINE__);
			timeAttribute1.setSecond(12);
			if(!(timeAttribute1 > time1))
				report("The first time was suposed to be less than the second!", __FUNCTION__, __LINE__);

			timeAttribute2.setSecond(10);
			timeAttribute1.setSecond(8);
			if(timeAttribute1 > timeAttribute2)
				report("The first time was suposed to be more than the second!", __FUNCTION__, __LINE__);
			timeAttribute1.setSecond(10);
			if(timeAttribute1 > timeAttribute2)
				report("The first time was suposed to be equal to the second!", __FUNCTION__, __LINE__);
			timeAttribute1.setSecond(12);
			if(!(timeAttribute1 > timeAttribute2))
				report("The first time was suposed to be less than the second!", __FUNCTION__, __LINE__);
			delete(time1);
		}

		void testLessThan(){
			Time* time1 = new Time(22, 14, 10, 0, 0, 0);
			timeAttribute1.setSecond(12);
			if(timeAttribute1 < time1)
				report("The first time was suposed to be more than the second!", __FUNCTION__, __LINE__);
			timeAttribute1.setSecond(10);
			if(timeAttribute1 < time1)
				report("The first time was suposed to be equal to the second!", __FUNCTION__, __LINE__);
			timeAttribute1.setSecond(8);
			if(!(timeAttribute1 < time1))
				report("The first time was suposed to be less than the second!", __FUNCTION__, __LINE__);

			timeAttribute2.setSecond(10);
			timeAttribute1.setSecond(12);
			if(timeAttribute1 < timeAttribute2)
				report("The first time was suposed to be more than the second!", __FUNCTION__, __LINE__);
			timeAttribute1.setSecond(10);
			if(timeAttribute1 < timeAttribute2)
				report("The first time was suposed to be equal to the second!", __FUNCTION__, __LINE__);
			timeAttribute1.setSecond(8);
			if(!(timeAttribute1 < timeAttribute2))
				report("The first time was suposed to be less than the second!", __FUNCTION__, __LINE__);
			delete(time1);
		}

		void testMoreOrEqualTo(){
			Time* time1 = new Time(22, 14, 10, 0, 0, 0);
			timeAttribute1.setSecond(8);
			if(timeAttribute1 >= time1)
				report("The first time was suposed to be more than the second!", __FUNCTION__, __LINE__);
			timeAttribute1.setSecond(10);
			if(!(timeAttribute1 >= time1))
				report("The first time was suposed to be equal to the second!", __FUNCTION__, __LINE__);
			timeAttribute1.setSecond(12);
			if(!(timeAttribute1 >= time1))
				report("The first time was suposed to be less than the second!", __FUNCTION__, __LINE__);

			timeAttribute2.setSecond(10);
			timeAttribute1.setSecond(8);
			if(timeAttribute1 >= timeAttribute2)
				report("The first time was suposed to be more than the second!", __FUNCTION__, __LINE__);
			timeAttribute1.setSecond(10);
			if(!(timeAttribute1 >= timeAttribute2))
				report("The first time was suposed to be equal to the second!", __FUNCTION__, __LINE__);
			timeAttribute1.setSecond(12);
			if(!(timeAttribute1 >= timeAttribute2))
				report("The first time was suposed to be less than the second!", __FUNCTION__, __LINE__);
			delete(time1);
		}

		void testLessOrEqualTo(){
			Time* time1 = new Time(22, 14, 10, 0, 0, 0);
			timeAttribute1.setSecond(12);
			if(timeAttribute1 <= time1)
				report("The first time was suposed to be more than the second!", __FUNCTION__, __LINE__);
			timeAttribute1.setSecond(10);
			if(!(timeAttribute1 <= time1))
				report("The first time was suposed to be equal to the second!", __FUNCTION__, __LINE__);
			timeAttribute1.setSecond(8);
			if(!(timeAttribute1 <= time1))
				report("The first time was suposed to be less than the second!", __FUNCTION__, __LINE__);

			timeAttribute2.setSecond(10);
			timeAttribute1.setSecond(12);
			if(timeAttribute1 <= timeAttribute2)
				report("The first time was suposed to be more than the second!", __FUNCTION__, __LINE__);
			timeAttribute1.setSecond(10);
			if(!(timeAttribute1 <= timeAttribute2))
				report("The first time was suposed to be equal to the second!", __FUNCTION__, __LINE__);
			timeAttribute1.setSecond(8);
			if(!(timeAttribute1 <= timeAttribute2))
				report("The first time was suposed to be less than the second!", __FUNCTION__, __LINE__);
			delete(time1);
		}

		void testFormat(){
			Time* time1 = new Time(22, 14, 10, 0, 0, 0);
			reportIfDifferent(time1->format("H:i:s"), "22:14:10", __FUNCTION__, __LINE__);
			delete(time1);
		}

		void testFromString(){
			Time* time1 = new Time();
			int microseconds = 999999;
			reportIfDifferent((double) microseconds, 999999.0, __FUNCTION__, __LINE__);
			time1->loadFromString("09:54:51.801376 -02:00", "H:i:s.u P");
			reportIfDifferent(time1->format("H:i:s.u (P)"), "09:54:51.801376 (-02:00)", __FUNCTION__, __LINE__);
			delete(time1);
		}

		void testToHours(){
			Time* time1 = new Time();
			time1->loadFromString("01:00:00.0 00:00", "H:i:s.u P");
			reportIfNotBetween(time1->toHours(), 1.0, 1.0, __FUNCTION__, __LINE__);
			time1->loadFromString("01:20:40.0 00:00", "H:i:s.u P");
			reportIfNotBetween(time1->toHours(), 1.34, 1.35, __FUNCTION__, __LINE__);
			time1->loadFromString("01:20:40.5635 00:00", "H:i:s.u P");
			reportIfNotBetween(time1->toHours(), 1.34, 1.35, __FUNCTION__, __LINE__);
			time1->loadFromString("16:20:40.5635 00:00", "H:i:s.u P");
			reportIfNotBetween(time1->toHours(), 16.34, 16.35, __FUNCTION__, __LINE__);
			time1->loadFromString("16:20:40.5635 04:00", "H:i:s.u P");
			reportIfNotBetween(time1->toHours(), 20.34, 20.35, __FUNCTION__, __LINE__);
			time1->loadFromString("16:20:40.5635 -03:00", "H:i:s.u P");
			reportIfNotBetween(time1->toHours(), 13.34, 13.35, __FUNCTION__, __LINE__);
			time1->loadFromString("16:20:40.5635 +04:30", "H:i:s.u P");
			reportIfNotBetween(time1->toHours(), 20.84, 20.85, __FUNCTION__, __LINE__);
			time1->loadFromString("16:20:40.5635 04:30", "H:i:s.u P");
			reportIfNotBetween(time1->toHours(), 20.84, 20.85, __FUNCTION__, __LINE__);
			time1->loadFromString("16:20:40.5635 -03:40", "H:i:s.u P");
			reportIfNotBetween(time1->toHours(), 12.67, 12.68, __FUNCTION__, __LINE__);
			delete(time1);
		}
};

int main(int argc, char* argv[]){
	TimeTest* timeTest = new TimeTest();
	timeTest->testEqualAndDifferent();
	timeTest->testMoreThan();
	timeTest->testLessThan();
	timeTest->testMoreOrEqualTo();
	timeTest->testLessOrEqualTo();
	timeTest->testFormat();
	timeTest->testFromString();
	timeTest->testToHours();
	delete(timeTest);

	// Time* time1 = new Time();
	// std::cout << time1->now()->format("H:i:s") << std::endl;
	// delete(time1);
	// Time* time2 = new Time();
	// std::cout << time2->format("H:i:s") << std::endl;
	// delete(time2);
	// std::cout << Time::now()->format("H:i:s.u P") << std::endl;
}
