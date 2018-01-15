#include "Grille.hpp"
#include <iostream>

using namespace std;

Grille::Grille(){}

Grille::Grille(int nbCases):nbCases(nbCases){
	this->grille = new int *[nbCases];
	for(int i=0; i < this->nbCases; i++){
		this->grille[i] = new int(0);
	}
}

Grille::~Grille(){}

int Grille::getNbCases(){
	return this->nbCases;
}

void Grille::setNbCases(int n){
	this->nbCases = n;
	this->grille = new int *[nbCases];
	for(int i=0; i < this->nbCases; i++){
		this->grille[i] = new int(0);
	}
}

void Grille::setNbCases2Dim(int n){
	this->nbCases = n;
	this->grille = new int *[nbCases];
	for(int i=0; i < this->nbCases; i++){
		this->grille[i] = new int[nbCases];
	}
	for(int i=0;i<nbCases;i++){
		for(int j=0;j<nbCases;j++){
			grille[i][j] = 0;
		}
	}
}

int **Grille::getGrille(){
	return this->grille;
}

int *Grille::getCase(int c){
	return this->grille[c];
}
