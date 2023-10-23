#ifndef HANGMAN_H
#define HANGMAN_H

#include <string>
#include <vector>

class Hangman {
public:
    int numberOfGuesses;
    int maxGuesses;
    int wordLength;
    std::string wordToGuess;
    std::string displayString;
    std::string lettersGuessed;
    bool showRemainingWords;
    bool gameRunning;
    
    enum GameState {
        inPlay,
        playerWin,
        playerLose
    };
    GameState state;

    std::vector<std::string> dictionary;
    std::vector<std::string> currentWordList;

    std::string findWord();
    void updateDisplayString(char guess);
    bool isGuessCorrect(char guess);
    void checkState();

public:
    Hangman();
    ~Hangman();

    void displayBoard();
    void handleInput();
    void turn();
    void play();
    std::string getWordToGuess();
};

#endif
