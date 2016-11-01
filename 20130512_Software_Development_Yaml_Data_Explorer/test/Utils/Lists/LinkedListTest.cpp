#include "../../TestBase.cpp"
#include <vector>
#include "../../../src/Utils/Lists/LinkedList.h"
using namespace Utils::Lists;

class LinkedListTest : public TestBase {
	private:
		void appendOnList(LinkedList<TestObject>* list, int times = 1){
			TestObject* testObject;
			for(int i = 0; i < times; i++){
				testObject = new TestObject();
				list->append(testObject);
			}
		}
	public:
		void testAppend(){
			LinkedList<TestObject>* list1 = new LinkedList<TestObject>();
			reportIfDifferent(list1->count(), 0, __FUNCTION__, __LINE__);
			this->appendOnList(list1);
			reportIfDifferent(list1->count(), 1, __FUNCTION__, __LINE__);
			this->appendOnList(list1);
			reportIfDifferent(list1->count(), 2, __FUNCTION__, __LINE__);
			list1->removeAll(true);
			delete(list1);
		}
		void testRemoveAll(){
			LinkedList<TestObject>* list1 = new LinkedList<TestObject>();
			reportIfDifferent(list1->count(), 0, __FUNCTION__, __LINE__);
			list1->removeAll(true);
			reportIfDifferent(list1->count(), 0, __FUNCTION__, __LINE__);
			this->appendOnList(list1);
			reportIfDifferent(list1->count(), 1, __FUNCTION__, __LINE__);
			list1->removeAll(true);
			list1->append(NULL);
			this->appendOnList(list1);
			reportIfDifferent(list1->count(), 2, __FUNCTION__, __LINE__);
			list1->removeAll(true);
			reportIfDifferent(list1->count(), 0, __FUNCTION__, __LINE__);
			this->appendOnList(list1, 4);
			reportIfDifferent(list1->count(), 4, __FUNCTION__, __LINE__);
			list1->append(NULL);
			reportIfDifferent(list1->count(), 5, __FUNCTION__, __LINE__);
			list1->removeAll(true);
			reportIfDifferent(list1->count(), 0, __FUNCTION__, __LINE__);
			list1->removeAll(true);
			reportIfDifferent(list1->count(), 0, __FUNCTION__, __LINE__);
			this->appendOnList(list1);
			reportIfDifferent(list1->count(), 1, __FUNCTION__, __LINE__);
			list1->removeAll(true);
			delete(list1);
		}
		void testGet(){
			LinkedList<TestObject>* list1 = new LinkedList<TestObject>();
			for(short s = 0; s < 2; s++){
				resetTestObjectCount();
				this->appendOnList(list1, 4);
				reportIfNotNull(list1->get(-1), __FUNCTION__, __LINE__);
				reportIfDifferent(list1->get(0)->toString(), "TestObject {innerId:1}", __FUNCTION__, __LINE__);
				reportIfDifferent(list1->get(1)->toString(), "TestObject {innerId:2}", __FUNCTION__, __LINE__);
				reportIfDifferent(list1->get(2)->toString(), "TestObject {innerId:3}", __FUNCTION__, __LINE__);
				reportIfDifferent(list1->get(3)->toString(), "TestObject {innerId:4}", __FUNCTION__, __LINE__);
				reportIfNotNull(list1->get(4), __FUNCTION__, __LINE__);
				list1->removeAll(true);
			}
			delete(list1);
		}
		void testInsert(){
			LinkedList<TestObject>* list1 = new LinkedList<TestObject>();
			resetTestObjectCount();
			reportIfDifferent(list1->count(), 0, __FUNCTION__, __LINE__);
			this->appendOnList(list1, 4);
			reportIfDifferent(list1->count(), 4, __FUNCTION__, __LINE__);
			TestObject* testObject5 = new TestObject();
			list1->insert(testObject5,2);
			reportIfDifferent(list1->count(), 5, __FUNCTION__, __LINE__);
			reportIfDifferent(list1->get(0)->toString(), "TestObject {innerId:1}", __FUNCTION__, __LINE__);
			reportIfDifferent(list1->get(1)->toString(), "TestObject {innerId:2}", __FUNCTION__, __LINE__);
			reportIfDifferent(list1->get(2)->toString(), "TestObject {innerId:5}", __FUNCTION__, __LINE__);
			reportIfDifferent(list1->get(3)->toString(), "TestObject {innerId:3}", __FUNCTION__, __LINE__);
			reportIfDifferent(list1->get(4)->toString(), "TestObject {innerId:4}", __FUNCTION__, __LINE__);
			reportIfNotNull(list1->get(5), __FUNCTION__, __LINE__);
			list1->insert(testObject5,10);
			reportIfDifferent(list1->count(), 11, __FUNCTION__, __LINE__);
			reportIfDifferent(list1->get(10)->toString(), "TestObject {innerId:5}", __FUNCTION__, __LINE__);
			list1->insert(testObject5,-1);
			reportIfDifferent(list1->count(), 11, __FUNCTION__, __LINE__);
			list1->remove(10);
			list1->removeAll(true);
			delete(list1);
		}
		void testRemove(){
			LinkedList<TestObject>* list1 = new LinkedList<TestObject>();
			resetTestObjectCount();
			reportIfDifferent(list1->count(), 0, __FUNCTION__, __LINE__);
			list1->remove(0, true);
			reportIfDifferent(list1->count(), 0, __FUNCTION__, __LINE__);
			this->appendOnList(list1, 4);
			reportIfDifferent(list1->get(0)->toString(), "TestObject {innerId:1}", __FUNCTION__, __LINE__);
			reportIfDifferent(list1->get(1)->toString(), "TestObject {innerId:2}", __FUNCTION__, __LINE__);
			reportIfDifferent(list1->get(2)->toString(), "TestObject {innerId:3}", __FUNCTION__, __LINE__);
			reportIfDifferent(list1->get(3)->toString(), "TestObject {innerId:4}", __FUNCTION__, __LINE__);
			reportIfNotNull(list1->get(4), __FUNCTION__, __LINE__);
			reportIfDifferent(list1->count(), 4, __FUNCTION__, __LINE__);
			list1->remove(2, true);
			reportIfDifferent(list1->get(0)->toString(), "TestObject {innerId:1}", __FUNCTION__, __LINE__);
			reportIfDifferent(list1->get(1)->toString(), "TestObject {innerId:2}", __FUNCTION__, __LINE__);
			reportIfNotNull(list1->get(2), __FUNCTION__, __LINE__);
			reportIfDifferent(list1->get(3)->toString(), "TestObject {innerId:4}", __FUNCTION__, __LINE__);
			reportIfNotNull(list1->get(4), __FUNCTION__, __LINE__);
			reportIfDifferent(list1->count(), 4, __FUNCTION__, __LINE__);
			list1->remove(3, true);
			reportIfDifferent(list1->get(0)->toString(), "TestObject {innerId:1}", __FUNCTION__, __LINE__);
			reportIfDifferent(list1->get(1)->toString(), "TestObject {innerId:2}", __FUNCTION__, __LINE__);
			reportIfNotNull(list1->get(2), __FUNCTION__, __LINE__);
			reportIfNotNull(list1->get(3), __FUNCTION__, __LINE__);
			reportIfNotNull(list1->get(4), __FUNCTION__, __LINE__);
			reportIfDifferent(list1->count(), 3, __FUNCTION__, __LINE__);
			list1->remove(0, true);
			reportIfNotNull(list1->get(0), __FUNCTION__, __LINE__);
			reportIfDifferent(list1->get(1)->toString(), "TestObject {innerId:2}", __FUNCTION__, __LINE__);
			reportIfNotNull(list1->get(2), __FUNCTION__, __LINE__);
			reportIfNotNull(list1->get(3), __FUNCTION__, __LINE__);
			reportIfNotNull(list1->get(4), __FUNCTION__, __LINE__);
			reportIfDifferent(list1->count(), 3, __FUNCTION__, __LINE__);
			list1->remove(10, true);
			list1->remove(2, true);
			reportIfNotNull(list1->get(0), __FUNCTION__, __LINE__);
			reportIfDifferent(list1->get(1)->toString(), "TestObject {innerId:2}", __FUNCTION__, __LINE__);
			reportIfNotNull(list1->get(2), __FUNCTION__, __LINE__);
			reportIfNotNull(list1->get(3), __FUNCTION__, __LINE__);
			reportIfNotNull(list1->get(4), __FUNCTION__, __LINE__);
			reportIfDifferent(list1->count(), 2, __FUNCTION__, __LINE__);
			list1->removeAll(true);
			delete(list1);
		}
		void testCreateIterator(){
			LinkedList<TestObject>* list1 = new LinkedList<TestObject>();
			resetTestObjectCount();
			this->appendOnList(list1, 4);
			Iterator<TestObject>* iterator1 = list1->createIterator();
			reportIfNull(iterator1->getCurrentItem(), __FUNCTION__, __LINE__);
			reportIfFalse(iterator1->hasNext(), __FUNCTION__, __LINE__);
			reportIfDifferent(iterator1->getCurrentItem()->toString(), "TestObject {innerId:1}", __FUNCTION__, __LINE__);
			iterator1->next();
			reportIfNull(iterator1->getCurrentItem(), __FUNCTION__, __LINE__);
			reportIfFalse(iterator1->hasNext(), __FUNCTION__, __LINE__);
			reportIfDifferent(iterator1->getCurrentItem()->toString(), "TestObject {innerId:2}", __FUNCTION__, __LINE__);
			iterator1->next();
			reportIfNull(iterator1->getCurrentItem(), __FUNCTION__, __LINE__);
			reportIfFalse(iterator1->hasNext(), __FUNCTION__, __LINE__);
			reportIfDifferent(iterator1->getCurrentItem()->toString(), "TestObject {innerId:3}", __FUNCTION__, __LINE__);
			iterator1->next();
			reportIfNull(iterator1->getCurrentItem(), __FUNCTION__, __LINE__);
			reportIfTrue(iterator1->hasNext(), __FUNCTION__, __LINE__);
			reportIfDifferent(iterator1->getCurrentItem()->toString(), "TestObject {innerId:4}", __FUNCTION__, __LINE__);
			iterator1->next();
			reportIfNotNull(iterator1->getCurrentItem(), __FUNCTION__, __LINE__);
			reportIfTrue(iterator1->hasNext(), __FUNCTION__, __LINE__);
			list1->removeAll(true);
			delete(iterator1);
			delete(list1);

			list1 = new LinkedList<TestObject>();
			resetTestObjectCount();
			iterator1 = list1->createIterator();
			reportIfNotNull(iterator1->getCurrentItem(), __FUNCTION__, __LINE__);
			reportIfTrue(iterator1->hasNext(), __FUNCTION__, __LINE__);
			iterator1->next();
			reportIfNotNull(iterator1->getCurrentItem(), __FUNCTION__, __LINE__);
			reportIfTrue(iterator1->hasNext(), __FUNCTION__, __LINE__);
			list1->removeAll(true);
			delete(iterator1);
			delete(list1);

			list1 = new LinkedList<TestObject>();
			resetTestObjectCount();
			this->appendOnList(list1);
			iterator1 = list1->createIterator();
			reportIfNull(iterator1->getCurrentItem(), __FUNCTION__, __LINE__);
			reportIfTrue(iterator1->hasNext(), __FUNCTION__, __LINE__);
			reportIfDifferent(iterator1->getCurrentItem()->toString(), "TestObject {innerId:1}", __FUNCTION__, __LINE__);
			iterator1->next();
			reportIfNotNull(iterator1->getCurrentItem(), __FUNCTION__, __LINE__);
			reportIfTrue(iterator1->hasNext(), __FUNCTION__, __LINE__);
			delete(iterator1);
			list1->removeAll(true);
			delete(list1);
		}
		void testIndexOf(){
			LinkedList<TestObject>* list1 = new LinkedList<TestObject>();
			resetTestObjectCount();
			TestObject* testObject1 = new TestObject();
			TestObject* testObject2 = new TestObject();
			TestObject* testObject3 = new TestObject();
			TestObject* testObject4 = new TestObject();
			TestObject* testObjectNULL = NULL;
			reportIfDifferent(list1->indexOf(testObject1), -1, __FUNCTION__, __LINE__);
			list1->append(testObject3);
			list1->append(testObject1);
			list1->append(testObject2);
			reportIfDifferent(list1->indexOf(NULL), -1, __FUNCTION__, __LINE__);
			reportIfDifferent(list1->indexOf(testObject1), 1, __FUNCTION__, __LINE__);
			reportIfDifferent(list1->indexOf(testObject2), 2, __FUNCTION__, __LINE__);
			reportIfDifferent(list1->indexOf(testObject3), 0, __FUNCTION__, __LINE__);
			reportIfDifferent(list1->indexOf(testObject4), -1, __FUNCTION__, __LINE__);
			reportIfDifferent(list1->indexOf(testObject2), 2, __FUNCTION__, __LINE__);
			reportIfDifferent(list1->indexOf(testObjectNULL), -1, __FUNCTION__, __LINE__);
			delete(list1);
			delete(testObject1);
			delete(testObject2);
			delete(testObject3);
			delete(testObject4);
		}
};

int main(int argc, char* argv[]){
	LinkedListTest* linkedListTest = new LinkedListTest();
	linkedListTest->testAppend();
	linkedListTest->testRemoveAll();
	linkedListTest->testGet();
	linkedListTest->testInsert();
	linkedListTest->testRemove();
	linkedListTest->testCreateIterator();
	linkedListTest->testIndexOf();
	delete(linkedListTest);
}
