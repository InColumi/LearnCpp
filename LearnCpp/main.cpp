#include <iostream>
#include "NPoint.h"
#include "Barycenter.h"

using namespace std;

void ShowBarycenter()
{
	int countPoints;
	int sizePoint;
	cout << "Введите размерность точки: "; cin >> sizePoint;
	cout << "Введите кол-во точек: "; cin >> countPoints;
	cout << endl;
	NPoint<int>* points = new NPoint<int>[countPoints]; // массив точек для проверкаи барицентра
	for(int i = 0; i < countPoints; i++)
	{
		cout << "Введите координату точки: [" << i << "]:" << endl;
		points[i] = NPoint<int>(sizePoint); // заполнение точки соответствующей размерности
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

	cout << "Их барицентр: " << Barycenter<int>::getBarycenter(points, countPoints) << endl;
}

template <typename T>
void ShowAdd(NPoint<T>& a, NPoint<T>& b)
{
	cout << "Точки, которые будем складывать: \n";
	cout << a << endl;
	cout << b << endl;
	NPoint<double> c = a + b;
	cout << "Результат: " << c << endl;
}

template <typename T>
void ShowSub(NPoint<T>& a, NPoint<T>& b)
{
	cout << "Точки, которые будем вычитать: \n";
	cout << a << endl;
	cout << b << endl;
	NPoint<double> c = a - b;
	cout << "Результат: " << c << endl;
}

template <typename T>
void ShowLength(NPoint<T>& a)
{
	cout << "Точка модуль которой будем искать: \n";
	cout << a << endl;
	cout << "Результат: " << a.getLength() << endl;
}

/// <summary>
/// Генераций координат точки
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="sizePoint"></param>
/// <returns></returns>
template <typename T>
NPoint<T> GetNewPoint(int sizePoint)
{
	NPoint<T> a = NPoint<T>(sizePoint); // создание точки размерности sizePoint
	for(int i = 0; i < sizePoint; i++)
	{
		a[i] = 1 + rand() % 100;
	}	
	return a;
}

int main(int argc, char** argv)
{
	srand(time(0));
	setlocale(LC_ALL, "rus");
	try
	{
		ShowBarycenter();
	}
	catch(const char* exception)
	{
		cout << exception << endl;
	}

	int sizePoint = 5;
	NPoint<double> a = GetNewPoint<double>(sizePoint);
	NPoint<double> b = GetNewPoint<double>(sizePoint);

	ShowAdd(a, b);
	ShowSub(a, b);
	ShowLength(a);
	return 0;
}