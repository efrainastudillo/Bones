#include "Bone.h"

/*All static variables that contains some class should be initialize like this*/
std::map<int,Bone*> BoneUtility::BoneIDs;
//=============================FINISHED==============================AND TEST
std::map<int,Bone*>& BoneUtility::getBones(){
	return BoneUtility::BoneIDs;
}
//=============================FINISHED==============================AND TEST
BoneUtility& BoneUtility::getInstance(){
		static BoneUtility utility;
		return utility;
}
//=============================FINISHED==============================AND TEST
//only should be used in createBone method
Status BoneUtility::addKeyAndBone(int key, Bone* bone){
	try{
		BoneUtility::getInstance().getBones().insert(std::make_pair (key,bone));
	}catch(std::exception& e){
		LOG("An error occured"<<e.what());
		return Status::STATUS_ERROR;
	}
	return Status::STATUS_OK;
}
//=============================FINISHED==============================AND TEST
//return a Bone Pointer
Bone* BoneUtility::createBone(int ID,char* name,float angle,float lenght,float x,float y,float z){
	if(BoneUtility::getInstance().getBones().count(ID)!=0){
		LOG("Bone insertion attemp failed \""<<name<<"\", Key "<<ID<<" Already Exist");
		return BoneUtility::getInstance().findByID(ID);
	}
	else{
		 Bone *bone=new Bone(ID,name,angle,lenght,x,y,z);
		 if(BoneUtility::getInstance().addKeyAndBone(ID,bone)!=Status::STATUS_OK){
			 throw new std::exception("Can't insert bone into MAP");
		 };
		 return bone;
	}
}
//=============================FINISHED==============================AND TEST
Status BoneUtility::removeBone(int id){
	if(BoneUtility::getInstance().getBones().count(id)!=0){
		BoneUtility::getInstance().getBones().erase(id);
		return Status::STATUS_OK;
	}else{
		LOG("Can't remove bone with key->"<<id);
		return Status::STATUS_ERROR;
	}
}
//=============================FINISHED==============================AND TEST
Status BoneUtility::removeBones(std::vector<Bone*> bones){
	for(int i=0;i<bones.size();i++){
		if(BoneUtility::getInstance().removeBone(bones[i]->getID())!=Status::STATUS_OK){
			LOG("Error trying to erase bones of the MapBone");
			return Status::STATUS_ERROR;
		}
	};
	return Status::STATUS_OK;
}
//=============================FINISHED==============================AND TEST
Bone* BoneUtility::findByName(char* name){
	std::map<int,Bone*>::iterator it;
	for(it= BoneUtility::getInstance().getBones().begin(); it != BoneUtility::getInstance().BoneIDs.end();++it){
		int key=it->first;
		Bone *value=it->second;
		//if two  strings are equals
		if(value->getName().compare(name)==0){
			LOG("Bone Found Key: "<<key<< " Name: "<< value->getName());
			return value;
		}
	}
	LOG("Bone \""<<name<<"\" not Found");
	return NULL;
}
//=============================FINISHED==============================AND TEST
Bone* BoneUtility::findByID(int id){ 
	if(BoneUtility::getInstance().getBones().count(id)!=0){
		return BoneUtility::getInstance().getBones().find(id)->second;
	}
	else{
		LOG("Bone not found");
		return NULL;
	}
}
/****************************    Private methods   ***********************************/
BoneUtility::BoneUtility(){}
BoneUtility::BoneUtility(const BoneUtility&){};
BoneUtility& BoneUtility::operator=(const BoneUtility&){
	return this->getInstance();
};