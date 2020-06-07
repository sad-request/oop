#include "Processor.hpp"
#include "stdafx.hpp"

const string text_info = "Information\nline <first point> <second point> <color>\nrectangle <upper left point> <width> <height> <outline color> <fill color>\ncircle <center point> <radius> <outline color> <fill color>\ntriangle <vertex 1> <vertex 2> <vertex 2> <outline color> <fill color>\n";

CShapeControl::CShapeControl(istream& command, ostream& answer)
	:m_command(command),
	m_answer(answer)
{
}

vector<string> ParseValuesShape(istringstream& valuesShape)
{
	vector<string> values;
	string valuesToString;
	while (valuesShape >> valuesToString)
	{
		values.push_back(valuesToString);
	}
	return values;
}

bool CShapeControl::AnswerCommand()
{
	string commandString;
	getline(m_command, commandString);
	istringstream commandStringStream(commandString);
	vector<string> valuesShape = ParseValuesShape(commandStringStream);
	if (valuesShape.empty())
	{
		return false;
	}

	if (valuesShape[0] == "rectangle")
	{
		return SetRectangle(valuesShape);;
	}
	else if (valuesShape[0] == "circle")
	{
		return SetCircle(valuesShape);
	}
	else if (valuesShape[0] == "triangle")
	{
		return SetTriangle(valuesShape);
	}
	else if (valuesShape[0] == "line")
	{
		return SetLineSegment(valuesShape);
	}
	else
	{
		m_answer << "Incorrect Shape\n";
		Info();
		return false;
	}
}

void CShapeControl::Info() const
{
	m_answer << text_info;
}

void CShapeControl::PrintShapeWithMaxArea() const
{
	if(!m_listsOfShape.empty())
	{
		auto it = max_element(m_listsOfShape.begin(), m_listsOfShape.end(), []
		(const shared_ptr<IShape>& firstShape, const shared_ptr<IShape>& secondShape)
			{ return firstShape->GetArea() < secondShape->GetArea(); });

		m_answer << (*it)->ToString();
	}
}


void CShapeControl::PrintShapeWithMinPerimeter() const
{
	if (!m_listsOfShape.empty())
	{
		auto it = min_element(m_listsOfShape.begin(), m_listsOfShape.end(), []
		(const shared_ptr<IShape>& firstShape, const shared_ptr<IShape>& secondShape)
			{return firstShape->GetArea() < secondShape->GetArea(); });

		m_answer << (*it)->ToString();
	}
}


bool CShapeControl::SetLineSegment(const vector<string>& valuesLineSegment)
{
    CPoint startPoint(stod(valuesLineSegment[1]), stod(valuesLineSegment[2]));
    CPoint endPoint(stod(valuesLineSegment[3]), stod(valuesLineSegment[4]));
    uint32_t color = stoul(valuesLineSegment[5], 0, 16);
    m_listsOfShape.push_back(make_shared<CLineSegment>(startPoint, endPoint, color));
    return true;

	m_answer << "Incorrect command\n";
	return false;
}

bool CShapeControl::SetCircle(const vector<string>& valuesCircle)
{
    CPoint center(stod(valuesCircle[1]), stod(valuesCircle[2]));
    double radius = stod(valuesCircle[3]);
    uint32_t outlineColor = stoul(valuesCircle[4], 0, 16);
    uint32_t fillColor = stoul(valuesCircle[5], 0, 16);
    m_listsOfShape.push_back(make_shared<CCircle>(center, radius, outlineColor, fillColor));

    return true;

	m_answer << "Incorrect command\n";
	return false;
}

bool CShapeControl::SetRectangle(const vector<string>& valuesRectangle)
{
    CPoint leftTop(stod(valuesRectangle[1]), stod(valuesRectangle[2]));
    double width = stod(valuesRectangle[3]);
    double height = stod(valuesRectangle[4]);
    uint32_t outlineColor = stoul(valuesRectangle[5], 0, 16);
    uint32_t fillColor = stoul(valuesRectangle[6], 0, 16);
    m_listsOfShape.push_back(make_shared<CRectangle>(leftTop, width, height, outlineColor, fillColor));

    return true;

	m_answer << "Incorrect command\n";
	return false;
}

bool CShapeControl::SetTriangle(const vector<string>& valuesTriangle)
{
    CPoint vertex1(stod(valuesTriangle[1]), stod(valuesTriangle[2]));
    CPoint vertex2(stod(valuesTriangle[3]), stod(valuesTriangle[4]));
    CPoint vertex3(stod(valuesTriangle[5]), stod(valuesTriangle[6]));
    uint32_t outlineColor = stoul(valuesTriangle[7], 0, 16);
    uint32_t fillColor = stoul(valuesTriangle[8], 0, 16);
    m_listsOfShape.push_back(make_shared<CTriangle>(vertex1, vertex2, vertex3, outlineColor, fillColor));

    return true;

	m_answer << "Incorrect command\n";
	return false;
}
