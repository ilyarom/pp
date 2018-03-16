#include "stdafx.h"
#include "Tribe.h"


CTribe::CTribe(size_t cannibalCount)
{
	for (size_t i = 0; i < cannibalCount; ++i) {
		CCannibal cannibal;
		cannibals.push_back(cannibal);
	}
}


void CTribe::Live() {
	handler.AddThread(cook->Live, pot);
	for (size_t i = 0; i < cannibals.size(); ++i) {
		TribeCookingData *data = new TribeCookingData(cook, pot);
		handler.AddThread(cannibals[i].Live, data);
	}
	handler.Wait();
}
