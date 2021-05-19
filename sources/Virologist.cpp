#include "Virologist.hpp"

using namespace pandemic;

Virologist::Virologist(Board& b, City c) : Player(b, c,"Virologist"){}
    
Virologist& Virologist::treat(City c){
    if(currCity==c){
        Player::treat(c);
        return *this;
    }

    if(cards.count(c)==0){
        throw ("there no card!");
    }
    if(board[c]==0){
        throw ("can't treat nothing!");
    }
    cards.erase(c);
    
    if(board.have_cure(Board::get_color(c))){
    board[c]=0;
    }
    else{
        board[c]--;;
    }

       
    return *this;
}
