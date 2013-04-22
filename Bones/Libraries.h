#ifndef LIBRARIES_H
#define LIBRARIES_H
#pragma once

 /* Define numbers and flags */
 #define MAX_CHCOUNT				8				/* Max children count */
 #define BONE_ABSOLUTE_ANGLE		0x01		/* Bone angle is absolute or relative to parent */
 #define BONE_ABSOLUTE_POSITION		0x02	/* Bone position is absolute in the world or relative to the parent */
 #define BONE_ABSOLUTE				(BONE_ABSOLUTE_ANGLE | BONE_ABSOLUTE_POSITION)
 #define LOG(msg) (std::cout<<">> BONE: \t"<<msg<<std::endl);

typedef enum Status{ 
	STATUS_OK,STATUS_ERROR,STATUS_UNKNOWN
}Status;

/*includes*/
#include <iostream>
#include <vector>
#include <array>
#include <exception>
#include <string>
#include <map>
#include "Bone.h"

#endif