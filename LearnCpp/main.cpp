#include <iostream>
#include "NPoint.h"
#include "Barycenter.h"

using namespace std;

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "rus");
	int countPoints;
	int sizePoint;
	cout << "Введите размерность точки: "; cin >> sizePoint;
	cout << "Введите кол-во точек: "; cin >> countPoints;
	cout << endl;
	NPoint<int>* points = new NPoint<int>[countPoints];
	for(int i = 0; i < countPoints; i++)
	{
		cout << "Введите координату точки: [" << i << "]:" << endl;
		points[i] = NPoint<int>(sizePoint);
		for(int j = 0; j < sizePoint; j++)
		{
			cout << "\tКоордината [" << j << "] = "; cin >> points[i][j];
		}
		cout << endl;
	}

	cout << "Вы ввели точки:\n";
	for(int i = 0; i < countPoints; i++)
	{
		cout << points[i] << endl;
	}


	return 0;
}