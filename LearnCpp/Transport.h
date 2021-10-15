#pragma once
#include <string>
#include <iostream>

class Transport
{
protected:
	std::string _name;
	unsigned int _countofSeats;
	std::string _dateOfBirth;
	std::string _color;
	float _weight;

public:
	Transport() : _name("default name"), _countofSeats(0), _dateOfBirth("default date"), _color("default color"), _weight(0) {}

	Transport(std::string name, unsigned int countOfSeats, std::string dateOfBirth, std::string color, float weight)
	{
		_name = name;
		_countofSeats = countOfSeats;
		_dateOfBirth = dateOfBirth;
		_color = color;
		_weight = weight;
	}

	virtual void ShowInfo()
	{
		std::cout << "Transport\n";
		PrintInfo();
	}

	virtual void Move()
	{
		std::cout << "� ����� �� ���, ���� � ��������� (���������� ����)\n";
	}

protected:

	//����� ���������� � ���������� �������
	void PrintInfo()
	{
		std::cout << "�������� ����������: " << _name << '\n';
		std::cout << "���-�� ���������� ����: " << _countofSeats << '\n';
		std::cout << "���� �������: " << _dateOfBirth << '\n';
		std::cout << "����: " << _color << '\n';
		std::cout << "���: " << _weight << '\n';
	}
};