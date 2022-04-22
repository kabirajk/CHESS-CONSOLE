#include "rook.h"
#include "bishop.h"

class Wqueen: public virtual Wrook,public virtual  Wbishop
{
    string name="WHITE_QUEEN";
    int color=1;
    string piece="W_Q";
    public:
    virtual int getcolor()
    {
        return color;
    }
    virtual string getname()
    {
        return name;
    }
    virtual string getpiece()
    {
        return piece;
    }
    void possible_moves(int row,int col)
    {
        horizontal(row,col);
        vertical(row,col);
        rightdiag(row, col);
        leftdiag(row,col);
    }
};
class Bqueen:public virtual Wqueen
{
    string name="BLACK_QUEEN";
    int color=0;
    string piece="B_Q";
    public:
    int getcolor()
    {
        return color;
    }
    string getname()
    {
        return name;
    }
    string getpiece()
    {
        return piece;
    }
    
};