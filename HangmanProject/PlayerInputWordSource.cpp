#include "PlayerInputWordSource.h"
#include <iostream>
#include <limits>

PlayerInputWordSource::PlayerInputWordSource(Player& setter) : wordSetter(setter) {}

WordWithHint PlayerInputWordSource::getWord(Difficulty difficulty) {
    WordWithHint data;
    int minLen = 3, maxLen = 5;

    switch (difficulty) {
        case Difficulty::Easy:   minLen = 3; maxLen = 5; break;
        case Difficulty::Medium: minLen = 6; maxLen = 9; break;
        case Difficulty::Hard:   minLen = 10; maxLen = 1000; break;
    }

    while (true) {
        std::cout << wordSetter.getName() << ", enter the word to guess (length " << minLen << "-" << maxLen << "): ";
        std::cin >> data.word;
        if (data.word.length() >= minLen && data.word.length() <= maxLen)
            break;
        std::cout << "Word length invalid for selected difficulty. Try again.\n";
    }

    std::cin.ignore();
    std::cout << "Enter a hint for the word: ";
    std::getline(std::cin, data.hint);
    return data;
}
