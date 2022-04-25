
#include "COINS.h"
Space space;
WhiteKing white_king;
BlackKing black_king;
WhiteBishop white_bishop;
BlackBishop black_bishop;
WhiteQueen white_queen;
BlackQueen black_queen;
WhiteRook white_rook;
BlackRook black_rook;
WhiteKnight white_knight;
BlackKnight black_knight;
WhitePawn white_pawn;
BlackPawn black_pawn;
void board_initializer() {
  for (int col = 0; col < 8; col++) {
    Board[1][col] = &white_pawn;
    Board[6][col] = &black_pawn;
    Board[2][col] = &space;
    Board[3][col] = &space;
    Board[4][col] = &space;
    Board[5][col] = &space;
  }
  Board[0][0] = Board[0][7] = &white_rook;
  Board[7][0] = Board[7][7] = &black_rook;
  Board[0][1] = Board[0][6] = &white_knight;
  Board[7][1] = Board[7][6] = &black_knight;
  Board[0][2] = Board[0][5] = &white_bishop;
  Board[7][2] = Board[7][5] = &black_bishop;
  Board[0][3] = &white_queen;
  Board[7][3] = &black_queen;
  Board[0][4] = &white_king;
  Board[7][4] = &black_king;
}

int is_move_avilable(string Index) {
  for (int i = 0; i < available_moves.size(); i++) {
    if (available_moves[i] == Index) {
      std::cout << "matched";
      return 1;
    }
  }
  std::cout << "notmatched";
  return 0;
}
void change_piece(int row = 1, int col = 1, string replaceable = "___") {
  printf("\e[%d;%dH", row + 2, ((col + 1) * 4) + 1);
  cout << replaceable;
}

void change_coins(int from_row, int from_col, int to_row, int to_col) {
  std::string s1;
  if (Box::isEnemy(from_row, from_col, to_row, to_col)) {
    Board[to_row][to_col] = Board[from_row][from_col];
    Board[from_row][from_col] = &space;
    s1 = Board[to_row][to_col]->getPiece();
    change_piece(to_row, to_col, s1);
    change_piece(from_row, from_col);
  } else if (Box::isEnemy(from_row, from_col, to_row, to_col) == 2) {
    std::cout << "hey choose a different place";
  } else if (Box::isEnemy(from_row, from_col, to_row, to_col) == 0) {
    Board[to_row][to_col] = Board[from_row][from_col];
    Board[from_row][from_col] = &space;
    s1 = Board[to_row][to_col]->getPiece();
    change_piece(to_row, to_col, s1);
    change_piece(from_row, from_col);
  }
}

void cointype(int row, int col) {
  string coin = Board[row][col]->getPiece();
  cout << Board[row][col]->getName();
  if (coin == "W_K") {
    white_king.possibleAvailableMoves(row, col);
    // white_king.getName();
  } else if (coin == "B_K") {
    black_king.possibleAvailableMoves(row, col);
    // black_king.getName();
  } else if (coin == "W_Q") {
    white_queen.possibleAvailableMoves(row, col);
    // white_queen.getName();
  } else if (coin == "B_Q") {
    black_queen.possibleAvailableMoves(row, col);
    // black_queen.getName();
  } else if (coin == "W_B") {
    white_bishop.possibleAvailableMoves(row, col);
    // white_bishop.getName();
  } else if (coin == "B_B") {
    black_bishop.possibleAvailableMoves(row, col);
    // black_bishop.getName();
  } else if (coin == "W_N") {
    white_knight.possibleAvailableMoves(row, col);
    // white_knight.getName();
  } else if (coin == "B_N") {
    black_knight.possibleAvailableMoves(row, col);
    // black_knight.getName();
  } else if (coin == "W_R") {
    white_rook.possibleAvailableMoves(row, col);
    // white_rook.getName();
  } else if (coin == "B_R") {
    black_rook.possibleAvailableMoves(row, col);
    // black_rook.getName();
  } else if (coin == "W_P") {
    white_pawn.possibleAvailableMoves(row, col);
    // white_pawn.getName();
  } else if (coin == "B_P") {
    black_pawn.possibleAvailableMoves(row, col);
    // black_pawn.getName();
  } else {
    std::cout << "invalid input: " << Board[row][col]->getName();
  }
}

void print_available_moves() {
  std::cout << "Here the available available_moves \n";
  for (int i = 0; i < available_moves.size(); i++) {
    if (available_moves[i] != "*")
      std::cout << Box::numericToAlphaNumeric(Box::row(available_moves[i]),
                                              Box::col(available_moves[i]))
                << " ";
    else if (available_moves[i] == "*")
      std::cout << "\b" << available_moves[i] << "  ";
  }
  cout << "\n";
}

void clear_words() {
  printf("\e[11;1H");
  printf("\e[0J");
  printf("\e[11;1H");
}
// void printwords(int row=10,int col=1)
// {
//   printf("\e[10;1H");
// }
void print_board() {
  printf("\e[1;1H");
  printf("\e[J");
  string s = " ";
  std::cout << "    ";
  for (int i = 0; i < 8; i++) {
    cout << s + ((char)(97 + i)) + s << " ";
  }
  std::cout << "\n";
  for (int row = 1; row <= 8; row++) {
    cout << s + ((char)(48 + row)) + s << " ";
    for (int col = 0; col < 8; col++) {
      std::cout << Board[row - 1][col]->getPiece() << " ";
    }
    cout << "\n";
  }
  // for(int row=0;row<8;row++)
  //     {
  //         for(int col=0;col<8;col++)
  //         {
  //             std::cout<<" "<<Board[row][col]->getPiece()<<" ";
  //         }
  //         std::cout<<"\n\n";
  //     }
}

void gameloop() {
  while (1) { // print board firs
    string source;
    clear_words();
    std::cout << (Completed_available_moves.size() % 2 == 0 ? "White's Turn"
                                                            : "Black's Turn")
              << std::endl;
    std::cout << "Enter the position//command: ";
    std::cin >> source;
    if (source == "PRINT")
      print_board();
    if (source == "EXIT") {
      on_exit();
      break;
    } else {
      source = Box::alphanumericToNumberstring(source);
      int source_row = Box::row(source);
      int source_col = Box::col(source);
      if (Completed_available_moves.size() % 2 ==
          !Box::isWhite(source_row, source_col)) {
        cointype(source_row, source_col);
        if (available_moves.size() == 0) {
          // system("cls");
          std::cout << "# The coin is blocked \n";
        } else {

          std::cout << "\n";
          print_available_moves();
          string destinaion_string;
          std::cout << "\nEnter the destinaion of the coin:\n";
          std::cin >> destinaion_string;
          destinaion_string =
              Box::alphanumericToNumberstring(destinaion_string); // b1to11
          if (is_move_avilable(destinaion_string)) {
            int destrow = Box::row(destinaion_string);
            int destcol = Box::col(destinaion_string);
            clear_words();
            change_coins(source_row, source_col, destrow, destcol);
            pushToCompleted(Box::numericToAlphaNumeric(source_row, source_col) +
                            "->" +
                            Box::numericToAlphaNumeric(destrow, destcol));
            // std::cout << Completed_available_moves.back() <<"\n";
          }
          available_moves.clear();
        }
      }

      else
      // clear_words();
      {
        std::cout << "u picked a wrong coin that is "
                  << (Box::isWhite(source_row, source_col) ? "White" : "Black")
                  << " Coin. !press any key to continue" << std::endl;
        getch();
      }
      // clearwords();
    }
  }
}
