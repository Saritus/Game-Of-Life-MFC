#pragma once
#include "spritelib.h"
#include "XUnzip.h"


class CSlider {
public:
	CSlider();
	CSlider(int, int);
	~CSlider();
	void SetPosition(int, int);
	void SetZ(int);
	void SetAlpha(float);
	int SetCurrent(int);
	int GetCurrent();
	int GetTime();

	// void SetCurrent(int);
	// int GetCurrent();

	CSprite slider;
	CSprite line;
	CSprite number;
private:
	int mini;
	int maxi;
	int current;
};

