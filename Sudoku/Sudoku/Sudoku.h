//Sudoku.h
//David Sylvestre et Patrick Lemay
//1er Décembre 2014
//Ce fichier contient la déclaration de la classe Sudoku

#pragma once
#include "Matrice.h"
#include <iostream>
#include <vector>

class Sudoku
{
   //Membre privés
   Matrice<int> matrice_;
   Matrice <vector<int>> matricePossibilités_;
   ostream& out_;

   //Vérifie si la grille est pleine
   bool MatriceEstPleine();

   //Efface les chiffre impossible à placer du vecteur
   //de possibilité des cases correspondates
   void EnleverPossibilités();

   //Vérifie si le chiffre donné se trouve dans le quadrant
   bool EstDansQuadrant(int nombre, int x, int y);

   //Vérifie si le chiffre donné se trouve dans la colonne
   bool EstDansLaColonne(int nombre, int y);

   //Vérifie si le chiffre donné se trouve dans la ligne
   bool EstDansLaLigne(int nombre, int x);
<<<<<<< HEAD
   vector<int>* TrouverPlusPetitVector();
=======

   //Si on n'est certains d'aucun chiffre, on fait du essais erreur
>>>>>>> parent of 86e9f06... Revert "lol charlie"
   bool CommencerBacktracking(Matrice<vector<int>> Possibilitées);

public:
   //Constructeur paramétrique
   Sudoku(ifstream& fichierDonnees, ostream& out);

   //Affiche la grille avec une séparation pour les quadrants
   void Afficher();

   //Trouve les chiffres manquants de la grille
   bool Solutionner();

};