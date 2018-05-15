#include "stdafx.h"
#include "PiGenerator.h"
#include <iostream>
#include <string>


PiGenerator::PiGenerator(const size_t iterations) {
	this->iterations = iterations;
}

void PiGenerator::SetMultithreading(bool multithreading) {
	this->multithreading = multithreading;
}

bool PiGenerator::isPointInCircle(const RandomPoint &point) {
	return pow(point.GetX(), 2) + pow(point.GetY(), 2) <= fieldSize;
}

void PiGenerator::CheckPoint(int &caughtPoints) {
	RandomPoint point = RandomPoint();
	point.Generate();
	if (isPointInCircle(point)) {
		++caughtPoints;
	};
}

void PiGenerator::CountHitsParallel() {
	int count = 0;
	#pragma omp parallel for reduction(+:count)
	for (int i = 0; i < iterations; ++i) {
		CheckPoint(count);
	};
	caughtPoints = count;

}

void PiGenerator::CountHits() {
	for (int i = 0; i < iterations; ++i) {
		CheckPoint(caughtPoints);
	};
}

double PiGenerator::GetPiValue() {
	if (multithreading) {
		CountHitsParallel();
	}
	else {
		CountHits();
	}
	return (PI_CALCULATION_COEFFICIENT * (double(caughtPoints) / double(iterations)));
}