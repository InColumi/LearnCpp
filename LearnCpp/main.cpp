#include <iostream>
#include <vector>
#include <conio.h>
#include <ctype.h>
#include <string>
#include <fstream>
#include <algorithm>

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

	string getInfo()
	{
		string line;
		line.append(Name);
		line.append(" (");
		line.append(Genre);
		line.append(" " + to_string(Duration));
		line.append(" min)\n");
		line.append("Rating: " + to_string(Rating));
		line.append(". " + to_string(RealeseYear) + " year");
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
		cout << films[i].getInfo() << "\n\n";
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

void FilterByDuration()
{
	vector<Film> films = ReadAllFiles();
	double min = films[0].Duration;
	size_t indexMin = 0;
	double max = films[0].Duration;
	size_t indexMax = 0;
	for(size_t i = 1; i < films.size(); i++)
	{
		if(min > films[i].Duration)
		{
			min = films[i].Duration;
			indexMin = i;
		}

		if(max < films[i].Duration)
		{
			max = films[i].Duration;
			indexMax = i;
		}
	}

	cout << "Film with min duration = " << min << endl;
	cout << "Film with max duration = " << max << endl;
}

void FilterByRating()
{
	vector<Film> films = ReadAllFiles();
	vector<double> ratings;
	ratings.push_back(floor(films[0].Rating));
	double rating;
	int count = 0;
	for(size_t i = 1; i < films.size(); i++)
	{
		rating = floor(films[i].Rating);
		for(size_t j = 0; j < ratings.size(); j++)
		{
			if(ratings[j] == rating)
			{
				count++;
			}
		}
		if(count == 0)
		{
			ratings.push_back(rating);
		}
		count = 0;
	}
	sort(ratings.begin(), ratings.end());
	for(size_t i = 0; i < ratings.size() - 1; i++)
	{
		cout << ratings[i] << " --- ";
	}
	cout << ratings[ratings.size() - 1] << "\n\n";

	cout << "Enter ratings from list: ";
	bool isCorrect = false;
	while(isCorrect == false)
	{
		cin >> rating;
		for(size_t i = 0; i < ratings.size(); i++)
		{
			if(rating == ratings[i])
			{
				isCorrect = true;
				break;
			}
		}
	}

	Film film;
	for(size_t i = 0; i < films.size(); i++)
	{
		film = films[i];
		if(floor(film.Rating) == rating)
		{
			cout << film.getInfo() << "\n\n";
		}
	}
}

void FilterByActor()
{
	string actor;
	cout << "Enter Actors: ";
	getline(cin, actor);

	vector<Film> films = ReadAllFiles();
	vector<size_t> indexFilms;
	vector<string> actors;
	for(size_t i = 0; i < films.size(); i++)
	{
		actors = films[i].Actors;
		for(size_t j = 0; j < actors.size(); j++)
		{
			if(actor == actors[j])
			{
				indexFilms.push_back(i);
				break;
			}
		}
	}

	cout << "\nFilms with actor: " << actor << "\n\n";
	for(size_t i = 0; i < indexFilms.size(); i++)
	{
		cout << films[indexFilms[i]].getInfo() << "\n\n";
	}
}

void Recomendation()
{
	Film film;
	film = GetRandomFilm();
	//cout << film.getInfo() << '\n';
	//FilterByGenre();
	//FilterByDuration();
	//FilterByActor();
	FilterByRating();
}

int main(int argc, char** argv)
{
	srand(time(0));
	Recomendation();
	return 0;
}