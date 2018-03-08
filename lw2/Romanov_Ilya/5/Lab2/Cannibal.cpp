#include "stdafx.h"
#include "Cannibal.h"
#include <stdexcept>
#include <windows.h>


void CCannibal::Eat(CPot &pot) {
	if (pot.GetMeatCount() != 0) {
		pot.SetMeatCount(pot.GetMeatCount() - 1);
		return;
	}
	throw std::exception("Pot is empty");
}

void CCannibal::Live(CPot &pot) {
	while (true) {
		Eat(pot);
		int sleepingTime = rand() % 2000 + 1000;
		Sleep(sleepingTime);
	}
}
