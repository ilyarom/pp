#pragma once
#include "Pot.h"
#include <windows.h>

class CCook
{
public:
	CCook() = default;
	void StewMissionary(CPot &pot);
	bool isNeedCooking() const;
	bool isCooking() const;
	void SetNeedCooking(bool arg);
private:
	bool isNeedCook = true;
	bool isCook = false;
};

static const struct Missionary {
	const int MEAT_COUNT = 5;
	const int STEW_TIME = 5000;
	int GetStewTimeInSeconds() {
		return STEW_TIME / 1000;
	}
} missionary;
