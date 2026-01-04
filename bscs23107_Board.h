#pragma once
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <string>
#include "Piece.h"
#include "Header.h"

using namespace std;




class Piece;

class Board
{
private:
    Piece*** BD ;
    int dimension;
    string PNames[2];
    int turn;
    char chessBoard[8][8];
    bool Highlighter[8][8];

public:
    Board();
    ~Board();

  
    void colorboard();
    void Highlightboard();
    void printBoard();
	void initialise();
	void Play();
    void Highlight(Piece*** BD,int sr,int sc,int turn);
    void UNHighlight();

    void initPlayers(string _PNames);
    void printMsg(int turn);
    bool checkmate(int turn);
    //void performcastling(int sr, int sc, int er, int ec);
    bool iscastling(int sr, int sc, int er, int ec);

    bool validselectedrowcol(int sr, int sc, Piece***, int turn);
    bool validgotorowcol(int sr, int sc, Piece***, int turn);
  

    void move(int Sr, int Sc, int Er,int Ec );


};





