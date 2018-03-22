#include "stdafx.h"
#include "RandomPoint.h"
#include <utility>
#include <ctime>

RandomPoint::RandomPoint() {
	std::srand(std::time(0));
	Regenerate();
}

void RandomPoint::Regenerate() {
	x = CreateRandomFractionalNumber();
	y = CreateRandomFractionalNumber();
}

double RandomPoint::CreateRandomFractionalNumber() {
	return (double)(rand()) / RAND_MAX;
}

double RandomPoint::GetX() const {
	return x;
}

double RandomPoint::GetY() const {
	return y;
}
