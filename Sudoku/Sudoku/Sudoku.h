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
   //Constantes statiques
   const static int DIMENSION_MATRICE;
   const static int DIMENSION_QUADRANT;

   //Membres privés
   Matrice<int> matrice_;
   Matrice <vector<int>> matricePossibilités_;
   ostream& out_;

   //La fonction dit si la matrice est pleine
   bool MatriceEstPleine();

   //Enlever les possibilité dans les vectors des cases
   //correspondantes
   void EnleverPossibilités();

   //La fonction dit si le chiffre et dans le quadrant
   bool EstDansQuadrant(int nombre, int x, int y);

   //La fonction dit si le chiffre et dans la colonne
   bool EstDansLaColonne(int nombre, int y);

   //La fonction dit si le chiffre et dans la ligne
   bool EstDansLaLigne(int nombre, int x);

   //Si on est sur de la position d'aucun chiffre,
   //on commence l'essais-erreur
   bool CommencerBacktracking(Matrice<vector<int>> Possibilitées);

public:
   //Constructeur paramétrique
   Sudoku(ifstream& fichierDonnees, ostream& out);

   //Affiche la grille avec la quadrants
   void Afficher();

   //Rempli la grille avec les bons chiffres
   bool Solutionner();
};