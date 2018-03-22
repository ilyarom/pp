#pragma once
#include <utility>
#include <Windows.h>
#include "RandomPoint.h"
#include "ThreadsHandler.h"
#include <ctime>

struct IterationsData {
	size_t commonPoints;
	size_t *commonProcessedPoints;
	IterationsData(size_t commonPoints, size_t *commonProcessedPoints) {
		this->commonPoints = commonPoints;
		this->commonProcessedPoints = commonProcessedPoints;
	}
};

struct ThreadData {
	size_t threadIterations;
	size_t *caughtPoints;
	IterationsData *iterationsData;
	ThreadData(size_t threadIterations, size_t *caughtPoints, IterationsData *iterationsData) {
		this->threadIterations = threadIterations;
		this->caughtPoints = caughtPoints;
		this->iterationsData = iterationsData;
	}
};

class PiGenerator
{
public:
	PiGenerator(const size_t iterations, const size_t threads);
	double GetPiValue();
private:
	static bool isPointInCircle(const RandomPoint &point);
	static DWORD WINAPI CountHits(CONST LPVOID data);
	static DWORD WINAPI CountIterations(CONST LPVOID data);
	size_t caughtPoints = 0;
	size_t iterations;
	static const size_t sideSize = 1;
	static const size_t fieldSize = sideSize * sideSize;
	size_t threads;
	const size_t PI_CALCULATION_COEFFICIENT = 4;
};

