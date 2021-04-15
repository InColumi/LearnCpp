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
	int _size;
	T* _coordinates;

	/// <summary>
	/// Очищает память из под массива, выбрасывает исключение и останавливает программу
	/// </summary>
	/// <param name="exception">назваине исключения</param>
	void ClearMemoryAndShowMessage(const char*& exception) const
	{
		std::cout << "Error: " << exception << '\n';
		this->~NPoint();
		exit(-1);
	}

	/// <summary>
	/// Проверка на корректный индекс
	/// </summary>
	/// <param name="index">индекс</param>
	/// <returns></returns>
	bool IsCorrectIndex(int index) const
	{
		return index >= 0 && index < _size;
	}

	/// <summary>
	/// Проверка индекса и выбрасывания исключения в случае выхода размерности
	/// </summary>
	/// <param name="index"></param>
	void CheckIndex(int index) const
	{
		if(IsCorrectIndex(index) == false)
		{
			throw "Выход за размерность!";
		}
	}

	/// <summary>
	/// Проверка размерности и выбрасывания исключеия в случае выхода размерности
	/// </summary>
	/// <param name="size"></param>
	void CheckSize(int size)
	{
		if(size != _size || _size == 0)
		{
			throw "Вектора разных размерностей!";
		}
	}

public:
	/// <summary>
	/// Конструктор по умолчанию
	/// </summary>
	NPoint()
	{
		_size = 0;
		_coordinates = NULL;
	}

	/// <summary>
	/// Конструктор с параметром
	/// </summary>
	/// <param name="size">размерность</param>
	NPoint(int size)
	{
		try
		{
			if(size < 0)
			{
				throw "Отрицательная размерность!";
			}
			_size = size;
			_coordinates = new T[_size];
			for(int i = 0; i < _size; i++)
			{
				_coordinates[i] = T();
			}
		}
		catch(const char* exception)
		{
			ClearMemoryAndShowMessage(exception);
		}
	}

	/// <summary>
	/// Конструктор копирования
	/// </summary>
	/// <param name="point">объект копирования</param>
	NPoint(const NPoint& point)
	{
		_size = point._size;
		_coordinates = new T[_size];
		for(int i = 0; i < _size; i++)
		{
			_coordinates[i] = point._coordinates[i];
		}
	}

	// Деструктор
	~NPoint()
	{
		if(_coordinates != NULL)
		{
			_size = 0;
			delete[]_coordinates;
		}
	}

	/// <summary>
	/// Оператор доступа по индексу
	/// </summary>
	/// <param name="index">индекс</param>
	/// <returns>значение под index</returns>
	T& operator[] (const int index)
	{
		try
		{
			CheckIndex(index);
			return _coordinates[index];
		}
		catch(const char* exception)
		{
			ClearMemoryAndShowMessage(exception);
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
		_size = point._size;
		_coordinates = new T[_size];
		for(int i = 0; i < _size; i++)
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
			NPoint<T> answer(_size);
			for(int i = 0; i < _size; i++)
			{
				answer._coordinates[i] = _coordinates[i] - point._coordinates[i];
			}
			return answer;
		}
		catch(const char* exception)
		{
			ClearMemoryAndShowMessage(exception);
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
			NPoint<T> answer(_size);
			for(int i = 0; i < _size; i++)
			{
				answer._coordinates[i] = _coordinates[i] + point._coordinates[i];
			}
			return answer;
		}
		catch(const char* exception)
		{
			ClearMemoryAndShowMessage(exception);
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
			if(_size >= 1)
			{
				double res = (double)(_coordinates[0] * _coordinates[0]);
				for(size_t i = 1; i < _size; i++)
				{
					res += (double)(_coordinates[i] * _coordinates[i]);
				}
				return sqrt(res);
			}
			else
			{
				throw "Точка не задана!";
			}
		}
		catch(const char* exception)
		{
			ClearMemoryAndShowMessage(exception);
			return double();
		}
	}

	/// <summary>
	/// Оператор вывода
	/// </summary>
	/// <param name="out"></param>
	/// <param name="point"></param>
	/// <returns></returns>
	template <typename T> friend std::ostream& operator<< (std::ostream& out, const NPoint<T>& point)
	{
		int size = point._size;
		out << "Размер: " << size;
		if(size != 0)
		{
			out << ". -> [";
			for(int i = 0; i < size - 1; i++)
			{
				out << point[i] << ", ";
			}
			out << point[size - 1] << "]";
		}
		return out;
	}
};
#endif