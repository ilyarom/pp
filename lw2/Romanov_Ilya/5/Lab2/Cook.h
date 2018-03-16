#pragma once
#include "Pot.h"
#include <windows.h>
class CCook
{
public:
	CCook() = default;
	void StewMissionary(CPot &pot);
	bool isNeedCooking() const;
	void SetNeedCooking(bool arg);
	DWORD WINAPI Live(CONST LPVOID data);
private:
	bool isNeedCook = true;
};

static const struct Missionary {
	const int MEAT_COUNT = 30;
	const int STEW_TIME = 50000;
} missionary;

