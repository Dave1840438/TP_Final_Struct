#include "Sudoku.h"
#include "Matrice.h"
#include <iostream>
#include <string>
using namespace std;

const int DIMENSION_MATRICE = 9;

Sudoku::Sudoku(istream fichierDonnees, ostream out)
{
   matrice_ = Matrice<int>(DIMENSION_MATRICE, DIMENSION_MATRICE);
   string buffer;

   for (int i = 0; i < DIMENSION_MATRICE; i++)
   {
      getline(fichierDonnees, buffer);
      for (int j = 0; j < 9; j++)
      {
         try
         {
            if (fichierDonnees[j] == '*')
         }
         catch (...)
         {
            out << "Erreur de lecture";
         }
            
      }
   }
}
