/*******************************************************************************
FILE : HorseTrackparser.h
DESCRIPTION :
This file is HorseTrackparser class declaration. This class is responsible 
for parsing HorseTrack command line input parsing
==============================================================================*/

#include <string>

class HorseTrackParser {
public:
    enum class Command {
        UNKNOWN = 0,
        RESTOCK = 1,
        QUIT = 2,
        SET_WINNING_HORSE = 3,
        WAGER = 4,
    };

    static Command ParseCommand(const std::string &input);
    static void ParseSetWinningHorseCommand(const std::string& input, unsigned& winning_horse);
    static void ParseWagerCommand(const std::string& input,unsigned& horse_number,unsigned& amount);
};
