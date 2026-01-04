#include "Rook.h"
#include <iostream>
using namespace std;


Rook::Rook(Position _p, COLOR _c) :Piece(_c, _p) {
	if (_c == Black)
		type = 'R';
	else
		type = 'r';


}

Rook:: ~Rook() {};

void Rook::move(int Er, int Ec) {
	Pos.posx = Er;
	Pos.posy = Ec;
}

bool Rook::isLegal(Piece*** BD, int sr, int sc, int er, int ec) {
	

	return (horizontalmove(sr, er) || verticalmove(sc,ec ));

}

bool Rook::pathClear(Piece*** BD, int sr, int sc, int er, int ec) {

    int deltaRow = (er > sr) ? 1 : (er < sr) ? -1 : 0;
    int deltaCol = (ec > sc) ? 1 : (ec < sc) ? -1 : 0;
    int r = sr + deltaRow;
    int c = sc + deltaCol;

    if (!horizontalmove(sr, er) && !verticalmove(sc, ec)) {
        return false; // Rook moves either horizontally or vertically
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


void Rook::promote(Piece*** BD, int er, int ec) {

}
