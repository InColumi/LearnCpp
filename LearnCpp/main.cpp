#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

class Product
{
private:
	string _name;
	string _dateDelivery;


public:
	Product():_name(NULL), _dateDelivery(NULL)
	{}

	Product(string name, string dateDelivery)
	{
		_name = name;
		_dateDelivery = dateDelivery;
	}

	string GetName()
	{
		return _name;
	}

	string GetDateDelivery()
	{
		return _dateDelivery;
	}

	string GetInfo()
	{
		cout << "��������: " << _name << ". "
			<< "���� ��������: " << _dateDelivery << ".\n";
	}
};

class Employee
{
private:
	string _fcs;
	/// <summary>
	/// ������ ��/��/����
	/// </summary>
	string _dateOfBirth;
	string _position;

public:
	Employee(): _fcs(string()), _dateOfBirth(string()), _position(string())
	{}

	Employee(string fcs, string dateOfBirth, string position)
	{
		_fcs = fcs;
		_dateOfBirth = dateOfBirth;
		_position = position;
	}

	string GetFcs()
	{
		return _fcs;
	}

	string GetDateOfBirth()
	{
		return _dateOfBirth;
	}

	string GetPosition()
	{
		return _position;
	}

	void Edit()
	{
		cout << "�������� ��� - 1" << endl;
		cout << "�������� ���� �������� - 2" << endl;
		cout << "�������� ��������� - 3" << endl;

		int numberOfCommand;
		cout << "�������� ����� �������: "; cin >> numberOfCommand;
		string input;
		switch(numberOfCommand)
		{
			case 1:
			{
				cout << "������� ����� ���: "; cin >> input;
				_fcs = input;
				break;
			}
			case 2:
			{
				cout << "������� ����� ���� ��������(��/��/����): "; cin >> input;
				_dateOfBirth = input;
				break;
			}
			case 3:
			{
				cout << "������� ����� ���������: "; cin >> input;
				_dateOfBirth = input;
				break;
			}
			default: cout << "����������� �������!" << endl;
				break;
		}
	}

	string GetInfo()
	{
		cout << "���: " << _fcs << ". "
			<< "���� ��������: " << _dateOfBirth << ". "
			<< "���������: " << _position << ".\n";
	}
};

class Schedule
{
	string* _days;
public:
	Schedule()
	{
		_days = new string[7];
	}

	void Edit(size_t numberOfDay, string newDay)
	{
		_days[numberOfDay] = newDay;
	}
};

class Warehouse
{
private:
	vector<Employee> _employees;
	vector<Product> _products;

public:
	Warehouse()
	{
		_employees = vector<Employee>();
		_products = vector<Product>();
	}

	void AddEmployee(Employee employee)
	{
		_employees.push_back(employee);
	}

	void AddProduct(Product product)
	{
		_products.push_back(product);
	}
};

void ReadFromFile()
{

}

int main(int argc, char* argv[])
{

	setlocale(LC_ALL, "rus");

	system("pause");
	return 0;
}