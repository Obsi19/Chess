#include "Queen.h"
#include <iostream>
using namespace std;


Queen::Queen(Position _p, COLOR _c) :Piece(_c, _p) {
	if (_c == Black)
		type = 'Q';
	else
		type = 'q';


}

Queen:: ~Queen() {};

void Queen::move(int Er, int Ec) {
	Pos.posx = Er;
	Pos.posy = Ec;
}

bool Queen::isLegal(Piece*** BD, int sr, int sc, int er, int ec) {



	return (horizontalmove(sr, er) || verticalmove(sc, ec) || diagonalMove(sr, sc, er, ec));

}

bool Queen::pathClear(Piece*** BD, int sr, int sc, int er, int ec) {
    int deltaRow = (er > sr) ? 1 : (er < sr) ? -1 : 0;
    int deltaCol = (ec > sc) ? 1 : (ec < sc) ? -1 : 0;
    int r = sr + deltaRow;
    int c = sc + deltaCol;

    if (!horizontalmove(sr, er) && !verticalmove(sc, ec) && !diagonalMove(sr, sc, er, ec)) {
        return false; // Queen moves horizontally, vertically, or diagonally
    }
    if (horizontalmove(sr, er)) {
        deltaCol = (ec > sc) ? 1 : -1;
    }
    if (verticalmove(sc, ec)) {
        deltaRow = (er > sr) ? 1 : -1;
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

void Queen::promote(Piece*** BD, int er, int ec) {


}
