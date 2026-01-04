#pragma once
#include <iostream>
#include <iomanip>
#include "Board.h"
#include "Header.h"

using namespace std;

bool horizontalmove(int sr, int er);
bool verticalmove(int sc, int ec);
bool diagonalMove(int sr, int sc, int er, int ec);

class Board;

class Piece {


protected:

    char type;
    COLOR c;
    Position Pos;


public:

    Piece();
    Piece(COLOR& _c, Position _pos);
    ~Piece();


    void make();
    void clear();
    char getSymbol();
    COLOR& getcolor();

    virtual void move(int Er, int Ec);

    virtual bool isLegal(Piece*** BD,int sr, int sc, int er, int ec)=0;
    virtual bool pathClear(Piece*** BD, int sr, int sc, int er, int ec)=0;
    virtual void promote(Piece*** BD, int er, int ec)=0;


};




