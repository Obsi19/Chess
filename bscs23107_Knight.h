#pragma once
#include "Piece.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
using namespace std;



class Knight :
    public Piece
{

public:

    Knight(Position _p, COLOR _c);
    ~Knight();

    void move(int Er, int Ec)override;
    bool isLegal(Piece*** BD, int sr, int sc, int er, int ec)override;
    bool pathClear(Piece*** BD, int sr, int sc, int er, int ec) override;
    void promote(Piece*** BD, int er, int ec)override;


};

