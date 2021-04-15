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
	void ClearMemoryAndShowMessage(const char*& exception) const
	{
		std::cout << "Error: " << exception << '\n';
		this->~NPoint();
		exit(-1);
	}

	/// <summary>
	/// �������� �� ���������� ������
	/// </summary>
	/// <param name="index">������</param>
	/// <returns></returns>
	bool IsCorrectIndex(int index) const
	{
		return index >= 0 && index < _size;
	}

	/// <summary>
	/// �������� ������� � ������������ ���������� � ������ ������ �����������
	/// </summary>
	/// <param name="index"></param>
	void CheckIndex(int index) const
	{
		if(IsCorrectIndex(index) == false)
		{
			throw "����� �� �����������!";
		}
	}

	/// <summary>
	/// �������� ����������� � ������������ ��������� � ������ ������ �����������
	/// </summary>
	/// <param name="size"></param>
	void CheckSize(int size)
	{
		if(size != _size || _size == 0)
		{
			throw "������� ������ ������������!";
		}
	}

public:
	/// <summary>
	/// ����������� �� ���������
	/// </summary>
	NPoint()
	{
		_size = 0;
		_coordinates = NULL;
	}

	/// <summary>
	/// ����������� � ����������
	/// </summary>
	/// <param name="size">�����������</param>
	NPoint(int size)
	{
		try
		{
			if(size < 0)
			{
				throw "������������� �����������!";
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
	/// ����������� �����������
	/// </summary>
	/// <param name="point">������ �����������</param>
	NPoint(const NPoint& point)
	{
		_size = point._size;
		_coordinates = new T[_size];
		for(int i = 0; i < _size; i++)
		{
			_coordinates[i] = point._coordinates[i];
		}
	}

	// ����������
	~NPoint()
	{
		if(_coordinates != NULL)
		{
			_size = 0;
			delete[]_coordinates;
		}
	}

	/// <summary>
	/// �������� ������� �� �������
	/// </summary>
	/// <param name="index">������</param>
	/// <returns>�������� ��� index</returns>
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
	/// �������� ������� ���������� �� �������
	/// </summary>
	/// <param name="index">������</param>
	/// <returns>�������� ��� index</returns>
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
	/// �������� ������������
	/// </summary>
	/// <param name="point">������ ������������</param>
	/// <returns>������ �� ����� �����</returns>
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
	/// �������� ���������
	/// </summary>
	/// <param name="point">������ ��� ���������</param>
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
	/// �������� ��������
	/// </summary>
	/// <param name="point">������ ������������</param>
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
	/// �������� �����������
	/// </summary>
	/// <returns>�����������</returns>
	int getSize()
	{
		return _size;
	}

	/// <summary>
	/// ���������� ������
	/// </summary>
	/// <returns>������</returns>
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
				throw "����� �� ������!";
			}
		}
		catch(const char* exception)
		{
			ClearMemoryAndShowMessage(exception);
			return double();
		}
	}

	/// <summary>
	/// �������� ������
	/// </summary>
	/// <param name="out"></param>
	/// <param name="point"></param>
	/// <returns></returns>
	template <typename T> friend std::ostream& operator<< (std::ostream& out, const NPoint<T>& point)
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
};
#endif