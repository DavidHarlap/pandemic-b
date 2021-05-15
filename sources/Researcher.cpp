#include "Researcher.hpp"
#include <iostream>

using namespace pandemic;

Researcher::Researcher(Board b, City c) : Player(b, c,"Researcher"){}
    
Researcher& Researcher::discover_cure(Color clr){
    if(board.have_cure(clr)){
        return *this;
    }
    if(cards.size()<5 || Player::check_if_same_color(clr,5)){
        throw ("canot discover cure!");
    }
    int count=0;
    for(City c : cards){
        if(count==5){ return *this; }
        try{
            if(Player::throw_card(c,(int)clr)){
                count= count+1;
            }
        }
        catch(std::string s) { 
            std::cout << s;
        }
    }
    return *this;
}