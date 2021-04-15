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
	/// ����������� �� ���������
	/// </summary>
	NDemention();
	
	/// <summary>
	/// ����������� � ����������
	/// </summary>
	/// <param name="size">�����������</param>
	NDemention(int size);

	/// <summary>
	/// ����������� �����������
	/// </summary>
	/// <param name="point">������ �����������</param>
	NDemention(const NDemention& point);
	
	// ����������
	~NDemention();

	/// <summary>
	/// �������� ������� �� �������
	/// </summary>
	/// <param name="index">������</param>
	/// <returns>�������� ��� index</returns>
	T& operator[] (const int index);

	/// <summary>
	/// �������� ������������
	/// </summary>
	/// <param name="point">������ ������������</param>
	/// <returns>������ �� ����� �����</returns>
	NDemention<T>& operator= (const NDemention<T>& point);

	/// <summary>
	/// �������� ���������
	/// </summary>
	/// <param name="point">������ ��� ���������</param>
	/// <returns></returns>
	NDemention<T> operator- (const NDemention<T>& point);

	/// <summary>
	/// �������� ��������
	/// </summary>
	/// <param name="point">������ ������������</param>
	/// <returns></returns>
	NDemention<T> operator+ (const NDemention<T>& point);
	
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

	friend std::ostream& operator<< (std::ostream& out, NDemention<T>& point);
};
#endif