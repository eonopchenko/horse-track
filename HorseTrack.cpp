/*******************************************************************************
FILE : HorseTrack.cpp
DESCRIPTION :
This file is implementation of the HorseTrack application.
==============================================================================*/

#pragma once

// HorseTrack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Include/HorseTrackParser.h"
#include "Include/InvalidInputException.h"
#include "Include/HorseWinningTable.h"
#include "Include/Inventory.h"

#include <iostream>
#include <map>
#include <vector>
#include <string>

int main()
{
    HorseWinningTable horseWinningTable;
    Inventory inventory;

    std::cout << "Welcome to Horse Track app, enter a command to start:" << std::endl;
    std::cout << std::endl;
    std::cout << "================================================================================" << std::endl;
    std::cout << "'R' or 'r' - restocks the cash inventory" << std::endl;
    std::cout << "'Q' or 'q' - quits the application" << std::endl;
    std::cout << "'W' or 'w' [1-7] - sets the winning horse number" << std::endl;
    std::cout << "[1-7] <amount> - specifies the horse wagered on and the amount of the bet" << std::endl;
    std::cout << "================================================================================" << std::endl;
    std::cout << std::endl;
    std::cout << "> ";

    std::string input = "";
    while (std::getline(std::cin, input))
    {
        try {
            switch (HorseTrackParser::ParseCommand(input)) {

            case HorseTrackParser::Command::RESTOCK:
            {
                inventory.Restock();
                break;
            }

            case HorseTrackParser::Command::QUIT:
            {
                return 0;
            }

            case HorseTrackParser::Command::SET_WINNING_HORSE:
            {
                unsigned winning_horse_number = 0;
                HorseTrackParser::ParseSetWinningHorseCommand(input, winning_horse_number);
                horseWinningTable.SetWinningHorseNumber(winning_horse_number);
                break;
            }

            case HorseTrackParser::Command::WAGER:
            {
                unsigned horse_number = 0;
                unsigned amount = 0;

                HorseTrackParser::ParseWagerCommand(input, horse_number, amount);

                std::cout << "Inventory:" << std::endl;
                inventory.Display();

                std::cout << "Horses:" << std::endl;
                horseWinningTable.Display();

                const std::string& horse_name = horseWinningTable.GetHorseName(horse_number);

                if (horseWinningTable.GetWinningHorseNumber() == horse_number)
                {
                    unsigned horse_odd = horseWinningTable.GetHorseOdd(horse_number);

                    unsigned payout = amount * horse_odd;

                    std::cout << "Payout: " << horse_name << ",$" << payout << std::endl;

                    inventory.Dispense(payout);
                }
                else
                {
                    std::cout << "No Payout: " << horse_name << std::endl;
                }
                break;
            }

            }
        }
        catch (InvalidInputException& e) {
            std::cerr << e.what() << std::endl;
        }

        std::cout << "> ";
    }
}
