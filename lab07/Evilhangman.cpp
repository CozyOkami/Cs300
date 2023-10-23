#include "Evilhangman.h"
#include <iostream>
#include <algorithm>
#include <ctime>

// Private method to partition words into word families based on the guessed letter
void EvilHangman::partitionWordList(char guess) {
    currentWordFamily.clear();
    for (const std::string& word : currentWordList) {
        std::string wordFamily = word;
        for (char& c : wordFamily) {
            if (c != guess) {
                c = '_';
            }
        }
        if (std::count(wordFamily.begin(), wordFamily.end(), '_') <= maxGuesses - numberOfGuesses) {
            currentWordFamily.push_back(word);
        }
    }
    currentWordList = currentWordFamily;
}

std::string EvilHangman::findWord() {
    if (currentWordList.empty()) {
        state = playerWin;
        return "";
    }

    std::srand(static_cast<unsigned>(std::time(nullptr)));
    int randomIndex = std::rand() % currentWordList.size();
    wordToGuess = currentWordList[randomIndex];
    currentWordList.erase(currentWordList.begin() + randomIndex);

    wordLength = wordToGuess.length();
    displayString = std::string(wordLength, '_');
    return wordToGuess;
}

EvilHangman::EvilHangman() : Hangman() {
}

EvilHangman::~EvilHangman() {
 
}
