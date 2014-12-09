//Sudoku.cpp
//David Sylvestre et Patrick Lemay
//1er D�cembre 2014
//Ce fichier contient la d�finition de la classe Sudoku

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
	matricePossibilit�s_ = Matrice<vector<int>>(DIMENSION_MATRICE, DIMENSION_MATRICE);
	vector<int> initialisateur = vector<int>();

	for (int i = 1; i <= DIMENSION_MATRICE; i++)
		initialisateur.push_back(i);

	for (int i = 0; i < DIMENSION_MATRICE; i++)
	{
		for (int j = 0; j < DIMENSION_MATRICE; j++)
		{
			matricePossibilit�s_[i][j] = initialisateur;
		}
	}

	string buffer;
	for (int i = 0; i < DIMENSION_MATRICE; i++)
	{
		getline(fichierDonnees, buffer);
		for (int j = 0; j < DIMENSION_MATRICE; j++)
		{
			char c = buffer[j];
			if (buffer[j] == '*')
				matrice_[i][j] = 0;
			else
				matrice_[i][j] = atoi(&c);
		}
	}
}

void Sudoku::Afficher()
{
	const int nbTirets = 25;

	for (int i = 0; i < DIMENSION_MATRICE; i++)
	{
		if (i % DIMENSION_QUADRANT == 0)
			cout << string(nbTirets, '-') << endl;
		for (int j = 0; j < DIMENSION_MATRICE; j++)
		{
			if (j % DIMENSION_QUADRANT == 0)
				cout << "| ";
			out_ << matrice_[i][j] << ' ';
		}
		out_ << '|' << endl;
	}
	cout << string(nbTirets, '-') << endl;
}



bool Sudoku::CommencerBacktracking(Matrice<vector<int>> Possibilit�es)
{
	int xPossible = -1;
	int yPossible = -1;
	int dimensionVecteur = DIMENSION_MATRICE + 1;

	for (int i = 0; i < DIMENSION_MATRICE; i++)
	{
		for (int j = 0; j < DIMENSION_MATRICE; j++)
		{
			if (matrice_[i][j] == 0)
			{
				if (matricePossibilit�s_[i][j].size() < dimensionVecteur && matricePossibilit�s_[i][j].size() != 0)
				{
					xPossible = i;
					yPossible = j;
					dimensionVecteur = matricePossibilit�s_[i][j].size();
				}
			}
		}
	}

	if (dimensionVecteur != DIMENSION_MATRICE + 1)
	{
		for (vector<int>::iterator it = matricePossibilit�s_[xPossible][yPossible].begin(); it != matricePossibilit�s_[xPossible][yPossible].end(); it++)
		{
			matrice_[xPossible][yPossible] = *it;

			if (Solutionner())
				return true;

			matricePossibilit�s_ = Possibilit�es;
		}
		matrice_[xPossible][yPossible] = 0;
	}
	return false;
}

bool Sudoku::Solutionner()
{
	Matrice<vector<int>> tampon;
	EnleverPossibilit�s();
	tampon = matricePossibilit�s_;
	bool matriceModifiee = false;

	for (int i = 0; i < DIMENSION_MATRICE && !matriceModifiee; i++)
	{
		for (int j = 0; j < DIMENSION_MATRICE && !matriceModifiee; j++)
		{
			if (matrice_[i][j] == 0)
			{
				if (matricePossibilit�s_[i][j].size() == 1)
				{
					EnleverPossibilit�s();
					if (matricePossibilit�s_[i][j].size() == 1)
					{
						matrice_[i][j] = matricePossibilit�s_[i][j][0];
						matriceModifiee = true;
						if (Solutionner())
							return true;
						matrice_[i][j] = 0;
						matricePossibilit�s_ = tampon;
					}
				}
			}
		}
	}

	if (MatriceEstPleine())
		return true;
	else if (!matriceModifiee)
	{
		if (CommencerBacktracking(tampon))
			return true;
	}
	return false;
}

void Sudoku::EnleverPossibilit�s()
{

	for (int i = 0; i < DIMENSION_MATRICE; i++)
	{
		for (int j = 0; j < DIMENSION_MATRICE; j++)
		{
			for (vector<int>::iterator it = matricePossibilit�s_[i][j].begin(); it < matricePossibilit�s_[i][j].end(); it++)
			{
				if (it != matricePossibilit�s_[i][j].end())
				{
					if (EstDansLaLigne(*it, i) || EstDansLaColonne(*it, j)
						|| EstDansQuadrant(*it, i, j))
					{
						matricePossibilit�s_[i][j].erase(it);
                  it--;
					}
				}
			}
		}
	}
}


bool Sudoku::EstDansLaLigne(int nombre, int x)
{
	for (int i = 0; i < DIMENSION_MATRICE; i++)
	{
		if (matrice_[x][i] == nombre)
			return true;
	}

	return false;
}

bool Sudoku::EstDansLaColonne(int nombre, int y)
{
	for (int i = 0; i < DIMENSION_MATRICE; i++)
	{
		if (matrice_[i][y] == nombre)
			return true;
	}

	return false;
}

bool Sudoku::EstDansQuadrant(int nombre, int x, int y)
{
	for (int i = 0; i < DIMENSION_QUADRANT; i++)
	{
		for (int j = 0; j < DIMENSION_QUADRANT; j++)
		{
			if (matrice_[x / DIMENSION_QUADRANT * DIMENSION_QUADRANT + i]
				[y / DIMENSION_QUADRANT * DIMENSION_QUADRANT + j] == nombre)
				return true;
		}
	}

	return false;
}

bool Sudoku::MatriceEstPleine()
{
	for (int i = 0; i < DIMENSION_MATRICE; i++)
	{
		for (int j = 0; j < DIMENSION_MATRICE; j++)
		{
			if (matrice_[i][j] == 0)
				return false;
		}
	}
	return true;
}


