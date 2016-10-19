#pragma once
#include "CircleObject.h"
class LazerGun :
	public CircleObject
{
public:
	LazerGun();
	~LazerGun();

	void Create(int, int, int);
};

