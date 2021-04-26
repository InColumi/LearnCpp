#include <iostream>
#include <vector>
#include <conio.h>
#include <ctype.h>
#include <string>
#include <fstream>

using namespace std;
//
//double getValueFunc_237_2_1(double x)
//{
//	return cos(x * x + 1);
//}
//
//void Task_237_2_1()
//{
//	double PI = 3.141592;
//	double a = PI / 3.0;
//	double b = 3.0 * PI / 2.0;
//	int m = 10;
//	double h = (b - a) / (double)m;
//
//	int counter = 1;
//	for(double x = a; x < b; x += h)
//	{
//		cout << counter++ << " cos(" << x << "^2 + 1) = " << getValueFunc_237_2_1(x) << '\n';
//	}
//}
//
//double getValueFunc_2_2(double x)
//{
//	return log10(x) / 2.0f;
//}
//
//double getApproximation(double x, double eps = 0.001)
//{
//	double sumPrev = -x + 1;
//	double sumNext = 0.0f;
//	double x1 = x - 1;
//	double preciseValue = getValueFunc_2_2(x);
//	for(int n = 1; fabs(sumPrev - sumNext) > eps; n++)
//	{
//		sumNext = sumPrev;
//		x1 *= (x - 1);
//		sumPrev -= x1 / (n + 1.0);
//		//cout << fabs(sumPrev - sumNext) << endl;
//	}
//	return sumPrev;
//}
//
//void Task_2_2()
//{
//	double a = 0.2;
//	double b = 1;
//	int m = 10;
//	double eps = 0.0001;
//	double h = (b - a) / m;
//	double approximation;
//	double precise;
//	double diff;
//	for(double x = a; x <= b; x += h)
//	{
//		approximation = getApproximation(x, eps);
//		precise = getValueFunc_2_2(x);
//		diff = fabs(fabs(precise) - fabs(approximation));
//		cout <<
//			"x = " << x << "; y = " << precise <<
//			" <---> " << approximation << ";\n";
//	}
//}
//
//double getValueFunc_2_4_239_1(double x)
//{
//	return 1.0 / sqrt(9.0 + x * x);
//}
//
//double getPrecise_2_4_239_1(double x)
//{
//	return log10(x + sqrt(x * x + 9));
//}
//
//double getValueFunc_2_4_239_2(double x)
//{
//	double x2 = x * x;
//	return (x2 - 1) / ((x2 + 1) * (sqrt(x2 * x2 + 1)));
//}
//
//double getPrecise_2_4_239_2(double x)
//{
//	double sqrt2 = sqrt(2);
//	return -sqrt2 * asin(sin(2 * atan(x)) / sqrt2) / 2.0;
//}
//
//double getMethodTrapeze(double a, double b, int n, double (*f)(double))
//{
//	double h = (b - a) / n;
//	double sum = 0;
//	for(double i = a; i < b; i += h)
//	{
//		sum += f(i);
//	}
//	return 0.5 * h * (f(a) + f(b)) + sum * h;
//}
//
//double getApproximationMethodTrapeze(double a, double b, double (*f)(double), double eps = 0.000001)
//{
//	double resPrev = getMethodTrapeze(a, b, 1, f);
//	double resNext = 0.0;
//	for(int n = 2; fabs(resPrev - resNext) >= eps; n *= 2)
//	{
//		resNext = resPrev;
//		resPrev = getMethodTrapeze(a, b, n, f);
//		//cout << fabs(resPrev - resNext) << endl;
//	}
//	return resPrev;
//}
//
//double getCheck(double a, double b, double (*F)(double))
//{
//	return F(b) - F(a);
//}
//
//void Task_2_4_239()
//{
//	double a = 0;
//	double b = 2;
//	double eps = 0.00001;
//	cout << getApproximationMethodTrapeze(a, b, getValueFunc_2_4_239_1, eps) << " = "
//		<< getCheck(a, b, getPrecise_2_4_239_1) << endl;
//
//	a = 0;
//	b = 1;
//	cout << getApproximationMethodTrapeze(a, b, getValueFunc_2_4_239_2, eps) << " = "
//		<< getCheck(a, b, getPrecise_2_4_239_2) << endl;
//}
//
//void Task_249(int k)
//{
//	double size = 1000;
//	bool isNextNumber;
//	int xPow;
//	int yPow;
//
//	for(size_t i = 100; i <= size; i++)
//	{
//		isNextNumber = false;
//		for(size_t x = 1; x <= 9; x++)
//		{
//			if(isNextNumber)
//			{
//				break;
//			}
//			xPow = pow(x, k);
//			for(size_t y = 1; y <= 9; y++)
//			{
//				if(isNextNumber)
//				{
//					break;
//				}
//				yPow = pow(y, k);
//				for(size_t z = 1; z <= 9; z++)
//				{
//					if(isNextNumber)
//					{
//						break;
//					}
//					if(i == (xPow + yPow + pow(z, k)))
//					{
//						cout << i << ", ";
//						isNextNumber = true;
//					}
//				}
//			}
//		}
//	}
//}

void Print(vector<string> lines)
{
	for(size_t i = 0; i < lines.size(); i++)
	{
		cout << "[" << i + 1 << "] " << lines[i] << '\n';
	}
	cout << '\n';
}

vector<string> getLines()
{
	bool isLastLine = false;
	vector<string> lines;
	int counter = 0;
	string line;
	cout << "Вводите строки, чтобы закончить ввод - введите Done.\n";
	cout << "Нажмите Enter, чтобы закончить ввод текущей строки\n";
	cin.ignore(32767, '\n');
	while(isLastLine == false)
	{
		getline(cin, line);
		if(line == "Done")
		{
			isLastLine = true;
			cout << "\nВы ввели " << counter << " строк.\n";
		}
		else
		{
			counter++;
			lines.push_back(line);
		}
	}
	return lines;
}

void UpperFirstSymbol(string& line)
{
	line[0] = (char)toupper(line[0]);
	size_t size = line.size();
	for(size_t i = 1; i < size; i++)
	{
		if(line[i] == ' ' && i + 1 < size)
		{
			line[i + 1] = (char)toupper(line[i + 1]);
		}
	}
}

size_t FindWordInLine(string word, string line)
{
	return line.find(word);
}

vector<string>  ReadFromFile()
{
	string fileName;
	cout << "Введите имя файла с расширением. "; cin >> fileName;
	ifstream in;
	in.open(fileName);
	if(in.is_open() == false)
	{
		cout << "Такого файла - нет.\n";
		exit(0);
	}

	string line;
	vector<string> lines;

	while(getline(in, line))
	{
		lines.push_back(line);
	}
	in.close();
	return lines;
}

size_t InputNumberRow(size_t countRows)
{
	size_t numberLine;
	bool isCorrect = false;
	while(isCorrect == false)
	{
		cout << "Введие номер строки: "; cin >> numberLine;
		numberLine--;
		if(numberLine >= 0 && numberLine < countRows)
		{
			isCorrect = true;
		}
	}
	return numberLine;
}

void AllTask(string name, int command)
{
	system("cls");
	cout << "Вы выбрали: " << name << ".\n";
	vector<string> lines;
	size_t numberRow;
	switch(command)
	{
		case 1:
		{
			lines = getLines();
			Print(lines);
			numberRow = InputNumberRow(lines.size());
			UpperFirstSymbol(lines[numberRow]);
			cout << lines[numberRow] << endl;
			break;
		}
		case 2:
		{
			lines = getLines();
			Print(lines);
			string word;
			numberRow = InputNumberRow(lines.size());
			cout << lines[numberRow] << endl;
			cout << "Введите слово. "; cin >> word;
			cout << FindWordInLine(word, lines[numberRow]) << '\n';
			break;
		}
		case 3:
		{
			vector<string> linesFromFile = ReadFromFile();
			
			cout << "Строки из файла: \n";
			Print(linesFromFile);

			lines = getLines();
			cout << "Введенные строки: \n";
			Print(lines);

			cout << "Введите номер строки (из файла), которую хотите вставить: ";
			size_t numberRowFromFile = InputNumberRow(linesFromFile.size());

			cout << "Введите номер строки куда хотите вставить (введенные строки): ";
			size_t numberRowInput = InputNumberRow(lines.size());

			bool isCorrectIndex = false;
			size_t pos;
			while(isCorrectIndex == false)
			{
				cout << "Введите позицию, куда нужно вставить: "; cin >> pos;
				if(pos >= 0 && pos < lines[numberRowInput].size())
				{
					isCorrectIndex = true;
				}
				else
				{
					cout << "Неверная позиция!\n";
				}
			}

			auto iter = lines[numberRowInput].begin();

			lines[numberRowInput].insert(iter + pos, linesFromFile[numberRowFromFile].begin(), linesFromFile[numberRowFromFile].end());
			cout << lines[numberRowInput] << '\n';
			break;
		}
	}
}

void Task()
{
	string textReplace = "Замена всех первых строчных букв слов заглавными";
	string textSearch = "Поиск в строке";
	string textInsertFromFile = "Вставка текста из файла";
	bool isNextCommand = true;
	while(isNextCommand)
	{
		cout << "1 - " << textReplace << "\n";
		cout << "2 - " << textSearch << "\n";
		cout << "3 - " << textInsertFromFile << "\n";
		cout << "4 - выйти из программы\n";
		int numberOfCommand;
		cout << "Введите номер комманды: "; cin >> numberOfCommand;

		switch(numberOfCommand)
		{
			case 1:
			{
				AllTask(textReplace, numberOfCommand);
				break;
			}
			case 2:
			{
				AllTask(textSearch, numberOfCommand);
				break;
			}
			case 3:
			{
				AllTask(textInsertFromFile, numberOfCommand);
				break;
			}
			case 4:
			{
				cout << "Программа закончила свою работу!";
				isNextCommand = false;
				break;
			}
			default:
				cout << "Неизвестаня комманда! Внимательнее.\n";
				break;
		}
	}
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "rus");
	//Task_237_2_1();
	//Task_2_2();
	//Task_2_4_239();
	//Task_249(3);
	Task();


	return 0;
}