class WpawnPawn : public Box {
  string name = "WHITE_PAWN";
  int color = 1;
  string piece = "W_P";

public:
public:
  virtual int getColor() { return color; }
  virtual string getName() { return name; }
  virtual string getPiece() { return piece; }
  virtual void possibleAvailableMoves(int row, int col) {
    if (twomove(row, col) == 1)
      available_moves.push_back(numberTostring(row + 2, col));
    if (move(row, col) == 1)
      available_moves.push_back(numberTostring(row + 1, col));
    if (moveright(row, col) == 1) {
      available_moves.push_back(numberTostring(row + 1, col + 1));
      available_moves.push_back("*");
    }
    if (moveleft(row, col) == 1) {
      available_moves.push_back(numberTostring(row + 1, col - 1));
      available_moves.push_back("*");
    }
  }
  virtual int move(int row, int col) {
    if ((row + 1) > 7)
      return 0;
    if (isSpace(row + 1, col))
      return 1;
    else
      return 0;
  }
  virtual int twomove(int row, int col) { // white
    if ((row + 1) > 7)
      return 0;
    if (row == 1 && isSpace(row + 1, col) && isSpace(row + 2, col))
      return 1;
    return 0;
  }
  virtual int moveright(int row, int col) {
    if ((row + 1) > 7 || (col + 1) > 7)
      return 0;
    return isEnemy(row, col, row + 1, col + 1); // check enemey
  }
  virtual int moveleft(int row, int col) {
    if ((row + 1) > 7 || (col - 1) < 0)
      return 0;
    return isEnemy(row, col, row + 1, col - 1); // check enemey
  }
};
//#black
// pawn{

class BlackPawn : public virtual Box {
  string name = "BLACK_PAWN";
  int color = 0;
  string piece = "B_P";

public:
  virtual int getColor() { return color; }
  virtual string getName() { return name; }
  virtual string getPiece() { return piece; }
  virtual void possibleAvailableMoves(int row, int col) {
    if (twomove(row, col) == 1)
      available_moves.push_back(numberTostring(row - 2, col));

    if (move(row, col) == 1)
      available_moves.push_back(numberTostring(row - 1, col));

    if (moveright(row, col) == 1) {
      available_moves.push_back(numberTostring(row - 1, col + 1));
      available_moves.push_back("*");
    }
    if (moveleft(row, col) == 1) {
      available_moves.push_back(numberTostring(row - 1, col - 1));
      available_moves.push_back("*");
    }
  }
  virtual int move(int row, int col) {
    if ((row - 1) < 0)
      return 0;
    if (isSpace(row - 1, col))
      return 1;
    else
      return 0;
  }
  virtual int twomove(int row, int col) { // black
    if ((row - 1) > 7)
      return 0;
    if (row == 6 && isSpace(row - 1, col) && isSpace(row - 2, col))
      return 1;
    return 0;
  }
  virtual int moveright(int row, int col) {
    if ((row - 1) < 0 || (col + 1) > 7)
      return 0;
    return isEnemy(row, col, row - 1, col + 1); // check enemey
  }
  virtual int moveleft(int row, int col) {
    if ((row - 1) < 0 || (col - 1) < 0)
      return 0;
    return isEnemy(row, col, row - 1, col - 1); // check enemey
  }
};