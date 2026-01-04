#include "Piece.h"
#include "iostream"
#include <iomanip>
#include <string>
#include <windows.h>
using namespace std;

bool horizontalmove(int sr, int er)
{
    if (er == sr)
    {
        return true;
    }
    return false;
}


bool verticalmove(int sc, int ec)
{
    if (ec == sc)
    {
        return true;
    }
    return false;
}



bool diagonalMove(int sr, int sc, int er, int ec)
{
    int dr = er - sr;
    int dc = ec - sc;
    return (abs(dr) == abs(dc));
}

Piece::Piece() {
   
}

Piece::Piece(COLOR& _c, Position _pos) {
   
    c = _c;
    Pos = _pos;
}

Piece::~Piece() {};

void Piece::make()
{
    gotoRowCol(Pos.posx, Pos.posy);
    cout << type;
}

void Piece::clear()
{
    gotoRowCol(Pos.posx, Pos.posy);
    cout << ' ';
}

char Piece::getSymbol() {

    return type;
}

void Piece::move(int Er, int Ec) {


}


COLOR& Piece::getcolor() {
    return c;
}

//bool Piece::isLegal(Piece*** BD,int sr, int sc, int er, int ec) {
//
//    return false; //default return statement else it will give me not return error
//}
//
//
//bool Piece::pathClear(Piece*** BD, int sr, int sc, int er, int ec) {
//
//    return true;
//}


//// setter and getter of the posiiton of the pieces and color as well;
//void Piece::SetPosition(Position Pos)
//{
//    this->Pos = Pos;
//}
//
//Position Piece::GetPosition() {
//    return Pos;
//}
//
//COLOR Piece::getcolor() {
//    return c;
//}


