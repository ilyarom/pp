#pragma once
#include "Pot.h"
class CCook
{
public:
	CCook();
	~CCook();
	void StewMissionary(CPot &pot);
private:
	bool isSleep = true;
};

