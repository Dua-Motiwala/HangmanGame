#include "Player.h"
#include "HangmanGame.h"
#include "PlayerInputWordSource.h"
#include "Difficulty.h"
#include "WordWithHint.h"
#include <iostream>
#include <memory>

using namespace std;

auto isValidName = [](const string& name) {
    if (name.empty()) return false;

    for (char c : name) {
        if (!isalpha(c)) return false;
    }

    return true;
    };

int main() {
    string name1, name2;

    while (true) {
        cout << "Enter Player 1 name (letters only): ";
        getline(cin, name1);

        if (isValidName(name1)) break;

        cout << "Invalid name. Use letters only.\n";
    }

    // Input Player 2 name
    while (true) {
        cout << "Enter Player 2 name (letters only): ";
        getline(cin, name2);

        if (isValidName(name2)) break;

        cout << "Invalid name. Use letters only.\n";
    }

    Player player1(name1), player2(name2);

    while (true) {
        Player* guesser;
        Player* wordSetter;

        while (true) {
            cout << "Who will guess the word? (1 or 2): ";
            int choice;
            cin >> choice;

            if (choice == 1) {
                guesser = &player1;
                wordSetter = &player2;
                break;
            }
            else if (choice == 2) {
                guesser = &player2;
                wordSetter = &player1;
                break;
            }
            else {
                cout << "Invalid choice. Try again.\n";
            }
        }

        cout << "\nChoose difficulty:\n1. Easy\n2. Medium\n3. Hard\nSelect (1/2/3): ";
        int levelInput;
        cin >> levelInput;

        Difficulty difficulty = Difficulty::Medium;

        switch (levelInput) {
        case 1: {
            difficulty = Difficulty::Easy;
            break;
        }
        case 2: {
            difficulty = Difficulty::Medium;
            break;
        }
        case 3: {
            difficulty = Difficulty::Hard;
            break;
        }
        default: {
            cout << "Invalid. Defaulting to Medium.\n";
        }
        }

        unique_ptr<WordSource> wordSource = make_unique<PlayerInputWordSource>(*wordSetter);
        WordWithHint wordData = wordSource->getWord(difficulty);
        unique_ptr<Game> game = make_unique<HangmanGame>(*guesser, wordData, difficulty);

        game->startGame();

        cout << "\nCurrent Scores:\n";
        cout << player1.getName() << ": " << player1.getScore() << "\n";
        cout << player2.getName() << ": " << player2.getScore() << "\n";

        cout << "\nDo you want to play again? (y/n): ";
        char again;
        cin >> again;

        if (tolower(again) != 'y') {
            break;
        }
    }

    cout << "\nThanks for playing!\nFinal Scores:\n";
    cout << player1.getName() << ": " << player1.getScore() << "\n";
    cout << player2.getName() << ": " << player2.getScore() << "\n";

    return 0;
}