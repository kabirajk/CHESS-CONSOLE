namespace diag
{
    int topright(int r,int c)
{
    if((r)>=0 && (c)<=7) return 1;
    else return 0;
}
int topleft(int r,int c)
{
    if( (r)>=0 && (c>=0)) return 1;
    else return 0;
}

int bottomright(int r,int c)
{
    if((r)<=7&&(c)<=7) return 1;
    else return 0;
}
int bottomleft(int r,int c)
{

    if((r)<=7&&(c)>=-1) return 1;
    else return 0;
}
} 

class Wbishop:public virtual Box
{
    string name="WHITE_BISHOP";
    int color=1;
    string piece="W_B";
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
        rightdiag(row, col);
        leftdiag(row,col);
    }
    void rightdiag(int row,int col)//"\"
{
    int  move=1;
    while(1)//horizontal bl <-+^
    {   int indication=is_enemy(row,col,abs(row-move),abs(col-move));
        if(indication==2) break;
       
    if(col-move >=0 && row-move>=0)
        {
        if(diag::bottomleft(abs(row-move),abs(col-move)) == 1&&is_enemy(row,col,abs(row-move),abs(col-move)) !=2)
            {
                MOVES.push_back(number_to_string(abs(row-move),abs(col-move)));
                if (is_enemy(row,col,abs(row-move),abs(col-move))==1)    MOVES.push_back("*");
            }
        }
    else break;
        
        if (indication==1)
            { break;}
        move++;
        if (move>7) break;
     }
    move=1;
    while(1)//horizontal v->
    {
        int indication=is_enemy(row,col,row+move,col+move);
        if(indication==2) break;
    if(col+move<=7 && row+move<=7) 
    {   
        if(diag::topright(row+move,move+col) == 1 && is_enemy(row,col,row+move,col+move) !=2)
            {
                MOVES.push_back(number_to_string(row+move,col+move));
                if (is_enemy(row,col,row+move,col+move)==1)    MOVES.push_back("*");
            }
        }
    else break;
       if (indication==1)
            {// std::cout<<" <=kill ";
             break;}
        move++;
        if (move>7) break;
    }
}
    void leftdiag(int row,int col)//"/"
{
    int  move=1;
    while(1)//^->
    {   int indication=is_enemy(row,col,abs(row-move),abs(col+move));
        if(indication==2) break;
       
    if(col+move <=7 && row-move>=0)
       { 
        if(diag::bottomright(abs(row-move),(abs(col+move))) == 1 && is_enemy(row,col,abs(row-move),abs(col+move))!=2)
           {
                MOVES.push_back(number_to_string(abs(row-move),abs(col+move)));
                if (is_enemy(row,col,abs(row-move),abs(col+move))==1)    MOVES.push_back("*");
           }
        }
    else break;
        if (indication==1)
            { break;}
        move++;
        if (move>7) break;
    }
    move=1;
    while(1)//horizontal<-v
    {
        int indication=is_enemy(row,col,row+move,abs(col-move));
        if(indication==2) break;
    if(col-move>=0 && row+move<=7) 
       { 
       if(diag::topleft(row+move,abs(move-col)) == 1 && is_enemy(row,col,row+move,abs(col-move))!=2)
            {
                MOVES.push_back(number_to_string(row+move,abs(col-move)));
            if (is_enemy(row,col,row+move,abs(col-move))==1)    MOVES.push_back("*");
            }
       }
    else break;
        if (indication==1)
            { break;}
        move++;
        if (move>7) break;
    }
}

};
class Bbishop:public virtual Wbishop
{
    string name="BLACK_BISHOP";
    int color=0;
    string piece="B_B";
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