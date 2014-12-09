//Sudoku.h
//David Sylvestre et Patrick Lemay
//1er D�cembre 2014
//Ce fichier contient la d�claration de la classe Sudoku

#pragma once
#include "Matrice.h"
#include <iostream>
#include <vector>

class Sudoku
{
   //Membre priv�s
   Matrice<int> matrice_;
   Matrice <vector<int>> matricePossibilit�s_;
   ostream& out_;

   //V�rifie si la grille est pleine
   bool MatriceEstPleine();

   //Efface les chiffre impossible � placer du vecteur
   //de possibilit� des cases correspondates
   void EnleverPossibilit�s();

   //V�rifie si le chiffre donn� se trouve dans le quadrant
   bool EstDansQuadrant(int nombre, int x, int y);

   //V�rifie si le chiffre donn� se trouve dans la colonne
   bool EstDansLaColonne(int nombre, int y);

   //V�rifie si le chiffre donn� se trouve dans la ligne
   bool EstDansLaLigne(int nombre, int x);
<<<<<<< HEAD
   vector<int>* TrouverPlusPetitVector();
=======

   //Si on n'est certains d'aucun chiffre, on fait du essais erreur
>>>>>>> parent of 86e9f06... Revert "lol charlie"
   bool CommencerBacktracking(Matrice<vector<int>> Possibilit�es);

public:
   //Constructeur param�trique
   Sudoku(ifstream& fichierDonnees, ostream& out);

   //Affiche la grille avec une s�paration pour les quadrants
   void Afficher();

   //Trouve les chiffres manquants de la grille
   bool Solutionner();

};