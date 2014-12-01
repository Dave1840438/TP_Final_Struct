#include "Sudoku.h"
#include "Chrono.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream fichier("Test.txt", ios::in);
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