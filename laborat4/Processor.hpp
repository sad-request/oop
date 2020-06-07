#pragma once
#include "IShape.hpp"
#include "CPoint.hpp"
#include "CLineSegment.hpp"
#include "CCircle.hpp"
#include "CRectangle.hpp"
#include "CTriangle.hpp"

#include "stdafx.hpp"

class CShapeControl
{
public:
	CShapeControl(istream& command, ostream& answer);
	bool AnswerCommand();
	void Info() const;
	void PrintShapeWithMaxArea() const;
	void PrintShapeWithMinPerimeter() const;

private:
	bool SetLineSegment(const vector<string>& valuesLineSegment);
	bool SetCircle(const vector<string>& valuesCircle);
	bool SetRectangle(const vector<string>& valuesRectangle);
	bool SetTriangle(const vector<string>& valuesTriangle);
	istream& m_command;
	ostream& m_answer;
	vector<shared_ptr<IShape>> m_listsOfShape;
};
