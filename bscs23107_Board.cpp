#include "Board.h"
#include "Pawn.h"
#include "Rook.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include <iostream>
#include <iomanip>

using namespace std;



#define WHITE 15
#define BLACK 0
#define GREEN 2
#define RED  4
#define YELLOW 6

void SetClr(unsigned char tcl, unsigned char bcl)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (tcl + (bcl * 16)));
}


void gotoRowCol(unsigned char rpos, unsigned char cpos)
{
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = cpos;
    scrn.Y = rpos;
    SetConsoleCursorPosition(hOuput, scrn);
}


void getRowColbyLeftClick(int& rpos, int& cpos)
{
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    DWORD Events;
    INPUT_RECORD InputRecord;
    SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
    do
    {
        ReadConsoleInput(hInput, &InputRecord, 1, &Events);
        if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
        {
            cpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
            rpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
            break;
        }
    } while (true);
}



Board::Board()
{
	dimension = 8;
	initialise();
    turn = 0;

    char tempBoard[8][8] = {
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
    };


    for (int i = 0; i < 8; i++)
    {

        for (int c = 0; c < 8; c++)
        {
            chessBoard[i][c] = tempBoard[i][c];
        }
    }


}


Board::~Board() {

}



void Board::Play() {


    int sr = 1, sc = 1, er = 1, ec = 1;
    int nc = 1, c = 1;
    /*PNames[2] = { "White" ,"Black" };*/
   

    while (sr != 1000 && sc != 10000)
    {
        colorboard();
        cout << "\n\n\n\n\n \t\t\t\t";
        printBoard();

        cout << "\n\n\n\n ";

        if (turn % 2 == 0)
            cout << " ---- WHITE'S TURN ---- ";
        else
            cout << " ---- BLACK'S TURN ---- ";

        
     

        //(first turn white ke hai)
        do {
            do {

                do {

                    getRowColbyLeftClick(sr, sc);
                    sc = (sc - 31) / 3;

                    if (!validselectedrowcol(sr, sc, BD, turn))
                        cerr << endl << "invalid selected position ";

                } while (!validselectedrowcol(sr, sc, BD, turn));

                
                system("cls");
                Highlight(BD,sr,sc,turn);

                getRowColbyLeftClick(er, ec);
                ec = (ec - 31) / 3;

                system("cls");
                UNHighlight();



                if (!validgotorowcol(er, ec, BD, turn))
                    cerr << endl << " invalid goto position ";

            } while (!validgotorowcol(er, ec, BD, turn));

           if (!BD[sr][sc]->isLegal(BD, sr, sc, er, ec) || !BD[sr][sc]->pathClear(BD, sr, sc, er, ec))
               cout << " invalid piece move";
            
        } while (!BD[sr][sc]->isLegal(BD, sr, sc, er, ec) || !BD[sr][sc]->pathClear(BD, sr, sc, er, ec));

        move(sr, sc, er, ec);

        if (er == 0 || er == 7 /*&& (BD[er][ec]->getSymbol == 'p' || BD[er][ec]->getSymbol == 'P')*/) {
            BD[er][ec]->promote(BD, er, ec);


        }

        system("cls");
        turn++;
    }




}

void Board::initialise() {
    // Dynamically allocating 8 by 8 2d pointer array Board
    BD = new Piece **[dimension];

    for (int r = 0; r < dimension; r++) {
        BD[r] = new Piece * [dimension] {};

        for (int c = 0; c < dimension; c++) {
            if (r == 1) {
                BD[r][c] = new Pawn(Position{ r,c }, Black);
            }
            else if (r == 6) {
                BD[r][c] = new Pawn(Position{ r,c }, White);
            }
            else if (r == 0) {
                if (c == 0 || c == 7) {
                    BD[r][c] = new Rook(Position{ r,c }, Black);
                }
                else if (c == 1 || c == 6) {
                    BD[r][c] = new Knight(Position{ r,c }, Black);
                }
                else if (c == 2 || c == 5) {
                    BD[r][c] = new Bishop(Position{ r,c }, Black);
                }
                else if (c == 3) {
                    BD[r][c] = new Queen(Position{ r,c }, Black);
                }
                else if (c == 4) {
                    BD[r][c] = new King(Position{ r,c }, Black);
                }
            }
            else if (r == 7) {
                if (c == 0 || c == 7) {
                    BD[r][c] = new Rook(Position{ r,c }, White);
                }
                else if (c == 1 || c == 6) {
                    BD[r][c] = new Knight(Position{ r,c }, White);
                }
                else if (c == 2 || c == 5) {
                    BD[r][c] = new Bishop(Position{ r,c }, White);
                }
                else if (c == 3) {
                    BD[r][c] = new Queen(Position{ r,c }, White);
                }
                else if (c == 4) {
                    BD[r][c] = new King(Position{ r,c }, White);
                }
            }
            else
            {
                BD[r][c] = nullptr;
            }
        }
    }
}




void Board::colorboard() {

 
      
        for (int i = 0; i < 8; i++)
        {
            for (int k = 0; k < 30; k++)
            {
                SetClr(WHITE, BLACK);
                cout << " ";
            }
            for (int j = 0; j < 8; j++)
            {
                if ((i + j) % 2 == 0)
                {
                    SetClr(BLACK, WHITE);
                    cout << " " << chessBoard[i][j] << " ";
                    SetClr(WHITE, BLACK);
                }
                else
                {
                    cout << " " << chessBoard[i][j] << " ";
                }
            }
            cout << endl;
        }

    

}






void Board::printBoard() {

    for (int r = 0; r < dimension; r++)
    {
      
        for (int c = 0; c < dimension; c++)
        {


            if (BD[r][c] == nullptr)
            {
                
                
                cout  << '-';
            }
            else
            {
                
                BD[r][c]->make();
                
            }
        }
        cout << endl;
    }
}






void Board::initPlayers(string _PNames) {

    for (int i = 0; i < 2; i++)
    {
        PNames[i] = _PNames[i * 5, 5];
    }

}



void Board::printMsg(int turn) {

    if (turn % 2 == 0)
        cout << PNames[0] << "turn" ; // black
    else
        cout << PNames[1] << "turn";  // white
}

bool Board::checkmate(int turn) {


	return false;
}


void Board::move(int Sr, int Sc, int Er, int Ec) {

    char temp = char(chessBoard[Sr][Sc]);
    /* swap(chessBoard[Sr][c], chessBoard[Er][nc]);*/
    chessBoard[Er][Ec] = chessBoard[Sr][Sc];
    chessBoard[Sr][Sc] = ' ';     // movement in chess board 


    /*delete BD[Er][nc];*/
    BD[Er][Ec] = BD[Sr][Sc];
    BD[Sr][Sc]->move(Er,Ec);
    BD[Sr][Sc] = nullptr;
    printBoard();

}


bool Board::validselectedrowcol(int Sr, int Sc, Piece***, int turn) {

    
    if (turn % 2 == 0)
    {
       
        if (BD[Sr][Sc] != nullptr && BD[Sr][Sc]->getcolor() == 1)/*|| BD[Sr][Sc]->getSymbol() == 'q' || BD[Sr][Sc]->getSymbol() == 'k' || BD[Sr][Sc]->getSymbol() == 'n' || BD[Sr][Sc]->getSymbol() == 'b' || BD[Sr][Sc]->getSymbol() == 'r'*/
        {
            return true;
        }
        else if (BD[Sr][Sc] == nullptr)
        {
            return false;
        }
        else
            return false;
    }
    else if (turn % 2 != 0)   // WHITE
    {
       
        if (BD[Sr][Sc] != nullptr && BD[Sr][Sc]->getcolor() == 0)/* || BD[Sr][Sc]->getSymbol() == 'Q' || BD[Sr][Sc]->getSymbol() == 'K' || BD[Sr][Sc]->getSymbol() == 'N' || BD[Sr][Sc]->getSymbol() == 'B' || BD[Sr][Sc]->getSymbol() == 'R')*/
        {
            return true;
        }
        else if (BD[Sr][Sc] == nullptr)
        {
            return false;
        }
        else
            return false;
    }

    return false;
}



bool Board::validgotorowcol(int Er, int Ec, Piece***, int turn) {
    

    if (turn % 2 == 0)  // white (first)
    {
       if (BD[Er][Ec] == nullptr || BD[Er][Ec]->getcolor() != 1 )
       {
            return true;
        }
       

    }
    else if (turn % 2 != 0)  //black ( second )
    {
        if (BD[Er][Ec] == nullptr || BD[Er][Ec]-> getcolor() != 0 )
        {
            return true;
        }
      
    }
   

    return false;

}

void Board::Highlightboard() {

    

    for (int i = 0; i < 8; i++)
    {
        for (int k = 0; k < 30; k++)
        {
            SetClr(WHITE, BLACK);
            cout << " ";
        }
        for (int j = 0; j < 8; j++)
        {
            if ((i + j) % 2 == 0)
            {
                SetClr(BLACK, WHITE);
                if (Highlighter[i][j] == true)
                {
                    SetClr(BLACK+1, WHITE+2);
                    cout << " " << chessBoard[i][j] << " ";
                    SetClr(WHITE, BLACK);

                }
                else {
                    cout << " " << chessBoard[i][j] << " ";
                    SetClr(WHITE, BLACK);
                }
            }
            else
            {
                if (Highlighter[i][j] == true)
                {
                    SetClr(BLACK + 1, WHITE + 2);
                    cout << " " << chessBoard[i][j] << " ";
                    SetClr(WHITE, BLACK);
                }
                else
                cout << " " << chessBoard[i][j] << " ";
                

            }
        }
        cout << endl;
    }


 
}

void Board::Highlight(Piece *** BD,int sr , int sc , int turn) {
   
   
  
    for (int r = 0; r < 8; r++)
    {
        for (int c = 0; c < 8; c++)
        {
            

            if (BD[sr][sc]->isLegal(BD, sr, sc, r, c) && validgotorowcol(r, c, BD, turn)&& BD[sr][sc]->pathClear(BD, sr, sc, r, c)) {

                Highlighter[r][c] = true;
            }
            else {
                Highlighter[r][c] = false;
            }

        }
    }

    Highlightboard();
}


void Board::UNHighlight() {


    for (int r = 0; r < 8; r++)
    {
        for (int c = 0; c < 8; c++)
        {
            Highlighter[r][c] = false;
            if (chessBoard[r][c] == 'x')
            {
                chessBoard[r][c] == ' ';
            }
        }
    }

    Highlightboard();
}

bool Board::iscastling(int sr, int sc, int er, int ec) {
    if (BD[sr][sc]->getSymbol() == 'K' && BD[er][ec]->getSymbol() == 'R' && sr == 7 && sc == 4 && er == 7 && ec == 6) {
		return true;
	}
    else if (BD[sr][sc]->getSymbol() == 'K' && BD[er][ec]->getSymbol() == 'R' && sr == 7 && sc == 4 && er == 7 && ec == 2) {
		return true;
	}
    else if (BD[sr][sc]->getSymbol() == 'k' && BD[er][ec]->getSymbol() == 'r' && sr == 0 && sc == 4 && er == 0 && ec == 6) {
		return true;
	}
    else if (BD[sr][sc]->getSymbol() == 'k' && BD[er][ec]->getSymbol() == 'r' && sr == 0 && sc == 4 && er == 0 && ec == 2) {
		return true;
	}
	return false;
}



//void Board::performcastling(int sr, int sc, int er, int ec) {
//
//    if (sr == 0 && sc == 4 && er == 0 && ec == 2) {
//		BD[0][0]->move(0, 3);
//		BD[0][3] = BD[0][0];
//		BD[0][0] = nullptr;
//		BD[0][2]->move(0, 3);
//		BD[0][3] = BD[0][2];
//		BD[0][2] = nullptr;
//	}
//    else if (sr == 0 && sc == 4 && er == 0 && ec == 6) {
//		BD[0][7]->move(0, 5);
//		BD[0][5] = BD[0][7];
//		BD[0][7] = nullptr;
//		BD[0][4]->move(0, 5);
//		BD[0][5] = BD[0][4];
//		BD[0][4] = nullptr;
//	}
//    else if (sr == 7 && sc == 4 && er == 7 && ec == 2) {
//		BD[7][0]->move(7, 3);
//		BD[7][3] = BD[7][0];
//		BD[7][0] = nullptr;
//		BD[7][2]->move(7, 3);
//		BD[7][3] = BD[7][2];
//		BD[7][2] = nullptr;
//	}
//    else if (sr == 7 && sc == 4 && er == 7 && ec == 6) {
//		BD[7][7]->move(7, 5);
//		BD[7][5] = BD[7][7];
//		BD[7][7] = nullptr;
//		BD[7][4]->move(7, 5);
//		BD[7][5] = BD[7][4];
//		BD[7][4] = nullptr;
//	}
//}