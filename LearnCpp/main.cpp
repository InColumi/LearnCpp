#include <iostream>

using namespace std;

double getValueFunc_237_2_1(double x)
{
	return cos(x * x + 1);
}

void Task_237_2_1()
{
	double PI = 3.141592;
	double a = PI / 3.0;
	double b = 3.0 * PI / 2.0;
	int m = 10;
	double h = (b - a) / (double)m;

	int counter = 1;
	for(double x = a; x < b; x += h)
	{
		cout << counter++ << " cos(" << x << "^2 + 1) = " << getValueFunc_237_2_1(x) << '\n';
	}
}

double getValueFunc_2_2(double x)
{
	return log10(x) / 2.0f;
}

double getApproximation(double x, double eps = 0.001)
{
	double sumPrev = -x + 1;
	double sumNext = 0.0f;
	double x1 = x - 1;
	double preciseValue = getValueFunc_2_2(x);
	for(int n = 1; fabs(sumPrev - sumNext) > eps; n++)
	{
		sumNext = sumPrev;
		x1 *= (x - 1);
		sumPrev -= x1 / (n + 1.0);
		//cout << fabs(sumPrev - sumNext) << endl;
	}
	return sumPrev;
}

void Task_2_2()
{
	double a = 0.2;
	double b = 1;
	int m = 10;
	double eps = 0.0001;
	double h = (b - a) / m;
	double approximation;
	double precise;
	double diff;
	for(double x = a; x <= b; x += h)
	{
		approximation = getApproximation(x, eps);
		precise = getValueFunc_2_2(x);
		diff = fabs(fabs(precise) - fabs(approximation));
		cout <<
			"x = " << x << "; y = " << precise <<
			" <---> " << approximation << ";\n";
	}
}

double getValueFunc_2_4_239_1(double x)
{
	return 1.0 / sqrt(9.0 + x * x);
}

double getPrecise_2_4_239_1(double x)
{
	return log10(x + sqrt(x * x + 9));
}

double getValueFunc_2_4_239_2(double x)
{
	double x2 = x * x;
	return (x2 - 1) / ((x2 + 1) * (sqrt(x2 * x2 + 1)));
}

double getPrecise_2_4_239_2(double x)
{
	double sqrt2 = sqrt(2);
	return -sqrt2 * asin(sin(2 * atan(x)) / sqrt2) / 2.0;
}

double getMethodTrapeze(double a, double b, int n, double (*f)(double))
{
	double h = (b - a) / n;
	double sum = 0;
	for(double i = a; i < b; i += h)
	{
		sum += f(i);
	}
	return 0.5 * h * (f(a) + f(b)) + sum * h;
}

double getApproximationMethodTrapeze(double a, double b, double (*f)(double), double eps = 0.000001)
{
	double resPrev = getMethodTrapeze(a, b, 1, f);
	double resNext = 0.0;
	for(int n = 2; fabs(resPrev - resNext) >= eps; n *= 2)
	{
		resNext = resPrev;
		resPrev = getMethodTrapeze(a, b, n, f);
		//cout << fabs(resPrev - resNext) << endl;
	}
	return resPrev;
}

double getCheck(double a, double b, double (*F)(double))
{
	return F(b) - F(a);
}

void Task_2_4_239()
{
	double a = 0;
	double b = 2;
	double eps = 0.00001;
	cout << getApproximationMethodTrapeze(a, b, getValueFunc_2_4_239_1, eps) << " = "
		<< getCheck(a, b, getPrecise_2_4_239_1) << endl;

	a = 0;
	b = 1;
	cout << getApproximationMethodTrapeze(a, b, getValueFunc_2_4_239_2, eps) << " = "
		<< getCheck(a, b, getPrecise_2_4_239_2) << endl;
}

/// <summary>
/// Число Армстронга – это такое число из k цифр, для которого сумма k - х 
/// степеней его цифр равна самому числу. Найти все числа Армстронга из трех цифр.
/// </summary>
void Task_249(int k)
{
	double res;
	double size = 1000;
	bool isNextNumber ;
	int xPow;
	int yPow;

	for(size_t i = 100; i <= size; i++)
	{
		isNextNumber = false;
		for(size_t x = 1; x <= 9; x++)
		{
			if(isNextNumber)
			{
				break;
			}
			xPow = pow(x, k);
			for(size_t y = 1; y <= 9; y++)
			{
				if(isNextNumber)
				{
					break;
				}
				yPow = pow(y, k);
				for(size_t z = 1; z <= 9; z++)
				{
					if(isNextNumber)
					{
						break;
					}
					if(i == (xPow + yPow + pow(z, k)))
					{
						cout << i << ", ";
						isNextNumber = true;
					}
				}
			}
		}
	}
}

int main(int argc, char** argv)
{
	srand(time(0));
	setlocale(LC_ALL, "rus");
	//Task_237_2_1();
	//Task_2_2();
	//Task_2_4_239();
	Task_249(3);
	return 0;
}