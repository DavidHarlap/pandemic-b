#include "Dispatcher.hpp"
#include "Board.hpp"


using namespace pandemic;
using namespace std;


Dispatcher::Dispatcher(Board& b, City c) : Player(b, c,"Dispatcher"){}
    
Dispatcher& Dispatcher::fly_direct(City c){
     if(currCity == c){
        throw ("can't fly from city to itself");
    }
    if(board.if_station(currCity)){
        currCity=c;
        return *this;
    }
    if(cards.count(c)==0){
        throw ("no card!");
    }
    cards.erase(c);
    currCity=c;
        
    
    return *this;
}