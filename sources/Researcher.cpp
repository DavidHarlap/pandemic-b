#include "Researcher.hpp"
#include <iostream>

using namespace pandemic;

Researcher::Researcher(Board b, City c) : Player(b, c,"Researcher"){}
    
Researcher& Researcher::discover_cure(Color clr){
   if(board.have_cure(clr)){
        return *this;
    }
    if(cards.size()<5 || !check_if_same_color(clr,5)){
        throw ("canot discover cure!");
    }

    board.find_cure(clr);

    int count=5;
    std::set<City> temp = cards;
    auto it = cards.begin();
    while (it != cards.end() && count > 0)
    {
        if (board.get_color(*it) == clr)
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
