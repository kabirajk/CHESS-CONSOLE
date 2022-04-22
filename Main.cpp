#include <fstream>
#include <iostream>
#include <vector>
std::vector<std::string> available_moves;
std::vector<std::string> Completed_available_moves;
void pushToCompleted(std::string completedmove) {
  Completed_available_moves.push_back(completedmove);
}
void on_exit() {
  std::fstream logfile("log.txt", std::ios::app);
  try {
    if (!logfile.is_open())
      throw "There is no file";
    logfile << "\n";
  } catch (const char *c) {
    std::ofstream logfile("log.txt", std::ios::app);
  }
  for (int i = 0; i < Completed_available_moves.size(); i++) {
    logfile << Completed_available_moves[i] << std::endl;
  }
}

using namespace std;
#include "HELPER.h"
void printv() {
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

int main() {
  board_initializer();
  print_board();
  gameloop();
  return 0;
}