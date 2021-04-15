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
	void ClearMemoryAndShowMessage(const char*& exception) const;

	/// <summary>
	/// Проверка на корректный индекс
	/// </summary>
	/// <param name="index">индекс</param>
	/// <returns></returns>
	bool IsCorrectIndex(int index) const;

	/// <summary>
	/// Проверка индекса и выбрасывания исключения в случае выхода размерности
	/// </summary>
	/// <param name="index"></param>
	void CheckIndex(int index) const;

	/// <summary>
	/// Проверка размерности и выбрасывания исключеия в случае выхода размерности
	/// </summary>
	/// <param name="size"></param>
	void CheckSize(int size);

public:
	/// <summary>
	/// Конструктор по умолчанию
	/// </summary>
	NPoint();

	/// <summary>
	/// Конструктор с параметром
	/// </summary>
	/// <param name="size">размерность</param>
	NPoint(int size);

	/// <summary>
	/// Конструктор копирования
	/// </summary>
	/// <param name="point">объект копирования</param>
	NPoint(const NPoint& point);

	// Деструктор
	~NPoint();

	/// <summary>
	/// Оператор доступа по индексу
	/// </summary>
	/// <param name="index">индекс</param>
	/// <returns>значение под index</returns>
	T& operator[] (const int index);

	/// <summary>
	/// Оператор доступа считывания по индексу
	/// </summary>
	/// <param name="index">индекс</param>
	/// <returns>значение под index</returns>
	const T& operator[] (const int index) const;

	/// <summary>
	/// Оператор присваивания
	/// </summary>
	/// <param name="point">Объект присваивания</param>
	/// <returns>ссылку на новый объкт</returns>
	NPoint<T>& operator= (const NPoint<T>& point);

	/// <summary>
	/// Оператор вычитания
	/// </summary>
	/// <param name="point">Объект для вычитания</param>
	/// <returns></returns>
	NPoint<T> operator- (const NPoint<T>& point);

	/// <summary>
	/// Оператор сложения
	/// </summary>
	/// <param name="point">Объект присваивания</param>
	/// <returns></returns>
	NPoint<T> operator+ (const NPoint<T>& point);

	/// <summary>
	/// Получить размерность
	/// </summary>
	/// <returns>размерность</returns>
	int getSize();

	/// <summary>
	/// Возвращает длинну
	/// </summary>
	/// <returns>длинну</returns>
	double getLength();

	/// <summary>
	/// Оператор вывода
	/// </summary>
	/// <param name="out"></param>
	/// <param name="point"></param>
	/// <returns></returns>
	template <typename T> friend std::ostream& operator<< (std::ostream& out, const NPoint<T>& point);
};

template <typename T>
std::ostream& operator<< (std::ostream& out, const NPoint<T>& point)
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
#endif