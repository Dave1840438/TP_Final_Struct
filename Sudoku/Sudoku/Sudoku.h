//Sudoku.h
//David Sylvestre et Patrick Lemay
//1er D�cembre 2014
//Ce fichier contient la d�claration de la classe Sudoku

#pragma once
#include "Matrice.h"
#include <iostream>

class Sudoku
{
   Matrice<int> matrice_;
   Matrice <vector<int>> matricePossibilit�s_;
   ostream& out_;
   bool MatriceEstPleine();
   void EnleverPossibilit�s();
   bool EstDansQuadrant(int nombre, int x, int y);
   bool EstDansLaColonne(int nombre, int y);
   bool EstDansLaLigne(int nombre, int x);

public:
   Sudoku(ifstream& fichierDonnees, ostream& out);
   void Afficher();
   bool Solutionner();

};