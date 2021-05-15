#include "GeneSplicer.hpp"

using namespace pandemic;

GeneSplicer::GeneSplicer(Board b, City c) : Player(b, c,"GeneSplicer"){}
    
GeneSplicer& GeneSplicer::discover_cure(Color clr){
     if(board.have_cure(clr)){
        return *this;
    }
    if(!board.if_station(currCity) || cards.size()<5 ){
        throw ("canot discover cure!");
    }
    int count=0;
    for(City c : cards){
        if(count++< 5){
           cards.erase(c);
        }
    }
    return *this;
}