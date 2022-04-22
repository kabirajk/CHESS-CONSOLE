class Space: public Box
{   public:
    string name="space";
    string piece="___";
    int color=32;
   string getname(){return name;}
   string getpiece(){return piece;}
   int getcolor(){return 32;}
   void possible_moves(int row,int col){}
};