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
	static DWORD WINAPI RunCannibalLife(CONST LPVOID data);
	static DWORD WINAPI RunCookLife(CONST LPVOID data);
	static void PrintMessage(const std::string &message);
	static HANDLE semaphore;
private:
	CCook *cook = new CCook();
	CPot *pot = new CPot();
	std::vector<CCannibal> cannibals = {};
	ThreadsHandler handler;
	const size_t MAX_EATING_CANIBALLS_COUNT = 3;
	std::vector<CCannibal*> potQueue;
};

struct TribeCookingData {
	CCook *cook;
	CPot *pot;
	TribeCookingData(CCook *cookArg, CPot *potArg) {
		cook = cookArg;
		pot = potArg;
	};
};

struct CannibalData {
	TribeCookingData * cookingData;
	CCannibal * cannibal;
	CannibalData(TribeCookingData *cookArg, CCannibal *cannibalArg) {
		cookingData = cookArg;
		cannibal = cannibalArg;
	};
};
