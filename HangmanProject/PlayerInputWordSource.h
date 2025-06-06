#ifndef PLAYERINPUTWORDSOURCE_H
#define PLAYERINPUTWORDSOURCE_H

using namespace std;

#include "WordSource.h"
#include "Player.h"

class PlayerInputWordSource : public WordSource {
private:
    Player& wordSetter;

public:
    PlayerInputWordSource(Player& setter);
    WordWithHint getWord(Difficulty difficulty) override;
};

#endif