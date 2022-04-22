
#include"coins.h"
Space space;
Wking WK;
Bking BK;
Wbishop WB;
Bbishop BB;
Wqueen WQ;
Bqueen BQ;
Wrook WR;
Brook BR;
Wknight WN;
Bknight BN;
Wpawn WP;
Bpawn BP;
void initializer()
{
    for(int col=0;col<8;col++)
    {
        Board[1][col]=&WP;
        Board[6][col]=&BP;
        Board[2][col]=&space;
        Board[3][col]=&space;
        Board[4][col]=&space;
        Board[5][col]=&space;
    }
    Board[0][0]=Board[0][7]=&WR;
    Board[7][0]=Board[7][7]=&BR;
    Board[0][1]=Board[0][6]=&WN;
    Board[7][1]=Board[7][6]=&BN;
    Board[0][2]=Board[0][5]=&WB;
    Board[7][2]=Board[7][5]=&BB;
    Board[0][3]=&WQ;
    Board[7][3]=&BQ;
    Board[0][4]=&WK;
    Board[7][4]=&BK;
}

int is_move_avilable(string Index)
{
    for(int i=0;i<MOVES.size();i++)
    {
        if(MOVES[i]==Index)
            {std::cout<<"matched";
            return 1;}
    }
    std::cout<<"notmatched";return 0;
}
void change_coins(int from_row,int from_col,int to_row,int to_col)
{   
    if(Box::is_enemy(from_row ,from_col ,to_row,to_col))
    { 
        Board[to_row][to_col]=Board[from_row][from_col];
        Board[from_row][from_col]=&space;
    }
    else if (Box::is_enemy(from_row ,from_col ,to_row,to_col)==2)
    {
        std::cout<<"hey choose a different place";
    }
    else if(Box::is_enemy(from_row ,from_col ,to_row,to_col)==0)
    {
        Board[to_row][to_col]=Board[from_row][from_col];
        Board[from_row][from_col]=&space;
    }
}

void cointype(int row,int col)
{   
    string coin=Board[row][col]->getpiece();
    if(coin=="W_K")
        {   WK.possible_moves(row,col); WK.getname(); }

    else if(coin=="B_K")
       { BK.possible_moves(row,col); BK.getname(); }
    else if(coin=="W_Q")
       { WQ.possible_moves(row,col); WQ.getname(); }
    else if(coin=="B_Q")
        { BQ.possible_moves(row,col); BQ.getname(); }
    else if(coin=="W_B")
        { WB.possible_moves(row,col); WB.getname(); }
    else if(coin=="B_B")
        { BB.possible_moves(row,col); BB.getname(); }
    else if(coin=="W_N")
        { WN.possible_moves(row,col); WN.getname(); }
    else if(coin=="B_N")
        { BN.possible_moves(row,col); BN.getname(); }
    else if(coin=="W_R")
        { WR.possible_moves(row,col); WR.getname(); }
    else if(coin=="B_R")
        { BR.possible_moves(row,col); BR.getname(); }
    else if(coin=="W_P")
        { WP.possible_moves(row,col); WP.getname(); }
    else if(coin=="B_P")
        { BP.possible_moves(row,col); BP.getname(); }
    else
        { std::cout<<"invalid input: "<<Board[row][col]->getname();}
}

void Print_avivalbe_moves( )
{
    std::cout<<"Here the available moves \n";
    for(int i=0;i<MOVES.size();i++)
    {
        if (MOVES[i] != "*")
            std::cout<<Box::numeric_to_Alphanumeric(Box::row(MOVES[i]),Box::col(MOVES[i]))<<" ";
        else if(MOVES[i]=="*")
            std::cout<<"\b"<<MOVES[i]<<"  ";
    }
    cout<<"\n";
}
void printboard()
{
    string s="   ";
    string ss="  ";
    std::cout<<"      ";
    for(int i=0;i<8;i++)
        {
            cout<< s+((char)(97+i))+s;
        }
    std::cout<<"\n\n";
    for(int row=1;row<=8;row++)
    {
       cout<< s+((char)(48+row))+s;
            for(int col=0;col<8;col++)
            {
                std::cout<< ss+Board[row-1][col]->getpiece()+ss;
            }
        cout<<"\n\n";
    }
    // for(int row=0;row<8;row++)
    //     {
    //         for(int col=0;col<8;col++)
    //         {
    //             std::cout<<" "<<Board[row][col]->getpiece()<<" ";
    //         }
    //         std::cout<<"\n\n";
    //     }
}


void GameLoop()
{
    while (1)
    {//print board firs
        string source;
        std::cout<<(Completed_moves.size()%2==0?"White's Turn":"Black's Turn")<<std::endl;
        std::cout<<"Enter the position//command: ";
        std::cin>>source;
        if(source=="PRINT")
            printboard();
        if(source=="EXIT")
        {
            EXIT();
            break;
        }
        else
            {
                source=Box::Alphanumeric_to_numberstring(source);
                int source_row=Box::row(source);
                int source_col=Box::col(source);
                std::cout<<Completed_moves.size()<<Box::iswhite(source_row,source_col)<<(Completed_moves.size()%2 == !Box::iswhite(source_row,source_col))<<"<+++ \n";
                if(Completed_moves.size()%2 == !Box::iswhite(source_row,source_col))
                    {
                        cointype(source_row,source_col);
                        if(MOVES.size()==0)
                            {   system("cls");
                                std::cout<<"# The coin is blocked \n";
                            }
                        else
                            {

                                std::cout<<"\n";
                                Print_avivalbe_moves( );
                                string destinaion_string;
                                std::cout<<"\nEnter the destinaion of the coin: "<<std::endl;
                                std::cin>>destinaion_string;
                                destinaion_string=Box::Alphanumeric_to_numberstring(destinaion_string);//b1to11
                                if (is_move_avilable(destinaion_string))
                                    {
                                        int destrow=Box::row(destinaion_string); int destcol=Box::col(destinaion_string);
                                        system("cls");
                                        change_coins(source_row,source_col,destrow,destcol);
                                        push_to_completed(Box::numeric_to_Alphanumeric(source_row,source_col)+"->"+Box::numeric_to_Alphanumeric(destrow,destcol));
                                        std::cout<<Completed_moves.back()<<std::endl;
                                    }
                                MOVES.clear();
                            }
                    }

                else
                    std::cout<<"u picked a wrong coin that is "<<(Box::iswhite(source_row,source_col)?"White":"Black")<<" Coin."<<std::endl;
                printboard();
            }
    }
}


