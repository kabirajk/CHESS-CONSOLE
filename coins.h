#include <iostream>
using namespace std;

class Box;
Box* Board[8][8]={nullptr};

class Box
{
    public:
    virtual string getname()=0;
    virtual string getpiece()=0;
    virtual int getcolor()=0;
    virtual void possible_moves(int row,int col)=0;
    static string number_to_string(int row,int col)// 11 to "11"
        {   string s="";
            return s+((char)(48+row))+(((char)(48+col)));
        }

    static string Alphanumeric_to_numberstring(string alnu)
        {   string s="";//b1 to 01 //col row to rwo col
            char row=alnu[1]-1;
            char col=(48+(alnu[0]-97));
            return s+row+col;
        }
    static string numeric_to_Alphanumeric(int row,int col)
        {//11 to b1//col row
            string s;
            char r=48+row+1;
            char c=97+col;
            return s+c+r;
        }
    //for pusing purpose//completed moves
    static void push_to_completed (string completedmove)
    {
        Completed_moves.push_back(completedmove);
    }
    static int row(string s)//internal 1,1
        { 
            return ((int)s[0]-48);
        }
    static int col(string s)//internal 1,1
        { 
            return ((int)s[1]-48);
        }

    static int iswhite(int row,int col)
        {
            if (Board[row][col]->getcolor()==1)
                return 1;
            return 0; // char c=board[row][col]; // if(c>=65 && c<=90)  return 1;// else return 0;
        }

    static int is_space(int row,int col)
        {
            if( Board[row][col]->getname()=="space") return 32;
        return 0;
        }
    static int is_enemy(int crow,int ccol,int drow,int dcol)
        {
            if(iswhite(crow,ccol))
                {   if(iswhite(crow,ccol) && iswhite(drow,dcol)&& is_space(drow,dcol)!=32)    return 2;//friends
                    else if(is_space(drow,dcol)==32) return 0;//space
                    else return 1;//it enemy because one is enemy
                }
            else if(!iswhite(crow,ccol))
                {  
                    if(! iswhite(crow,ccol) && ! iswhite(drow,dcol) && is_space(drow,dcol)!=32)    return 2;//friends
                    else if(is_space(drow,dcol)==32) return 0;//space
                    else return 1;//it enemy because one is enemy
                }
            return 0;
        }

};
#include"queen.h"
#include"knight.h"
#include"pawn.h"
#include"king.h"
#include"space.h"

