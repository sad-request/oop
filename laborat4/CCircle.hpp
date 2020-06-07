#pragma once
#include "CPoint.hpp"
#include "ISolidShape.hpp"
#include "stdafx.hpp"

const double PI = 3.14159;

class CCircle: public ISolidShape
{
public:
	CCircle(CPoint& center, double radius, uint32_t outlineColor, uint32_t fillColor);

	double GetArea() const override;
	double GetPerimeter() const override;
	string ToString() const override;
	uint32_t GetOutlineColor() const override;
	uint32_t GetFillColor() const override;
	CPoint GetCenter() const;
	double GetRadius() const;

private:
	CPoint m_center;
	double m_radius;
	uint32_t m_outlineColor;
	uint32_t m_fillColor;
};
