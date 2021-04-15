#include "NDimention.h"

template <typename T>
void NDemention<T>::ClearMemoryAndShowMessage(const char*& exception)
{
	std::cout << "Error: " << exception << '\n';
	this->~NDemention();
	exit(-1);
}

template <typename T>
bool NDemention<T>::IsCorrectIndex(int index)
{
	return index >= 0 && index < _size;
}

template <typename T>
void NDemention<T>::CheckIndex(int index)
{
	if(IsCorrectIndex(index) == false)
	{
		throw "Выход за размерность!";
	}
}

template <typename T>
void NDemention<T>::CheckSize(int size)
{
	if(size != _size || _size == 0)
	{
		throw "Вектора разных размерностей!";
	}
}

template <typename T>
NDemention<T>::NDemention():_size(0), _array(NULL)
{}

template <typename T>
NDemention<T>::NDemention(int size)
{
	try
	{
		if(size < 0)
		{
			throw "Отрицательная размерность!";
		}
		_size = size;
		_array = new T[_size];
		for(int i = 0; i < _size; i++)
		{
			_array[i] = T();
		}
	}
	catch(const char* exception)
	{
		ClearMemoryAndShowMessage(exception);
	}
}

template <typename T>
NDemention<T>::NDemention(const NDemention& point)
{
	_size = point._size;
	_array = new T[_size];
	for(int i = 0; i < _size; i++)
	{
		_array[i] = point._array[i];
	}
}

template <typename T>
NDemention<T>::~NDemention()
{
	if(_array != NULL)
	{
		_size = 0;
		delete[]_array;
	}
}

template <typename T>
T& NDemention<T>::operator[] (const int index)
{
	try
	{
		CheckIndex(index);
		return _array[index];
	}
	catch(const char* exception)
	{
		ClearMemoryAndShowMessage(exception);
	}
}

template <typename T>
NDemention<T>& NDemention<T>::operator= (const NDemention<T>& point)
{
	_size = point._size;
	_array = new T[_size];
	for(int i = 0; i < _size; i++)
	{
		_array[i] = point._array[i];
	}
	return *this;
}

template <typename T>
NDemention<T> NDemention<T>::operator- (const NDemention<T>& point)
{
	try
	{
		CheckSize(point._size);
		NDemention<T> answer(_size);
		for(int i = 0; i < _size; i++)
		{
			answer._array[i] = _array[i] - point._array[i];
		}
		cout << answer << endl;
		return answer;
	}
	catch(const char* exception)
	{
		ClearMemoryAndShowMessage(exception);
	}
}

template <typename T>
NDemention<T> NDemention<T>::operator+ (const NDemention<T>& point)
{
	try
	{
		CheckSize(point._size);
		NDemention<T> answer(_size);
		for(int i = 0; i < _size; i++)
		{
			answer._array[i] = _array[i] + point._array[i];
		}
		cout << answer << endl;
		return answer;
	}
	catch(const char* exception)
	{
		ClearMemoryAndShowMessage(exception);
	}
}

template <typename T>
int NDemention<T>::getSize()
{
	return _size;
}

template <typename T>
double NDemention<T>::getLength()
{
	try
	{
		if(_size >= 1)
		{
			double res = _array[0] * _array[0];
			for(size_t i = 1; i < _size; i++)
			{
				res += _array[i] * _array[i];
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
	}
}

template <typename T>
std::ostream& operator<< (std::ostream& out, NDemention<T>& point)
{
	int size = point.getSize();
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