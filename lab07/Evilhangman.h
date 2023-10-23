#ifndef EVILHANGMAN_H
#define EVILHANGMAN_H

#include "Hangman.h"

class EvilHangman : public Hangman {
private:
    std::vector<std::string> currentWordFamily;
    void partitionWordList(char guess);
    std::string findWord();

public:
    EvilHangman();
    ~EvilHangman();


};

#endif


