#pragma once
class CPot
{
public:
	CPot();
	~CPot();
	size_t GetMeatCount();
	void SetMeatCount(size_t meatCount);
private:
	size_t m_meatCount = 0;
};

