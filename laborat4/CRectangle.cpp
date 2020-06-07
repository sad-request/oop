#include "CRectangle.hpp"


const string rectangle_name="Shape: Rectangle\n";
const string rectangle_area="Area: ";
const string rectangle_perimetr="Perimeter: ";
const string rectangle_left_top="Left top: ";
const string rectangle_right_bottom="Right bottom: ";
const string rectangle_height="Height: ";
const string rectangle_width="Width: ";
const string rectangle_fill_color="Fill Color: ";
const string rectangle_outline_color="Outline Color: ";


CRectangle::CRectangle(const CPoint& leftTop, double width,
	double height, uint32_t outlineColor, uint32_t fillColor)
	:m_leftTop(leftTop),
	m_width(width),
	m_height(height),
	m_outlineColor(outlineColor),
	m_fillColor(fillColor)
{
}

double CRectangle::GetArea() const
{
	return m_height * m_width;
}

double CRectangle::GetPerimeter() const
{
	return 2 * (m_height + m_width);
}

string CRectangle::ToString() const
{
	stringstream output;
	output << rectangle_name;
	output << fixed << setprecision(2);
	output << rectangle_area << GetArea() << endl;
	output << rectangle_perimetr << GetPerimeter() << endl;
	output << rectangle_left_top << m_leftTop.ToString() << endl;
	output << rectangle_right_bottom << GetRightBottom().ToString() << endl;
	output << rectangle_height << m_height << endl;
	output << rectangle_width << m_width << endl;
	output << hex;
	output << rectangle_fill_color << setw(6) << setfill('0') << m_fillColor << endl;
	output << rectangle_outline_color << setw(6) << setfill('0') << m_outlineColor << endl;

	return output.str();
}

uint32_t CRectangle::GetOutlineColor() const
{
	return m_outlineColor;
}

uint32_t CRectangle::GetFillColor() const
{
	return m_fillColor;
}

CPoint CRectangle::GetLeftTop() const
{
	return m_leftTop;
}

CPoint CRectangle::GetRightBottom() const
{
	CPoint rightBottom(m_leftTop.x + m_width, m_leftTop.y - m_height);
	return rightBottom;
}

double CRectangle::GetWidth() const
{
	return m_width;
}

double CRectangle::GetHeight() const
{
	return m_height;
}
