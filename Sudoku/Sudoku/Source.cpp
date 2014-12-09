//Source.cpp
//David Sylvestre et Patrick Lemay
//1er Décembre 2014
//Ce fichier contient le main

#include "Sudoku.h"
#include "Chrono.h"
#include <iostream>
#include <fstream>

using namespace std;

//Instancie un objet de type Sudoku, lui commande de se résoudre
//puis affiche le temps d'éxécution ainsi que la solution
int main()
{
	ifstream fichier("TestPierre.txt", ios::in);
	Chrono chrono;

	if (fichier)
	{
		cout << "good" << endl;
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
		cout << "...." << endl;
	}
}