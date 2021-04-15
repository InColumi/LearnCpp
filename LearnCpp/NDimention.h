#ifndef NDemention_H
#define NDemention_H

template <typename T = int>
class NDemention
{
private:
	int _size;
	T* _array;

	void ClearMemoryAndShowMessage(const char*& exception);

	bool IsCorrectIndex(int index);

	void CheckIndex(int index);

	void CheckSize(int size);

public:
	/// <summary>
	/// Конструктор по умолчанию
	/// </summary>
	NDemention();
	
	/// <summary>
	/// Конструктор с параметром
	/// </summary>
	/// <param name="size">размерность</param>
	NDemention(int size);

	/// <summary>
	/// Конструктор копирования
	/// </summary>
	/// <param name="point">объект копирования</param>
	NDemention(const NDemention& point);
	
	// Деструктор
	~NDemention();

	/// <summary>
	/// Оператор доступа по индексу
	/// </summary>
	/// <param name="index">индекс</param>
	/// <returns>значение под index</returns>
	T& operator[] (const int index);

	/// <summary>
	/// Оператор присваивания
	/// </summary>
	/// <param name="point">Объект присваивания</param>
	/// <returns>ссылку на новый объкт</returns>
	NDemention<T>& operator= (const NDemention<T>& point);

	/// <summary>
	/// Оператор вычитания
	/// </summary>
	/// <param name="point">Объект для вычитания</param>
	/// <returns></returns>
	NDemention<T> operator- (const NDemention<T>& point);

	/// <summary>
	/// Оператор сложения
	/// </summary>
	/// <param name="point">Объект присваивания</param>
	/// <returns></returns>
	NDemention<T> operator+ (const NDemention<T>& point);
	
	/// <summary>
	/// Получить размерность
	/// </summary>
	/// <returns>размерность</returns>
	int getSize();

	/// <summary>
	/// Возвращает длинну
	/// </summary>
	/// <returns>длинну</returns>
	double getLength();

	friend std::ostream& operator<< (std::ostream& out, NDemention<T>& point);
};
#endif