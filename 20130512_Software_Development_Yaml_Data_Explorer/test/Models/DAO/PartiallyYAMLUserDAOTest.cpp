#include "../../TestBase.cpp"
#include "../../../src/Models/DAO/PartiallyYAMLUserDAO.cpp"
using namespace Models::DAO;

class PartiallyYAMLUserDAOTest : public TestBase {
	public:
		void testNew(){
			PartiallyYAMLUserDAO* partiallyYAMLUserDAO1 = new PartiallyYAMLUserDAO();
			delete(partiallyYAMLUserDAO1);
		}
		void testLoadAllToList(){
			PartiallyYAMLUserDAO* partiallyYAMLUserDAO1 = new PartiallyYAMLUserDAO();
			EntityList* list1 = new EntityList();
			partiallyYAMLUserDAO1->loadAllToList(list1);
			std::cout << list1->count() << std::endl;

			//Free Memory
			Utils::Lists::Iterator<Entity>* iterator = list1->createIterator();
			UserEntity* currentItem = static_cast<UserEntity*>(iterator->getCurrentItem());
			while(currentItem != NULL || iterator->hasNext()) {
				if(currentItem != NULL)
					delete(currentItem);
				iterator->next();
				currentItem = static_cast<UserEntity*>(iterator->getCurrentItem());
			}
			delete(iterator);
			delete(list1);
			delete(partiallyYAMLUserDAO1);
		}
		void testSave(){
			PartiallyYAMLUserDAO* partiallyYAMLUserDAO1 = new PartiallyYAMLUserDAO();
			UserEntity* user = new UserEntity();
			user->setName("Test1");
			user->setIsDeveloper(true);
			Time* entryTime = new Time();
			entryTime->loadFromString("09:54:51.801376 -02:00", "H:i:s.u P");
			user->setEntryAt(entryTime);
			Time* departTime = new Time();
			departTime->loadFromString("19:14:51.801376 -02:00", "H:i:s.u P");
			user->setDepartAt(departTime);

			DateTime* createDateTime = new DateTime();
			createDateTime->loadFromString("2013-04-06 09:54:51.801376 -02:00", "Y-m-d H:i:s.u P");
      		user->setCreatedAt(createDateTime);
			DateTime* updateDateTime = new DateTime();
			updateDateTime->loadFromString("2012-11-27 09:12:08.10 -00:30", "Y-m-d H:i:s.u P");
      		user->setUpdatedAt(updateDateTime);
      		partiallyYAMLUserDAO1->save(user);
      		delete(user);
			delete(partiallyYAMLUserDAO1);

			BinaryUserDAO* BinaryUserDAO1 = new BinaryUserDAO();
			EntityList* list1 = new EntityList();
			BinaryUserDAO1->loadAllToList(list1);
			reportIfDifferent(list1->count(), 1, __FUNCTION__, __LINE__);
			if(list1->count() == 1){
				Entity* entity = list1->get(0);
				reportIfNull(entity, __FUNCTION__, __LINE__);
				if(entity != NULL){
					UserEntity* user = static_cast<UserEntity*>(entity);
					reportIfDifferent(user->getName(), "Test1", __FUNCTION__, __LINE__);
					reportIfFalse(user->getIsDeveloper(), __FUNCTION__, __LINE__);
					reportIfNullC(user->getCreatedAt(), __FUNCTION__, __LINE__);
					reportIfNullC(user->getUpdatedAt(), __FUNCTION__, __LINE__);
					createDateTime = const_cast<DateTime*>(user->getCreatedAt());
					updateDateTime = const_cast<DateTime*>(user->getUpdatedAt());
					reportIfDifferent(createDateTime->format("Y-m-d H:i:s.u P"), "2013-04-06 09:54:51.801376 -02:00", __FUNCTION__, __LINE__);
					reportIfDifferent(updateDateTime->format("Y-m-d H:i:s.u P"), "2012-11-27 09:12:08.10 -00:30", __FUNCTION__, __LINE__);
					entryTime = const_cast<Time*>(user->getEntryAt());
					departTime = const_cast<Time*>(user->getDepartAt());
					reportIfDifferent(entryTime->format("H:i:s.u P"), "09:54:51.801376 -02:00", __FUNCTION__, __LINE__);
					reportIfDifferent(departTime->format("H:i:s.u P"), "19:14:51.801376 -02:00", __FUNCTION__, __LINE__);
				}
			}
		}
};

int main(int argc, char* argv[]){
	PartiallyYAMLUserDAOTest* partiallyYAMLUserDAOTest = new PartiallyYAMLUserDAOTest();
	partiallyYAMLUserDAOTest->testNew();
	partiallyYAMLUserDAOTest->testSave();
	delete(partiallyYAMLUserDAOTest);
}

