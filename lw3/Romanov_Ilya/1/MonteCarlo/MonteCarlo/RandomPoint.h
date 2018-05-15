#pragma once
class RandomPoint
{
public:
	RandomPoint();
	double GetX() const;
	double GetY() const;
	void Generate();
private:
	double CreateRandomFractionalNumber();
	double x;
	double y;
};

