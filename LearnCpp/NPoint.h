#include <iostream>
#ifndef NPOINT_H
#define NPOINT_H
#pragma once

/// <summary>
/// Класс N-мерной точки
/// </summary>
/// <typeparam name="T"></typeparam>
template <typename T = int>
class NPoint
{
private:
	/// <summary>
	/// Размерность точки
	/// </summary>
	int _size;
	/// <summary>
	/// массив координат точки
	/// </summary>
	T* _coordinates;

	/// <summary>
	/// Очищает память из под массива, выбрасывает исключение и останавливает программу
	/// </summary>
	/// <param name="exception">назваине исключения</param>
	void ClearMemoryAndShowMessage(const char*& exception) const
	{
		std::cout << "Error: " << exception << '\n'; // вывести сообщение на монитор
		this->~NPoint(); // вызов деструктора для очистки памяти из под массива координат
		exit(-1); // аварийное закрытие программы
	}

	/// <summary>
	/// Проверка на корректный индекс
	/// </summary>
	/// <param name="index">индекс</param>
	/// <returns></returns>
	bool IsCorrectIndex(int index) const
	{
		return index >= 0 && index < _size; // проверка индекса, чтобы он был в пределе введенной размерности
	}

	/// <summary>
	/// Проверка индекса и выбрасывания исключения в случае выхода размерности
	/// </summary>
	/// <param name="index"></param>
	void CheckIndex(int index) const
	{
		if(IsCorrectIndex(index) == false) // если индекс не корректный
		{
			throw "Выход за размерность!"; // выбрасывает соответствующее исключение
		}
	}

	/// <summary>
	/// Проверка размерности и выбрасывания исключеия в случае выхода размерности
	/// </summary>
	/// <param name="size"></param>
	void CheckSize(int size)
	{
		if(size != _size || _size == 0) // если размерности не равны или одна из них равна 0
		{
			throw "Вектора разных размерностей!"; // выбрасывает соответствующее исключение
		}
	}

public:
	/// <summary>
	/// Конструктор по умолчанию
	/// </summary>
	NPoint()
	{
		_size = 0; // размерность точки по умолчанию = 0
		_coordinates = NULL; // массив координат является NULL
	}

	/// <summary>
	/// Конструктор с параметром
	/// </summary>
	/// <param name="size">размерность</param>
	NPoint(int size)
	{
		try  // блок try для возможной ошибки
		{
			if(size < 0) // если размерность меньше нуля
			{
				throw "Отрицательная размерность!";// выбрасывает соответствующее исключение
			}
			_size = size; // присваивает размерности заданную размерность
			_coordinates = new T[_size];  // выделяет пямять под размерность _size
			for(int i = 0; i < _size; i++) // заполнение координат по умолчанию
			{
				_coordinates[i] = T();
			}
		}
		catch(const char* exception)
		{
			ClearMemoryAndShowMessage(exception); // вывод сообщений с соответствующей ошибкой и останавливает программу
		}
	}

	/// <summary>
	/// Конструктор копирования
	/// </summary>
	/// <param name="point">объект копирования</param>
	NPoint(const NPoint& point)
	{
		_size = point._size; // присваивает _size размерность точки point 
		_coordinates = new T[_size]; // выделяет соответствующее кол-во памяти
		for(int i = 0; i < _size; i++) // поэлементно переписывает координаты точки point
		{
			_coordinates[i] = point._coordinates[i];
		}
	}

	// Деструктор
	~NPoint()
	{
		if(_coordinates != NULL) // если массив координат не указывает на NULL
		{
			_size = 0; // обнуляем кол-во элементов
			delete[]_coordinates; // очищаем память из под массива
		}
	}

	/// <summary>
	/// Оператор доступа по индексу
	/// </summary>
	/// <param name="index">индекс</param>
	/// <returns>значение под index</returns>
	T& operator[] (const int index)
	{
		try // блок try для возможной ошибки
		{
			CheckIndex(index);
			return _coordinates[index]; // возвращает значение под индексом index
		}
		catch(const char* exception)
		{
			ClearMemoryAndShowMessage(exception); // вывод сообщений с соответствующей ошибкой и останавливает программу
		}
	}

	/// <summary>
	/// Оператор доступа считывания по индексу
	/// </summary>
	/// <param name="index">индекс</param>
	/// <returns>значение под index</returns>
	const T& operator[] (const int index) const
	{
		try
		{
			CheckIndex(index);
			return _coordinates[index];
		}
		catch(const char* exception)
		{
			ClearMemoryAndShowMessage(exception);
			return NULL;
		}
	}

	/// <summary>
	/// Оператор присваивания
	/// </summary>
	/// <param name="point">Объект присваивания</param>
	/// <returns>ссылку на новый объкт</returns>
	NPoint<T>& operator= (const NPoint<T>& point)
	{
		_size = point._size; // присваивает _size размерность точки point 
		_coordinates = new T[_size]; // выделяет соответствующее кол-во памяти
		for(int i = 0; i < _size; i++) // поэлементно переписывает координаты точки point
		{
			_coordinates[i] = point._coordinates[i];
		}
		return *this;
	}

	/// <summary>
	/// Оператор вычитания
	/// </summary>
	/// <param name="point">Объект для вычитания</param>
	/// <returns></returns>
	NPoint<T> operator- (const NPoint<T>& point)
	{
		try
		{
			CheckSize(point._size);
			NPoint<T> answer(_size); // переменная для результата
			for(int i = 0; i < _size; i++) // поэлементно отнимаем коордианты
			{ 
				answer._coordinates[i] = _coordinates[i] - point._coordinates[i];
			}
			return answer; // возвращаем результат
		}
		catch(const char* exception)
		{
			ClearMemoryAndShowMessage(exception); // вывод сообщений с соответствующей ошибкой и останавливает программу
		}
	}

	/// <summary>
	/// Оператор сложения
	/// </summary>
	/// <param name="point">Объект присваивания</param>
	/// <returns></returns>
	NPoint<T> operator+ (const NPoint<T>& point)
	{
		try
		{
			CheckSize(point._size);
			NPoint<T> answer(_size); // переменная для результата
			for(int i = 0; i < _size; i++) // поэлементно отнимаем коордианты
			{
				answer._coordinates[i] = _coordinates[i] + point._coordinates[i];
			}
			return answer;
		}
		catch(const char* exception)
		{
			ClearMemoryAndShowMessage(exception); // вывод сообщений с соответствующей ошибкой и останавливает программу
		}
	}

	/// <summary>
	/// Получить размерность
	/// </summary>
	/// <returns>размерность</returns>
	int getSize()
	{
		return _size;
	}

	/// <summary>
	/// Возвращает длинну
	/// </summary>
	/// <returns>длинну</returns>
	double getLength()
	{
		try
		{
			if(_size >= 1) // если размер точки больше либо равен 1
			{
				double res = (double)(_coordinates[0] * _coordinates[0]); // возведение первой координаты в квадрат
				for(size_t i = 1; i < _size; i++) // возведение остальных координаты в квадрат
				{
					res += (double)(_coordinates[i] * _coordinates[i]);
				}
				return sqrt(res); // извлечение корня
			}
			else
			{
				throw "Точка не задана!";
			}
		}
		catch(const char* exception)
		{
			ClearMemoryAndShowMessage(exception); // вывод сообщений с соответствующей ошибкой и останавливает программу
			return double(); 
		}
	}

	/// <summary>
	/// Оператор вывода
	/// </summary>
	/// <param name="out"></param>
	/// <param name="point"></param>
	/// <returns></returns>
	friend std::ostream& operator<< (std::ostream& out, const NPoint<T>& point)
	{
		int size = point._size; // считывание размера точки, чтобы не обращаться каждый раз
		out << "Размер: " << size;
		if(size != 0)
		{
			out << ". -> [";
			for(int i = 0; i < size - 1; i++) // красивый вывод
			{
				out << point[i] << ", ";
			}
			out << point[size - 1] << "]";
		}
		return out;
	}
};
#endif