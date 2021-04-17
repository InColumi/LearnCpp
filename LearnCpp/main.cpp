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
		cout << "�������� ������ " << countPoint - countInputPoints << " �����(��).\n";
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
			cout << "������ �����! ������� ���������� ������!" << endl;
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
		cout << "�� ����� �����: \n";
		for(int i = 0; i < countPoint; i++)
		{
			cout << "� " << i + 1 << " " << points[i] << endl;
		}

		cout << "������� ������ �����, � �������� ������ ��������:\n";
		try
		{
			cout << "����� ������ �����: "; cin >> input;
			point1 = stoi(input);
			point1--;
			cout << "����� ������ �����: "; cin >> input;
			point2 = stoi(input);
			point2--;
			system("cls");
		}
		catch(...)
		{
			cout << "������� ���������� ������!" << endl;
			continue;
		}

		while(isExit == false)
		{
			cout << "����� �����:\n";
			cout << "\t1 - ��������\n";
			cout << "\t2 - ����������\n";
			cout << "\t3 - ����������\n";
			cout << "\t4 - �������� ������\n";
			cout << "\t5 - �������� ���������\n";
			cout << "\t6 - ����� �� ���������\n";
			cout << "������� ����� �������: "; cin >> input;
			try
			{
				numberOfCommand = stoi(input);
				system("cls");
			}
			catch(...)
			{
				cout << "������� ��������� ������! ������������!" << endl;
			}
			cout << "�� ������� �����: " << endl;
			cout << points[point1] << endl;
			cout << points[point2] << endl;

			switch(numberOfCommand)
			{
				case 1:
				{
					cout << "�� ������� ��������" << endl;

					res = points[point1] - points[point2];
					cout << "���������: " << res << endl;
					break;
				}
				case 2:
				case 4:
				{
					int l1 = points[point1].getLength();
					int l2 = points[point2].getLength();
					cout << "�� ������� " << ((numberOfCommand == 2) ? "����������" : "�������� ������" ) << endl;
					cout << "����� ����� 1: " << l1 << '\n';
					cout << "����� ����� 2: " << l2 << '\n';
					if(numberOfCommand == 2)
					{
						cout << "����� 1 " << ((l1 >= l2) ? ">=" : "<") << " ����� 2.\n";
					}					
					break;
				}
				case 3:
				{
					cout << "�� ������� ����������" << endl;
					res = points[point1] - points[point2];
					cout << "���������: " << res << endl;
					break;
				}
				case 5:
				{
					cout << "�� ������� �������� ���������" << endl;
					cout << Barycenter<int>::getBarycenter(points[point1], points[point2]) << endl;
					break;
				}
				case 6:
				{
					isExit = true;
					system("cls");
					cout << "��������� ��������� ���� ������!" << endl;
					break;
				}
				default:
					cout << "����������� ��������! ������������!" << endl;
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
		cout << "������� ��-�� ����� (������ 1): "; cin >> input;
		countPoint = stoi(input);
		if(countPoint > 1)
		{
			InputUser(countPoint);
		}
		else
		{
			cout << "����� ������� ������ 1 �����!";
		}		
	}
	catch(...)
	{
		cout << "������ ����� ���-�� �����! ������� ���������� ������!";
	}
	return 0;
}