#include "CPoint.hpp"
#include "stdafx.hpp"

CPoint::CPoint(double x, double y)
{
	this->x = x;
	this->y = y;
}

string CPoint::ToString() const
{
	stringstream output;
	output << fixed << setprecision(2);
	output << x << ", " << y;
	return output.str();
}

bool CPoint::operator==(const CPoint& point) const
{
	return (this->x == point.x && this->y == point.y);
}
