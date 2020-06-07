#include <iostream>
#include "Processor.hpp"

const string max_area="Max Area: \n";
const string min_perimeter="\nMin perimeter:";

int main()
{
	CShapeControl shapeControl(std::cin, std::cout);
	shapeControl.Info();

	while (!std::cin.eof() && !std::cin.fail())
	{
		shapeControl.AnswerCommand();
	}

	std::cout << max_area;
	shapeControl.PrintShapeWithMaxArea();
	std::cout << min_perimeter << std::endl;
	shapeControl.PrintShapeWithMinPerimeter();

	return 0;
}
