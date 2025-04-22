#include "HangmanGame.h"
#include <iostream>
#include <cctype>

HangmanGame::HangmanGame(Player& guesser, WordWithHint wordData, Difficulty difficulty)
    : wordData(wordData), guesser(guesser), currentTries(0) {
    guessedWord = std::string(wordData.word.length(), '_');
}

void HangmanGame::startGame() {
    std::cout << "=== Hangman Game ===\n";
    std::cout << "Hint: " << wordData.hint << "\n";

    while (!isGameOver()) {
        displayStatus();
        char guess = getValidLetter();
        processGuess(guess);
    }

    if (isWordGuessed()) {
        std::cout << "\nCongratulations, " << guesser.getName() << "! You guessed the word: " << wordData.word << "\n";
        guesser.incrementScore();
    } else {
        std::cout << "\nGame Over! The word was: " << wordData.word << "\n";
    }
}

void HangmanGame::displayStatus() const {
    std::cout << "\nWord: ";
    for (char c : guessedWord) std::cout << c << " ";
    std::cout << "\nUsed letters: ";
    for (char c : guessedLetters) std::cout << c << " ";
    std::cout << "\nTries left: " << maxTries - currentTries << "\n";
    HangmanVisualizer::display(currentTries);
}

char HangmanGame::getValidLetter() {
    char ch;
    while (true) {
        std::cout << guesser.getName() << ", guess a letter: ";
        std::cin >> ch;
        ch = std::tolower(ch);
        if (std::isalpha(ch) && guessedLetters.find(ch) == guessedLetters.end()) {
            return ch;
        }
        std::cout << "Invalid or already guessed. Try again.\n";
    }
}

void HangmanGame::processGuess(char letter) {
    guessedLetters.insert(letter);
    bool found = false;
    for (size_t i = 0; i < wordData.word.length(); ++i) {
        if (std::tolower(wordData.word[i]) == letter) {
            guessedWord[i] = wordData.word[i];
            found = true;
        }
    }
    if (!found) {
        std::cout << "Wrong guess!\n";
        currentTries++;
    }
}

bool HangmanGame::isWordGuessed() const {
    return guessedWord == wordData.word;
}

bool HangmanGame::isGameOver() const {
    return isWordGuessed() || currentTries >= maxTries;
}