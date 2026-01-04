#include "King.h"
#include <iostream>
using namespace std;


King::King(Position _p, COLOR _c) :Piece(_c, _p) {

	if (_c == Black)
		type = 'K';
	else
		type = 'k';
}

King:: ~King() {};

void King::move(int Er, int Ec) {
	Pos.posx = Er;
	Pos.posy = Ec;
}

bool King::isLegal(Piece*** BD, int sr, int sc, int er, int ec) {


	int deltaRow = abs(er - sr);
	int deltaCol = abs(ec - sc);

	// King can move one step in any direction
	return ((deltaRow <= 1) && (deltaCol <= 1));
}


bool King::pathClear(Piece*** BD, int sr, int sc, int er, int ec) {
	if (abs(er - sr) <= 1 && abs(ec - sc) <= 1) {
		return true; // King can move one step in any direction
	}
	return false;
}

void King::promote(Piece*** BD, int er, int ec) {


}
