#include "Matrice.h"
#include <iostream>

class Sudoku
{
   Matrice<int> matrice_;

public:
   Sudoku(istream fichierDonnees, ostream out);
   void Solutionner();
};