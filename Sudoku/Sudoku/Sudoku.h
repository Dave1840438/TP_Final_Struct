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
   bool EstDansLaLigne(int nombre, int y);
   bool EstDansLaColonne(int nombre, int x);
   void RajouterPossibilités(int nombreEnleve, int x, int y);

public:
   Sudoku(ifstream& fichierDonnees, ostream& out);
   void Afficher();
   bool Solutionner();

};