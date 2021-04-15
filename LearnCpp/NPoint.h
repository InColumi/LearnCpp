#include <iostream>
#ifndef NPOINT_H
#define NPOINT_H
#pragma once

/// <summary>
/// ����� N-������ �����
/// </summary>
/// <typeparam name="T"></typeparam>
template <typename T = int>
class NPoint
{
private:
	int _size;
	T* _coordinates;

	/// <summary>
	/// ������� ������ �� ��� �������, ����������� ���������� � ������������� ���������
	/// </summary>
	/// <param name="exception">�������� ����������</param>
	void ClearMemoryAndShowMessage(const char*& exception) const;

	/// <summary>
	/// �������� �� ���������� ������
	/// </summary>
	/// <param name="index">������</param>
	/// <returns></returns>
	bool IsCorrectIndex(int index) const;

	/// <summary>
	/// �������� ������� � ������������ ���������� � ������ ������ �����������
	/// </summary>
	/// <param name="index"></param>
	void CheckIndex(int index) const;

	/// <summary>
	/// �������� ����������� � ������������ ��������� � ������ ������ �����������
	/// </summary>
	/// <param name="size"></param>
	void CheckSize(int size);

public:
	/// <summary>
	/// ����������� �� ���������
	/// </summary>
	NPoint();

	/// <summary>
	/// ����������� � ����������
	/// </summary>
	/// <param name="size">�����������</param>
	NPoint(int size);

	/// <summary>
	/// ����������� �����������
	/// </summary>
	/// <param name="point">������ �����������</param>
	NPoint(const NPoint& point);

	// ����������
	~NPoint();

	/// <summary>
	/// �������� ������� �� �������
	/// </summary>
	/// <param name="index">������</param>
	/// <returns>�������� ��� index</returns>
	T& operator[] (const int index);

	/// <summary>
	/// �������� ������� ���������� �� �������
	/// </summary>
	/// <param name="index">������</param>
	/// <returns>�������� ��� index</returns>
	const T& operator[] (const int index) const;

	/// <summary>
	/// �������� ������������
	/// </summary>
	/// <param name="point">������ ������������</param>
	/// <returns>������ �� ����� �����</returns>
	NPoint<T>& operator= (const NPoint<T>& point);

	/// <summary>
	/// �������� ���������
	/// </summary>
	/// <param name="point">������ ��� ���������</param>
	/// <returns></returns>
	NPoint<T> operator- (const NPoint<T>& point);

	/// <summary>
	/// �������� ��������
	/// </summary>
	/// <param name="point">������ ������������</param>
	/// <returns></returns>
	NPoint<T> operator+ (const NPoint<T>& point);

	/// <summary>
	/// �������� �����������
	/// </summary>
	/// <returns>�����������</returns>
	int getSize();

	/// <summary>
	/// ���������� ������
	/// </summary>
	/// <returns>������</returns>
	double getLength();

	/// <summary>
	/// �������� ������
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
	out << "������: " << size;
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