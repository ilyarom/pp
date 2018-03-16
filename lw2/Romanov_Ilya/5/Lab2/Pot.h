#pragma once
class CPot
{
public:
	CPot() = default;
	size_t GetMeatCount() const;
	void SetMeatCount(size_t meatCount);
private:
	size_t m_meatCount = 0;
};

