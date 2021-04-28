#include "MyTime.h"

/// <summary>
/// Функция подсчета времени
/// </summary>
/// <param name="method"> метод для подсчета</param>
/// <returns>время в миллисекундах</returns>
double GetTime(void (*method)(void))
{
	double start_time = clock(); // начальное время
	method(); 
	double end_time = clock(); // конечное время
	return (end_time - start_time) / 1000.0; // искомое время
}