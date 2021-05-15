#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <set>
#include <stdexcept>
#include <iostream>

using namespace std;
using namespace pandemic;

Player::Player(Board &b, City c,string str) : board(b),currCity(c),type(str){ }

bool Player::throw_card(City c, int clr){
    if(cards.count(c)==0){
        throw ("you dont have the specific card");
    }
    if(clr>=0 && clr!= (int)Board::disease_color[c]){
        throw ("the card color dont mach");
    }
    cards.erase(c);
    return true;
}

void Player::access_city() {}


Player& Player::drive(City c){
    if(board.are_neighbors(currCity,c)){
        throw invalid_argument("the city is not conected with curr city");                                                                                                                                                                                                                                       
    }
    currCity=c;                                                                                   
    access_city();
    return *this;
}
Player& Player::fly_direct(City c){
    if(throw_card(c)){
        currCity=c;
        access_city();
    }
    return *this;
}
Player& Player::fly_charter(City c){
    if(throw_card(currCity)){
        currCity=c;
        access_city();
    }
    return *this;
}
Player& Player::fly_shuttle(City c){
    if(board.if_station(currCity) && board.if_station(c)){
        currCity = c;
        access_city();
    }
    return *this;
}
Player& Player::build(){
    if(!board.if_station(currCity)){
        try {
            if(throw_card(currCity)){
                board.add_station(currCity);
            }
        }
        catch (string s) { 
            cout<<"can't build";
        }
    }
    return *this;
}
bool Player::check_if_same_color(Color clr, int n){
    int count = 0;
    for(City c : cards){
        if(board.get_color(c)==clr){
            count= count+1;
        }
    }
    return count>= n;
}
Player& Player::discover_cure(Color clr){
    if(board.have_cure(clr)){
        return *this;
    }
    if(!board.if_station(currCity) || cards.size()<5 || check_if_same_color(clr,5)){
        throw ("canot discover cure!");
    }
    int count=0;
    for(City c : cards){
        if(count==5){ return *this; }
        try{
            if(throw_card(c,(int)clr)){
                count= count+1;
            }
        }
        catch(string s) { 
            cout<< s;
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
    if(board.have_cure(board.get_color(c))){
        board[c]=0;
    }
    else{
        board[c]=board[c]-1;
    }
    return *this;
}

Player& Player::take_card(City c){
    //if(cards.count(c)==0){
    cards.emplace(c);
//}
    return *this;
}
std::string Player::role(){
    return type;
}