#ifndef BARYCENTER_H
#define BARYCENTER_H
#pragma once

template <typename T>
class Barycenter
{
public:
	static NPoint<double> getBarycenter(NPoint<T>*& points, int countPoints)
	{
		if(CheckSizes(points, countPoints))
		{
			int sizePoint = points[0].getSize();
			NPoint<double> res(sizePoint);
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
#endif