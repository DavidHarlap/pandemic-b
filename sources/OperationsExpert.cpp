#include "OperationsExpert.hpp"
#include "Board.hpp"

using namespace pandemic;
using namespace std;

OperationsExpert::OperationsExpert(Board b, City c) : Player(b, c,"OperationsExpert"){}

OperationsExpert& OperationsExpert::build(){
    board.add_station(currCity);
    return *this;
}