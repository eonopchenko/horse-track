#include "pch.h"

#include "../Include/HorseTrackParser.h"
#include "../Include/InvalidInputException.h"

TEST(TestHorseTrackParser, TestRestock) {
	HorseTrackParser::Command command;

	command = HorseTrackParser::ParseCommand("r");
	EXPECT_EQ(HorseTrackParser::Command::RESTOCK, command);
}

TEST(TestHorseTrackParser, TestQuit) {
	HorseTrackParser::Command command;

	command = HorseTrackParser::ParseCommand("Q");
	EXPECT_EQ(HorseTrackParser::Command::QUIT, command);
}

TEST(TestHorseTrackParser, TestWager) {
	HorseTrackParser::Command command;

	command = HorseTrackParser::ParseCommand("1 55");
	EXPECT_EQ(HorseTrackParser::Command::WAGER, command);

	command = HorseTrackParser::ParseCommand("2 55");
	EXPECT_EQ(HorseTrackParser::Command::WAGER, command);
}

TEST(TestHorseTrackParser, TestSetWinningHorse) {
	HorseTrackParser::Command command;

	command = HorseTrackParser::ParseCommand("W 4");
	EXPECT_EQ(HorseTrackParser::Command::SET_WINNING_HORSE, command);
}

TEST(TestHorseTrackParser, TestInvalidInput) {
	HorseTrackParser::Command command;

	try {
		command = HorseTrackParser::ParseCommand("r 1");
		FAIL() << "Expected InvalidInputException";
	}
	catch (InvalidInputException e) {
		EXPECT_EQ(e.what(), std::string("Invalid Command: r 1"));
	}
}

TEST(TestHorseTrackParser, TestInvalidBet) {
	HorseTrackParser::Command command;

	const std::string input = "4 10.25";
	unsigned horse_number = 0;
	unsigned amount = 0;

	command = HorseTrackParser::ParseCommand(input);
	EXPECT_EQ(HorseTrackParser::Command::WAGER, command);

	try {
		HorseTrackParser::ParseWagerCommand(input, horse_number, amount);
		FAIL() << "Expected InvalidInputException";
	}
	catch (InvalidInputException e) {
		EXPECT_EQ(e.what(), std::string("Invalid Bet: 10.25"));
	}
}
