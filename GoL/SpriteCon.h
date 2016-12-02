#pragma once
#include "spritelib.h"

class CSpriteCon
{
public:
	CSpriteCon(void);
	CSpriteCon(CPoint &new_position = CPoint(0, 0), int new_z = 0, float new_alpha = 0);
	CSpriteCon(int x = 0, int y = 0, int new_z = 0, float new_alpha = 0);
	~CSpriteCon(void);

	bool Add(char* bmp_datei, CSize &size, bool hit = false, CPoint &position = CPoint(0, 0), int z = 0, float alpha = 0.0f, bool drag = false);
	bool Add(char* bmp_datei, CSize &size, bool hit = false, int x = 0, int y = 0, int z = 0, float alpha = 0.0f, bool drag = false);
	bool Add(CSprite& new_sprite, bool hit = false, CPoint &position = CPoint(0, 0), int z = 0, float alpha = 0.0f, bool drag = false);
	bool Add(CSprite& new_sprite, bool hit = false, int x = 0, int y = 0, int z = 0, float alpha = 0.0f, bool drag = false);
	
	int GetZ(void);
	void SetZ(int);

	CPoint& GetPos(void);
	void SetPosition(CPoint&);
	void SetPosition(int, int);

	int GetXPos(void);
	void SetXPos(int);

	int GetYPos(void);
	void SetYPos(int);

	int GetXW(void);
	int GetYW(void);

	float GetAlpha(void);
	void SetAlpha(float);

	CSprite* HitTest(CPoint&);

	void Insert(CSpriteList&);

	CSpriteCon& operator=(CSpriteCon&);
	CSprite& operator[](int);

private:
	//Listenwerte
	CSprite *list;				// Liste der Sprites
	bool *hitlist;				// Liste der Mouse-interaktivität
	CPoint *poslist;			// Liste der relativen Positionen
	float *alphalist;			// Liste der relativen Alphawerte
	int *zlist;					// Liste der relativen z-Ebenen
	bool *draglist;				// Liste der MouseMove-interaktivität
	int counter;				// Anzahl der Elemente
	//Grundwerte
	int z;						// Grund-z-Wert
	CPoint position;			// Grund-Position
	float alpha;				// Grund-alpha-Wert

};

