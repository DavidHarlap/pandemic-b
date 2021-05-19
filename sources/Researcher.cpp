#include "Researcher.hpp"
#include <iostream>
const int MUM_CARD_TO_THROW =5;

using namespace pandemic;

Researcher::Researcher(Board& b, City c) : Player(b, c,"Researcher"){}
    
Researcher& Researcher::discover_cure(Color clr){
   if(board.have_cure(clr)){
        return *this;
    }
    if(cards.size()<MUM_CARD_TO_THROW || !check_if_same_color(clr,MUM_CARD_TO_THROW)){
        throw ("canot discover cure!");
    }

    board.find_cure(clr);

    int count=MUM_CARD_TO_THROW;
    std::set<City> temp = cards;
    auto it = cards.begin();
    while (it != cards.end() && count > 0)
    {
        if (Board::get_color(*it) == clr)
        {
            cards.erase(it++);
            count--;
        }
        else
        {
            ++it;
        }
    }
    return *this;
}
