class Knight : public Box {
  string name;
  int color;
  string piece;

public:
  virtual int getColor() = 0;    //{ return color; }
  virtual string getName() = 0;  //{ return name; }
  virtual string getPiece() = 0; //{ return piece; }
  void possibleAvailableMoves(int row, int col) {
    if (upleft(row, col) == 1) {
      available_moves.push_back(numberTostring(row - 2, col - 1));
      if (isEnemy(row, col, row - 2, col - 1))
        available_moves.push_back("*");
    }
    if (upright(row, col) == 1) {
      available_moves.push_back(numberTostring(row - 2, col + 1));
      if (isEnemy(row, col, row - 2, col + 1) == 1)
        available_moves.push_back("*");
    }
    if (downleft(row, col) == 1) {
      available_moves.push_back(numberTostring(row + 2, col - 1));
      if (isEnemy(row, col, (row + 2), (col - 1)) == 1)
        available_moves.push_back("*");
    }
    if (downright(row, col) == 1) {
      available_moves.push_back(numberTostring(row + 2, col + 1));
      if (isEnemy(row, col, row + 2, col + 1) == 1)
        available_moves.push_back("*");
    }
    if (leftdown(row, col) == 1) {
      available_moves.push_back(numberTostring(row + 1, col - 2));
      if (isEnemy(row, col, row + 1, col - 2) == 1)
        available_moves.push_back("*");
    }
    if (leftup(row, col) == 1) {
      available_moves.push_back(numberTostring(row - 1, col - 2));
      if (isEnemy(row, col, row - 1, col - 2) == 1)
        available_moves.push_back("*");
    }
    if (rightdown(row, col) == 1) {
      available_moves.push_back(numberTostring(row + 1, col + 2));
      if (isEnemy(row, col, row + 1, col + 2) == 1)
        available_moves.push_back("*");
    }
    if (rightup(row, col) == 1) {
      available_moves.push_back(numberTostring(row - 1, col + 2));
      if (isEnemy(row, col, row - 1, col + 2) == 1)
        available_moves.push_back("*");
    }
  }
  int upleft(int row, int col) {
    if ((row - 2) < 0 || (col - 1) < 0)
      return 0;
    int indication = isEnemy(row, col, row - 2, col - 1);
    if (indication == 2)
      return 0;
    return 1;
  }
  int upright(int row, int col) {
    if ((row - 2) < 0 || (col + 1) > 7)
      return 0;
    int indication = isEnemy(row, col, row - 2, col + 1);
    if (indication == 2)
      return 0;
    return 1;
  }
  int downleft(int row, int col) {
    if ((row + 2) > 7 || (col - 1) < 0)
      return 0;

    int indication = isEnemy(row, col, (row + 2), (col - 1));
    if (indication == 2)
      return 0;
    return 1;
  }
  int downright(int row, int col) {
    if ((row + 2) > 7 || (col + 1) > 7)
      return 0;
    int indication = isEnemy(row, col, row + 2, col + 1);
    if (indication == 2)
      return 0;
    return 1;
  }
  int leftdown(int row, int col) {
    if ((row + 1) > 7 || (col - 2) < 0)
      return 0;
    int indication = isEnemy(row, col, row + 1, col - 2);
    if (indication == 2)
      return 0;
    return 1;
  }
  int leftup(int row, int col) {
    if ((row - 1) < 0 || (col - 2) < 0)
      return 0;
    int indication = isEnemy(row, col, row - 1, col - 2);
    if (indication == 2)
      return 0;
    return 1;
  }
  int rightdown(int row, int col) {
    if ((row + 1) > 7 || (col + 2) > 7)
      return 0;
    int indication = isEnemy(row, col, row + 1, col + 2);
    if (indication == 2)
      return 0;
    return 1;
  }
  int rightup(int row, int col) {
    if ((row - 1) < 0 || (col + 2) > 7)
      return 0;
    int indication = isEnemy(row, col, row - 1, col + 2);
    if (indication == 2)
      return 0;
    return 1;
  }
};
class WhiteKnight : public Knight {
  string name = "WHITE_KNIGHT";
  int color = 1;
  string piece = "W_N";

public:
  int getColor() { return color; }
  string getName() { return name; }
  string getPiece() { return piece; }
};
class BlackKnight : public WhiteKnight {
  string name = "BLACK_KNIGHT";
  int color = 0;
  string piece = "B_N";

public:
  int getColor() { return color; }
  string getName() { return name; }
  string getPiece() { return piece; }
};