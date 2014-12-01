#include "Sudoku.h"
#include "Matrice.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

const int DIMENSION_MATRICE = 9;
const int DIMENSION_QUADRANT = 3;

Sudoku::Sudoku(ifstream& fichierDonnees, ostream& out) : out_(out)
{
	matrice_ = Matrice<int>(DIMENSION_MATRICE, DIMENSION_MATRICE);
	matricePossibilités_ = Matrice<vector<int>>(DIMENSION_MATRICE, DIMENSION_MATRICE);
	vector<int> initialisateur = vector<int>();

	for (int i = 1; i <= DIMENSION_MATRICE; i++)
		initialisateur.push_back(i);

	for (int i = 0; i < DIMENSION_MATRICE; i++)
	{
		for (int j = 0; j < DIMENSION_MATRICE; j++)
		{
			matricePossibilités_[i][j] = initialisateur;
		}
	}

	string buffer;

	try
	{
		for (int i = 0; i < DIMENSION_MATRICE; i++)
		{
			getline(fichierDonnees, buffer);
			for (int j = 0; j < DIMENSION_MATRICE; j++)
			{
				string s(1, buffer[j]);
				if (buffer[j] == '*')
					matrice_[i][j] = 0;
				else
					matrice_[i][j] = stoi(s.c_str());
			}
		}
	}

	catch (exception e)
	{
		out << e.what() << endl;
	}
}

void Sudoku::Afficher()
{
	for (int i = 0; i < DIMENSION_MATRICE; i++)
	{
		for (int j = 0; j < DIMENSION_MATRICE; j++)
		{
			out_ << matrice_[i][j] << ' ';
		}
		out_ << endl;
	}
}

bool Sudoku::Solutionner()
{
	Matrice<vector<int>> tampon;
	Matrice<int> tampon2 = matrice_;
	EnleverPossibilités();
	tampon = matricePossibilités_;
	int xPossible = -1;
	int yPossible = -1;
	int dimensionVecteur = DIMENSION_MATRICE + 1;
	bool matriceModifiee = false;

	for (int i = 0; i < DIMENSION_MATRICE; i++)
	{
		for (int j = 0; j < DIMENSION_MATRICE; j++)
		{
			if (matrice_[i][j] == 0)
			{
				if (matricePossibilités_[i][j].size() < dimensionVecteur && matricePossibilités_[i][j].size() != 0)
				{
					xPossible = i;
					yPossible = j;
					dimensionVecteur = matricePossibilités_[i][j].size();
				}

				if (matricePossibilités_[i][j].size() == 1)
				{
					matrice_[i][j] = matricePossibilités_[i][j][0];
					matriceModifiee = true;
				}
			}
		}
	}

	if (MatriceEstPleine())
		return true;
	else if (matriceModifiee)
	{
		if (Solutionner())
			return true;
		matricePossibilités_ = tampon;
		matrice_ = tampon2;
	}
	else if (dimensionVecteur == DIMENSION_MATRICE + 1)
	{
		Afficher();
		cout << endl << endl;
		return false;

	}
	else if (dimensionVecteur != 1)
	{
		
		for (int i = 0; i < matricePossibilités_[xPossible][yPossible].size(); i++)
		{
			matrice_[xPossible][yPossible] = matricePossibilités_[xPossible][yPossible][i];
			
			
			if (Solutionner())
				return true;
			matricePossibilités_ = tampon;
			matrice_ = tampon2;
		}
	}

	matrice_ = tampon2;
	matricePossibilités_ = tampon;
	return false;
}

void Sudoku::EnleverPossibilités()
{
	for (int i = 0; i < DIMENSION_MATRICE; i++)
	{
		for (int j = 0; j < DIMENSION_MATRICE; j++)
		{
			if (matrice_[i][j] == 0)
			{
				for (int k = 1; k <= DIMENSION_MATRICE; k++)
				{
					vector<int>::iterator it = find(matricePossibilités_[i][j].begin(), matricePossibilités_[i][j].end(), k);
					if (it != matricePossibilités_[i][j].end())
					{
						if (EstDansLaLigne(k, j) || EstDansLaColonne(k, i)
							|| EstDansQuadrant(k, i, j))
							matricePossibilités_[i][j].erase(it);
					}
				}
			}
		}
	}
}




void Sudoku::RajouterPossibilités(int nombreEnleve, int x, int y)
{
	for (int i = 0; i < DIMENSION_MATRICE; i++)
	{
		if (matrice_[x][i] == 0)
			matricePossibilités_[x][i].push_back(nombreEnleve);
		if (matrice_[i][y] == 0)
			matricePossibilités_[i][y].push_back(nombreEnleve);
	}

	for (int i = 0; i < DIMENSION_QUADRANT; i++)
	{
		for (int j = 0; j < DIMENSION_QUADRANT; j++)
		{
			if (matrice_[(x / DIMENSION_QUADRANT) * DIMENSION_QUADRANT + i][(y / DIMENSION_QUADRANT) * DIMENSION_QUADRANT + j] == 0)
				matricePossibilités_[(x / DIMENSION_QUADRANT) * DIMENSION_QUADRANT + i][(y / DIMENSION_QUADRANT) * DIMENSION_QUADRANT + j].push_back(nombreEnleve);
		}
	}

}

bool Sudoku::EstDansLaColonne(int nombre, int x)
{
	bool resultat = false;

	for (int i = 0; i < DIMENSION_MATRICE; i++)
	{
		if (matrice_[x][i] == nombre)
			resultat = true;
	}

	return resultat;
}

bool Sudoku::EstDansLaLigne(int nombre, int y)
{
	bool resultat = false;

	for (int i = 0; i < DIMENSION_MATRICE; i++)
	{
		if (matrice_[i][y] == nombre)
			resultat = true;
	}

	return resultat;
}

bool Sudoku::EstDansQuadrant(int nombre, int x, int y)
{

	bool resultat = false;

	for (int i = 0; i < DIMENSION_QUADRANT; i++)
	{
		for (int j = 0; j < DIMENSION_QUADRANT; j++)
		{
			int s = (x / DIMENSION_QUADRANT) * DIMENSION_QUADRANT + i;
			int t = (y / DIMENSION_QUADRANT) * DIMENSION_QUADRANT + j;
			if (matrice_[s][t] == nombre)
				resultat = true;
		}
	}

	return resultat;
}

bool Sudoku::MatriceEstPleine()
{
	bool resultat = true;

	for (int i = 0; i < DIMENSION_MATRICE; i++)
	{
		for (int j = 0; j < DIMENSION_MATRICE; j++)
		{
			if (matrice_[i][j] == 0)
				resultat = false;
		}
	}

	return resultat;
}

bool Sudoku::Verifier()
{
	bool resultat = true;

	return resultat;





}

