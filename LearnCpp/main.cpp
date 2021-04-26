#include <iostream>
#include <vector>
#include <conio.h>
#include <ctype.h>
#include <string>
#include <fstream>

using namespace std;

struct Film
{
	string Name;
	string Genre;
	double Rating;
	double Duration;
	vector<string> Actors;
	int RealeseYear;

	Film(string name, string genre, double duration, double rating, int realeseYear, vector<string> actors)
	{
		Name = name;
		Genre = genre;
		Duration = duration;
		Rating = rating;
		RealeseYear = realeseYear;
		Actors = actors;
	}

	Film()
	{
		Name = string();
		Genre = string();
		Duration = double();
		Rating = double();
		RealeseYear = int();
		Actors = vector<string>();
	}

	string ShowInfo()
	{
		string line = "";
		line += "Name: " + Name + '\n';
		line += "Genre: " + Genre + '\n';
		line += "Rating: " + to_string(Rating )+ '\n';
		line += "Duration: " + to_string(Duration) + '\n';
		line += "RealeseYear: " + RealeseYear + '\n';
		line += "Actors: ";
		for(size_t i = 0; i < Actors.size() - 1; i++)
		{
			line += Actors[i] + ", ";
		}
		line += Actors[Actors.size() - 1];

		return line;
	}
};

void ShowOnMonitor(vector<Film> films)
{
	for(size_t i = 0; i < films.size(); i++)
	{
		 cout << films[i].ShowInfo() << '\n';
	}
}

vector<Film> ReadFromFile(string fileName)
{
	ifstream in;
	in.open(fileName);
	if(in.is_open() == false)
	{
		cout << "Такого файла - нет.\n";
		exit(0);
	}

	string line;
	vector<Film> lines;
	Film film;
	while(getline(in, line))
	{

		for(size_t i = 0; i < 3; i++)
		{

		}
	}
	in.close();
	return lines;
}

vector<Film> InputUser()
{
	Film film;
	vector<Film>  films;
	bool isAddFilm = true;
	char symbol;
	bool isEnd = false;
	string actor;
	while(isAddFilm)
	{
		cout << "Do you want to add film? Y(yes)\\N(no)";
		symbol = _getch();
		if(symbol == 'Y')
		{
			cout << "Enter Name: "; cin >> film.Name;
			cout << "Enter Genre: "; cin >> film.Genre;
			cout << "Enter Rating: "; cin >> film.Rating;
			cout << "Enter Duration: "; cin >> film.Duration;
			cout << "Enter RealeseYear: "; cin >> film.RealeseYear;

			while(isEnd == false)
			{
				cout << "Enter Actors (enter end for exit): "; cin >> actor;
				if(actor == "exit")
				{
					system("cls");
					isEnd = true;
				}
				else
				{
					film.Actors.push_back(actor);
				}
			}
		}
		else if (symbol == 'N')
		{
			system("cls");
			isAddFilm = false;
		}
		else
		{
			cout << "Do you want to add film ? Y(yes)\N(no)";
		}		
	}
	return films;
	
}
int main(int argc, char** argv)
{
	setlocale(LC_ALL, "rus");

	vector<Film> films = InputUser();

	ShowOnMonitor(films);
	return 0;
}