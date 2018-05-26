#include "stdafx.h"
#include "Tribe.h"


CTribe::CTribe(size_t cannibalCount)
{
	for (size_t i = 0; i < cannibalCount; ++i) {
		CCannibal cannibal("#" + std::to_string(i));
		cannibals.push_back(cannibal);
	}
}

DWORD WINAPI CTribe::RunCookLife(CONST LPVOID data) {
	TribeCookingData *cookingData = (TribeCookingData *)data;
	const int SECOND_TO_MILISECOND_DIFFERENCE = 1000;
	while (true) {
		CCook *cook = cookingData->cook;
		CPot *pot = cookingData->pot;
		if (cook->IsNeedCooking() && !cook->IsCooking()) {
			PrintMessage("[Cook]: Empty pot? Guys, please wait " + std::to_string(missionary.STEW_TIME / SECOND_TO_MILISECOND_DIFFERENCE) + " seconds");
			cookingData->cook->StewMissionary(*pot);
		}
	}
	return 0;
}

void CTribe::PrintMessage(const std::string &message) {
	printf((message + '\n').c_str());
}

DWORD WINAPI CTribe::RunCannibalLife(CONST LPVOID data) {
	CannibalData *cannibalData = (CannibalData *)data;
	while (true) {
		try {
			CCannibal *cannibal = cannibalData->cannibal;
			CCook *cook = cannibalData->cookingData->cook;
			CPot *pot = cannibalData->cookingData->pot;
			cannibal->Eat(*pot, *cook);
			PrintMessage("[Cannibal " + cannibal->GetName() + "] eat meat");
		}	
		catch (const std::exception &exc) {
			WaitForSingleObject(semaphore, INFINITE);
			CCannibal *cannibal = cannibalData->cannibal;
			CCook *cook = cannibalData->cookingData->cook;
			if (!cook->IsNeedCooking() && !cook->IsCooking()) {
				PrintMessage("[Cannibal " + cannibal->GetName() + "]: Hey cook! Where is my meat!!!");
				cook->SetNeedCooking(true);
			}
			ReleaseSemaphore(semaphore, 1, NULL);
		}
		//std::srand(std::time(NULL));
		std::random_device rnd;
		const int SLEEPING_TIME = rnd() % 2000 + 1000;
		Sleep(SLEEPING_TIME);
	}
	return 0;
}

void CTribe::Live() {
	TribeCookingData *data = new TribeCookingData(cook, pot);
	handler.AddThread(RunCookLife, data);
	PrintMessage("[Cook]: Hi, i'm cook and i like stew missionary");
	for (size_t i = 0; i < cannibals.size(); ++i) {
		CannibalData *cannibalData = new CannibalData(data, &cannibals[i]);
		PrintMessage("[Cannibal" + cannibals[i].GetName() + "]: Hi, i'm very hungry cannibal");
		handler.AddThread(RunCannibalLife, cannibalData);
	}
	handler.Wait();
}
