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

    board.find_cure(clr);

    int count=5;
    set<City> temp = cards;
    auto it = cards.begin();
    while (it != cards.end() && count > 0)
    {
        cards.erase(it++);
        count--;
    }
        
    return *this;
}
    
