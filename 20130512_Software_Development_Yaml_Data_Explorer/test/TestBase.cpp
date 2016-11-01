#include <stdio.h>
#include <sstream>
#include <string>
#include <cstring>
#include <iostream>
#include <cmath>
#include <limits>

class TestObject {
	private:
		static int lastId;
		int innerId;
	public:
		TestObject() {
		 	this->innerId = (++lastId);
		}
		~TestObject(){}
		std::string toString() {
			std::stringstream stream;
			stream << "TestObject {innerId:" << this->innerId << "}";
			return stream.str();
		}
		void resetLastId(){
			lastId = 0;
		}
};
int TestObject::lastId = 0;

class TestBase {
	protected:
		void resetTestObjectCount(){
			TestObject* testObject = new TestObject();
			testObject->resetLastId();
			delete(testObject);
		}
		TestBase(){}
		virtual ~TestBase(){}

		void report(char const* message, char const* calledFunction, int calledLine){
			std::cout << message << " At " << calledFunction << ':' << calledLine << std::endl;
		}
		void reportIfNotBetween(double valueToTest, double minValue, double maxValue, char const* calledFunction, int calledLine){
			if(valueToTest > maxValue || valueToTest < minValue)
				std::cout << "Value is \"" << valueToTest << "\" but should be more than \"" << minValue << "\" and less than \"" << maxValue << "\"! At " << calledFunction << ':' << calledLine << std::endl;
		}
		void reportIfDifferent(long valueToTest, long expectedValue, char const* calledFunction, int calledLine){
			if(valueToTest != expectedValue)
				std::cout << "Value is \"" << valueToTest << "\" but should be \"" << expectedValue << "\"! At " << calledFunction << ':' << calledLine << std::endl;
		}
		void reportIfDifferent(std::string valueToTest, char const* expectedValue, char const* calledFunction, int calledLine){
			if(std::strcmp(valueToTest.c_str(),expectedValue) != 0)
				std::cout << "Value is \"" << valueToTest << "\" but should be \"" << expectedValue << "\"! At " << calledFunction << ':' << calledLine << std::endl;
		}
		void reportIfDifferent(std::string valueToTest, std::string expectedValue, char const* calledFunction, int calledLine){
			if(valueToTest.compare(expectedValue) != 0)
				std::cout << "Value is \"" << valueToTest << "\" but should be \"" << expectedValue << "\"! At " << calledFunction << ':' << calledLine << std::endl;
		}
		void reportIfDifferentObject(void* pointer1, void* pointer2, char const* calledFunction, int calledLine){
			if(pointer1 != pointer2)
				std::cout << "The objects should be the same! At " << calledFunction << ':' << calledLine << std::endl;
		}
		void reportIfNotNull(void* pointer, char const* calledFunction, int calledLine){
			if(pointer != NULL)
				std::cout << "The pointer should be NULL! At " << calledFunction << ':' << calledLine << std::endl;
		}
		void reportIfNull(void* pointer, char const* calledFunction, int calledLine){
			if(pointer == NULL)
				std::cout << "The pointer shouldn't be NULL! At " << calledFunction << ':' << calledLine << std::endl;
		}
		void reportIfNullC(const void* pointer, char const* calledFunction, int calledLine){
			if(pointer == NULL)
				std::cout << "The pointer shouldn't be NULL! At " << calledFunction << ':' << calledLine << std::endl;
		}
		void reportIfFalse(bool variable, char const* calledFunction, int calledLine){
			if(!variable)
				std::cout << "The variable shouldn't be FALSE! At " << calledFunction << ':' << calledLine << std::endl;
		}
		void reportIfTrue(bool variable, char const* calledFunction, int calledLine){
			if(variable)
				std::cout << "The variable shouldn't be FALSE! At " << calledFunction << ':' << calledLine << std::endl;
		}
};