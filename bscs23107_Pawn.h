#pragma once
#include "Piece.h"
#include <iostream>
using namespace std;

class Piece;

class Pawn :
    public Piece
{
private:

    bool isfirst;

public:

    Pawn(Position _p , COLOR _c);

    ~Pawn();
    void move(int Er,int Ec) override;

    bool isLegal(Piece*** BD,int sr, int sc, int er, int ec)override;
    bool pathClear(Piece*** BD, int sr, int sc, int er, int ec)override;
    void promote(Piece*** BD, int er, int ec) override;

};

