#include "BISHOP.h"
#include "ROOK.h"

class WhiteQueen : public virtual WhiteRook, public virtual WhiteBishop {
  string name = "WHITE_QUEEN";
  int color = 1;
  string piece = "W_Q";

public:
  virtual int getColor() { return color; }
  virtual string getName() { return name; }
  virtual string getPiece() { return piece; }
  void possibleAvailableMoves(int row, int col) {
    horizontal(row, col);
    vertical(row, col);
    rightdiag(row, col);
    leftdiag(row, col);
  }
};
class BlackQueen : public virtual WhiteQueen {
  string name = "BLACK_QUEEN";
  int color = 0;
  string piece = "B_Q";

public:
  int getColor() { return color; }
  string getName() { return name; }
  string getPiece() { return piece; }
};