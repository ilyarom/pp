#pragma once
class RandomPoint
{
public:
	RandomPoint();
	double GetX() const;
	double GetY() const;
	void Regenerate();
private:
	double CreateRandomFractionalNumber();
	double x;
	double y;
};

