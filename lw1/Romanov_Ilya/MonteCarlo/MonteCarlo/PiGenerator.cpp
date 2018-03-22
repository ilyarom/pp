#include "stdafx.h"
#include "PiGenerator.h"
#include <iostream>
#include <string>


PiGenerator::PiGenerator(const size_t iterations, const size_t threads) {
	this->iterations = iterations;
	this->threads = threads;
}

bool PiGenerator::isPointInCircle(const RandomPoint &point) {
	return pow(point.GetX(), 2) + pow(point.GetY(), 2) <= fieldSize;
}

DWORD WINAPI PiGenerator::CountIterations(CONST LPVOID data) {
	IterationsData *iterationsData = (IterationsData *)data;
	std::string output = "";
	while (*iterationsData->commonProcessedPoints < iterationsData->commonPoints) {
		output = "Completed [" + std::to_string(*iterationsData->commonProcessedPoints) + "/" + std::to_string(iterationsData->commonPoints) + "] elements";
		std::cout << output << "\r";
		Sleep(50);
	}
	std::cout << output << "\n";
	return 0;
}

DWORD WINAPI PiGenerator::CountHits(CONST LPVOID data) {
	RandomPoint point = RandomPoint();
	ThreadData *threadData = (ThreadData *)data;
	for (size_t i = 0; i < threadData->threadIterations; ++i) {
		point.Regenerate();
		if (isPointInCircle(point)) {
			InterlockedIncrement(threadData->caughtPoints);
		}
		InterlockedIncrement(threadData->iterationsData->commonProcessedPoints);
	}
	return 0;
}

double PiGenerator::GetPiValue() {
	ThreadsHandler handler;
	size_t iterationsOnThread = (iterations / threads) + 1;
	size_t remainder = iterations % threads;
	size_t processedPoints = 0;
	IterationsData *iterationsData = new IterationsData(iterations, &processedPoints);
	handler.AddThread(CountIterations, iterationsData);
	for (size_t i = 0; i < threads; ++i) {
		if (i == remainder) {
			--iterationsOnThread;
		}
		ThreadData *data = new ThreadData(iterationsOnThread, &caughtPoints, iterationsData);
		if (threads != 1) {
			handler.AddThread(CountHits, data);
		}
		else {
			CountHits(data);
		}

	}
	handler.Wait();
	return (PI_CALCULATION_COEFFICIENT * (double(caughtPoints) / double(iterations)));
}