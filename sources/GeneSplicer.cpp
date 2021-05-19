#include "GeneSplicer.hpp"

const int MUM_CARD_TO_THROW = 5;

using namespace pandemic;

GeneSplicer::GeneSplicer(Board& b, City c) : Player(b, c,"GeneSplicer"){}
    
GeneSplicer& GeneSplicer::discover_cure(Color clr){
    if(board.have_cure(clr)){
        return *this;
    }
    if(!board.if_station(currCity) || cards.size()<MUM_CARD_TO_THROW ){
        throw ("canot discover cure!");
    }

    board.find_cure(clr);

    int count=MUM_CARD_TO_THROW;
    std::set<City> temp = cards;
    auto it = cards.begin();
    while (it != cards.end() && count > 0)
    {
        cards.erase(it++);
        count--;
    }
        
    return *this;
}
    
