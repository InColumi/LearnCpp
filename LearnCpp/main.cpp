#include <string>
#include <iostream>
#include "Transport.h"

/*
Сам вариант:  Создать базовый класс «Транспорт» и производные от него классы «Автомобиль», «Поезд», «Самолет». 
Создать базовый класс «Тип» и производные от него классы «Грузовой» и «Пассажирский». 
На основе этих классов создать набор различных классов с использованием множественного наследования.

Что общего между машиной, поездом, самолётом ?
Поля класса Транспорт
1) у них есть название
2) посадочных мест
3) дата выпуска
4) цвет
5) вес
6) .... и хватит
Методы
1) получение каждого поля
2) метод перемещение
3) способ заправки

Что у них разного ?
Машина
	1) едет по дороге
	2) заправляется где угодно, где есть бензин
Поезд
	1) едет по рельсам
	2) заправляется где угодно, где есть бензин
Самолёт
	1) летит
	2) заправляется в аэропорту
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
		std::cout << "Я - машина. Еду по дороге.";
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