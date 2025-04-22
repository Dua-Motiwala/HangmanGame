#ifndef HANGMANGAME_H
#define HANGMANGAME_H

#include "Game.h"
#include "WordWithHint.h"
#include "Player.h"
#include "HangmanVisualizer.h"
#include "Difficulty.h"
#include <set>
#include <string>

class HangmanGame : public Game {
private:
    WordWithHint wordData;
    std::string guessedWord;
    std::set<char> guessedLetters;
    int maxTries = 6;
    int currentTries;
    Player& guesser;

public:
    HangmanGame(Player& guesser, WordWithHint wordData, Difficulty difficulty);
    void startGame() override;

private:
    void displayStatus() const;
    char getValidLetter();
    void processGuess(char letter);
    bool isWordGuessed() const;
    bool isGameOver() const;
};

#endif
