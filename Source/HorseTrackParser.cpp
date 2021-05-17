/*******************************************************************************
FILE : HorseTrackparser.cpp
DESCRIPTION :
This file is HorseTrackparser class implementation. This class is responsible 
for parsing HorseTrack command line input parsing
==============================================================================*/

#include "../Include/HorseTrackParser.h"
#include "../Include/InvalidInputException.h"

HorseTrackParser::Command HorseTrackParser::ParseCommand(const std::string &input)
{
    Command command = Command::UNKNOWN;

    /// Restock
    if ((input == "R") || (input == "r"))
    {
        command = Command::RESTOCK;
    }

    /// Quit
    else if ((input == "Q") || (input == "q"))
    {
        command = Command::QUIT;
    }

    /// Set winning horse
    else if ((input.rfind("W ", 0) == 0) || (input.rfind("w ", 0) == 0))
    {
        command = Command::SET_WINNING_HORSE;
    }

    /// Wager
    else if (std::isdigit(input[0]) && (input.find(' ') != std::string::npos))
    {
        command = Command::WAGER;
    }

    /// Syntax error
    else
    {
        throw InvalidInputException("Invalid Command: " + input);
    }

    return command;
};

void HorseTrackParser::ParseSetWinningHorseCommand(const std::string& input, unsigned& winning_horse)
{
    std::string horse_number_s = input.substr(2, input.length()-1);
    if (horse_number_s.empty() || 
        (std::find_if(horse_number_s.begin(), horse_number_s.end(), 
            [](unsigned char c) { return !std::isdigit(c); }) != horse_number_s.end()) || 
        ((winning_horse = std::stoi(horse_number_s)) < 1) || (winning_horse > 7))
    {
        throw InvalidInputException("Invalid Horse Number: " + horse_number_s);
    }
};

void HorseTrackParser::ParseWagerCommand(const std::string& input, unsigned& horse_number, unsigned& amount)
{
    std::string horse_number_s = "";
    std::string amount_s = "";
    size_t space_pos = input.find(' ');

    if ((space_pos == 0) || ((horse_number_s = input.substr(0, space_pos)) == "") || 
        horse_number_s.empty() || (std::find_if(horse_number_s.begin(), horse_number_s.end(), 
            [](unsigned char c) { return !std::isdigit(c); }) != horse_number_s.end()) || 
        ((horse_number = std::stoi(horse_number_s)) == 0) || (horse_number < 1) || (horse_number > 7))
    {
        throw InvalidInputException("Invalid Horse Number: " + horse_number_s);
    }

    if ((space_pos == input.length()-1) || ((amount_s = input.substr(space_pos+1, input.length()-1)) == "") || 
        amount_s.empty() || (std::find_if(amount_s.begin(), amount_s.end(), 
            [](unsigned char c) { return !std::isdigit(c); }) != amount_s.end()) || 
        ((amount = std::stoi(amount_s)) == 0))
    {
        throw InvalidInputException("Invalid Bet: " + amount_s);
    }
}
