#include "../../TestBase.cpp"
#include "../../../src/Utils/DateAndTime/Date.cpp"
using namespace Utils::DateAndTime;

class DateTest : public TestBase {
	private:
		Date dateAttribute1;
		Date dateAttribute2;
	private:
	public:
		void testEqualAndDifferent(){
			Date* date1 = new Date(2010, 10, 10);
			dateAttribute1.setYear(2010);
			dateAttribute1.setMonth(10);
			dateAttribute1.setDay(12);
			if(dateAttribute1 == date1)
				report("The first date was suposed to be different to the second!", __FUNCTION__, __LINE__);
			dateAttribute1.setDay(10);
			if(dateAttribute1 != date1)
				report("The first date was suposed to be equal to the second!", __FUNCTION__, __LINE__);
			dateAttribute2.setYear(2010);
			dateAttribute2.setMonth(10);
			dateAttribute2.setDay(12);
			if(dateAttribute1 == dateAttribute2)
				report("The first date was suposed to be different to the second!", __FUNCTION__, __LINE__);
			dateAttribute2.setDay(10);
			if(dateAttribute1 != dateAttribute2)
				report("The first date was suposed to be equal to the second!", __FUNCTION__, __LINE__);
			delete(date1);
		}

		void testMoreThan(){
			Date* date1 = new Date(2010, 10, 10);
			dateAttribute1.setYear(2010);
			dateAttribute1.setMonth(10);
			dateAttribute1.setDay(8);
			if(dateAttribute1 > date1)
				report("The first date was suposed to be more than the second!", __FUNCTION__, __LINE__);
			dateAttribute1.setDay(10);
			if(dateAttribute1 > date1)
				report("The first date was suposed to be equal to the second!", __FUNCTION__, __LINE__);
			dateAttribute1.setDay(12);
			if(!(dateAttribute1 > date1))
				report("The first date was suposed to be less than the second!", __FUNCTION__, __LINE__);

			dateAttribute2.setYear(2010);
			dateAttribute2.setMonth(10);
			dateAttribute2.setDay(10);
			dateAttribute1.setDay(8);
			if(dateAttribute1 > dateAttribute2)
				report("The first date was suposed to be more than the second!", __FUNCTION__, __LINE__);
			dateAttribute1.setDay(10);
			if(dateAttribute1 > dateAttribute2)
				report("The first date was suposed to be equal to the second!", __FUNCTION__, __LINE__);
			dateAttribute1.setDay(12);
			if(!(dateAttribute1 > dateAttribute2))
				report("The first date was suposed to be less than the second!", __FUNCTION__, __LINE__);
			delete(date1);
		}

		void testLessThan(){
			Date* date1 = new Date(2010, 10, 10);
			dateAttribute1.setYear(2010);
			dateAttribute1.setMonth(10);
			dateAttribute1.setDay(12);
			if(dateAttribute1 < date1)
				report("The first date was suposed to be more than the second!", __FUNCTION__, __LINE__);
			dateAttribute1.setDay(10);
			if(dateAttribute1 < date1)
				report("The first date was suposed to be equal to the second!", __FUNCTION__, __LINE__);
			dateAttribute1.setDay(8);
			if(!(dateAttribute1 < date1))
				report("The first date was suposed to be less than the second!", __FUNCTION__, __LINE__);

			dateAttribute2.setYear(2010);
			dateAttribute2.setMonth(10);
			dateAttribute2.setDay(10);
			dateAttribute1.setDay(12);
			if(dateAttribute1 < dateAttribute2)
				report("The first date was suposed to be more than the second!", __FUNCTION__, __LINE__);
			dateAttribute1.setDay(10);
			if(dateAttribute1 < dateAttribute2)
				report("The first date was suposed to be equal to the second!", __FUNCTION__, __LINE__);
			dateAttribute1.setDay(8);
			if(!(dateAttribute1 < dateAttribute2))
				report("The first date was suposed to be less than the second!", __FUNCTION__, __LINE__);
			delete(date1);
		}

		void testMoreOrEqualTo(){
			Date* date1 = new Date(2010, 10, 10);
			dateAttribute1.setYear(2010);
			dateAttribute1.setMonth(10);
			dateAttribute1.setDay(8);
			if(dateAttribute1 >= date1)
				report("The first date was suposed to be more than the second!", __FUNCTION__, __LINE__);
			dateAttribute1.setDay(10);
			if(!(dateAttribute1 >= date1))
				report("The first date was suposed to be equal to the second!", __FUNCTION__, __LINE__);
			dateAttribute1.setDay(12);
			if(!(dateAttribute1 >= date1))
				report("The first date was suposed to be less than the second!", __FUNCTION__, __LINE__);

			dateAttribute2.setYear(2010);
			dateAttribute2.setMonth(10);
			dateAttribute2.setDay(10);
			dateAttribute1.setDay(8);
			if(dateAttribute1 >= dateAttribute2)
				report("The first date was suposed to be more than the second!", __FUNCTION__, __LINE__);
			dateAttribute1.setDay(10);
			if(!(dateAttribute1 >= dateAttribute2))
				report("The first date was suposed to be equal to the second!", __FUNCTION__, __LINE__);
			dateAttribute1.setDay(12);
			if(!(dateAttribute1 >= dateAttribute2))
				report("The first date was suposed to be less than the second!", __FUNCTION__, __LINE__);
			delete(date1);
		}

		void testLessOrEqualTo(){
			Date* date1 = new Date(2010, 10, 10);
			dateAttribute1.setYear(2010);
			dateAttribute1.setMonth(10);
			dateAttribute1.setDay(12);
			if(dateAttribute1 <= date1)
				report("The first date was suposed to be more than the second!", __FUNCTION__, __LINE__);
			dateAttribute1.setDay(10);
			if(!(dateAttribute1 <= date1))
				report("The first date was suposed to be equal to the second!", __FUNCTION__, __LINE__);
			dateAttribute1.setDay(8);
			if(!(dateAttribute1 <= date1))
				report("The first date was suposed to be less than the second!", __FUNCTION__, __LINE__);

			dateAttribute2.setYear(2010);
			dateAttribute2.setMonth(10);
			dateAttribute2.setDay(10);
			dateAttribute1.setDay(12);
			if(dateAttribute1 <= dateAttribute2)
				report("The first date was suposed to be more than the second!", __FUNCTION__, __LINE__);
			dateAttribute1.setDay(10);
			if(!(dateAttribute1 <= dateAttribute2))
				report("The first date was suposed to be equal to the second!", __FUNCTION__, __LINE__);
			dateAttribute1.setDay(8);
			if(!(dateAttribute1 <= dateAttribute2))
				report("The first date was suposed to be less than the second!", __FUNCTION__, __LINE__);
			delete(date1);
		}

		void testFormat(){
			Date* date1 = new Date(2010, 10, 12);
			reportIfDifferent(date1->format("d/m/Y"), "12/10/2010", __FUNCTION__, __LINE__);
			delete(date1);
		}

		void testFromString(){
			Date* date1 = new Date(2010, 10, 12);
			date1->loadFromString("2013-04-08", "Y-m-d");
			reportIfDifferent(date1->format("d/m/Y"), "08/04/2013", __FUNCTION__, __LINE__);
			delete(date1);
		}

		void testToHours(){
			Date* date1 = new Date(2017, 10, 12);
			reportIfDifferent(date1->toHours(), 17687496.0, __FUNCTION__, __LINE__);
			date1->setYear(2013);
			reportIfDifferent(date1->toHours(), 17652432.0, __FUNCTION__, __LINE__);
			date1->setYear(2012);
			reportIfDifferent(date1->toHours(), 17643672.0, __FUNCTION__, __LINE__);
			date1->setYear(2011);
			reportIfDifferent(date1->toHours(), 17634888.0, __FUNCTION__, __LINE__);
			Date* date2 = new Date(0, 1, 0);
			reportIfDifferent(date2->toHours(), 0.0, __FUNCTION__, __LINE__);
			date2->setDay(1);
			reportIfDifferent(date2->toHours(), 24.0, __FUNCTION__, __LINE__);
			date2->setDay(31);
			reportIfDifferent(date2->toHours(), 744.0, __FUNCTION__, __LINE__);
			date2->setDay(1);
			date2->setMonth(2);
			reportIfDifferent(date2->toHours(), 768.0, __FUNCTION__, __LINE__);
			date2->setDay(1);
			date2->setMonth(1);
			date2->setYear(3);
			reportIfDifferent(date2->toHours(), 26304.0, __FUNCTION__, __LINE__);
			date2->setDay(1);
			date2->setMonth(1);
			date2->setYear(4);
			reportIfDifferent(date2->toHours(), 35064.0, __FUNCTION__, __LINE__);
			date2->setDay(1);
			date2->setMonth(3);
			date2->setYear(4);
			reportIfDifferent(date2->toHours(), 36504.0, __FUNCTION__, __LINE__);
			date2->setDay(1);
			date2->setMonth(1);
			date2->setYear(5);
			reportIfDifferent(date2->toHours(), 43848.0, __FUNCTION__, __LINE__);
			date2->setDay(1);
			date2->setMonth(3);
			date2->setYear(5);
			reportIfDifferent(date2->toHours(), 45264.0, __FUNCTION__, __LINE__);
			delete(date1);
			delete(date2);
		}
};

int main(int argc, char* argv[]){
	DateTest* dateTest = new DateTest();
	dateTest->testEqualAndDifferent();
	dateTest->testMoreThan();
	dateTest->testLessThan();
	dateTest->testMoreOrEqualTo();
	dateTest->testLessOrEqualTo();
	dateTest->testFormat();
	dateTest->testFromString();
	dateTest->testToHours();
	delete(dateTest);

	// Date* date1 = new Date();
	// std::cout << date1->today()->format("d/m/Y") << std::endl;
	// delete(date1);
	// Date* date2 = new Date();
	// std::cout << date2->format("d/m/Y") << std::endl;
	// delete(date2);
	//std::cout << Date::today()->format("d/m/Y") << std::endl;
}
