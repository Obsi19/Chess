#include "Bishop.h"
#include <iostream>
using namespace std;


Bishop::Bishop(Position _p, COLOR _c) :Piece(_c, _p) {
	if (_c == Black)
		type = 'B';
	else
		type = 'b';


}

Bishop:: ~Bishop() {};

void Bishop::move(int Er, int Ec) {
	Pos.posx = Er;
	Pos.posy = Ec;
}


bool Bishop::isLegal(Piece*** BD,int sr, int sc, int er, int ec) {


	return diagonalMove(sr, sc, er, ec);

}

bool Bishop::pathClear(Piece*** BD, int sr, int sc, int er, int ec) {
    int deltaRow = (er > sr) ? 1 : (er < sr) ? -1 : 0;
    int deltaCol = (ec > sc) ? 1 : (ec < sc) ? -1 : 0;
    int r = sr + deltaRow;
    int c = sc + deltaCol;

    if (!diagonalMove(sr, sc, er, ec)) {
        return false; // Bishop moves diagonally
    }
    while (r != er || c != ec) {
        if (BD[r][c] != nullptr) {
            return false; // There's a piece in the path
        }
        r += deltaRow;
        c += deltaCol;
    }
    return true; // Path is clear
}

void Bishop::promote(Piece*** BD, int er, int ec) {

}
