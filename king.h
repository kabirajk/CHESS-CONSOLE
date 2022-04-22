// #include "coins.h"
class Wking : public Box
{
    string name="WHITE_KING";
    int color=1;//if white 1
    string piece="W_K";
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
    void possible_moves(int row,int col)
    {
        if(top(row,col) == 1 &&is_enemy(row,col,row-1,col)!=2)
            {  
                MOVES.push_back(number_to_string(row-1,col));
                if (is_enemy(row,col,row-1,col)==1)    MOVES.push_back("*");
            }
        if(bottom(row,col) == 1&& is_enemy(row,col,row+1,col)!=2)
            {
                MOVES.push_back(number_to_string(row+1,col));
                if (is_enemy(row,col,row+1,col)==1)    MOVES.push_back("*");
            }

        if(left(row,col) == 1&& is_enemy(row,col,row,col-1) !=2)
            { MOVES.push_back(number_to_string(row,col-1));
                if (is_enemy(row,col,row,col-1)==1)    MOVES.push_back("*");
            }

        if(right(row,col) == 1&& is_enemy(row,col,row,col+1) !=2)
            {
                MOVES.push_back(number_to_string(row,col+1));
                if (is_enemy(row,col,row,col+1)==1)    MOVES.push_back("*");
            }

        if(topright(row,col) == 1 && is_enemy(row,col,row-1,col+1) !=2)
            {
                MOVES.push_back(number_to_string(row-1,col+1));
                if (is_enemy(row,col,row-1,col+1)==1)    MOVES.push_back("*");
            }

        if(topleft(row,col) == 1 && is_enemy(row,col,row-1,col-1)!=2)
            {
                MOVES.push_back(number_to_string(row-1,col-1));
                if (is_enemy(row,col,row-1,col-1)==1)    MOVES.push_back("*");
            }

        if(bottomright(row,col) == 1&& is_enemy(row,col,row+1,col+1)!=2)
            { 
                MOVES.push_back(number_to_string(row+1,col+1));
                if (is_enemy(row,col,row+1,col+1)==1)    MOVES.push_back("*");
            }

        if(bottomleft(row,col) == 1&&is_enemy(row,col,row+1,col-1) !=2)
            {
                MOVES.push_back(number_to_string(row+1,col-1));
                if (is_enemy(row,col,row+1,col-1)==1)    MOVES.push_back("*");
            }
    }
    int top(int r,int c)//-- decrease
    {   
        if(((r-1)>=0)&&(c>=0 && c<=7)) return 1;
        else return 0;
    }
    int bottom(int r,int c)
    {
        if(((r+1)<=7)&&(c>=0 && c<=7)) return 1;
        else return 0;
    }
    int left(int r,int c)
    {
        if((c-1)>=0 &&(r>=0 )) return 1;
        else return 0;
    }
    int right(int r,int c)
    {
        if((c+1)<=7 && r<=7) return 1;
        else return 0;
    }
    int topright(int r,int c)
    {
        if((r-1)>=0 && (c+1)<=7) return 1;
        else return 0;
    }
    int topleft(int r,int c)
    {
        if( (r-1)>=0 && (c-1>=0)) return 1;
        else return 0;
    }
    int bottomright(int r,int c)
    {
        if((r+1)<=7&&(c+1)<=7) return 1;
        else return 0;
    }
    int bottomleft(int r,int c)
    {
        if((r+1)<=7&&(c-1)>=0) return 1;
        else return 0;
    }
};

class Bking:public Wking
{   
    string name="BLACK_KING";
    int color=0;
    string piece="B_K";

};
