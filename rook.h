 namespace line
    {
        int top(int r,int c)//-- decrease
        {   
            if(((r)>=0)&&(c>=0 && c<=7)) return 1;
            else return 0;
        }
        int bottom(int r,int c)
        {
            if(((r)<=7)&&(c>=0 && c<=7)) return 1;
            else return 0;
        }
        int left(int r,int c)
        {
            if((c)>=0 &&(r>=0 )) return 1;
            else return 0;
        }
        int right(int r,int c)
        {
            if((c)<=7 && r<=7) return 1;
            else return 0;
        }
    }
class Wrook:public virtual Box
{   
    string name="WHITE_ROOK";
    int color=1;//if white 1
    string piece="W_R";
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
    virtual    void possible_moves(int row,int col)
    {
        horizontal(row,col);
        // cout<<endl;
        vertical(row,col);
    }
    void horizontal(int row,int col)
    {   int  move=1;
        while(1)//horizontal left
        {
            int indication=is_enemy(row,col,row,abs(col-move));
            if(indication==2)   break;
            if(col-move >-1)
            {
            if(line::left(row,(abs(col-move))) == 1&& is_enemy(row,col,row,abs(col-move)) !=2)
                {
                    MOVES.push_back(number_to_string(row,abs(col-move)));}
                    if (is_enemy(row,col,row,abs(col-move))==1)    MOVES.push_back("*");
                }
            else break;
                if (indication==1)
                    break;
                
            move++;
            if (move>7) break;
        }
        move=1;
        while(1)//horizontal right
        {
            int indication=is_enemy(row,col,row,col+move);
            if(indication==2) break;
            
            if(col+move<8)
            {if(line::right(row,move+col) == 1&& is_enemy(row,col,row,col+move) !=2)
                {   
                MOVES.push_back(number_to_string(row,move+col));
                if (is_enemy(row,col,row,col+move)==1)    MOVES.push_back("*");
                }
            }
            else break;
            if (indication==1)
                    break;
                
            move++;
            if (move>7) break;
        }
    }
    void vertical(int row,int col)
    {   int  move=1;
        while(1)//verticaltop
        {   int indication=is_enemy(row,col,abs(row-move),col);
            if(indication==2) break;
            if(row-move>=0)
            {
            if(line::top(abs(row-move),col) == 1 &&is_enemy(row,col,abs(row-move),col)!=2)
                { 
                    MOVES.push_back(number_to_string(abs(row-move),col));
                    if (is_enemy(row,col,abs(row-move),col)==1)    MOVES.push_back("*");
                }
            }
            else break;
            if (indication==1)
                 break;
                
            move++;
            if (move>7) break;
        }
        move=1;
        while(1)//verticalbottom
        {   int indication=is_enemy(row,col,row+move,col);
                if(indication==2) break;
            if(row+move<8)
            {
                if(line::bottom(row+move,col) == 1&& is_enemy(row,col,row+move,col)!=2)
                {  MOVES.push_back(number_to_string(row+move,col));
                        if (is_enemy(row,col,row+move,col)==1) MOVES.push_back("*");
                    }
                }
            else break;

            if (indication==1)
                {break;}
                
            move++;
            if (move>7) break;
        }
    }
};
class Brook:public virtual Wrook
{
    string name="BLACK_ROOK";
    int color=0;
    string piece="B_R";
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