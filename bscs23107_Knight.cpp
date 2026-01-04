#include "Knight.h"
#include <iostream>
using namespace std;


Knight::Knight(Position _p, COLOR _c):Piece(_c, _p) {
	if (_c == Black)
		type = 'H';
	else
		type = 'h';


}

Knight:: ~Knight() {};

void Knight::move(int Er, int Ec) {
	Pos.posx = Er;
	Pos.posy = Ec;
}

bool Knight::isLegal(Piece*** BD, int sr, int sc, int er, int ec) {


	int deltaRow = abs(er - sr);
	int deltaCol = abs(ec - sc);

	// Knight moves in an L shape: two squares in one direction and one square in a perpendicular direction.
	return ((deltaRow == 2 && deltaCol == 1) || (deltaRow == 1 && deltaCol == 2));
}

bool Knight::pathClear(Piece*** BD, int sr, int sc, int er, int ec) {
	if ((abs(er - sr) == 2 && abs(ec - sc) == 1) || (abs(er - sr) == 1 && abs(ec - sc) == 2)) {
		return true; // Knight moves in an L shape
	}
	return false;
}

void Knight::promote(Piece*** BD, int er, int ec) {

}
