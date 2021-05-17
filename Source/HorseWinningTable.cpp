/*******************************************************************************
FILE : HorseWinningTable.cpp
DESCRIPTION :
This file is HorseWinningTable class declaration. This class is responsible 
for storing, changing and providing race results and horse odds
==============================================================================*/

#include "../Include/HorseWinningTable.h"

#include <iostream>

HorseWinningTable::HorseWinningTable()
{
    winning_horse_number = 1;
    horse_winning_table = {
        Horse("That Darn Gray Cat",5),
        Horse("Fort Utopia",10),
        Horse("Count Sheep",9),
        Horse("Ms Traitour",4),
        Horse("Real Princess",3),
        Horse("Pa Kettle",5),
        Horse("Gin Stinger",6)
    };
}

unsigned HorseWinningTable::GetWinningHorseNumber()
{
    return winning_horse_number;
}

void HorseWinningTable::SetWinningHorseNumber(unsigned horse_number)
{
    winning_horse_number = horse_number;
}

unsigned HorseWinningTable::GetHorseOdd(unsigned horse_number)
{
    return horse_winning_table[horse_number-1].odd;
}

const std::string& HorseWinningTable::GetHorseName(unsigned horse_number)
{
    return horse_winning_table[horse_number-1].name;
}

void HorseWinningTable::Display()
{
    for (auto horse = horse_winning_table.begin(); horse != horse_winning_table.end(); ++horse)
    {
        int horse_number = horse - horse_winning_table.begin() + 1;
        std::cout << horse_number << "," << horse->name << "," << horse->odd << "," << ((horse_number == winning_horse_number) ? "won" : "lost") << std::endl;
    }
}
