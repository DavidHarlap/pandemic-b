#include "Scientist.hpp"
#include "Board.hpp"

using namespace pandemic;
using namespace std;

Scientist::Scientist(Board b, City c,int num) : n(num), Player(b, c,"Scientist"){}

Scientist& Scientist::discover_cure(Color clr){
   if(board.have_cure(clr)){
        return *this;
    }
    if(!board.if_station(currCity) || cards.size()<n || Player::check_if_same_color(clr,n)){
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
        catch(string s) { 
            cout<< s;
        }
    }
    return *this;
}