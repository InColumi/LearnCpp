#include <iostream>
#include <vector>
#include <conio.h>
#include <ctype.h>
#include <string>
#include <fstream>

using namespace std;

const vector<string> _genres = {"action","comedy","drama","fantasy","horror"};

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

	string toStr()
	{
		string line;
		line.append(Name + '\n');
		line.append(to_string(Duration) + '\n');
		line.append(to_string(Rating) + '\n');
		line.append(to_string(RealeseYear) + '\n');
		for(size_t i = 0; i < Actors.size(); i++)
		{
			line.append(Actors[i] + ",");
		}
		line.append("\n");
		return line;
	}

	string ShowInfo()
	{
		string line;
		line.append(Name);
		line.append(" (");
		line.append(Genre);
		line.append(" " + to_string(Duration));
		line.append(" min)\n");
		line.append("Rating: ");
		line.append(to_string(Rating));
		line.append(" RealeseYear: ");
		line.append(to_string(RealeseYear));
		line.append("\n");
		line.append("Actors: ");
		for(size_t i = 0; i < Actors.size() - 1; i++)
		{
			line.append(Actors[i] + ", ");
		}
		line.append(Actors[Actors.size() - 1]);

		return line;
	}

	void Clear()
	{
		Name.clear();
		Genre.clear();
		Duration = double();
		Rating = double();
		RealeseYear = int();
		Actors.clear();
	}
};

void ShowOnMonitor(vector<Film> films)
{
	for(size_t i = 0; i < films.size(); i++)
	{
		cout << films[i].ShowInfo() << "\n\n";
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
	vector<Film> films;
	Film film;
	string genre = fileName.substr(0, fileName.size() - 4);

	while(getline(in, line))
	{
		film.Genre = genre;
		film.Name = line;
		getline(in, line);
		film.Duration = stod(line);
		getline(in, line);
		film.Rating = stod(line);
		getline(in, line);
		film.RealeseYear = stoi(line);
		getline(in, line);
		string actor = "";
		size_t start = 0;
		size_t end = 0;
		for(size_t i = 0; i < line.size(); i++)
		{
			if(line[i] == ',')
			{
				end = i;
				actor = line.substr(start, end - start);
				start = end + 1;
				film.Actors.push_back(actor);
			}
		}
		films.push_back(film);
		film.Clear();
	}
	in.close();
	return films;
}

vector<Film> InputUser()
{
	Film film;
	vector<Film>  films;
	bool isAddFilm = true;
	char symbol;
	bool isEnd = false;
	string actorName;
	while(isAddFilm)
	{
		cout << "Do you want to add film? Y(yes)\\N(no): ";
		symbol = _getch();
		if(symbol == 'Y')
		{
			cout << "\nEnter Name: "; cin >> film.Name;
			cout << "Enter Genre: "; cin >> film.Genre;
			cout << "Enter Rating(double): "; cin >> film.Rating;
			cout << "Enter Duration(double): "; cin >> film.Duration;
			cout << "Enter RealeseYear: "; cin >> film.RealeseYear;

			cout << "Enter Actors: Name and Surname (enter end for exit):\n";
			cin.ignore(32767, '\n');
			while(isEnd == false)
			{
				getline(cin, actorName);
				if(actorName == "exit")
				{
					system("cls");
					isEnd = true;
				}
				else
				{
					film.Actors.push_back(actorName);
				}
			}
			films.push_back(film);
		}
		else if(symbol == 'N')
		{
			system("cls");
			isAddFilm = false;
		}
		else
		{
			cout << "Do you want to add film ? Y(yes)\\N(no)";
		}
	}
	return films;

}

void AddFilms(vector<Film>& achievefilms, vector<Film> newFilms)
{
	for(size_t i = 0; i < newFilms.size(); i++)
	{
		achievefilms.push_back(newFilms[i]);
	}
}

vector<Film> ReadAllFiles()
{
	vector<Film> films;
	for(size_t i = 0; i < _genres.size(); i++)
	{
		AddFilms(films, ReadFromFile(_genres[i] + ".txt"));
	}
	return films;
}

Film GetRandomFilm()
{
	vector<Film> films = ReadAllFiles();
	return films[0 + rand() % (films.size() - 1)];
}

void FilterByGenre()
{
	bool isCorrect = false;
	string genre;
	while(isCorrect == false)
	{
		cout << "Enter genre: "; cin >> genre;
		for(size_t i = 0; i < _genres.size(); i++)
		{
			if(genre == _genres[i])
			{
				isCorrect = true;
				break;
			}
		}
	}

	vector<Film> films = ReadFromFile(genre + ".txt");
	ShowOnMonitor(films);
}

int main(int argc, char** argv)
{
	srand(time(0));
	setlocale(LC_ALL, "rus");
	FilterByGenre();
	return 0;
}