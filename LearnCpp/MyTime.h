#include <ctime>

#ifndef MYTIME_H
#define MYTIME_H
#pragma once

/// <summary>
/// Функция подсчета времени
/// </summary>
/// <param name="method"> метод для подсчета</param>
/// <returns>время в миллисекундах</returns>
double GetTime(void (*method)(void));

#endif