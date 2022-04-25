#include "BISHOP.h"
#include "ROOK.h"

class Queen : public Rook, public Bishop {
  string name = "QUEEN";
  int color = 'Q';
  string piece = "Q";

public:
  virtual int getColor() =0;//{ return color; }
  virtual string getName()=0;// { return name; }
  virtual string getPiece()=0;// { return piece; }
  void possibleAvailableMoves(int row, int col) {
    horizontal(row, col);
    vertical(row, col);
    rightdiag(row, col);
    leftdiag(row, col);
  }
};
class WhiteQueen : public Queen {
  string name = "WHITE_QUEEN";
  int color = 1;
  string piece = "W_Q";

public:
  int getColor() { return color; }
  string getName() { return name; }
  string getPiece() { return piece; }
};
class BlackQueen : public Queen
{
  string name = "BLACK_QUEEN";
  int color = 0;
  string piece = "B_Q";

public:
  int getColor() { return color; }
  string getName() { return name; }
  string getPiece() { return piece; }
};