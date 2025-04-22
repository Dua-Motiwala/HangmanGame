#include "Player.h"
#include "HangmanGame.h"
#include "PlayerInputWordSource.h"
#include "Difficulty.h"
#include "WordWithHint.h"
#include <iostream>
#include <memory>

int main() {
    std::string name1, name2;
    std::cout << "Enter Player 1 name: ";
    std::getline(std::cin, name1);
    std::cout << "Enter Player 2 name: ";
    std::getline(std::cin, name2);

    Player player1(name1), player2(name2);

    while (true) {
        Player* guesser;
        Player* wordSetter;

        while (true) {
            std::cout << "Who will guess the word? (1 or 2): ";
            int choice;
            std::cin >> choice;
            if (choice == 1) {
                guesser = &player1;
                wordSetter = &player2;
                break;
            } else if (choice == 2) {
                guesser = &player2;
                wordSetter = &player1;
                break;
            } else {
                std::cout << "Invalid choice. Try again.\n";
            }
        }

        std::cout << "\nChoose difficulty:\n1. Easy\n2. Medium\n3. Hard\nSelect (1/2/3): ";
        int levelInput;
        std::cin >> levelInput;
        Difficulty difficulty = Difficulty::Medium;
        switch (levelInput) {
            case 1: difficulty = Difficulty::Easy; break;
            case 2: difficulty = Difficulty::Medium; break;
            case 3: difficulty = Difficulty::Hard; break;
            default: std::cout << "Invalid. Defaulting to Medium.\n";
        }

        std::unique_ptr<WordSource> wordSource = std::make_unique<PlayerInputWordSource>(*wordSetter);
        WordWithHint wordData = wordSource->getWord(difficulty);
        std::unique_ptr<Game> game = std::make_unique<HangmanGame>(*guesser, wordData, difficulty);
        game->startGame();

        std::cout << "\nCurrent Scores:\n";
        std::cout << player1.getName() << ": " << player1.getScore() << "\n";
        std::cout << player2.getName() << ": " << player2.getScore() << "\n";

        std::cout << "\nDo you want to play again? (y/n): ";
        char again;
        std::cin >> again;
        if (std::tolower(again) != 'y') break;
    }

    std::cout << "\nThanks for playing!\nFinal Scores:\n";
    std::cout << player1.getName() << ": " << player1.getScore() << "\n";
    std::cout << player2.getName() << ": " << player2.getScore() << "\n";
    return 0;
}