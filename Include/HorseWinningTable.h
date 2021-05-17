/*******************************************************************************
FILE : HorseWinningTable.h
DESCRIPTION :
This file is HorseWinningTable class implementation. This class is responsible 
for storing, changing and providing race results and horse odds
==============================================================================*/

#include <string>
#include <vector>

class HorseWinningTable {
public:
    unsigned GetWinningHorseNumber();
    void SetWinningHorseNumber(unsigned horse_number);
    unsigned GetHorseOdd(unsigned horse_number);
    const std::string& GetHorseName(unsigned horse_number);
    void Display();

    HorseWinningTable();

private:
    class Horse {
    public: 
        std::string name = "";
        unsigned odd = 0;

        Horse(std::string name, unsigned odd): name(name), odd(odd) {}
    };

    unsigned winning_horse_number = 1;
    std::vector<Horse> horse_winning_table;
};
