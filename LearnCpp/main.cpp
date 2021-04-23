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
	return log10(x) / 2.0;
}

double getApproximation(double x, double eps = 0.001)
{
	double sum = 0;
	double x1 = x - 1;
	double preciseValue = getValueFunc_2_2(x);
	for(int n = 0; fabs(sum - preciseValue) > eps; n++)
	{
		sum += -x1 / (n + 1.0);
		x1 *= (x - 1);
		cout << sum << endl;
	}
	return sum;
}

void Task_2_2()
{
	double a = 0.2;
	double b = 1.0;
	int m = 10;
	double h = (b - a) / (double)m;
	for(double x = a; x <= b; x += h)
	{
		cout << "x = " << x << "; y = " << getApproximation(x) << " <---> " << getValueFunc_2_2(x) << "; \n";
	}
}

double getValueFunc_2_4_239_1(double x)
{
	return 1.0 / sqrt(9.0 + x * x);
}

double getValueFunc_2_4_239_2(double x)
{
	double x2 = x * x;
	return (x2 - 1) / ((x2 - 1) * (sqrt(x2 * x2 + 1)));
}

double getMethodTrapeze(double a, double b, int n, double (*f)(double))
{
	double h = (b - a) / n;
	double sum = 0;
	for(double i = 1; i < n; i++)
	{
		sum += f(a + i * h);
	}
	sum *= h;
	sum += h * (f(a) + f(b)) / 2.0;
	return sum;
}

double getPrecise_2_4_239_1(double x)
{
	return log10(x + sqrt(x * x + 9));
}
//
//double getPrecise_2_4_239_2()
//{
//	return
//}

void Task_2_4_239()
{
	double a = 0;
	double b = 2;
	double eps = 0.0001;
	double resPrev = getMethodTrapeze(a, b, 2, getValueFunc_2_4_239_1);
	double resNext = 0.0;
	for(int n = 3; fabs(resPrev - resNext) >= eps; n++)
	{
		resNext = resPrev;
		resPrev = getMethodTrapeze(a, b, n, getValueFunc_2_4_239_1);
		cout << fabs(resPrev - resNext) << endl;
	}
	cout << resPrev << " " << getPrecise_2_4_239_1(b) - getPrecise_2_4_239_1(a) << endl;
}

int main(int argc, char** argv)
{
	srand(time(0));
	setlocale(LC_ALL, "rus");
	//Task_237_2_1();
	//Task_2_2();
	Task_2_4_239();

	return 0;
}