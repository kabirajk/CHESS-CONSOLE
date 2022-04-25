namespace line {
int top(int r, int c) //-- decrease
{
  if (((r) >= 0) && (c >= 0 && c <= 7))
    return 1;
  else
    return 0;
}
int bottom(int r, int c) {
  if (((r) <= 7) && (c >= 0 && c <= 7))
    return 1;
  else
    return 0;
}
int left(int r, int c) {
  if ((c) >= 0 && (r >= 0))
    return 1;
  else
    return 0;
}
int right(int r, int c) {
  if ((c) <= 7 && r <= 7)
    return 1;
  else
    return 0;
}
} // namespace line
class Rook : public virtual Box {
  string name = "ROOK";
  int color = 'R'; // if white 1
  string piece = "R";

public:
  virtual int getColor() = 0;    // { return color; }
  virtual string getName() = 0;  // { return name; }
  virtual string getPiece() = 0; // { return piece; }
  virtual void possibleAvailableMoves(int row, int col) {
    horizontal(row, col);
    // cout<<endl;
    vertical(row, col);
  }
  void horizontal(int row, int col) {
    int move = 1;
    while (1) // horizontal left
    {
      int indication = isEnemy(row, col, row, abs(col - move));
      if (indication == 2)
        break;
      if (col - move > -1) {
        if (line::left(row, (abs(col - move))) == 1 &&
            isEnemy(row, col, row, abs(col - move)) != 2) {
          available_moves.push_back(numberTostring(row, abs(col - move)));
        }
        if (isEnemy(row, col, row, abs(col - move)) == 1)
          available_moves.push_back("*");
      } else
        break;
      if (indication == 1)
        break;

      move++;
      if (move > 7)
        break;
    }
    move = 1;
    while (1) // horizontal right
    {
      int indication = isEnemy(row, col, row, col + move);
      if (indication == 2)
        break;

      if (col + move < 8) {
        if (line::right(row, move + col) == 1 &&
            isEnemy(row, col, row, col + move) != 2) {
          available_moves.push_back(numberTostring(row, move + col));
          if (isEnemy(row, col, row, col + move) == 1)
            available_moves.push_back("*");
        }
      } else
        break;
      if (indication == 1)
        break;

      move++;
      if (move > 7)
        break;
    }
  }
  void vertical(int row, int col) {
    int move = 1;
    while (1) // verticaltop
    {
      int indication = isEnemy(row, col, abs(row - move), col);
      if (indication == 2)
        break;
      if (row - move >= 0) {
        if (line::top(abs(row - move), col) == 1 &&
            isEnemy(row, col, abs(row - move), col) != 2) {
          available_moves.push_back(numberTostring(abs(row - move), col));
          if (isEnemy(row, col, abs(row - move), col) == 1)
            available_moves.push_back("*");
        }
      } else
        break;
      if (indication == 1)
        break;

      move++;
      if (move > 7)
        break;
    }
    move = 1;
    while (1) // verticalbottom
    {
      int indication = isEnemy(row, col, row + move, col);
      if (indication == 2)
        break;
      if (row + move < 8) {
        if (line::bottom(row + move, col) == 1 &&
            isEnemy(row, col, row + move, col) != 2) {
          available_moves.push_back(numberTostring(row + move, col));
          if (isEnemy(row, col, row + move, col) == 1)
            available_moves.push_back("*");
        }
      } else
        break;

      if (indication == 1) {
        break;
      }

      move++;
      if (move > 7)
        break;
    }
  }
};
class WhiteRook : public Rook {
  string name = "WHITE_ROOK";
  int color = 1;
  string piece = "W_R";

public:
  int getColor() { return color; }
  string getName() { return name; }
  string getPiece() { return piece; }
};
class BlackRook : public WhiteRook {
  string name = "BLACK_ROOK";
  int color = 0;
  string piece = "B_R";

public:
  int getColor() { return color; }
  string getName() { return name; }
  string getPiece() { return piece; }
};