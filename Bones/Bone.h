#ifndef BONE_H
#define BONE_H

#pragma once 

/*****************************************************************************
*	Author:			Efrain Astudillo
*	Description:	Bones Structure for then be drawn with OpenGL
*	Reference:		http://content.gpwiki.org/index.php/OpenGL:Tutorials:Basic_Bones_System
******************************************************************************/
#include "Libraries.h"

class Bone{
public:
	//==============constructors==================
	//only create an instance of Bone with "createBone" method from BoneUtility
	Bone(int id,std::string name,float angle,float lenght,float x,float y,float z)
		:_ID(id), _name(name),_angle(angle),_lenght(lenght),_x(x),_y(y),_z(z){
		_isValid=true;
		LOG("Successful creation of bone");
	};

	//==============getters==================
	int		getID();
	float getX();					//get x-coordinate
	float getY();					//get y-coordinate
	float getZ();					//get z-coordinate
	float getAngle();				//get angle of the bone
	float getLenght();				//get lenght of the bone
	int	   getChildrenCount();		//Quantity of the children
	std::vector<Bone*> getChildren();
	bool isValid();					//test if the object is valid
	std::string getName();			//get the name of the Bone

	//==============setters==================
	void setName(std::string);				//set the identification's name of the bone
	void setID(int id);						//set unique identification's ID of the bone 
	void setPosition(float x,float,float);	//set the position in the space 3D of the bone
	void setAngle(float angle);				//set the angle of the bone in the space
	void setLenght(float lenght);			//set the lenght of hte bone
	void setParent(Bone*);						//

	Status addChild(Bone *child);			//append child at this bone
	Status addParent(Bone *parent);			//append parent to this child
	Status changeParent();					//this coming soon
	Status removeAllChildren();				//remove all childrens of this bone
	Status removeChild(int ID);				//remove child with this ID

	Bone* getChildById(int id);				//get a reference of child bone by ID
	Bone* getChildByName(std::string);		//get a reference of child bone by name
	Bone* getParent();
	//==============overrides methods==================
	//toString() like Java
	friend std::ostream& operator<<(std::ostream &strm, const Bone &a) {
		return strm << "Bone(key->" << a._ID << ", name->"<<a._name<<")";
	};
	//override operator < . Std::map use it for order the elements store in it 
	bool operator<( Bone& tmp) {
		return this->getID() < tmp.getID();
	};
private:
	Bone();//this constructor is never used, ...Dont should be used
	//position initial of the bone
	float				_x;//X
	float				_y;//Y
	float				_z;//Z
	std::string			_name;			//name for each bone
	int					_ID;			//identification of each bone
	float				_angle;			//angle of orientation of the bone in radians
	float				_lenght;		//lenght of the bone
	bool				_isValid;
	std::vector<Bone*> children;		// children
	int amountOfChildren;				/* amount of chlidren*/
 	Bone *parent;						/* Parent bone */
};
/****************************************************************************
*		BoneUtility Class implementing a Singleton Pattern
*		All methods are statics and its contains a map with all bones
*****************************************************************************/
class BoneUtility{
public:
	static BoneUtility &getInstance();
	
	static Status addKeyAndBone(int, Bone*);				//add a element into std::map
	static Bone* findByName(char *name);					//this method will be implemented at last
	static Bone* findByID(int ID);							//Find a bone by ID in the Structure
	static Bone* createBone(int ID,char* name,				//
	float angle,float lenght,float x,float y,float z);		//create a Bone
	static Status removeBone(int id);						//remove Bone in std::Map by id
	static Status removeBones(std::vector<Bone*>);			//remove bones in std::map that contains std::vector 
	static  std::map<int,Bone*>& getBones();				//get an instance of the Bones return std::map 
	
private:
	//To do all posible duplicated are private for not access them
	BoneUtility();
	BoneUtility(const BoneUtility&);
	BoneUtility& operator=(const BoneUtility&);
	static std::map<int,Bone*> BoneIDs;
};
#endif