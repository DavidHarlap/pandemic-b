#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <set>
#include <stdexcept>
#include <iostream>

using namespace std;
using namespace pandemic;
const int MUM_CARD_TO_THROW =5;


Player::Player(Board& b, City c,string str) : board(b),currCity(c),type(std::move(str)){ }

/*bool Player::throw_card(City c, int clr){
    if(cards.count(c)==0){
        throw ("you dont have the specific card");
    }
    if(clr>=0 && clr!= board[c]){
        throw ("the card color dont mach");
    }
    cards.erase(c);
    return true;
}*/

void Player::access_city() {}


Player& Player::drive(City c){
    if(!Board::are_neighbors(currCity,c)){
        throw ("the city is not conected with curr city");                                                                                                                                                                                                                                       
    }
    currCity=c;                                                                                   
    access_city();
    return *this;
}

Player& Player::fly_direct(City c){
    if(currCity == c){
        throw ("can't fly from city to itself");
    }
    if(cards.count(c)==0){
        throw ("you dont have the specific card");
    }
    cards.erase(c);
    currCity=c;
    access_city();
    return *this;
}
Player& Player::fly_charter(City c){
    if(currCity == c){
        throw ("can't fly from city to itself");
    }
    if(cards.count(currCity)==0){
        throw ("you dont have the specific card");
    }
    cards.erase(currCity);
    currCity=c;
    access_city();
    return *this;
}
Player& Player::fly_shuttle(City c){
    //cout<< board.research_stations.size();
    /*for(City s: board.research_stations){
        cout <<"yy "<< (int)s<<" ";
    }
    cout<< endl;
    cout << "c is:" <<(int)c<< endl<<endl;*/
    if(currCity == c){
        throw ("can't fly from city to itself");
    }
    if(!board.if_station(currCity) || !board.if_station(c)){
        throw ("there no research station!");
    }
        currCity = c;
        access_city();
    
    return *this;
}


Player& Player::build(){
 //   if(!board.if_station(currCity)){
    if(cards.count(currCity)==0){
        throw ("there no card!");
    }
    if(!board.if_station(currCity)){
        //std::cout<< "if in build in "<< (int)currCity<<endl;
        cards.erase(currCity);
        board.add_station(currCity);
        //std::cout<< boolalpha<< board.if_station(currCity)<<endl;
    }
    return *this;

    
        
        /*
        try {
            if(throw_card(currCity)){
                board.add_station(currCity);
                std::cout << "build";
            }
        }
        catch (string s) { 
            cout<<"can't build";
        }
   // }*/
}

bool Player::check_if_same_color(Color clr, int n){
    int count = 0;
    for(City c : cards){
        if(Board::get_color(c)==clr){
            count= count+1;
        }
    }
    return count>= n;
}

Player& Player::discover_cure(Color clr){
    if(board.have_cure(clr)){
        return *this;
    }
    if(!board.if_station(currCity) || cards.size()<MUM_CARD_TO_THROW || !check_if_same_color(clr,MUM_CARD_TO_THROW)){
        throw ("canot discover cure!");
    }

    board.find_cure(clr);


    int count=MUM_CARD_TO_THROW;
;
    set<City> temp = cards;
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

Player& Player::treat(City c){
    if(currCity!=c){
        throw ("can't treat from far!");
    }
    if(board[c]==0){
        throw ("can't treat nothing!");
    }
    if(board.have_cure(Board::get_color(c))){
        board[c]=0;
    }
    else{
        board[c]--;;
    }
    return *this;
}

Player& Player::take_card(City c){
    //if(cards.count(c)==0){
    cards.insert(c);
//}
    return *this;
}
std::string Player::role(){
    return type;
}

void Player::remove_cards()

    {
        cout<<"deleteeeeeeeeeeeeeeeeeeeeeeeee"<<endl;
        cards.clear();
    }