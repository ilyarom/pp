#include "stdafx.h"
#include "Cook.h"

bool CCook::isNeedCooking() const {
	return isNeedCook;
}

bool CCook::isCooking() const {
	return isCook;
}

void CCook::SetNeedCooking(bool arg) {
	isNeedCook = arg;
}

void CCook::StewMissionary(CPot &pot) {
	isCook = true;
	int cookingTime = missionary.STEW_TIME;
	Sleep(cookingTime);
	pot.SetMeatCount(missionary.MEAT_COUNT);
	isCook = false;
	isNeedCook = false;
}
