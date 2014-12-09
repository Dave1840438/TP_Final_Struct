//Source.cpp
//David Sylvestre et Patrick Lemay
//1er D�cembre 2014
//Ce fichier contient le main

#include "Sudoku.h"
#include "Chrono.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Instancie un objet de type Sudoku, lui commande de se r�soudre
//puis affiche le temps d'�x�cution ainsi que la solution
int main()
{
   string nomFichier;
   cout << "Quel est le nom du fichier a lire?  ";
   cin >> nomFichier;

	ifstream fichier(nomFichier, ios::in);
	Chrono chrono;

	if (fichier)
	{
		cout << "Lecture reussie" << endl;
		Sudoku sudoku(fichier, cout);
		fichier.close();

		chrono.Start();
		sudoku.Solutionner();
		chrono.Stop();

		cout << "Temps requis: " << chrono.Read() << endl;
		sudoku.Afficher();
	}
	else
	{
		cout << "Erreur de lecture" << endl;
	}
}