#include <iostream>
#include "MyTime.h"

void SolveHardMethod()
{
	double a = 0;
	for(int i = 0; i < 999999; i++)
	{
		for(int j = 0; j < 100; j++)
		{
			a = pow(a, j);
		}
	}
}

int main(int argc, char** argv)
{

	std::cout << GetTime(SolveHardMethod) << " sec."<< std::endl;

	return 0;
}