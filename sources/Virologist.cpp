#include "Virologist.hpp"

using namespace pandemic;

Virologist::Virologist(Board b, City c) : Player(b, c,"Virologist"){}
    
Virologist& Virologist::treat(City c){
    if(board[c]==0){
        throw ("can't treat nothing!");
    }
    if(board.have_cure(board.get_color(c))){
        board[c]=0;
    }
    else{
        board[c]--;;
    }
    return *this;
}
