#pragma once
#include <map>
#include <iostream>
#include <set>
#include "City.hpp"
#include "Color.hpp"


namespace pandemic
{
    class Board
    {
        private:
            //std::set<City> research_stations;
            std::map<City,int> disease_cubes;
            std::map<Color, bool> is_cure;
            std::map<City,bool> research_stations;
            static std::map<City,Color> disease_color;
            static std::map<City, std::set<City>> neighbour;
           // static std::map<City,Color> disease_color;
          //  static std::map<City, std::set<City>> neighbour;
            
        public:
            

            
            
            Board();
            const bool is_clean();
            void remove_cures();
            const int operator[](City c) const;
            int& operator[](City c);
            friend std::ostream& operator<<(std::ostream& os, const Board& b);

            bool if_station(City);
            bool add_station(City);
            Color get_color(City);
            void find_cure(Color);
            bool have_cure(Color);
            bool are_neighbors(City,City);
            void remove_stations();



    };
}