#include "NPoint.h"
//#include "Barycenter.h"
//#include <iostream>
template <typename T>
class Barycenter
{
public:
	static NPoint<T> getBarycenter(NPoint<T>*& points, int countPoints)
	{
		if(CheckSizes(points, countPoints))
		{
			int sizePoint = points[0].getSize();
			NPoint<T> res(sizePoint);
			for(int i = 0; i < sizePoint; i++)
			{
				for(int j = 0; j < countPoints; j++)
				{
					res[i] += points[j][i];
				}
				res[i] = res[i] / (double)countPoints;
			}
			return res;
		}
		else
		{
			std::cout << "Точки разных измерений!" << std::endl;
		}
	}

private:

	static bool CheckSizes(NPoint<T>*& points, int countPoints)
	{
		int size = points[0].getSize();
		for(int i = 1; i < countPoints; i++)
		{
			if(size != points[i].getSize())
			{
				return false;
			}
		}
		return true;
	}
};

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
		throw "Выход за размерность!";
	}
}

template <typename T>
void NPoint<T>::CheckSize(int size)
{
	if(size != _size || _size == 0)
	{
		throw "Вектора разных размерностей!";
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
			throw "Точка не задана!";
		}
	}
	catch(const char* exception)
	{
		ClearMemoryAndShowMessage(exception);
		return double();
	}
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "rus");
	int countPoints = 2;
	NPoint<double>* points = new NPoint<double>[2];
	NPoint<double> a(countPoints);
	NPoint<double> b(countPoints);
	a[0] = 0;
	a[1] = 0;

	b[0] = 5;
	b[1] = 0;
	points[0] = a;
	points[1] = b;
	std::cout << Barycenter<double>::getBarycenter(points, countPoints) << std::endl;

	//cout << a << endl;
	return 0;
}