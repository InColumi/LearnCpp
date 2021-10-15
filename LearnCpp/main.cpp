#include <string>
#include <iostream>
#include "Transport.h"

/*
��� �������:  ������� ������� ����� ���������� � ����������� �� ���� ������ ������������, ������, ��������. 
������� ������� ����� ���� � ����������� �� ���� ������ ��������� � �������������. 
�� ������ ���� ������� ������� ����� ��������� ������� � �������������� �������������� ������������.

��� ������ ����� �������, �������, �������� ?
���� ������ ���������
1) � ��� ���� ��������
2) ���������� ����
3) ���� �������
4) ����
5) ���
6) .... � ������
������
1) ��������� ������� ����
2) ����� �����������
3) ������ ��������

��� � ��� ������� ?
������
	1) ���� �� ������
	2) ������������ ��� ������, ��� ���� ������
�����
	1) ���� �� �������
	2) ������������ ��� ������, ��� ���� ������
������
	1) �����
	2) ������������ � ���������
*/

using namespace std;

class Car: Transport
{
private:
	float _mileage;


public:
	Car() : Transport() {}
	Car(float mileage, std::string name, unsigned int countOfSeats, std::string dateOfBirth, std::string color, float weight) 
		: Transport(name, countOfSeats, dateOfBirth, color, weight)
	{
		_mileage = mileage;
	}

	void ShowInfo()
	{
		std::cout << "Car\n";
		PrintInfo();
	}

	void Move()
	{
		std::cout << "� - ������. ��� �� ������.";
	}
};



int main()
{
	setlocale(LC_ALL, "rus");
	Transport transport;

	transport.ShowInfo();
	transport.Move();

	Car car;
	car.ShowInfo();
	car.Move();
	system("pause");
	return 0;
}