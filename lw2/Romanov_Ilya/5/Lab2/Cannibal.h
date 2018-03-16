#pragma once
#include "Pot.h"
#include "Cook.h"
#include <windows.h>
class CCannibal
{
public:
	CCannibal() = default;
	void Eat(CPot &pot, const CCook &cook);
	DWORD WINAPI Live(CONST LPVOID data);
};

