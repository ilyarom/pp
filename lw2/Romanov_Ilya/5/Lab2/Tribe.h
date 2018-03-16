#pragma once
#include "Cannibal.h"
#include "Cook.h"
#include "Pot.h"
#include <vector>
#include "ThreadsHandler.h"
class CTribe
{
public:
	CTribe(size_t cannibalCount);
	void Live();
private:
	CCook *cook;
	CPot *pot;
	std::vector<CCannibal> cannibals;
	ThreadsHandler handler;
};

struct TribeCookingData {
	CCook *cook;
	CPot *pot;
	TribeCookingData(CCook *cookArg, CPot *potArg) {
		cook = cookArg;
		pot = potArg;
	};
};

