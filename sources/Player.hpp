#pragma once

#include <set>
#include <string>
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

namespace pandemic
{
    class Player
    {
    protected:
        Board& board;
        City currCity;
        std::set<City> cards;
        std::string type;

    public:
        Player(Board &, City, std::string);

        virtual Player &drive(City);
        virtual Player &fly_direct(City);
        virtual Player &fly_charter(City);
        virtual Player &fly_shuttle(City);
        virtual Player &build();
        virtual Player &discover_cure(Color);
        virtual Player &treat(City);
        virtual Player &take_card(City);
        std::string role();
        
        bool throw_card(City, int clr=-1);
        bool check_if_same_color(Color, int);
        virtual void access_city();

        void remove_cards();
    
    };
}