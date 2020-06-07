#include "CLineSegment.hpp"
#include "stdafx.hpp"


const string line_name="Shape: Line\n";
const string line_area="Area: ";
const string line_perimetr="Perimeter: ";
const string line_start_point="Start point:  ";
const string line_end_point="End point: ";
const string line_outline_color="Outline Color: ";


CLineSegment::CLineSegment(const CPoint& startPoint, const CPoint& endPoint, uint32_t outlineColor): m_startPoint(startPoint), m_endPoint(endPoint), m_outlineColor(outlineColor)
{
}

double CLineSegment::GetArea() const
{
	return 0.0;
}

double CLineSegment::GetPerimeter() const
{
	return sqrt(pow(m_startPoint.x - m_endPoint.x, 2) + pow(m_startPoint.y - m_endPoint.y, 2));
}

string CLineSegment::ToString() const
{
	stringstream output;
	output << fixed << setprecision(2);
	output << line_name;
	output << line_area << GetArea() << endl;
	output << line_perimetr << GetPerimeter() << endl;
	output << line_start_point << m_startPoint.ToString() << endl;
	output << line_end_point << m_endPoint.ToString() << endl;
	output << hex;
	output << line_outline_color << setw(6) << setfill('0') << m_outlineColor << endl;

	return output.str();
}

uint32_t CLineSegment::GetOutlineColor() const
{
	return m_outlineColor;
}

CPoint CLineSegment::GetStartPoint() const
{
	return m_startPoint;
}

CPoint CLineSegment::GetEndPoint() const
{
	return m_endPoint;
}
