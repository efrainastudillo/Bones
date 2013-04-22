#include "Libraries.h"

int main(int argc,char *argv[]){
	Bone *b=BoneUtility::getInstance().createBone	(1,"efrain",45,12,2.53,3.6,6.9);
	Bone *b1=BoneUtility::getInstance().createBone	(2,"marcos",45,12,2.53,3.6,6.9);
	Bone *b2=BoneUtility::getInstance().createBone	(3,"lucas",45,12,2.53,3.6,6.9);
	Bone *b3=BoneUtility::getInstance().createBone	(3,"juan",45,12,2.53,3.6,6.9);
	LOG("Test "<<b->getName());
	
	Bone *b4=BoneUtility::getInstance().findByName("efrain");
	LOG("Nombre de Hueso encontrado "<<b2->getName());
	LOG(b2);
	
	b4->setName("ANASTASIO");

	Bone *t=BoneUtility::getInstance().findByID(1);
	if(t)	LOG(t->getName());
	BoneUtility::removeBone(t->getID());
	t=BoneUtility::getInstance().findByID(1);
	if(t){
		LOG(t->getName());
	}
	else 
		LOG("Dont found");
	

	b->addChild(b1);
	b->addChild(b2);
	b1->setParent(b);
	b2->setParent(b);

	LOG(b->getChildrenCount());
	LOG(*b->getChildren()[0]);
	LOG("Nombre del Child "<<b->getChildren()[1]->getName());
	LOG("Nombre del Parent "<<b->getChildren()[1]->getParent()->getName());

	b->getChildren()[0]->setName("Natanael");//change name marcos to NATANAEL

	Bone* t1=b->getChildById(2);
	//root->removeAllChildren();
	LOG(t1->getName());
	LOG(BoneUtility::getInstance().findByID(2)->getName());
	LOG("Before "<<BoneUtility::getInstance().getBones().size());
	b->removeAllChildren();
	LOG("After "<<BoneUtility::getInstance().getBones().size());
	t1=b->getChildById(2);
	LOG(BoneUtility::getInstance().findByID(2));
	
	
	//LOG(t1->getName());

	system("pause");
	return 0;
}