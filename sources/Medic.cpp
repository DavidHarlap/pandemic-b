#include "Medic.hpp"

using namespace pandemic;

Medic::Medic(Board& b, City c) : Player(b, c,"Medic"){}
    
Medic& Medic::treat(City c){
    if(currCity!=c){
        throw ("can't treat from far!");
    }
    if(board[c]==0){
        throw ("can't treat nothing!");
    }
    board[c]=0;
    return *this;
}

void Medic::access_city() {
    if(board.have_cure(Board::get_color(currCity))){
        board[currCity]=0;
    }
}