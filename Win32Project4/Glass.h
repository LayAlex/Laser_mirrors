#pragma once
#include "CircleObject.h"
class Glass :
	public CircleObject
{
public:
	Glass();
	~Glass();

	void Create(int, int, int);
};

