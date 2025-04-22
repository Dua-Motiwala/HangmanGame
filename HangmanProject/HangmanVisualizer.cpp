#include "HangmanVisualizer.h"
#include <iostream>

void HangmanVisualizer::display(int triesUsed) {
    const char* stages[] = {
        " +---+\n     |\n     |\n     |\n    ===",
        " +---+\n O   |\n     |\n     |\n    ===",
        " +---+\n O   |\n |   |\n     |\n    ===",
        " +---+\n O   |\n/|   |\n     |\n    ===",
        " +---+\n O   |\n/|\\  |\n     |\n    ===",
        " +---+\n O   |\n/|\\  |\n/    |\n    ===",
        " +---+\n O   |\n/|\\  |\n/ \\  |\n    ===",
    };
    int index = std::min(triesUsed, 6);
    std::cout << stages[index] << "\n";
}