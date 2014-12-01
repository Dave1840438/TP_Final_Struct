//Sudoku.h
//David Sylvestre et Patrick Lemay
//1er Décembre 2014
//Ce fichier contient la déclaration de la classe Sudoku

#pragma once
#include "Matrice.h"
#include <iostream>

class Sudoku
{
   Matrice<int> matrice_;
   Matrice <vector<int>> matricePossibilités_;
   ostream& out_;
   bool MatriceEstPleine();
   void EnleverPossibilités();
   bool EstDansQuadrant(int nombre, int x, int y);
   bool EstDansLaColonne(int nombre, int y);
   bool EstDansLaLigne(int nombre, int x);

public:
   Sudoku(ifstream& fichierDonnees, ostream& out);
   void Afficher();
   bool Solutionner();

};