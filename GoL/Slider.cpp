#include "stdafx.h"
#include "afxdialogex.h"
#include "Slider.h"

CSlider::CSlider() {

	mini = 1;
	maxi = 25;
	current = maxi;

	if (!slider.Load("schieberegler.bmp", CSize(18, 30))) {
		AfxMessageBox(L"konnte schieberegler.bmp nicht laden");
	}
	slider.SetZ(60);

	if (!line.Load("balken.bmp")) {
		AfxMessageBox(L"konnte balken.bmp nicht laden");
	}
	line.SetZ(60);

	if (!number.Load("numbers.bmp", CSize(27, 20))) {
		AfxMessageBox(L"konnte numbers.bmp nicht laden");
	}
	number.SetZ(60);
	number.SetSpriteNumber(0, 25);

}

CSlider::CSlider(int minimum, int maximum) {

	if (!slider.Load("schieberegler.bmp", CSize(18, 30))) {
		AfxMessageBox(L"konnte schieberegler.bmp nicht laden");
	}
	slider.SetZ(60);
	number.SetSpriteNumber(0, 0);

	if (!line.Load("balken.bmp")) {
		AfxMessageBox(L"konnte balken.bmp nicht laden");
	}
	line.SetZ(60);

	if (!number.Load("numbers.bmp", CSize(27, 20))) {
		AfxMessageBox(L"konnte numbers.bmp nicht laden");
	}
	number.SetZ(60);
	number.SetSpriteNumber(0, maximum);

	mini = minimum;
	maxi = maximum;
	current = maximum;
}

CSlider::~CSlider() {

}

void CSlider::SetPosition(int xpos, int ypos) {
	slider.SetPosition((current * 15 + xpos), ypos);
	line.SetPosition(xpos, (ypos + 12));
	number.SetPosition((xpos + 400), (ypos + 6));
}

void CSlider::SetZ(int z) {
	slider.SetZ(z + 1);
	line.SetZ(z);
	number.SetZ(z);
}

void CSlider::SetAlpha(float transp) {
	slider.SetAlpha(transp);
	line.SetAlpha(transp);
	number.SetAlpha(transp);
}

int CSlider::SetCurrent(int value) {
	current = max(min(value, maxi), mini);
	number.SetSpriteNumber(0, current);
	slider.SetPosition((current * 15 + line.GetPos().x), 501);
	return current;
}

int CSlider::GetCurrent() {
	return current;
}

int CSlider::GetTime() {
	if (current == 0) return 0;
	else return (1000 / current);
}