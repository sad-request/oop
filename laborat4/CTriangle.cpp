#include "CTriangle.hpp"
#include "stdafx.hpp"

const string triangle_name="Shape: Triangle\n";
const string triangle_area="Area: ";
const string triangle_perimetr="Perimeter: ";
const string triangle_vertex1="vertex1: ";
const string triangle_vertex2="vertex2: ";
const string triangle_vertex3="vertex3: ";
const string triangle_fill_color="Fill Color: ";
const string triangle_outline_color="Outline Color: ";

CTriangle::CTriangle(const CPoint& vertex1, const CPoint& vertex2, const CPoint& vertex3,
	uint32_t outlineColor, uint32_t fillColor)
	: m_vertex1(vertex1),
	m_vertex2(vertex2),
	m_vertex3(vertex3),
	m_outlineColor(outlineColor),
	m_fillColor(fillColor)
{
}

double GetLengthSegment(const CPoint& firstPoint, const CPoint& secondPoint)
{
	double firstLine = firstPoint.x - secondPoint.x;
	double secondLine = firstPoint.y - secondPoint.y;
	return sqrt(pow(firstLine, 2) + pow(secondLine, 2));
}

double CTriangle::GetArea() const
{
	double halfPerimeter = GetPerimeter() / 2;
	double line1 = GetLengthSegment(m_vertex1, m_vertex2);
	double line2 = GetLengthSegment(m_vertex2, m_vertex3);
	double line3 = GetLengthSegment(m_vertex3, m_vertex1);
	return sqrt(halfPerimeter*(halfPerimeter - line1)*(halfPerimeter - line2)*(halfPerimeter - line3));
}

double CTriangle::GetPerimeter() const
{
	double line1 = GetLengthSegment(m_vertex1, m_vertex2);
	double line2 = GetLengthSegment(m_vertex2, m_vertex3);
	double line3 = GetLengthSegment(m_vertex3, m_vertex1);
	return line1 + line2 + line3;
}

string CTriangle::ToString() const
{
	stringstream output;
	output << triangle_name;
	output << fixed << setprecision(2);
	output << triangle_area << GetArea() << endl;
	output << triangle_perimetr << GetPerimeter() << endl;
	output << triangle_vertex1 << m_vertex1.ToString() << endl;
	output << triangle_vertex2 << m_vertex2.ToString() << endl;
	output << triangle_vertex3 << m_vertex3.ToString() << endl;
	output << hex;
	output << triangle_fill_color << setw(6) << setfill('0') << m_fillColor << endl;
	output << triangle_outline_color << setw(6) << setfill('0') << m_outlineColor << endl;

	return output.str();
}

uint32_t CTriangle::GetOutlineColor() const
{
	return m_outlineColor;
}

uint32_t CTriangle::GetFillColor() const
{
	return m_fillColor;
}

CPoint CTriangle::GetVertex1() const
{
	return m_vertex1;
}

CPoint CTriangle::GetVertex2() const
{
	return m_vertex2;
}

CPoint CTriangle::GetVertex3() const
{
	return m_vertex3;
}
