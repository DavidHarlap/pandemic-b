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
            std::map<City,int> disease_cubes;
            std::map<Color, bool> is_cure;
            //std::map<City,bool> research_stations;
            static std::map<City,Color> disease_color;
            static std::map<City, std::set<City>> neighbour;
           // static std::map<City,Color> disease_color;
          //  static std::map<City, std::set<City>> neighbour;
            
        public:
            
            std::set<City> research_stations;

            
            
            Board();
            bool is_clean();
            void remove_cures();
            //const int operator[](City c) const;
            int& operator[](City c);
            friend std::ostream& operator<<(std::ostream& os, const Board& b);

            bool if_station(City)const;
            void add_station(City);
            static Color get_color(City);
            void find_cure(Color);
            bool have_cure(Color);
            static bool are_neighbors(City,City);
            void remove_stations();



    };
}