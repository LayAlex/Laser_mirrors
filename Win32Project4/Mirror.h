#pragma once
#include "CircleObject.h"
class Mirror :
	public CircleObject
{
public:
	Mirror();	
	~Mirror();

	void Create(int, int,int);
};

