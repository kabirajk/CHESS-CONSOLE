// #include "COINS.h"
class king : public Box {
  string name;
  int color; // if white 1
  string piece;

public:
  virtual int getColor() = 0;    //{ return color; }
  virtual string getName() = 0;  //{ return name; }
  virtual string getPiece() = 0; // { return piece; }
  void possibleAvailableMoves(int row, int col) {
    if (top(row, col) == 1 && isEnemy(row, col, row - 1, col) != 2) {
      available_moves.push_back(numberTostring(row - 1, col));
      if (isEnemy(row, col, row - 1, col) == 1)
        available_moves.push_back("*");
    }
    if (bottom(row, col) == 1 && isEnemy(row, col, row + 1, col) != 2) {
      available_moves.push_back(numberTostring(row + 1, col));
      if (isEnemy(row, col, row + 1, col) == 1)
        available_moves.push_back("*");
    }

    if (left(row, col) == 1 && isEnemy(row, col, row, col - 1) != 2) {
      available_moves.push_back(numberTostring(row, col - 1));
      if (isEnemy(row, col, row, col - 1) == 1)
        available_moves.push_back("*");
    }

    if (right(row, col) == 1 && isEnemy(row, col, row, col + 1) != 2) {
      available_moves.push_back(numberTostring(row, col + 1));
      if (isEnemy(row, col, row, col + 1) == 1)
        available_moves.push_back("*");
    }

    if (topright(row, col) == 1 && isEnemy(row, col, row - 1, col + 1) != 2) {
      available_moves.push_back(numberTostring(row - 1, col + 1));
      if (isEnemy(row, col, row - 1, col + 1) == 1)
        available_moves.push_back("*");
    }

    if (topleft(row, col) == 1 && isEnemy(row, col, row - 1, col - 1) != 2) {
      available_moves.push_back(numberTostring(row - 1, col - 1));
      if (isEnemy(row, col, row - 1, col - 1) == 1)
        available_moves.push_back("*");
    }

    if (bottomright(row, col) == 1 &&
        isEnemy(row, col, row + 1, col + 1) != 2) {
      available_moves.push_back(numberTostring(row + 1, col + 1));
      if (isEnemy(row, col, row + 1, col + 1) == 1)
        available_moves.push_back("*");
    }

    if (bottomleft(row, col) == 1 && isEnemy(row, col, row + 1, col - 1) != 2) {
      available_moves.push_back(numberTostring(row + 1, col - 1));
      if (isEnemy(row, col, row + 1, col - 1) == 1)
        available_moves.push_back("*");
    }
  }
  int top(int r, int c) //-- decrease
  {
    if (((r - 1) >= 0) && (c >= 0 && c <= 7))
      return 1;
    else
      return 0;
  }
  int bottom(int r, int c) {
    if (((r + 1) <= 7) && (c >= 0 && c <= 7))
      return 1;
    else
      return 0;
  }
  int left(int r, int c) {
    if ((c - 1) >= 0 && (r >= 0))
      return 1;
    else
      return 0;
  }
  int right(int r, int c) {
    if ((c + 1) <= 7 && r <= 7)
      return 1;
    else
      return 0;
  }
  int topright(int r, int c) {
    if ((r - 1) >= 0 && (c + 1) <= 7)
      return 1;
    else
      return 0;
  }
  int topleft(int r, int c) {
    if ((r - 1) >= 0 && (c - 1 >= 0))
      return 1;
    else
      return 0;
  }
  int bottomright(int r, int c) {
    if ((r + 1) <= 7 && (c + 1) <= 7)
      return 1;
    else
      return 0;
  }
  int bottomleft(int r, int c) {
    if ((r + 1) <= 7 && (c - 1) >= 0)
      return 1;
    else
      return 0;
  }
};

class WhiteKing : public king {
  string name = "WHITE_KING";
  int color = 1;
  string piece = "W_K";

public:
  int getColor() { return color; }
  string getName() { return name; }
  string getPiece() { return piece; }
};
class BlackKing : public king {
  string name = "BLACK_KING";
  int color = 0;
  string piece = "B_K";

public:
  int getColor() { return color; }
  string getName() { return name; }
  string getPiece() { return piece; }
};
