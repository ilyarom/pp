#pragma once
#include "Cannibal.h"
#include "Cook.h"
#include "Pot.h"
#include "vector"
class CTribe
{
public:
	CTribe();
	void Live();
private:
	CCook cook;
	CPot pot;
	std::vector<CCannibal> cannibal;
};

