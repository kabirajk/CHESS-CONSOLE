namespace diag {
int topright(int r, int c) {
  if ((r) >= 0 && (c) <= 7)
    return 1;
  else
    return 0;
}
int topleft(int r, int c) {
  if ((r) >= 0 && (c >= 0))
    return 1;
  else
    return 0;
}

int bottomright(int r, int c) {
  if ((r) <= 7 && (c) <= 7)
    return 1;
  else
    return 0;
}
int bottomleft(int r, int c) {

  if ((r) <= 7 && (c) >= -1)
    return 1;
  else
    return 0;
}
} // namespace diag

class Bishop : public virtual Box {
  string name;
  int color;
  string piece;

public:
  virtual int getColor() = 0;    // { return color; }
  virtual string getName() = 0;  // { return name; }
  virtual string getPiece() = 0; // { return piece; }
  virtual void possibleAvailableMoves(int row, int col) {
    rightdiag(row, col);
    leftdiag(row, col);
  }
  void rightdiag(int row, int col) //"\"
  {
    int move = 1;
    while (1) // horizontal bl <-+^
    {
      int indication = isEnemy(row, col, abs(row - move), abs(col - move));
      if (indication == 2)
        break;

      if (col - move >= 0 && row - move >= 0) {
        if (diag::bottomleft(abs(row - move), abs(col - move)) == 1 &&
            isEnemy(row, col, abs(row - move), abs(col - move)) != 2) {
          available_moves.push_back(
              numberTostring(abs(row - move), abs(col - move)));
          if (isEnemy(row, col, abs(row - move), abs(col - move)) == 1)
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
    move = 1;
    while (1) // horizontal v->
    {
      int indication = isEnemy(row, col, row + move, col + move);
      if (indication == 2)
        break;
      if (col + move <= 7 && row + move <= 7) {
        if (diag::topright(row + move, move + col) == 1 &&
            isEnemy(row, col, row + move, col + move) != 2) {
          available_moves.push_back(numberTostring(row + move, col + move));
          if (isEnemy(row, col, row + move, col + move) == 1)
            available_moves.push_back("*");
        }
      } else
        break;
      if (indication == 1) { // std::cout<<" <=kill ";
        break;
      }
      move++;
      if (move > 7)
        break;
    }
  }
  void leftdiag(int row, int col) //"/"
  {
    int move = 1;
    while (1) //^->
    {
      int indication = isEnemy(row, col, abs(row - move), abs(col + move));
      if (indication == 2)
        break;

      if (col + move <= 7 && row - move >= 0) {
        if (diag::bottomright(abs(row - move), (abs(col + move))) == 1 &&
            isEnemy(row, col, abs(row - move), abs(col + move)) != 2) {
          available_moves.push_back(
              numberTostring(abs(row - move), abs(col + move)));
          if (isEnemy(row, col, abs(row - move), abs(col + move)) == 1)
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
    move = 1;
    while (1) // horizontal<-v
    {
      int indication = isEnemy(row, col, row + move, abs(col - move));
      if (indication == 2)
        break;
      if (col - move >= 0 && row + move <= 7) {
        if (diag::topleft(row + move, abs(move - col)) == 1 &&
            isEnemy(row, col, row + move, abs(col - move)) != 2) {
          available_moves.push_back(
              numberTostring(row + move, abs(col - move)));
          if (isEnemy(row, col, row + move, abs(col - move)) == 1)
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
class WhiteBishop : public Bishop {
  string name = "WHITE_BISHOP";
  int color = 1;
  string piece = "W_B";

public:
  int getColor() { return color; }
  string getName() { return name; }
  string getPiece() { return piece; }
};
class BlackBishop : public Bishop {
  string name = "BLACK_BISHOP";
  int color = 0;
  string piece = "B_B";

public:
  int getColor() { return color; }
  string getName() { return name; }
  string getPiece() { return piece; }
};