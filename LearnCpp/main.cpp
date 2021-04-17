#include <iostream>
#include "NPoint.h"
#include "Barycenter.h"

using namespace std;

void InputUser(int countPoint)
{
	NPoint<int>* points = new NPoint<int>[countPoint];
	bool IsAllPointsInput = false;
	int countInputPoints = 0;
	while(IsAllPointsInput == false)
	{
		cout << "Осталось ввести " << countPoint - countInputPoints << " точку(ек).\n";
		try
		{
			cin >> points[countInputPoints];
			countInputPoints++;
			if(countInputPoints == countPoint)
			{
				IsAllPointsInput = true;
			}
			system("cls");
		}
		catch(...)
		{
			cout << "Ошибка ввода! Вводите корректные данные!" << endl;
		}
	}
	bool isExit = false;
	int point1;
	int point2;
	int numberOfCommand;
	string input;
	NPoint<int> res;
	while(isExit == false)
	{
		cout << "Вы ввели точки: \n";
		for(int i = 0; i < countPoint; i++)
		{
			cout << "№ " << i + 1 << " " << points[i] << endl;
		}

		cout << "Введите номера точек, с которыми будете работать:\n";
		try
		{
			cout << "Номер первой точки: "; cin >> input;
			point1 = stoi(input);
			point1--;
			cout << "Номер второй точки: "; cin >> input;
			point2 = stoi(input);
			point2--;
			system("cls");
		}
		catch(...)
		{
			cout << "Вводите кооректные данные!" << endl;
			continue;
		}

		while(isExit == false)
		{
			cout << "Точки можно:\n";
			cout << "\t1 - вычитать\n";
			cout << "\t2 - сравнивать\n";
			cout << "\t3 - складывать\n";
			cout << "\t4 - находить длинну\n";
			cout << "\t5 - находить барицентр\n";
			cout << "\t6 - выйти их программы\n";
			cout << "Введите номер команды: "; cin >> input;
			try
			{
				numberOfCommand = stoi(input);
				system("cls");
			}
			catch(...)
			{
				cout << "Вводите коректные номера! Внимательнее!" << endl;
			}
			cout << "Вы выбрали точки: " << endl;
			cout << points[point1] << endl;
			cout << points[point2] << endl;

			switch(numberOfCommand)
			{
				case 1:
				{
					cout << "Вы выбрали вычитать" << endl;

					res = points[point1] - points[point2];
					cout << "Результат: " << res << endl;
					break;
				}
				case 2:
				case 4:
				{
					int l1 = points[point1].getLength();
					int l2 = points[point2].getLength();
					cout << "Вы выбрали " << ((numberOfCommand == 2) ? "сравнивать" : "находить длинну" ) << endl;
					cout << "Длина точки 1: " << l1 << '\n';
					cout << "Длина точки 2: " << l2 << '\n';
					if(numberOfCommand == 2)
					{
						cout << "Точка 1 " << ((l1 >= l2) ? ">=" : "<") << " точки 2.\n";
					}					
					break;
				}
				case 3:
				{
					cout << "Вы выбрали складывать" << endl;
					res = points[point1] - points[point2];
					cout << "Результат: " << res << endl;
					break;
				}
				case 5:
				{
					cout << "Вы выбрали находить барицентр" << endl;
					cout << Barycenter<int>::getBarycenter(points[point1], points[point2]) << endl;
					break;
				}
				case 6:
				{
					isExit = true;
					system("cls");
					cout << "Программа закончила свою работу!" << endl;
					break;
				}
				default:
					cout << "Неизвестная комманда! Внимательнее!" << endl;
					break;
			}

			cout << "\n\n";
		}
	}
}

int main(int argc, char** argv)
{
	srand(time(0));
	setlocale(LC_ALL, "rus");
	string input;
	int countPoint = 0;
	try
	{
		cout << "Введите ко-во точек (больше 1): "; cin >> input;
		countPoint = stoi(input);
		if(countPoint > 1)
		{
			InputUser(countPoint);
		}
		else
		{
			cout << "Нужно вводить больше 1 точки!";
		}		
	}
	catch(...)
	{
		cout << "Ошибка ввода кол-ва точек! Вводите корректные данные!";
	}
	return 0;
}