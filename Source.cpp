#include <iostream>
#include <string>
#include "Header.h"

using namespace std;

void Manager::option1() {
	string filename = "formatoArchivo.txt";
	ifstream file(filename.c_str());
	string line;
	vector<string> results;
	getline(file, line);
	getline(file, line);

	while (getline(file, line)) {
		//cout << line << endl;
		results = split(line, ',');

		if (results[0] == "p") {
			Movie newMovie = Movie(results[2], results[1], results[2], stoi(results[3]), results[4]);
			//dbVideos.push_back(newMovie);
			dbMovies.push_back(newMovie);
		}
		else if (results[0] == "c") {
			vector<string> splitArray = split(results[1], '-');
			//char *season;
			//season.append(splitArray.at(1).at(2));
			//strcat_s(season, &splitArray.at(1).at(1));
			//strcat_s(season, &splitArray.at(1).at(2));
			//string season = "" + splitArray.at(1).at(1) + splitArray.at(1).at(2);
			string seriesName = results[5];
			bool exists = false;
			Episode newEpisode = Episode(results[2], (int)splitArray.at(1).at(2), results[1], results[2], stoi(results[3]), results[4], stoi(results[6]));
			for (int i = 0; i < dbSeries.size(); i++) {
				if (seriesName == dbSeries.at(i).name) {
					exists = true;
					dbSeries.at(i).episodes.push_back(newEpisode);
				}
			}
			if (!exists) {
				Series serie = Series(seriesName);
				serie.episodes.push_back(newEpisode);
				dbSeries.push_back(serie);
			}
			dbVideos.push_back(newEpisode);
		}
	}

	file.close();

	/*while (!file.eof()) {
		file >> line;
		cout << line << endl;
	}*/

	/*
	while (getline(file, line))
	{
		stringstream stream(line);
		string valor;

		cout << "Contenido de la linea:\n";
		while (getline(stream, valor, ','))
		{
			cout << "valor leido: " << valor << '\n';
		}
		cout << "Fin de la linea\n";
	}*/


}

void Manager::option2() {
	cout << endl << "1. Filtrar videos por calificacion." << endl;
	cout << "2. Filtrar videos por genero." << endl;
	cout << "Opcion: ";
	cin >> option;

	if (option == 1) {
		cout << "Ingresa la calificacion a buscar (1-5): ";
		cin >> option;

		cout << endl << "Videos con " << option << " estrellas." << endl;
		for (int i = 0; i < dbVideos.size(); i++) {
			if (dbVideos.at(i).getRate() == option) {
				cout << dbVideos.at(i);
			}
		}
	}
	else if (option == 2) {
		cout << endl << "1. Drama." << endl;
		cout << "2. Accion." << endl;
		cout << "3. Misterio." << endl;
		cout << "Genero: ";
		cin >> option;
		string genreFilter = "";
		switch (option) {
		case 1:
			genreFilter = "drama";
			break;
		case 2:
			genreFilter = "accion";
			break;
		case 3:
			genreFilter = "misterio";
			break;
		}

		cout << endl << "Videos del genero -" << option << "- ." << endl;
		for (int i = 0; i < dbVideos.size(); i++) {
			if (dbVideos.at(i).getGenre() == genreFilter) {
				cout << dbVideos.at(i);
			}
		}
	}
}

void Manager::option3() {
	int rateFilter;
	cout << endl;
	for (int i = 0; i < dbSeries.size(); i++) {
		cout << i << ". " << dbSeries.at(i).name << endl;
	}
	cout << "Serie: ";
	cin >> option;

	//cin >> seriesName;
	cout << endl << "Ingresa la calificacion a buscar." << endl;
	cout << "Calificacion: ";
	cin >> rateFilter;

	cout << endl << "Episodios de " << dbSeries.at(option).name << " con calificacion de " << rateFilter << " estrellas." << endl;
	for (int j = 0; j < dbSeries.at(option).episodes.size(); j++) {
		if (rateFilter == dbSeries.at(option).episodes.at(j).getRate()) {
			cout << dbSeries.at(option).episodes.at(j);
		}
	}

}

void Manager::option4() {
	int rateFilter;
	cout << endl << "Ingresa la calificacion a buscar." << endl;
	cout << "Calificacion: ";
	cin >> rateFilter;

	cout << endl << "Peliculas con calificacion de " << rateFilter << " estrellas." << endl;
	for (int i = 0; i < dbMovies.size(); i++) {
		if (rateFilter == dbMovies.at(i).getRate()) {
			cout << dbMovies.at(i);
		}
	}
}

void Manager::option5() {
	string idFilter;
	int newRate;
	cout << endl << "Escribe el ID del video que quieras calificar." << endl;
	cout << "ID: ";
	cin >> idFilter;

	for (int i = 0; i < dbVideos.size(); i++) {
		if (idFilter == dbVideos.at(i).getName()) {
			cout << "Escribe la calificacion: ";
			cin >> newRate;
			dbVideos.at(i).setRate(newRate);
		}
	}


}

int main() {
	Manager manager;
	manager.option = 0;
	bool loop = true;
	while (loop) {
		cout << endl << "1. Cargar archivo de datos.\n";
		cout << "2. Mostrar los videos en general con una cierta calificacion o de un cierto genero.\n";
		cout << "3. Mostrar los episodios de una determinada serie con una calificacion determinada.\n";
		cout << "4. Mostrar las peliculas con cierta calificacion.\n";
		cout << "5. Calificar un video.\n";
		cout << "0. Salir.\n";
		cout << "Opcion: ";
		cin >> manager.option;
		switch (manager.option) {
		case 0:
			loop = false;
			break;
		case 1:
			manager.option1();
			break;
		case 2:
			manager.option2();
			break;
		case 3:
			manager.option3();
			break;
		case 4:
			manager.option4();
			break;
		case 5:
			manager.option5();
			break;

		}
	}
}