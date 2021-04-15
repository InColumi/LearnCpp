#ifndef BARYCENTER_H
#define BARYCENTER_H
#pragma once

/// <summary>
///  ласс Ѕарицентр
/// </summary>
/// <typeparam name="T"></typeparam>
template <typename T>
class Barycenter
{
public:
	/// <summary>
	/// —татический метод, чтобы получать доступ к методу без создан€ объекта класса
	/// </summary>
	/// <param name="points"></param>
	/// <param name="countPoints"></param>
	/// <returns></returns>
	static NPoint<double> getBarycenter(NPoint<T>*& points, int countPoints)
	{
		if(CheckSizes(points, countPoints)) // проверка, что все точки одинаковой размерности
		{
			int sizePoint = points[0].getSize(); // считывание размерности, чтобы посто€нно не обращатьс€
			NPoint<double> res(sizePoint); // дл€ сохранение результата
			for(int i = 0; i < sizePoint; i++)
			{
				for(int j = 0; j < countPoints; j++)
				{
					res[i] += points[j][i]; // суммирование координат
				}
				res[i] = res[i] / (double)countPoints; // деление на общее кол-во координат
			}
			return res;
		}
		else
		{
			std::cout << "“очки разных измерений!" << std::endl; 
		}
	}

private:

	/// <summary>
	/// ѕроврка размерностией координат
	/// </summary>
	/// <param name="points"></param>
	/// <param name="countPoints"></param>
	/// <returns></returns>
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
#endif