#pragma once
#include "stdafx.hpp"

class CPoint
{
public:
	CPoint(double x, double y);

	double x;
	double y;

	string ToString() const;

	bool operator==(const CPoint& point) const;
};
