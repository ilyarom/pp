#pragma once
#include <utility>
#include "RandomPoint.h"
#include "ThreadsHandler.h"
#include <ctime>

class PiGenerator
{
public:
	PiGenerator(const size_t iterations);
	double GetPiValue();
	void SetMultithreading(bool multithreading);
private:
	static bool isPointInCircle(const RandomPoint &point);
	void CountHits();
	void CountHitsParallel();
	void CheckPoint(int &caughtPoints);
	int caughtPoints;
	size_t iterations;
	static const size_t sideSize = 1;
	static const size_t fieldSize = sideSize * sideSize;
	const size_t PI_CALCULATION_COEFFICIENT = 4;
	bool multithreading = true;
};

