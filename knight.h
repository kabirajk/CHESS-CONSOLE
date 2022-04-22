class Wknight:public Box
{
    string name="WHITE_KNIGHT";
    int color=1;
    string piece="W_N";
    
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
        if(upleft(row,col) == 1)
            {
                MOVES.push_back(number_to_string(row-2,col-1));
                if(is_enemy(row,col,row-2,col-1))  MOVES.push_back("*");
            }
        if(upright(row,col) == 1)
            {
                MOVES.push_back(number_to_string(row-2,col+1));
            if(is_enemy(row,col,row-2,col+1)==1) MOVES.push_back("*");
            }
        if(downleft(row,col) == 1)
            {
                MOVES.push_back(number_to_string(row+2,col-1));
                if(is_enemy(row,col,(row+2),(col-1))==1) MOVES.push_back("*");
            }
        if(downright(row,col) == 1)
            {
                MOVES.push_back(number_to_string(row+2,col+1));
                if(is_enemy(row,col,row+2,col+1)==1) MOVES.push_back("*");
            }
        if(leftdown(row,col) == 1)
            {
                MOVES.push_back(number_to_string(row+1,col-2));
            if(is_enemy(row,col,row+1,col-2)==1) MOVES.push_back("*");
            }
        if(leftup(row,col) == 1)
        {
            MOVES.push_back(number_to_string(row-1,col-2));
            if(is_enemy(row,col,row-1,col-2)==1) MOVES.push_back("*");
        }
        if(rightdown(row,col) == 1)
            {
            MOVES.push_back(number_to_string(row+1,col+2));
            if(is_enemy(row,col,row+1,col+2)==1) MOVES.push_back("*");
            }
        if(rightup(row,col) == 1)
            {
                MOVES.push_back(number_to_string(row-1,col+2));
            if(is_enemy(row,col,row-1,col+2)==1) MOVES.push_back("*");
            }
    }
    int upleft(int row,int col)
{
    if ((row-2)<0||(col-1)<0) return 0;
    int indication=is_enemy(row,col,row-2,col-1);
    if (indication==2) return 0;
    return 1;
}
    int upright(int row,int col)
    {
        if ((row-2)<0||(col+1)>7) return 0;
        int indication=is_enemy(row,col,row-2,col+1);
        if (indication==2) return 0;
        return 1;
    }
    int downleft(int row,int col)
    {
        if ((row+2)>7||(col-1)<0) return 0;
        
        int indication=is_enemy(row,col,(row+2),(col-1));
        if (indication==2) return 0;
        return 1;
    }
    int downright(int row,int col)
    {
        if ((row+2)>7||(col+1)>7) return 0;
        int indication=is_enemy(row,col,row+2,col+1);
        if (indication==2) return 0;
        return 1;
    }
    int leftdown(int row,int col)
    {
        if ((row+1)>7||(col-2)<0) return 0;
        int indication=is_enemy(row,col,row+1,col-2);
        if (indication==2) return 0;
        return 1;
    }
    int leftup(int row,int col)
    {
        if ((row-1)<0||(col-2)<0) return 0;
        int indication=is_enemy(row,col,row-1,col-2);
        if (indication==2) return 0;
        return 1;
    }
    int rightdown(int row,int col)
    {
        if((row+1)>7 ||(col+2)>7 ) return 0;
        int indication=is_enemy(row,col,row+1,col+2);
        if (indication==2) return 0;
        return 1;
    }
    int rightup(int row,int col)
    {
        if((row-1)<0 ||(col+2)>7 ) return 0;
        int indication=is_enemy(row,col,row-1,col+2);
        if (indication==2) return 0;
        return 1;
    }
};
class Bknight:public  Wknight
{
    string name="BLACK_KNIGHT";
    int color=0;
    string piece="B_N";
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
};