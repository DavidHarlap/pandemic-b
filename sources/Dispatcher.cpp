#include "Dispatcher.hpp"
#include "Board.hpp"


using namespace pandemic;
using namespace std;


Dispatcher::Dispatcher(Board b, City c) : Player(b, c,"Dispatcher"){}
    
Dispatcher& Dispatcher::fly_direct(City c){
    if(board.if_station(this->currCity)){
        currCity=c;
    }
    return *this;
}