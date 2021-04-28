#include "MyTime.h"

/// <summary>
/// ������� �������� �������
/// </summary>
/// <param name="method"> ����� ��� ��������</param>
/// <returns>����� � �������������</returns>
double GetTime(void (*method)(void))
{
	double start_time = clock(); // ��������� �����
	method(); 
	double end_time = clock(); // �������� �����
	return (end_time - start_time) / 1000.0; // ������� �����
}