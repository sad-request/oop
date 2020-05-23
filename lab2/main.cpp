#include<iostream>

#include "PrimeNumbersGenerator.hpp"
#include <set>

int main(int argc, char *argv[])
{
    if (argc != 2)
	{
		std::cout << "Invalid argument count\n"
        << "Usage: PrimeNumbersGenerator.exe <number>\n";
		return 1;
	}

    std::set<int> result;
    int chislo = atoi(argv[1]);
    result = GeneratePrimeNumbersSet(chislo);

    for (std::set<int>::iterator it = result.begin(); it != result.end(); it++) {
        std::cout << *it << " ";
    }

    std::cout << std::endl << result.size() << std::endl;

    return 0;
}
