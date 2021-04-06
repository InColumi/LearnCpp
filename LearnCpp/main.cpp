#include <iostream>
#include <time.h>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class Product
{
private:
	string _name; // название товара
	string _dateDelivery; // дата поставки

public:
	Product():_name(string()), _dateDelivery(string())
	{}

	Product(string name, string dateDelivery)
	{
		_name = name;
		_dateDelivery = dateDelivery;
	}

	string GetName() // получить имя товара
	{
		return _name;
	}

	string GetDateDelivery() // Получить дату поставки
	{
		return _dateDelivery;
	}

	string GetInfo() // получить информацию в виде строки
	{
		return +"Название: " + _name + ". "
			+ "Дата поставки: " + _dateDelivery + ".\n";
	}
};

class Employee
{
private:
	string _fcs; // ФИО
	/// <summary>
	/// формат ДД/ММ/ГГГГ
	/// </summary>
	string _dateOfBirth; // Дата рождения
	string _position; // Должность

public:
	Employee(): _fcs(string()), _dateOfBirth(string()), _position(string())
	{}

	Employee(string fcs, string dateOfBirth, string position)
	{
		_fcs = fcs;
		_dateOfBirth = dateOfBirth;
		_position = position;
	}

	string GetFcs() // получить ФИО
	{
		return _fcs;
	}

	string GetDateOfBirth()
	{
		return _dateOfBirth;
	} // Получить дату рождения

	string GetPosition()
	{
		return _position;
	} // Получить должность

	void Edit()
	{
		cout << "Изменить ФИО - 1" << endl;
		cout << "Изменить Дату Рождения - 2" << endl;
		cout << "Изменить Должность - 3" << endl;

		int numberOfCommand;
		cout << "Выберете номер команды: "; cin >> numberOfCommand;
		string input;
		switch(numberOfCommand)
		{
			case 1:
			{
				cout << "Введите новое ФИО: "; cin >> input;
				_fcs = input;
				break;
			}
			case 2:
			{
				cout << "Введите новую Дату Рождения(ДД/ММ/ГГГГ): "; cin >> input;
				_dateOfBirth = input;
				break;
			}
			case 3:
			{
				cout << "Введите новую Должность: "; cin >> input;
				_dateOfBirth = input;
				break;
			}
			default: cout << "Неизвестная команда!" << endl;
				break;
		}
	} // Форматирование сотрудника

	string GetInfo() // ПОлучить информацию в виде строки
	{
		return 		+"ФИО: " + _fcs + ". "
			+ "Дата рождения: " + _dateOfBirth + ". "
			+ "Должность: " + _position + ".\n";
	}
};

class Schedule
{
	string* _days; // массив дней
	int _countDays; // подсчет добавленных дней
public:
	Schedule()
	{
		_days = new string[7];
		_countDays = 0;
	}

	void AddDay(string newDay) // добавление 7 дней
	{
		if(_countDays > 7)
		{
			cout << "Ошибка при вводе данных!" << endl;
			exit(1);
		}
		_days[_countDays++] = newDay;
	}

	void EditMonday(string newDay)
	{
		_days[0] = newDay;
	}
	void EditTusday(string newDay)
	{
		_days[1] = newDay;
	}
	void EditWednesday(string newDay)
	{
		_days[2] = newDay;
	}
	void EditThursday(string newDay)
	{
		_days[3] = newDay;
	}
	void EditFriday(string newDay)
	{
		_days[4] = newDay;
	}
	void EditSaturday(string newDay)
	{
		_days[5] = newDay;
	}
	void EditSunday(string newDay)
	{
		_days[6] = newDay;
	}

	string GetInfo()
	{
		string info;
		for(size_t i = 0; i < 7; i++)
		{
			info += _days[i] + '\n';
		}
		return info;
	}
};

class Warehouse
{
private:
	vector<Employee> _employees; // Список работников
	vector<Product> _products; // Список товаров
	Schedule _schedule; // расписание

	template <typename T>
	void WriteToFiles(string fileName, T date) // Запись в файлы
	{
		ofstream inFile;
		inFile.open(fileName + ".txt");
		for(size_t i = 0; i < date.size(); i++)
		{
			inFile << date[i].GetInfo();
		}
		inFile.close();
	}

public:
	Warehouse()
	{
		_employees = vector<Employee>();
		_products = vector<Product>();
		_schedule = Schedule();
	}

	void AddEmployee(Employee employee) // добавление сотрудника в штат
	{
		_employees.push_back(employee);
	}

	void AddProduct(Product product) // Добавление продукта на склад
	{
		_products.push_back(product);
	}

	void AddSchedule(vector<string> schedule) // Добавление расписание склада
	{
		for(size_t i = 0; i < schedule.size(); i++)
		{
			_schedule.AddDay(schedule[i]);
		}
	}

	void ShowInfo() // Вывод информации на монитор
	{
		cout << "Список сотрудников: " << endl;
		for(size_t i = 0; i < _employees.size(); i++)
		{
			cout << _employees[i].GetInfo();
		}
		cout << endl;
		cout << "Список товаров: " << endl;
		for(size_t i = 0; i < _products.size(); i++)
		{
			cout << _products[i].GetInfo();
		}

		cout << endl;
		cout << "Расписание: " << endl;
		cout << _schedule.GetInfo();

	}

	void WriteToFiles() // запись информации в файлы
	{
		WriteToFiles("Employee", _employees);
		WriteToFiles("Product", _products);

		ofstream inFile;
		inFile.open("Schedule.txt");
		inFile << _schedule.GetInfo();
		inFile.close();

	}
};

vector<string> Split(string line, char splitter = '$')
{
	size_t startIndex = 0;
	vector<string> lines = vector<string>();
	string temp = "";
	for(size_t i = 0; i < line.size(); i++)
	{
		if(line[i] == splitter)
		{
			lines.push_back(temp);
			temp = "";
			continue;
		}
		temp += line[i];
	}
	return lines;
}

Employee CreateEmployee(vector<string> line)
{
	return Employee(line[0], line[1], line[2]);
}

Product CreateProduct(vector<string> line)
{
	return Product(line[0], line[1]);
}

string CreateSchedule(vector<string> line)
{
	return line[0];
}

template <typename T>
vector<T> ReadFromFile(string fileName, T(*type)(vector<string>))
{
	vector<T> lines = vector<T>();
	fstream out;
	out.open(fileName + ".txt");
	if(out.is_open() == false)
	{
		cout << "Файл " << fileName << ".txt не найден!" << endl;
	}

	string input;

	while(getline(out, input))
	{
		vector<string> line = Split(input);
		lines.push_back(type(line));
	}
	out.close();
	return lines;
}

void ReadFromFile(Warehouse& warehouse)
{
	cout << "Информация из файлов: " << endl << endl;
	vector<Employee> employees;
	employees = ReadFromFile("Employee", CreateEmployee);
	vector<Product> products;
	products = ReadFromFile("Product", CreateProduct);
	vector<string> schedule = ReadFromFile("Schedule", CreateSchedule);

	warehouse = Warehouse();
	for(size_t i = 0; i < employees.size(); i++)
	{
		warehouse.AddEmployee(employees[i]);
	}

	for(size_t i = 0; i < products.size(); i++)
	{
		warehouse.AddProduct(products[i]);
	}

	warehouse.AddSchedule(schedule);
	warehouse.ShowInfo();
}

void Edit(Warehouse& warehouse)
{
	cout << "Запись в файл: " << endl;
	cout << "Добавить сотрудника - 1" << endl;
	cout << "Добавить товар - 2" << endl;
	cout << "Записсать данные в файлы - 3" << endl;

	int numberOfCommand;
	cout << "Введите номер команды: "; cin >> numberOfCommand;
	switch(numberOfCommand)
	{
		case 1:
		{
			string fcs;
			string dateOfBirth;
			string position;
			cout << "Введите ФИО: "; cin >> fcs;
			cout << "Введите Дату рождения(ДД/ММ/ГГГГ): "; cin >> dateOfBirth;
			cout << "Введите Должность: "; cin >> position;
			warehouse.AddEmployee(Employee(fcs, dateOfBirth, position));
			break;
		}

		case 2:
		{
			string name;
			string dateDelivery;
			cout << "Введите название товара: "; cin >> name;
			cout << "Введите Дату поставки(ДД/ММ/ГГГГ): "; cin >> dateDelivery;
			warehouse.AddProduct(Product(name, dateDelivery));
			break;
		}

		case 3:
		{
			warehouse.WriteToFiles();
			break;
		}

		default:
			cout << "Неизвестная комманда!" << endl;
			break;
	}
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	Warehouse warehouse;
	ReadFromFile(warehouse);
	Edit(warehouse);

	system("pause");
	return 0;
}