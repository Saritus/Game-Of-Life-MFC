#pragma once
#include "Cell.h"
#include <time.h>

class CField {
public:
	CField();
	CField(int, int);
	~CField();
	void feld_anzeigen();
	void feld_fuellen_random(int);
	bool next_life();
	void zustand_speichern(char*);
	void zustand_einlesen(char*);

	CCell field[20][20];
	int hoehe;
	int breite;
};