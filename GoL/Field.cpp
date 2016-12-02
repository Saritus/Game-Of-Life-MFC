#include "stdafx.h"
#include "Field.h"

CField::CField() {
	hoehe = 30;
	breite = 30;
}

CField::CField(int x, int y) {
	breite = x;
	hoehe = y;
}

CField::~CField() {
	// delete[] field;
}

void CField::feld_anzeigen() {
	
}

bool CField::next_life() {
	int count;
	int x, y;

	// Animation
	// 0 - Tot -> Tot
	// 1 - Leben -> Leben
	// 2 - Tot -> Leben
	// 3 - Leben -> Tot

	//Mitte-Mitte
	for (y = 1; y < (hoehe - 1); y++) {
		for (x = 1; x < (breite - 1); x++) {
			count = (field[x - 1][y - 1].life) + (field[x - 1][y].life) + (field[x - 1][y + 1].life) + (field[x][y - 1].life) + (field[x][y + 1].life) + (field[x + 1][y - 1].life) + (field[x + 1][y].life) + (field[x + 1][y + 1].life);
			switch (count) {
			case 2:
				field[x][y].animation = field[x][y].life;
				break;
			case 3:
				if (field[x][y].life == false) {
					field[x][y].animation = 2;
				}
				else {
					field[x][y].animation = 1;
				}
				break;
			default:
				if (field[x][y].life == false) {
					field[x][y].animation = 0;
				}
				else {
					field[x][y].animation = 3;
				}
				break;
			}
		}
	}

	//Oben-Mitte
	y = 0;
	for (x = 1; x < (breite - 1); x++) {
		count = (field[x - 1][y + 1].life) + (field[x - 1][y].life) + (field[x][y + 1].life) + (field[x + 1][y + 1].life) + (field[x + 1][y].life);
		switch (count) {
		case 2:
			field[x][y].animation = field[x][y].life;
			break;
		case 3:
			if (field[x][y].life == false) {
				field[x][y].animation = 2;
			}
			else {
				field[x][y].animation = 1;
			}
			break;
		default:
			if (field[x][y].life == false) {
				field[x][y].animation = 0;
			}
			else {
				field[x][y].animation = 3;
			}
			break;
		}
	}

	//Unten-Mitte
	y = (hoehe - 1);
	for (x = 1; x < (breite - 1); x++) {
		count = (field[x - 1][y - 1].life) + (field[x - 1][y].life) + (field[x][y - 1].life) + (field[x + 1][y - 1].life) + (field[x + 1][y].life);
		switch (count) {
		case 2:
			field[x][y].animation = field[x][y].life;
			break;
		case 3:
			if (field[x][y].life == false) {
				field[x][y].animation = 2;
			}
			else {
				field[x][y].animation = 1;
			}
			break;
		default:
			if (field[x][y].life == false) {
				field[x][y].animation = 0;
			}
			else {
				field[x][y].animation = 3;
			}
			break;
		}
	}
		
	//Mitte-Links
	x = 0;
	for (y = 1; y < (hoehe - 1); y++) {
		count = (field[x][y - 1].life) + (field[x][y + 1].life) + (field[x + 1][y - 1].life) + (field[x + 1][y].life) + (field[x + 1][y + 1].life);
		switch (count) {
		case 2:
			field[x][y].animation = field[x][y].life;
			break;
		case 3:
			if (field[x][y].life == false) {
				field[x][y].animation = 2;
			}
			else {
				field[x][y].animation = 1;
			}
			break;
		default:
			if (field[x][y].life == false) {
				field[x][y].animation = 0;
			}
			else {
				field[x][y].animation = 3;
			}
			break;
		}
	}
	
	//Mitte-Rechts
	x = (breite - 1);
	for (y = 1; y < (hoehe - 1); y++) {
		count = (field[x][y - 1].life) + (field[x][y + 1].life) + (field[x - 1][y - 1].life) + (field[x - 1][y].life) + (field[x - 1][y + 1].life);
		switch (count) {
		case 2:
			field[x][y].animation = field[x][y].life;
			break;
		case 3:
			if (field[x][y].life == false) {
				field[x][y].animation = 2;
			}
			else {
				field[x][y].animation = 1;
			}
			break;
		default:
			if (field[x][y].life == false) {
				field[x][y].animation = 0;
			}
			else {
				field[x][y].animation = 3;
			}
			break;
		}
	}
	
	//Ecken
	y = 0; x = 0;
	count = (field[x][y + 1].life) + (field[x + 1][y].life) + (field[x + 1][y + 1].life);
	switch (count) {
	case 2:
		field[x][y].animation = field[x][y].life;
		break;
	case 3:
		if (field[x][y].life == false) {
			field[x][y].animation = 2;
		}
		else {
			field[x][y].animation = 1;
		}
		break;
	default:
		if (field[x][y].life == false) {
			field[x][y].animation = 0;
		}
		else {
			field[x][y].animation = 3;
		}
		break;
	}
	
	y = 0; x = (breite - 1);
	count = (field[x][y + 1].life) + (field[x - 1][y].life) + (field[x - 1][y + 1].life);
	switch (count) {
	case 2:
		field[x][y].animation = field[x][y].life;
		break;
	case 3:
		if (field[x][y].life == false) {
			field[x][y].animation = 2;
		}
		else {
			field[x][y].animation = 1;
		}
		break;
	default:
		if (field[x][y].life == false) {
			field[x][y].animation = 0;
		}
		else {
			field[x][y].animation = 3;
		}
		break;
	}

	y = (hoehe - 1); x = 0;
	count = (field[x][y - 1].life) + (field[x + 1][y].life) + (field[x + 1][y - 1].life);
	switch (count) {
	case 2:
		field[x][y].animation = field[x][y].life;
		break;
	case 3:
		if (field[x][y].life == false) {
			field[x][y].animation = 2;
		}
		else {
			field[x][y].animation = 1;
		}
		break;
	default:
		if (field[x][y].life == false) {
			field[x][y].animation = 0;
		}
		else {
			field[x][y].animation = 3;
		}
		break;
	}
			
	y = (hoehe - 1); x = (breite - 1);
	count = (field[x][y - 1].life) + (field[x - 1][y].life) + (field[x - 1][y - 1].life);
	switch (count) {
	case 2:
		field[x][y].animation = field[x][y].life;
		break;
	case 3:
		if (field[x][y].life == false) {
			field[x][y].animation = 2;
		}
		else {
			field[x][y].animation = 1;
		}
		break;
	default:
		if (field[x][y].life == false) {
			field[x][y].animation = 0;
		}
		else {
			field[x][y].animation = 3;
		}
		break;
	}

	for (y = 0; y < hoehe; y++) {
		for (x = 0; x < breite; x++) {
			switch (field[x][y].animation) {
			case 0:
				field[x][y].life = false;
				break;
			case 1:
				field[x][y].life = true;
				break;
			case 2:
				field[x][y].life = true;
				break;
			case 3:
				field[x][y].life = false;
				break;
			default:
				field[x][y].life = false;
				break;
			}
		}
	}

	return true;
}

void CField::feld_fuellen_random(int prozent) {
	srand(time(NULL));
	for (int y = 0; y < hoehe; y++) {
		for (int x = 0; x < breite; x++) {
			if ((rand() % 100) < prozent) {
				field[x][y].life = true;
				field[x][y].animation = 1;
			}
			else {
				field[x][y].life = false;
				field[x][y].animation = 0;
			}
		}
	}
}

void CField::zustand_einlesen(char* datei) {
	FILE *stream;
	char load;
	char trash;
	int i, j;
	if ((stream = fopen(datei, "r+t")) != 0) {
		for (i = 0; i < hoehe; i++) {
			for (j = 0; j < breite; j++) {
				//field[j][i].animation=field[j][i].life = fgetc(stream);
				fscanf(stream, "%c", &load);
				if (load == '0') {
					field[j][i].life = false;
					field[j][i].animation = 0;
				}
				else{
					field[j][i].life = true;
					field[j][i].animation = 1;
				}
			}
			trash = fgetc(stream);
			// fscanf(stream, "%d", &trash);
		}
		fclose(stream);
	}
	else AfxMessageBox(L"konnte File nicht laden");
}

void CField::zustand_speichern(char* datei) {
	FILE *stream;
	int i, j;

	if ((stream = fopen(datei, "w+t")) != 0) {
		for (i = 0; i < hoehe; i++) {
			for (j = 0; j < breite; j++) {
				fprintf(stream, "%d", field[j][i].life);
			}
			fprintf(stream, "\n");
		}
		fclose(stream);
	}
	else AfxMessageBox(L"konnte File nicht laden");
}