#include "stdafx.h"
#include "Cannibal.h"
#include "Tribe.h"
#include <stdexcept>
#include <windows.h>

void CCannibal::Eat(CPot &pot, const CCook &cook) {
	if (pot.GetMeatCount() != 0) {
		pot.SetMeatCount(pot.GetMeatCount() - 1);
		return;
	}
	throw std::exception("Pot is empty");
}

DWORD WINAPI CCannibal::Live(CONST LPVOID data) {
	while (true) {
		TribeCookingData *tribeCookingData = (TribeCookingData *)data;
		try {
			Eat(*tribeCookingData->pot, *tribeCookingData->cook);
		}
		catch(std::exception exc) {
			if (!(*tribeCookingData->cook).isNeedCooking()) {
				(*tribeCookingData->cook).SetNeedCooking(true);
			}
		}
		int sleepingTime = rand() % 2000 + 1000;
		Sleep(sleepingTime);
	}
	return 0;
}
