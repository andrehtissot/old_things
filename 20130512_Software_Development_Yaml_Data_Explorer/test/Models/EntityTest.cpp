#include "../TestBase.cpp"
#include "../../src/Models/Entity.cpp"
using namespace Models;

class EntityTest : public TestBase {
	public:
		class SubEntity : public Entity {
			public:
				SubEntity(){};
				SubEntity(int const id) : Entity(id) {};
		};
	private:
		SubEntity entityAttribute1;
		SubEntity entityAttribute2;
	public:
		void testEqualAndDifferent(){
			Entity *entity1 = new SubEntity();
			entity1->setId(10);

			entityAttribute1.setId(12);
			if(entityAttribute1 == entity1)
				report("The first entity was suposed to be different to the second!", __FUNCTION__, __LINE__);

			entityAttribute1.setId(10);
			if(entityAttribute1 != entity1)
				report("The first entity was suposed to be equal to the second!", __FUNCTION__, __LINE__);

			Entity *entity2 = new SubEntity(10);

			entityAttribute1.setId(12);
			if(entityAttribute1 == entity2)
				report("The first entity was suposed to be different to the second!", __FUNCTION__, __LINE__);

			entityAttribute1.setId(10);
			if(entityAttribute1 != entity2)
				report("The first entity was suposed to be equal to the second!", __FUNCTION__, __LINE__);

			entityAttribute2.setId(12);
			if(entityAttribute1 == entityAttribute2)
				report("The first entity was suposed to be different to the second!", __FUNCTION__, __LINE__);

			entityAttribute2.setId(10);
			if(entityAttribute1 != entityAttribute2)
				report("The first entity was suposed to be equal to the second!", __FUNCTION__, __LINE__);

			delete(entity1);
			delete(entity2);
		}

};

int main(int argc, char* argv[]){
	EntityTest* entityTest = new EntityTest();
	entityTest->testEqualAndDifferent();
	delete(entityTest);
}
