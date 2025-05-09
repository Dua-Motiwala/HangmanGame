#include "PlayerInputWordSource.h"
#include <iostream>
#include <limits>

using namespace std;

PlayerInputWordSource::PlayerInputWordSource(Player& setter) : wordSetter(setter) {
}

WordWithHint PlayerInputWordSource::getWord(Difficulty difficulty) {
    WordWithHint data;
    int minLen = 3, maxLen = 5;

    switch (difficulty) {
    case Difficulty::Easy: {
        minLen = 3;
        maxLen = 5;
        break;
    }
    case Difficulty::Medium: {
        minLen = 6;
        maxLen = 9;
        break;
    }
    case Difficulty::Hard: {
        minLen = 10;
        maxLen = 1000;
        break;
    }
    }

    while (true) {
        cout << wordSetter.getName() << ", enter the word to guess (length " << minLen << "-" << maxLen << "): ";
        cin >> data.word;

        if (data.word.length() >= minLen && data.word.length() <= maxLen) {
            break;
        }

        cout << "Word length invalid for selected difficulty. Try again.\n";
    }

    cin.ignore();
    cout << "Enter a hint for the word: ";
    getline(cin, data.hint);

    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif


    return data;
}