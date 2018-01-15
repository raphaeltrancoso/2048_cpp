#ifndef GRILLE_HPP
#define GRILLE_HPP

class Grille{

private:
	int **grille;
	int nbCases;
public:
	Grille();
	Grille(int nbCases);
	virtual ~Grille();
	int getNbCases();
	void setNbCases(int n);
	void setNbCases2Dim(int n);
	int **getGrille();
	int *getCase(int c);
};

#endif
