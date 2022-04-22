#include <iostream>
#include <vector>
#include <fstream>
std::vector<std::string>MOVES;
std::vector<std::string>Completed_moves;
void push_to_completed (std::string completedmove)
    {
        Completed_moves.push_back(completedmove);
    }
void EXIT()
{
    std::fstream logfile("log.txt",std::ios::app);
    try
    {
        if(!logfile.is_open())
            throw "There is no file";
        logfile<<"\n";
    }
    catch(const char *c)
    {   
        std::ofstream logfile("log.txt",std::ios::app);
    }
    for(int i=0;i<Completed_moves.size();i++)
    {
        logfile<<Completed_moves[i]<<std::endl;
    }
}

using namespace std;
#include"helper.h"
void printv()
{   std::cout<<"Here the available moves \n";
    for(int i=0;i<MOVES.size();i++)
    {
        if (MOVES[i] != "*")
            std::cout<<Box::numeric_to_Alphanumeric(Box::row(MOVES[i]),Box::col(MOVES[i]))<<" ";
        else if(MOVES[i]=="*")
            std::cout<<"\b"<<MOVES[i]<<"  ";
    }
    cout<<"\n";
}

int main()
{   
    initializer();
    printboard();
    GameLoop();
    return 0;
}