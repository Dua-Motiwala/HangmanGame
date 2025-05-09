#include "HangmanGame.h"
#include <iostream>
#include <cctype>

using namespace std;

HangmanGame::HangmanGame(Player& guesser, WordWithHint wordData, Difficulty difficulty)
    : wordData(wordData), guesser(guesser), currentTries(0) {

    guessedWord = string(wordData.word.length(), '_');
}

void HangmanGame::startGame() {
    cout << R"(
 _    _                                         
| |  | |                                        
| |__| | __ _ _ __   __ _ _ __ ___   __ _ _ __  
|  __  |/ _` | '_ \ / _` | '_ ` _ \ / _` | '_ \ 
| |  | | (_| | | | | (_| | | | | | | (_| | | | |
|_|  |_|\__,_|_| |_|\__, |_| |_| |_|\__,_|_| |_|
                     __/ |                      
                    |___/                       

)";
    
    cout << "Hint: " << wordData.hint << "\n";

    while (!isGameOver()) {
        displayStatus();
        char guess = getValidLetter();
        processGuess(guess);
    }

    if (isWordGuessed()) {
        cout << "\nCongratulations, " << guesser.getName() << "! You guessed the word: " << wordData.word << "\n";
        guesser.incrementScore();
    }
    else {
        cout << "\nGame Over! The word was: " << wordData.word << "\n";
    }
}

void HangmanGame::displayStatus() const {
    cout << "\nWord: ";
    for (char c : guessedWord) {
        cout << c << " ";
    }

    cout << "\nUsed letters: ";
    for (char c : guessedLetters) {
        cout << c << " ";
    }

    cout << "\nTries left: " << maxTries - currentTries << "\n";

    HangmanVisualizer::display(currentTries);
}

char HangmanGame::getValidLetter() {
    char ch;

    while (true) {
        cout << guesser.getName() << ", guess a letter: ";
        cin >> ch;
        ch = tolower(ch);

        if (isalpha(ch) && guessedLetters.find(ch) == guessedLetters.end()) {
            return ch;
        }

        cout << "Invalid or already guessed. Try again.\n";
    }
}

void HangmanGame::processGuess(char letter) {
    guessedLetters.insert(letter);
    bool found = false;

    for (size_t i = 0; i < wordData.word.length(); ++i) {
        if (tolower(wordData.word[i]) == letter) {
            guessedWord[i] = wordData.word[i];
            found = true;
        }
    }

    if (!found) {
        cout << "Wrong guess!\n";
        currentTries++;
    }
}

bool HangmanGame::isWordGuessed() const {
    return guessedWord == wordData.word;
}

bool HangmanGame::isGameOver() const {
    return isWordGuessed() || currentTries >= maxTries;
}
