#include "stdafx.h"
#include "Tribe.h"

HANDLE CTribe::semaphore;

int main()
{
	CTribe::semaphore = CreateSemaphore(NULL, 1, 1, NULL);
	CTribe tribe(5);
	std::cout << "Tribe created" << std::endl;
	tribe.Live();
	return 0;
}

