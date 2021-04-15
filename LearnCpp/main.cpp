#include <iostream>
#include "NPoint.h"
#include "Barycenter.h"

using namespace std;

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "rus");
	int countPoints;
	int sizePoint;
	cout << "������� ����������� �����: "; cin >> sizePoint;
	cout << "������� ���-�� �����: "; cin >> countPoints;
	cout << endl;
	NPoint<int>* points = new NPoint<int>[countPoints];
	for(int i = 0; i < countPoints; i++)
	{
		cout << "������� ���������� �����: [" << i << "]:" << endl;
		points[i] = NPoint<int>(sizePoint);
		for(int j = 0; j < sizePoint; j++)
		{
			cout << "\t���������� [" << j << "] = "; cin >> points[i][j];
		}
		cout << endl;
	}

	cout << "�� ����� �����:\n";
	for(int i = 0; i < countPoints; i++)
	{
		cout << points[i] << endl;
	}


	return 0;
}