#include "stdafx.h"
#include "SpriteCon.h"


CSpriteCon::CSpriteCon(void) {
	counter = 0;
	list = NULL;
	hitlist = NULL;
	poslist = NULL;
	alphalist = NULL;
	zlist = NULL;
	// TODO: Standardwert festlegen
	//z=
	//position=
	//alpha=

}

CSpriteCon::CSpriteCon(CPoint &new_position, int new_z, float new_alpha) {
	counter = 0;
	list = NULL;
	hitlist = NULL;
	poslist = NULL;
	alphalist = NULL;
	zlist = NULL;
	// TODO: Standardwert festlegen
	z = new_z;
	position = new_position;
	alpha = new_alpha;
}

CSpriteCon::CSpriteCon(int x, int y, int new_z, float new_alpha) {
	counter = 0;
	list = NULL;
	hitlist = NULL;
	poslist = NULL;
	alphalist = NULL;
	zlist = NULL;
	// TODO: Standardwert festlegen
	z = new_z;
	position.x = x;
	position.y = y;
	alpha = new_alpha;
}

CSpriteCon::~CSpriteCon(void){
	delete[] list;
	delete[] hitlist;
	delete[] zlist;
	delete[] poslist;
	delete[] alphalist;
}

bool CSpriteCon::Add(char *bmp_datei, CSize &size, bool hit, CPoint &position, int z, float alpha, bool drag) {
	int i;
	CSprite neu;
	if (!neu.Load(bmp_datei, size)) {
		AfxMessageBox(L"Datei konnte nicht geladen werden");
	}
	neu.SetPosition(position.x, position.y);
	neu.SetZ(z);
	neu.SetAlpha(alpha);

	CSprite *new_list = new CSprite[counter + 1];
	for (i = 0; i < counter; i++) {
		new_list[i] = list[i];
	}
	list = new_list;
	list[counter] = neu;
	bool *new_hitlist = new bool[counter + 1];
	for (i = 0; i < counter; i++) {
		new_hitlist[i] = hitlist[i];
	}
	hitlist = new_hitlist;
	hitlist[counter] = hit;
	CPoint *new_poslist = new CPoint[counter + 1];
	for (i = 0; i < counter; i++) {
		new_poslist[i] = poslist[i];
	}
	poslist = new_poslist;
	poslist[counter] = position;
	float *new_alphalist = new float[counter + 1];
	for (i = 0; i < counter; i++) {
		new_alphalist[i] = alphalist[i];
	}
	alphalist = new_alphalist;
	alphalist[counter] = alpha;
	int *new_zlist = new int[counter + 1];
	for (i = 0; i < counter; i++) {
		new_zlist[i] = zlist[i];
	}
	zlist = new_zlist;
	zlist[counter] = z;
	bool *new_draglist = new bool[counter + 1];
	for (i = 0; i < counter; i++) {
		new_draglist[i] = draglist[i];
	}
	draglist = new_draglist;
	draglist[counter] = drag;

	counter++;
}
bool CSpriteCon::Add(char *bmp_datei, CSize &size, bool hit, int x, int y, int z, float alpha, bool drag) {
	int i;
	CSprite neu;
	CPoint position(x, y);
	if (!neu.Load(bmp_datei, size)) {
		AfxMessageBox(L"Datei konnte nicht geladen werden");
	}
	neu.SetPosition(x, y);
	neu.SetZ(z);
	neu.SetAlpha(alpha);

	CSprite *new_list = new CSprite[counter + 1];
	for (i = 0; i < counter; i++) {
		new_list[i] = list[i];
	}
	list = new_list;
	list[counter] = neu;
	bool *new_hitlist = new bool[counter + 1];
	for (i = 0; i < counter; i++) {
		new_hitlist[i] = hitlist[i];
	}
	hitlist = new_hitlist;
	hitlist[counter] = hit;
	CPoint *new_poslist = new CPoint[counter + 1];
	for (i = 0; i < counter; i++) {
		new_poslist[i] = poslist[i];
	}
	poslist = new_poslist;
	poslist[counter] = position;
	float *new_alphalist = new float[counter + 1];
	for (i = 0; i < counter; i++) {
		new_alphalist[i] = alphalist[i];
	}
	alphalist = new_alphalist;
	alphalist[counter] = alpha;
	int *new_zlist = new int[counter + 1];
	for (i = 0; i < counter; i++) {
		new_zlist[i] = zlist[i];
	}
	zlist = new_zlist;
	zlist[counter] = z;
	bool *new_draglist = new bool[counter + 1];
	for (i = 0; i < counter; i++) {
		new_draglist[i] = draglist[i];
	}
	draglist = new_draglist;
	draglist[counter] = drag;

	counter++;
}
bool CSpriteCon::Add(CSprite &new_sprite, bool hit, CPoint &position, int z, float alpha, bool drag) {
	int i;

	CSprite *new_list = new CSprite[counter + 1];
	for (i = 0; i < counter; i++) {
		new_list[i] = list[i];
	}
	list = new_list;
	list[counter] = new_sprite;
	bool *new_hitlist = new bool[counter + 1];
	for (i = 0; i < counter; i++) {
		new_hitlist[i] = hitlist[i];
	}
	hitlist = new_hitlist;
	hitlist[counter] = hit;
	CPoint *new_poslist = new CPoint[counter + 1];
	for (i = 0; i < counter; i++) {
		new_poslist[i] = poslist[i];
	}
	poslist = new_poslist;
	poslist[counter] = position;
	float *new_alphalist = new float[counter + 1];
	for (i = 0; i < counter; i++) {
		new_alphalist[i] = alphalist[i];
	}
	alphalist = new_alphalist;
	alphalist[counter] = alpha;
	int *new_zlist = new int[counter + 1];
	for (i = 0; i < counter; i++) {
		new_zlist[i] = zlist[i];
	}
	zlist = new_zlist;
	zlist[counter] = z;
	bool *new_draglist = new bool[counter + 1];
	for (i = 0; i < counter; i++) {
		new_draglist[i] = draglist[i];
	}
	draglist = new_draglist;
	draglist[counter] = drag;

	counter++;
}
bool CSpriteCon::Add(CSprite &new_sprite, bool hit, int x, int y, int z, float alpha, bool drag) {
	int i;
	CPoint position(x, y);

	CSprite *new_list = new CSprite[counter + 1];
	for (i = 0; i < counter; i++) {
		new_list[i] = list[i];
	}
	list = new_list;
	list[counter] = new_sprite;
	bool *new_hitlist = new bool[counter + 1];
	for (i = 0; i < counter; i++) {
		new_hitlist[i] = hitlist[i];
	}
	hitlist = new_hitlist;
	hitlist[counter] = hit;
	CPoint *new_poslist = new CPoint[counter + 1];
	for (i = 0; i < counter; i++) {
		new_poslist[i] = poslist[i];
	}
	poslist = new_poslist;
	poslist[counter] = position;
	float *new_alphalist = new float[counter + 1];
	for (i = 0; i < counter; i++) {
		new_alphalist[i] = alphalist[i];
	}
	alphalist = new_alphalist;
	alphalist[counter] = alpha;
	int *new_zlist = new int[counter + 1];
	for (i = 0; i < counter; i++) {
		new_zlist[i] = zlist[i];
	}
	zlist = new_zlist;
	zlist[counter] = z;
	bool *new_draglist = new bool[counter + 1];
	for (i = 0; i < counter; i++) {
		new_draglist[i] = draglist[i];
	}
	draglist = new_draglist;
	draglist[counter] = drag;

	counter++;
}

int CSpriteCon::GetZ(void){
	return z;
}
void CSpriteCon::SetZ(int new_z){
	z = new_z;
}

CPoint& CSpriteCon::GetPos(void){
	return position;
}
void CSpriteCon::SetPosition(CPoint &new_position){
	position = new_position;
	for (int i = 0; i < counter; i++) {
		list[i].SetPosition((position.x + poslist[i].x), (position.y + poslist[i].y));
	}
}
void CSpriteCon::SetPosition(int x, int y){
	position.x = x;
	position.y = y;
	for (int i = 0; i < counter; i++) {
		list[i].SetPosition((position.x + poslist[i].x), (position.y + poslist[i].y));
	}
}

int CSpriteCon::GetXPos(void){
	return position.x;
}
void CSpriteCon::SetXPos(int x){
	position.x = x;
	for (int i = 0; i < counter; i++) {
		list[i].SetPosition((position.x + poslist[i].x), (position.y + poslist[i].y));
	}
}

int CSpriteCon::GetYPos(void){
	return position.y;
}
void CSpriteCon::SetYPos(int y){
	position.y = y;
	for (int i = 0; i < counter; i++) {
		list[i].SetPosition((position.x + poslist[i].x), (position.y + poslist[i].y));
	}
}

int CSpriteCon::GetXW(void){
	if (counter > 0) {
		int mini = list[0].GetXPos(), maxi = (list[0].GetXPos() + list[0].GetXW());
		for (int i = 1; i < counter; i++) {
			min(mini, list[i].GetXPos());
			max(maxi, list[i].GetXPos() + list[i].GetXW());
		}
		return (maxi - mini);
	}
	else {
		return 0;
	}
}
int CSpriteCon::GetYW(void){
	if (counter > 0) {
		int mini = list[0].GetYPos(), maxi = (list[0].GetYPos() + list[0].GetYW());
		for (int i = 1; i < counter; i++) {
			mini = min(mini, list[i].GetYPos());
			maxi = max(maxi, list[i].GetYPos() + list[i].GetYW());
		}
		return (maxi - mini);
	}
	else {
		return 0;
	}
}

float CSpriteCon::GetAlpha(void){
	return alpha;
}
void CSpriteCon::SetAlpha(float new_alpha){
	alpha = new_alpha;
	for (int i = 0; i < counter; i++) {
		list[i].SetAlpha((alpha + alphalist[i]));
	}
}

CSprite* CSpriteCon::HitTest(CPoint &point){
	for (int i = 0; i < counter; i++) {
		if ((hitlist[i]) && (list[i].HitTest(point))) return &list[i];
	}
	return NULL;
}

void CSpriteCon::Insert(CSpriteList &spritelist){
	for (int i = 0; i < counter; i++) {
		spritelist.Insert(&list[i]);
	}
}

CSpriteCon& CSpriteCon::operator=(CSpriteCon& other){
	if (this != &other) {
		int i;
		counter = other.counter;
		alpha = other.alpha;
		z = other.z;
		position = other.position;

		delete[] list;
		list = new CSprite[counter];
		delete[] hitlist;
		hitlist = new bool[counter];
		delete[] poslist;
		poslist = new CPoint[counter];
		delete[] alphalist;
		alphalist = new float[counter];
		delete[] zlist;
		zlist = new int[counter];
		for (i = 0; i < counter; i++) {
			list[i] = other.list[i];
			hitlist[i] = other.hitlist[i];
			poslist[i] = other.poslist[i];
			alphalist[i] = other.alphalist[i];
			zlist[i] = other.zlist[i];
		}
	}
	return *this;
}
CSprite& CSpriteCon::operator[](int value){
	return list[value];
}