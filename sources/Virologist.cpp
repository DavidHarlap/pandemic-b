#include "Virologist.hpp"

using namespace pandemic;

Virologist::Virologist(Board b, City c) : Player(b, c,"Virologist"){}
    
Virologist& Virologist::treat(City c){
    if(board[c]==0){
        throw ("can't treat nothing!");
    }
    if(currCity!=c){
        try{
            if(!Player::throw_card(c)){
                std::cout<< "cant treat";
            }
        }
        catch(std::string s) { 
            std::cout<< "can't treat!";
        }
    }
    if(board.have_cure(board.get_color(c))){
        board[c]=0;
    }
    else{
        board[c]=board[c]-1;
    }
    return *this;
}
