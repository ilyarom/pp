#include "stdafx.h"
#include "Cook.h"


void CCook::StewMissionary(CPot &pot) {
	if (!isSleep) {
		pot.SetMeatCount();
	}
}
