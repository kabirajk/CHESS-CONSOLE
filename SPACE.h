class Space : public Box {
public:
  string name = "space";
  string piece = "___";
  int color = 32;
  string getName() { return name; }
  string getPiece() { return piece; }
  int getColor() { return 32; }
  void possibleAvailableMoves(int row, int col) {}
};