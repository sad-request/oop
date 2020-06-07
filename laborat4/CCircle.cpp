#include "CCircle.hpp"
#include "stdafx.hpp"


const string circle_name="Shape: Circle\n";
const string circle_area="Area: ";
const string circle_perimetr="Perimeter: ";
const string circle_center="Center: ";
const string circle_radius="Radius: ";
const string circle_fill_color="Fill Color: ";
const string circle_outline_color="Outline Color: ";

CCircle::CCircle(CPoint& center, double radius, uint32_t outlineColor, uint32_t fillColor): m_center(center), m_radius(radius), m_outlineColor(outlineColor), m_fillColor(fillColor)
{
}

double CCircle::GetArea() const
{
	return PI * pow(m_radius, 2);
}

double CCircle::GetPerimeter() const
{
	return 2.0 * PI * m_radius;
}

string CCircle::ToString() const
{
	stringstream output;
	output << fixed << setprecision(2);
	output << circle_name;
	output << circle_area << GetArea() << endl;
	output << circle_perimetr << GetPerimeter() << endl;
	output << circle_center << m_center.ToString() << endl;
	output << circle_radius<< m_radius << endl;
	output << hex;
	output << circle_fill_color << setw(6) << setfill('0') << m_fillColor << endl;
	output << circle_outline_color << setw(6) << setfill('0') << m_outlineColor << endl;

	return output.str();
}

uint32_t CCircle::GetOutlineColor() const
{
	return m_outlineColor;
}

uint32_t CCircle::GetFillColor() const
{
	return m_fillColor;
}


CPoint CCircle::GetCenter() const
{
	return m_center;
}

double CCircle::GetRadius() const
{
	return m_radius;
}
