#include <ctime>

#ifndef MYTIME_H
#define MYTIME_H
#pragma once

/// <summary>
/// ������� �������� �������
/// </summary>
/// <param name="method"> ����� ��� ��������</param>
/// <returns>����� � �������������</returns>
double GetTime(void (*method)(void));

#endif