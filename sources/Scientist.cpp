#include "Scientist.hpp"
#include "Board.hpp"

using namespace pandemic;
using namespace std;

Scientist::Scientist(Board &b, City c,int num) : n(num), Player(b, c,"Scientist"){}

Scientist& Scientist::discover_cure(Color clr){
   if(board.have_cure(clr)){
        return *this;
    }
    if(!board.if_station(currCity) || cards.size()<n || !check_if_same_color(clr,n)){
        throw ("canot discover cure!");
    }

    board.find_cure(clr);


    int count=n;
    set<City> temp = cards;
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
