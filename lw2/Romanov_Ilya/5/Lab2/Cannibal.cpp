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

CCannibal::CCannibal(std::string name) {
	m_name = name;
}

std::string CCannibal::GetName() {
	return m_name;
}
