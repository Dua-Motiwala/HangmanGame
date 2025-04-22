#ifndef WORDSOURCE_H
#define WORDSOURCE_H

#include <string>
#include "Difficulty.h"
#include "WordWithHint.h"

class WordSource {
public:
    virtual WordWithHint getWord(Difficulty difficulty) = 0;
    virtual ~WordSource() {}
};

#endif