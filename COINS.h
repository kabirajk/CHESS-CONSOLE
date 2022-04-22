#include <iostream>
using namespace std;

class Box;
Box *Board[8][8] = {nullptr};

class Box {
public:
  virtual string getName() = 0;
  virtual string getPiece() = 0;
  virtual int getColor() = 0;
  virtual void possibleAvailableMoves(int row, int col) = 0;
  static string numberTostring(int row, int col) // 11 to "11"
  {
    string s = "";
    return s + ((char)(48 + row)) + (((char)(48 + col)));
  }

  static string alphanumericToNumberstring(string alnu) {
    string s = ""; // b1 to 01 //col row to rwo col
    char row = alnu[1] - 1;
    char col = (48 + (alnu[0] - 97));
    return s + row + col;
  }
  static string numericToAlphaNumeric(int row, int col) { // 11 to b1//col row
    string s;
    char r = 48 + row + 1;
    char c = 97 + col;
    return s + c + r;
  }
  // for pusing purpose//completed available_moves
  static void pushToCompleted(string completedmove) {
    Completed_available_moves.push_back(completedmove);
  }
  static int row(string s) // internal 1,1
  {
    return ((int)s[0] - 48);
  }
  static int col(string s) // internal 1,1
  {
    return ((int)s[1] - 48);
  }

  static int isWhite(int row, int col) {
    if (Board[row][col]->getColor() == 1)
      return 1;
    return 0; // char c=board[row][col]; // if(c>=65 && c<=90)  return 1;// else
              // return 0;
  }

  static int isSpace(int row, int col) {
    if (Board[row][col]->getName() == "space")
      return 32;
    return 0;
  }
  static int isEnemy(int crow, int ccol, int drow, int dcol) {
    if(crow>7||drow>7||crow<0||drow<0)  return 2;
    if(ccol>7||dcol>7||ccol<0||dcol<0)  return 2;

    //<<"  "<<crow<<ccol<<drow<<dcol<<"<>"<<isWhite(crow,ccol)<<isWhite(drow,dcol);
    if (isWhite(crow, ccol)) {
      if (isWhite(crow, ccol) && isWhite(drow, dcol) &&
          isSpace(drow, dcol) != 32)
        return 2; // friends
      else if (isSpace(drow, dcol) == 32)
        return 0; // space
      else
        return 1; // it enemy because one is enemy
    } else if (!isWhite(crow, ccol)) {
      if (!isWhite(crow, ccol) && !isWhite(drow, dcol) &&
          isSpace(drow, dcol) != 32)
        return 2; // friends
      else if (isSpace(drow, dcol) == 32)
        return 0; // space
      else
        return 1; // it enemy because one is enemy
    }
    return 0;
  }
};
#include "KING.h"
#include "KNIGHT.h"
#include "PAWN.h"
#include "QUEEN.h"
#include "SPACE.h"
