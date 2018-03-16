#include "stdafx.h"
#include "Cook.h"

bool CCook::isNeedCooking() const {
	return isNeedCook;
}

void CCook::SetNeedCooking(bool arg) {
	isNeedCook = arg;
}

void CCook::StewMissionary(CPot &pot) {
	int cookingTime = missionary.STEW_TIME;
	Sleep(cookingTime);
	pot.SetMeatCount(missionary.MEAT_COUNT);
	isNeedCook = false;
}

DWORD WINAPI CCook::Live(CONST LPVOID data) {
	while (true) {
		CPot *potData = (CPot *)data;
		if (isNeedCook) {
			StewMissionary(*potData);
		}
	}
	return 0;
}

