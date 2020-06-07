#pragma once
#define CATCH_CONFIG_MAIN
#include "Processor.hpp"
#include "catch.hpp"
#include <math.h>

using namespace std;

void ExpectOperationSuccess(const std::string& command, const std::string& answer)
{
	std::stringstream input, output;
	CShapeControl shapeControl(input, output);
	input << command;
	CHECK(shapeControl.AnswerCommand());
	CHECK(answer == output.str());
}


TEST_CASE("set shapes with correct command")
{
	std::string command = "circle 0.5 1 1 ffdf00 ffee73";
	ExpectOperationSuccess(command, "");

	command = "line 0.5 0 0.5 1 ffffff";
	ExpectOperationSuccess(command, "");

	command = "rectangle 10.3 20.15 30.7 40.4 ff0000 00ff00";
	ExpectOperationSuccess(command, "");

	command = "triangle 0.0 0.0 4.0 0.0 4.0 5.0 00ff00 ff0000";
	ExpectOperationSuccess(command, "");
}

TEST_CASE("check output infofmation about the shape")
{
	std::stringstream input, output;
	CShapeControl shapeControl(input, output);
	shapeControl.Info();
	std::stringstream answer;
	answer << "Information\n";
	answer << "line <first point> <second point> <color>\n";
	answer << "rectangle <upper left point> <width> <height> <outline color> <fill color>\n";
	answer << "circle <center point> <radius> <outline color> <fill color>\n";
	answer << "triangle <vertex 1> <vertex 2> <vertex 2> <outline color> <fill color>\n";
	CHECK(answer.str() == output.str());
}

TEST_CASE("output info the shape with the max area")
{
	std::stringstream input, output;
	CShapeControl shapeControl(input, output);
	input << "rectangle 0 3 2 1 00ff00 ff0000" << std::endl;
	shapeControl.AnswerCommand();
	input << "rectangle 0 4 4 3 000000 000000" << std::endl;
	shapeControl.AnswerCommand();
	std::stringstream answer;
	answer << "Shape: Rectangle\n";
	answer << "Area: 12.00\n";
	answer << "Perimeter: 14.00\n";
	answer << "Left top: 0.00, 4.00\n";
	answer << "Right bottom: 4.00, 1.00\n";
	answer << "Height: 3.00\n";
	answer << "Width: 4.00\n";
	answer << "Fill Color: 000000\n";
	answer << "Outline Color: 000000\n";
	shapeControl.PrintShapeWithMaxArea();
	CHECK(answer.str() == output.str());
}

TEST_CASE("output info the shape with the min perimeter")
{
	std::stringstream input, output;
	CShapeControl shapeControl(input, output);
	input << "rectangle 0 3 2 1 000000 000000" << std::endl;
	shapeControl.AnswerCommand();
	input << "rectangle 0 4 4 3 000000 000000" << std::endl;
	shapeControl.AnswerCommand();
	std::stringstream answer;
	answer << "Shape: Rectangle\n";
	answer << "Area: 2.00\n";
	answer << "Perimeter: 6.00\n";
	answer << "Left top: 0.00, 3.00\n";
	answer << "Right bottom: 2.00, 2.00\n";
	answer << "Height: 1.00\n";
	answer << "Width: 2.00\n";
	answer << "Fill Color: 000000\n";
	answer << "Outline Color: 000000\n";
	shapeControl.PrintShapeWithMinPerimeter();
	CHECK(answer.str() == output.str());
}



#include "CPoint.hpp"
TEST_CASE("output check string")
{
	CPoint point(1.1234, 2.1234);
	CHECK(point.ToString() == "1.12, 2.12");
}


#include "CLineSegment.hpp"
TEST_CASE("check output values LineSegment")
{
	CPoint startPoint(0, 0);
	CPoint endPoint(3, 4);
	CLineSegment line(startPoint, endPoint, 0x00ff00);

	CHECK(line.GetArea() == 0);
	CHECK(line.GetStartPoint() == startPoint);
	CHECK(line.GetEndPoint() == endPoint);
	CHECK(line.GetPerimeter() == 5.0);
	CHECK(line.GetOutlineColor() == 0x00ff00);
}

TEST_CASE("check output information LineSegment")
{
	CPoint startPoint(0, 0);
	CPoint endPoint(3, 4);
	CLineSegment line(startPoint, endPoint, 0x00ff00);
	std::stringstream output;
	output << "Shape: Line\n";
	output << "Area: 0.00\n";
	output << "Perimeter: 5.00\n";
	output << "Start point:  0.00, 0.00\n";
	output << "End point: 3.00, 4.00\n";
	output << "Outline Color: 00ff00" << std::endl;

	CHECK(line.ToString() == output.str());
}



#include "CCircle.hpp"
TEST_CASE("Check in get value")
{
	CPoint circleNenter(3, 4);
	double radius = 3.0;
	uint32_t outlineColor = 0xff0000;
	uint32_t fillColor = 0x00ff00;
	CCircle circle(circleNenter, radius, outlineColor, fillColor);
	double area = PI * pow(radius, 2);
	double Perimeter = 2 * PI * radius;

	CHECK(circle.GetCenter() == circleNenter);
	CHECK(circle.GetRadius() == radius);
	CHECK(circle.GetOutlineColor() == outlineColor);
	CHECK(circle.GetFillColor() == fillColor);
}

TEST_CASE("check output ToString")
{
	CPoint circleNenter(3, 4);
	CCircle circle(circleNenter, 3.0, 0x00ff00, 0xff0000);
	std::stringstream output;
	output << "Shape: Circle\n";
	output << "Area: 28.27\n";
	output << "Perimeter: 18.85\n";
	output << "Center: 3.00, 4.00\n";
	output << "Radius: 3.00\n";
	output << "Fill Color: ff0000\n";
	output << "Outline Color: 00ff00\n";
	CHECK(circle.ToString() == output.str());
}

#include "CRectangle.hpp"
TEST_CASE("check for get infomation Rectangle")
{
	CPoint leftTop(2, 5);
	CRectangle rectangle(leftTop, 10, 5, 0x00ff00, 0xff0000);
	CHECK(rectangle.GetLeftTop() == leftTop);
	CHECK(rectangle.GetWidth() == 10);
	CHECK(rectangle.GetHeight() == 5);
	CHECK(rectangle.GetOutlineColor() == 0x00ff00);
	CHECK(rectangle.GetFillColor() == 0xff0000);
}

TEST_CASE("check for counting values Rectangle")
{
	CPoint leftTop(2, 5);
	CRectangle rectangle(leftTop, 10, 5, 0x00ff00, 0xff0000);
	CPoint rightBottom(leftTop.x + 10, leftTop.y - 5);
	CHECK(rectangle.GetRightBottom() == rightBottom);
	CHECK(rectangle.GetArea() == 50);
	CHECK(rectangle.GetPerimeter() == 30);
}

TEST_CASE("check for get info to string Rectangle")
{
	CPoint leftTop(2, 5);
	CRectangle rectangle(leftTop, 10, 5, 0x00ff00, 0xff0000);
	std::stringstream output;
	output << "Shape: Rectangle\n";
	output << "Area: 50.00\n";
	output << "Perimeter: 30.00\n";
	output << "Left top: 2.00, 5.00\n";
	output << "Right bottom: 12.00, 0.00\n";
	output << "Height: 5.00\n";
	output << "Width: 10.00\n";
	output << "Fill Color: ff0000\n";
	output << "Outline Color: 00ff00\n";

	CHECK(rectangle.ToString() == output.str());
}


#include "CTriangle.hpp"
TEST_CASE("check for get infomation Triangle")
{
	CPoint vertex1(4, 4);
	CPoint vertex2(2, 1);
	CPoint vertex3(6, 1);
	CTriangle triangle(vertex1, vertex2, vertex3, 0x00ff00, 0xff0000);

	CHECK(triangle.GetVertex1() == vertex1);
	CHECK(triangle.GetVertex2() == vertex2);
	CHECK(triangle.GetVertex3() == vertex3);
	CHECK(triangle.GetFillColor() == 0xff0000);
	CHECK(triangle.GetOutlineColor() == 0x00ff00);
}

TEST_CASE("check for counting values Triangle")
{
	CPoint vertex1(1, 1);
	CPoint vertex2(4, 5);
	CPoint vertex3(7, 1);
	CTriangle triangle(vertex1, vertex2, vertex3, 0x00ff00, 0xff0000);

	CHECK(triangle.GetArea() == 12.0);
	CHECK(triangle.GetPerimeter() == 16.0);
}

TEST_CASE("check get info to string Triangle")
{
	CPoint vertex1(4, 4);
	CPoint vertex2(2, 1);
	CPoint vertex3(6, 1);
	CTriangle triangle(vertex1, vertex2, vertex3, 0x00ff00, 0xff0000);

	std::stringstream output;
	output << "Shape: Triangle\n";
	output << "Area: 6.00\n";
	output << "Perimeter: 11.21\n";
	output << "vertex1: 4.00, 4.00\n";
	output << "vertex2: 2.00, 1.00\n";
	output << "vertex3: 6.00, 1.00\n";
	output << "Fill Color: ff0000\n";
	output << "Outline Color: 00ff00" << std::endl;

	CHECK(triangle.ToString() == output.str());
}
