#include "stdafx.h"
#include "Cell.h"

CCell::CCell() {
	life = false;
	animation = 2;
}

CCell::CCell(bool value) {
	life = value;
	animation = value;
}

CCell::~CCell() {

}
