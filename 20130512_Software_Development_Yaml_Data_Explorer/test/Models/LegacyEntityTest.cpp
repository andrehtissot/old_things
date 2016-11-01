#include "../TestBase.cpp"
#include "../../src/Models/LegacyEntity.cpp"
using namespace Models;

class LegacyEntityTest : public TestBase {
	public:
		class SubLegacyEntity : public LegacyEntity {
			public:
				SubLegacyEntity(){};
				SubLegacyEntity(int const id, std::string const legacyId) : LegacyEntity(id, legacyId) {};
		};
	private:
		SubLegacyEntity entityAttribute1;
		SubLegacyEntity entityAttribute2;
	public:
		void testEqualAndDifferentForId(){
			LegacyEntity *entity1 = new SubLegacyEntity();
			entity1->setId(10);

			entityAttribute1.setId(12);
			if(entityAttribute1 == entity1)
				report("The first entity was suposed to be different to the second!", __FUNCTION__, __LINE__);

			entityAttribute1.setId(10);
			if(entityAttribute1 != entity1)
				report("The first entity was suposed to be equal to the second!", __FUNCTION__, __LINE__);

			LegacyEntity *entity2 = new SubLegacyEntity(10, "TEN");

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

		void testEqualAndDifferentForLegacyIdAndId(){
			LegacyEntity *entity1 = new SubLegacyEntity();
			entity1->setId(10);
			entity1->setLegacyId("TEN");

			entityAttribute1.setId(12);
			entityAttribute1.setLegacyId("TWELVE");
			if(entityAttribute1 == entity1)
				report("The first entity was suposed to be different to the second!", __FUNCTION__, __LINE__);

			entityAttribute1.setId(10);
			entityAttribute1.setLegacyId("TEN");
			if(entityAttribute1 != entity1)
				report("The first entity was suposed to be equal to the second!", __FUNCTION__, __LINE__);

			LegacyEntity *entity2 = new SubLegacyEntity(10, "TEN");

			entityAttribute1.setId(12);
			entityAttribute1.setLegacyId("TWELVE");
			if(entityAttribute1 == entity2)
				report("The first entity was suposed to be different to the second!", __FUNCTION__, __LINE__);

			entityAttribute1.setId(10);
			entityAttribute1.setLegacyId("TEN");
			if(entityAttribute1 != entity2)
				report("The first entity was suposed to be equal to the second!", __FUNCTION__, __LINE__);

			entityAttribute2.setId(12);
			entityAttribute2.setLegacyId("TWELVE");
			if(entityAttribute1 == entityAttribute2)
				report("The first entity was suposed to be different to the second!", __FUNCTION__, __LINE__);

			entityAttribute2.setId(10);
			entityAttribute2.setLegacyId("TEN");
			if(entityAttribute1 != entityAttribute2)
				report("The first entity was suposed to be equal to the second!", __FUNCTION__, __LINE__);

			delete(entity1);
			delete(entity2);
		}

		void testEqualAndDifferentForLegacyId(){
			LegacyEntity *entity1 = new SubLegacyEntity();
			entity1->setId(1);
			entity1->setLegacyId("TEN");

			entityAttribute1.setId(2);
			entityAttribute1.setLegacyId("TWELVE");
			if(entityAttribute1 == entity1)
				report("The first entity was suposed to be different to the second!", __FUNCTION__, __LINE__);

			entityAttribute1.setId(3);
			entityAttribute1.setLegacyId("TEN");
			if(entityAttribute1 != entity1)
				report("The first entity was suposed to be equal to the second!", __FUNCTION__, __LINE__);

			LegacyEntity *entity2 = new SubLegacyEntity(10, "TEN");

			entityAttribute1.setId(4);
			entityAttribute1.setLegacyId("TWELVE");
			if(entityAttribute1 == entity2)
				report("The first entity was suposed to be different to the second!", __FUNCTION__, __LINE__);

			entityAttribute1.setId(5);
			entityAttribute1.setLegacyId("TEN");
			if(entityAttribute1 != entity2)
				report("The first entity was suposed to be equal to the second!", __FUNCTION__, __LINE__);

			entityAttribute2.setId(6);
			entityAttribute2.setLegacyId("TWELVE");
			if(entityAttribute1 == entityAttribute2)
				report("The first entity was suposed to be different to the second!", __FUNCTION__, __LINE__);

			entityAttribute2.setId(7);
			entityAttribute2.setLegacyId("TEN");
			if(entityAttribute1 != entityAttribute2)
				report("The first entity was suposed to be equal to the second!", __FUNCTION__, __LINE__);

			delete(entity1);
			delete(entity2);
		}

		void testEqualAndDifferentForLegacyIdOrId(){
			LegacyEntity *entity1 = new SubLegacyEntity();
			entity1->setId(1);
			entity1->setLegacyId("TEN");

			entityAttribute1.setId(2);
			entityAttribute1.setLegacyId("TWELVE");
			if(entityAttribute1 == entity1)
				report("The first entity was suposed to be different to the second!", __FUNCTION__, __LINE__);

			entityAttribute1.setId(1);
			entityAttribute1.setLegacyId("");
			if(entityAttribute1 != entity1)
				report("The first entity was suposed to be equal to the second!", __FUNCTION__, __LINE__);

			LegacyEntity *entity2 = new SubLegacyEntity(3, "");

			entityAttribute1.setId(4);
			entityAttribute1.setLegacyId("TWELVE");
			if(entityAttribute1 == entity2)
				report("The first entity was suposed to be different to the second!", __FUNCTION__, __LINE__);

			entityAttribute1.setId(3);
			entityAttribute1.setLegacyId("TEN");
			if(entityAttribute1 != entity2)
				report("The first entity was suposed to be equal to the second!", __FUNCTION__, __LINE__);

			entityAttribute2.setId(6);
			entityAttribute2.setLegacyId("TWELVE");
			if(entityAttribute1 == entityAttribute2)
				report("The first entity was suposed to be different to the second!", __FUNCTION__, __LINE__);

			entityAttribute2.setId(3);
			entityAttribute2.setLegacyId("");
			if(entityAttribute1 != entityAttribute2)
				report("The first entity was suposed to be equal to the second!", __FUNCTION__, __LINE__);

			delete(entity1);
			delete(entity2);
		}

};

int main(int argc, char* argv[]){
	LegacyEntityTest* legacyEntityTest = new LegacyEntityTest();
	legacyEntityTest->testEqualAndDifferentForId();
	legacyEntityTest->testEqualAndDifferentForLegacyIdAndId();
	legacyEntityTest->testEqualAndDifferentForLegacyId();
	legacyEntityTest->testEqualAndDifferentForLegacyIdOrId();
	delete(legacyEntityTest);
}
