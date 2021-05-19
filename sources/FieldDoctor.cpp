#include "FieldDoctor.hpp"

using namespace pandemic;

FieldDoctor::FieldDoctor(Board& b, City c)  : Player(b, c,"FieldDoctor"){}
    
FieldDoctor& FieldDoctor::treat(City c){
    if(!((currCity==c) || (Board::are_neighbors(currCity,c)))){
        throw ("can't treat from far!");
    }
    if(board[c]==0){
        throw ("can't treat nothing!");
    }
    if(board.have_cure(Board::get_color(c))){
        board[c]=0;
    }
    else{
        board[c]--;;
    }
    return *this;
}