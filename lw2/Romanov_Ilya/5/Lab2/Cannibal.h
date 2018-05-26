#pragma once
#include "Pot.h"
#include "Cook.h"
#include <string>

class CCannibal
{
public:
	CCannibal() = default;
	CCannibal(std::string name);
	void Eat(CPot &pot, const CCook &cook);
	std::string GetName();
private:
	std::string m_name;
};

