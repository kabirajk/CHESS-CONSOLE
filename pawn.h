class Wpawn:public Box
{
    string name="WHITE_PAWN";
    int color=1;
    string piece="W_P";
    public:
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
    virtual void possible_moves(int row,int col)
        {
            if(twomove(row,col)==1)
                MOVES.push_back(number_to_string(row+2,col));
            if(move(row,col)==1)
                MOVES.push_back(number_to_string(row+1,col));
            if(moveright(row,col)==1)
                {
                MOVES.push_back(number_to_string(row+1,col+1));
                MOVES.push_back("*");
                }
            if(moveleft(row,col)==1)
                {
                    MOVES.push_back(number_to_string(row+1,col-1));
                    MOVES.push_back("*");
                }
        } 
    virtual int move(int row,int col)
        {  
            if((row+1)>7) return 0;
            if(is_space(row+1,col))
                return 1;
            else return 0;
        }
    virtual int twomove(int row,int col)
        {   //white
            if ((row+1)>7) return 0;
            if(row==1 && is_space(row+1,col) &&is_space(row+2,col))  return 1;
            return 0;
        }
    virtual int moveright(int row,int col)
        {
            if((row+1)>7 || (col+1)>7) return 0;
            return is_enemy(row,col,row+1,col+1);//check enemey
        }
    virtual int moveleft(int row,int col)
        {
            if((row+1)>7 || (col-1)<0) return 0;
            return is_enemy(row,col,row+1,col-1);//check enemey
        }
};
//#black
//pawn{

class Bpawn:public virtual Wpawn
{
    string name="BLACK_PAWN";
    int color=0;
    string piece="B_P";
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
    virtual void possible_moves(int row,int col)
        {
            if(twomove(row,col)==1)
                MOVES.push_back(number_to_string(row-2,col));

            if(move(row,col)==1)
                MOVES.push_back(number_to_string(row-1,col));
                
            if(moveright(row,col)==1)
                {
                    MOVES.push_back(number_to_string(row-1,col+1));
                    MOVES.push_back("*");
                }
            if(moveleft(row,col)==1)
                {
                    MOVES.push_back(number_to_string(row-1,col-1));
                    MOVES.push_back("*");
                }
        }
    virtual int move(int row,int col)
    {  
        if((row-1)<0) return 0;
        if(is_space(row-1,col))
            return 1;
        else return 0;
    }
    virtual int twomove(int row,int col)
    {   //black
        if ((row-1)>7) return 0;
        if(row==6&&is_space(row-1,col) &&is_space(row-2,col) ) return 1;
        return 0;
    }
    virtual int moveright(int row,int col)
    {
        if((row-1)<0 || (col+1)>7) return 0;
        return is_enemy(row,col,row-1,col+1);//check enemey
    }
    virtual int moveleft(int row,int col)
    {
        if((row-1)<0 ||(col-1)<0) return 0;
        return is_enemy(row,col,row-1,col-1);//check enemey
    }
};