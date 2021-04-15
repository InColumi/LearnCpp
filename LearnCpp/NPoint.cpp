#include "NPoint.h"

template <typename T>
void NPoint<T>::ClearMemoryAndShowMessage(const char*& exception) const
{
	std::cout << "Error: " << exception << '\n';
	this->~NPoint();
	exit(-1);
}

template <typename T>
bool NPoint<T>::IsCorrectIndex(int index) const
{
	return index >= 0 && index < _size;
}

template <typename T>
void NPoint<T>::CheckIndex(int index) const
{
	if(IsCorrectIndex(index) == false)
	{
		throw "����� �� �����������!";
	}
}

template <typename T>
void NPoint<T>::CheckSize(int size)
{
	if(size != _size || _size == 0)
	{
		throw "������� ������ ������������!";
	}
}

template <typename T>
NPoint<T>::NPoint()
{
	_size = 0;
	_coordinates = NULL;
}

template <typename T>
NPoint<T>::NPoint(int size)
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

template <typename T>
NPoint<T>::NPoint(const NPoint& point)
{
	_size = point._size;
	_coordinates = new T[_size];
	for(int i = 0; i < _size; i++)
	{
		_coordinates[i] = point._coordinates[i];
	}
}

template <typename T>
NPoint<T>::~NPoint()
{
	if(_coordinates != NULL)
	{
		_size = 0;
		delete[]_coordinates;
	}
}

template <typename T>
T& NPoint<T>::operator[] (const int index)
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

template <typename T>
const T& NPoint<T>::operator[] (const int index) const
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

template <typename T>
NPoint<T>& NPoint<T>::operator= (const NPoint<T>& point)
{
	_size = point._size;
	_coordinates = new T[_size];
	for(int i = 0; i < _size; i++)
	{
		_coordinates[i] = point._coordinates[i];
	}
	return *this;
}

template <typename T>
NPoint<T> NPoint<T>::operator- (const NPoint<T>& point)
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

template <typename T>
NPoint<T> NPoint<T>::operator+ (const NPoint<T>& point)
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

template <typename T>
int NPoint<T>::getSize()
{
	return _size;
}

template <typename T>
double NPoint<T>::getLength()
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


