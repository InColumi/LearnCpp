#include <iostream>
#include "windows.h"
#include <string>

using namespace std;

void Task1()
{
    cout << "������� �����: ";
    string userInput;
    cin >> userInput;

    for(size_t i = 0; i < userInput.size(); i++)
    {
        cout << userInput[i];
        Sleep(100); // �������� � �������
    }
}

void Task2()
{

}

void CoutSpace(size_t count, char symbol = ' ')
{
    for(size_t j = 0; j < count; j++)
    {
        cout << symbol;
    }
}

void Task3()
{
    // ������� ������� �����
    size_t headSize = 10; // ������ ������
    size_t legSize = 10; // ������ �����
    size_t legLength= 10; // ������ �����
    size_t indent = 10; // ������ �����

    size_t countSpace = 1;
    size_t countIndet = headSize;
    CoutSpace(countIndet + indent);
    cout << "/\\" << "\n";
    for(size_t i = 0; i < headSize; i++)
    {
        CoutSpace(countIndet - countSpace + indent);
        cout << "/";
        CoutSpace(countSpace * 2);
        cout << "\\\n";
        countSpace++;
    }
    countSpace *= 2;
    countSpace--;

    // ����� ����������� �����
    size_t bodySize = headSize * 2;
    for(size_t i = 0; i < bodySize; i++)
    {
        CoutSpace(indent);
        cout << "|";        
  
        if(i == 2)
        {
            CoutSpace(countSpace / 2);
            cout << "O";
            CoutSpace(countSpace / 2);
        }
        else if(i == 5)
        {
            CoutSpace(countSpace / 2);
            cout << "O";
            CoutSpace(countSpace / 2);
        }
        else
        {
            CoutSpace(countSpace);
        }

        cout << "|\n";
    }

    // ����� ������ ����� (�����)
    size_t tailIndent = 0;
    for(size_t i = 0; i < legSize; i++)
    {
        CoutSpace(--indent);
        cout << "/";
        CoutSpace(tailIndent);
        cout << "|";
        CoutSpace(countSpace);
        cout << "|";
        CoutSpace(tailIndent++);
        cout << "\\\n";
    }
    tailIndent--;

    // ����� ������ �����
    for(size_t i = 0; i < legLength; i++)
    {
        cout << "|";
        CoutSpace(tailIndent);
        cout << "|";
        CoutSpace(countSpace);
        cout << "|";
        CoutSpace(tailIndent);
        cout << "|\n";
    }

    // ����� ������ �����
    cout << "|";
    CoutSpace(tailIndent);
    cout << "|";
    CoutSpace(countSpace,'-');
    cout << "|";
    CoutSpace(tailIndent);
    cout << "|\n";

    // ����� ������ ����� �����
    tailIndent--;
    for(size_t i = 0; i < legSize - 1; i++)
    {
        cout << "|";
        CoutSpace(tailIndent);
        cout << "/";
        countSpace += 2;
        CoutSpace(countSpace);
        cout << "\\";
        CoutSpace(tailIndent--);
        cout << "|\n";
    }
}

int main()
{
    setlocale(LC_ALL, "rus");

    //Task1();
    //Task2();
    Task3();
    return 0;
}

