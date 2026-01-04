# Console Chess in C++

A full console-based chess game implemented in modern C++ using clean object‑oriented design. The project models all standard chess pieces, move rules, and board logic through inheritance, polymorphism, and encapsulation.

## Features

- **Complete chess board** with an 8×8 representation and turn management (`Board` class) [file:31].
- **All pieces implemented**: King, Queen, Rook, Bishop, Knight, Pawn – each as a separate derived class from `Piece`.
- **Polymorphic move logic**:
  - Pure virtual functions in `Piece` (`isLegal`, `pathClear`, `move`, `promote`) overridden in each derived piece class.
- **Encapsulation of board state**:
  - Board manages a `Piece*** BD` grid, highlight array, and turn state, hiding internal details from `main`.
- **Helper movement utilities**:
  - Shared functions for horizontal, vertical, and diagonal movement (`horizontalmove`, `verticalmove`, `diagonalMove`) to avoid code duplication.
- **Pawn promotion** with runtime choice (Q, R, B, N) using dynamic allocation and virtual `promote`.

## Object-Oriented Design

This project is a **beautiful** demonstration of core OOP principles in C++:

- **Abstraction**: `Piece` is an abstract base class exposing only the operations needed by the board (`move`, `isLegal`, `pathClear`, `promote`).
- **Encapsulation**: Each piece stores its own type, color, and position and exposes only controlled methods to manipulate them.
- **Inheritance**: `King`, `Queen`, `Rook`, `Bishop`, `Knight`, and `Pawn` inherit from `Piece` and specialize movement rules.
- **Polymorphism**: The board works with `Piece***` and calls virtual methods, letting the correct piece behavior execute at runtime without knowing the concrete type.

## Project Structure

- `bscs23107_bscs23107_CHESS_Project_PRO.cpp` – Entry point, creates a `Board` and calls `Play()`.
- `bscs23107_Board.h` – Board class declaration and game loop interface.
- `bscs23107_Header.h` – Basic types (`Position`, `COLOR`) and UI helpers.
- `bscs23107_Piece.h/.cpp` – Abstract base piece class and shared movement utilities.
- `bscs23107_Pawn/Queen/Rook/Bishop/Knight/King.(h|cpp)` – Individual piece implementations with overridden rules.
- `bscs23107_Player.h` – Player metadata (names, colors).

## How to Build and Run

1. Compile all `.cpp` files together, for example:

   ```bash
   g++ -std=c++17 bscs23107_*.cpp -o chess
Run the executable:

bash
./chess
Follow on‑screen prompts to select source and destination squares (row/column) for each move.

Current Limitations
Checkmate detection is not implemented yet:

The Board interface declares bool checkmate(int turn); but the full logic is not completed, so the game does not automatically stop on checkmate and relies on players to recognize game end conditions.

Future Improvements

Better GUI 

Full checkmate and stalemate detection

Implement checkmate(int turn) to:

Detect when a king is in check.

Explore all legal moves for the current player and determine if escape is possible.

Announce check, checkmate, and stalemate states clearly.

AI opponent with difficulty levels

Add an AI Player/strategy layer that:

Plays legal moves automatically against a human.

Supports difficulty modes (easy: random legal move; medium: basic material evaluation; hard: minimax with depth and pruning).

Keeps the same polymorphic Piece and Board structure so that only decision logic changes.

Additional rules and polish

Castling and en‑passant implementation (hooks already hinted via iscastling in Board) [file:31].

Undo/redo moves and move history.

GUI front‑end (SFML/Qt) reusing the existing OOP engine.
