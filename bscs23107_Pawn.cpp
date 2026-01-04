#include "Pawn.h"
#include "Rook.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include <iostream>
using namespace std;


Pawn::Pawn(Position _p, COLOR _c):Piece(_c, _p) {

	if (_c == Black)
		type = 'P';
	else
		type = 'p';

}

Pawn::~Pawn() {


}

void Pawn::move(int Er, int Ec) {
	Pos.posx = Er;
	Pos.posy = Ec;
}


bool Pawn::isLegal(Piece*** BD, int sr, int sc, int er, int ec) {
  

        if (BD[er][ec] == nullptr) {
            if (BD[sr][sc]->getcolor() == White) {
                if (ec == sc && er == sr - 1) {
                    return true;
                }
                else if (sr == 6 && ec == sc && er == sr - 2 && BD[sr - 1][sc] == nullptr) {
                    return true;
                }
            }
            else if (BD[sr][sc]->getcolor() == Black) {
                if (ec == sc && er == sr + 1) {
                    return true;
                }
                else if (sr == 1 && ec == sc && er == sr + 2 && BD[sr + 1][sc] == nullptr) {
                    return true;
                }
            }
        }
        else if (std::abs(sc - ec) == 1) {
            if (BD[sr][sc]->getcolor() == White && er == sr - 1 && (BD[er][ec]->getcolor() == Black)) {
                return true;
            }
            else if (BD[sr][sc]->getcolor() == Black && er == sr + 1 && (BD[er][ec]->getcolor() == White)) {
                return true;
            }
        }

        return false;
    
}

bool Pawn::pathClear(Piece*** BD, int sr, int sc, int er, int ec) {
    int deltaRow = (c == White) ? 1 : -1;

    // Check if the pawn is moving one square forward
    if (sc == ec && BD[er][ec] == nullptr) {
        if (abs(er - sr) == 1) {
            return true;
        }
        // Check if the pawn is moving two squares forward on its first move
        else if (abs(er - sr) == 2 && ((sr == 6 && c == White) || (sr == 1 && c == Black))) {
            // Check if the intermediate square is empty
            return BD[(sr + er) / 2][ec] == nullptr && BD[er][ec] == nullptr;
        }
    }
    // Check if the pawn is capturing diagonally
    else if (abs(ec - sc) == 1 && abs(er - sr) == 1) {
        return BD[er][ec] != nullptr && BD[er][ec]->getcolor() != c;
    }
    return false;
}

void Pawn::promote(Piece*** BD, int er, int ec) {
    char choice;
    cout << "Your pawn reached the opposite end of the board. Choose a piece to promote to: (Q)ueen, (R)ook, (B)ishop, or (N)knight: ";
    cin >> choice;
    delete this; // Delete the pawn object after promotion
        switch (choice) {
        case 'Q':
            BD[er][ec] = new Queen(Position{ er,ec }, c);
            break;
        case 'R':
            BD[er][ec] = new Rook(Position{ er,ec }, c);
            break;
        case 'B':
            BD[er][ec] = new Bishop(Position{ er,ec }, c);
            break;
        case 'N':
            BD[er][ec] = new Knight(Position{ er,ec }, c);
            break;
        default:
            cout << "Invalid choice. Pawn promoted to Queen by default." << endl;
            BD[er][ec] = new Queen(Position{ er,ec }, c);
        }
    
}