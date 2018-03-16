#include "stdafx.h"
#include "Pot.h"

size_t CPot::GetMeatCount() const {
	return m_meatCount;
}

void CPot::SetMeatCount(size_t meatCount) {
	m_meatCount = meatCount;
}
