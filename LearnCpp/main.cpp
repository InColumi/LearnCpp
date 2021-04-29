#include <iostream>
#include "MyTime.h"

void SolveHardMethod()
{
	double a = 0;
	for(int i = 0; i < 999999; i++)
	{
		for(int j = 0; j < 10 + rand() % 99; j++) // генерация случайной величины
		{
			a = pow(a, j);
		}
	}
}

int main(int argc, char** argv)
{
	srand(time(0));
	std::cout << GetTime(SolveHardMethod) << " sec." << std::endl;
	std::cout << GetTime(SolveHardMethod) << " sec." << std::endl;
	std::cout << GetTime(SolveHardMethod) << " sec." << std::endl;
	std::cout << GetTime(SolveHardMethod) << " sec." << std::endl;
	std::cout << GetTime(SolveHardMethod) << " sec." << std::endl;

	return 0;
}