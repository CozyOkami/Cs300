#ifndef HANGMAN_H
#define HANGMAN_H

#include <string>
#include <vector>

class Hangman {
public:
    int numberOfGuesses;
    int maxGuesses; // Renamed from numberOfAllowedGuesses
    int wordLength;
    std::string wordToGuess; // Added to store the word to guess
    std::string displayString;
    std::string lettersGuessed; // Renamed from guessedLetters
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

    std::string findWord(); // Added to find a random word
    void updateDisplayString(char guess); // Added to update the display string
    bool isGuessCorrect(char guess); // Added to check if the guess is correct
    void checkState(); // Added to check the game state

public:
    Hangman();
    ~Hangman();

    void displayBoard();
    void handleInput();
    void turn();
    void play();
    std::string getWordToGuess(); // Added for testing purposes
};

#endif
