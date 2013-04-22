#include "Bone.h"

int Bone::getID(){
	return Bone::_ID;
}
//=============================FINISHED==============================AND TEST
Status Bone::removeAllChildren(){
	if(Bone::children.size()==0){
		LOG("Don't have any child to erase");
		return Status::STATUS_ERROR;
	}else{
		if(BoneUtility::getInstance().removeBones(this->children)!=Status::STATUS_OK){
			LOG("Error to try removing all Children of "<<this->_name<<" Bone");
			return Status::STATUS_ERROR;
		}
		Bone::children.clear();
		return Status::STATUS_OK;
	}
}
//=============================FINISHED==============================AND TEST
Status Bone::addChild(Bone *child){
	std::vector<Bone*>::iterator it=Bone::children.end();
	Bone::children.insert(it,child);
	return Status::STATUS_OK;
}

Status Bone::addParent(Bone* parent){return Status::STATUS_OK;}
Status Bone::changeParent(){return Status::STATUS_OK;}
//=============================FINISHED==============================AND TEST
Status Bone::removeChild(int ID){
	std::vector<Bone*>::iterator it=this->children.begin();
	for(;it!=this->children.end();it++){
		if((*it)->getID()==ID){
			this->children.erase(it);
			return Status::STATUS_OK;
		}
	}
	LOG("Can't remove child with key->"<<ID);
	return Status::STATUS_ERROR;
}
//=============================FINISHED==============================AND TEST
Bone* Bone::getChildById(int id){
	std::vector<Bone*>::iterator it=children.begin();
	Bone* temp;
	for(;it!=this->children.end();it++){
		temp=*it;
		if((*it)->getID()==id){
			return temp;
		}
	}
	LOG("Child not found with key->"<<id);
	return NULL;
};
//=============================FINISHED==============================AND TEST
/****************** getters and setters**************************/
float Bone::getAngle(){
	return Bone::_angle;
}
int Bone::getChildrenCount(){
	return Bone::children.size();
};
std::vector<Bone*> Bone::getChildren(){
	return Bone::children;
}
float Bone::getLenght(){
	return Bone::_lenght;	
}

float Bone::getX(){
	return Bone::_x;
}
float Bone::getY(){
	return Bone::_y;
}
float Bone::getZ(){
	return Bone::_z;
}
std::string Bone::getName(){
	return Bone::_name;
}
bool Bone::isValid(){
	return Bone::_isValid;
}

void Bone::setAngle(float angle){
	Bone::_angle=angle;
}
void Bone::setLenght(float lenght){
	Bone::_lenght=lenght;
}
void Bone::setPosition(float x,float y, float z){
	Bone::_x=x;
	Bone::_y=y;
	Bone::_z=z;
}
void Bone::setID(int id){
	Bone::_ID=id;
}
void Bone::setName(std::string name){
	Bone::_name=name;
}
void Bone::setParent(Bone* p){
	this->parent=p;
}
Bone* Bone::getParent(){
	return this->parent;
}
Bone::Bone(){
	Bone::_isValid=false;//I use isValid parameter because this constructor will never be used
	//although it's private
}