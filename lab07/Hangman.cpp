#include "Hangman.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

// Constructor
Hangman::Hangman() : numberOfGuesses(0), maxGuesses(6), wordLength(0), wordToGuess(""), displayString(""), lettersGuessed(""), showRemainingWords(true), gameRunning(true), state(inPlay) {
    // Initialize the dictionary with words
    std::ifstream dictionaryFile("dictionary.txt");
    std::string word;
    while (dictionaryFile >> word) {
        dictionary.push_back(word);
    }
    dictionaryFile.close();

    // Initialize the currentWordList with all words from the dictionary
    currentWordList = dictionary;
}

// Destructor
Hangman::~Hangman() {
    // Cleanup, if needed
}

// Private method to find a random word from the currentWordList
std::string Hangman::findWord() {
    if (currentWordList.empty()) {
        // No words left to guess, the player wins
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

// Private method to update the display string with correctly guessed letters
void Hangman::updateDisplayString(char guess) {
    for (int i = 0; i < wordLength; i++) {
        if (wordToGuess[i] == guess) {
            displayString[i] = guess;
        }
    }
}

// Private method to check if the guess is correct
bool Hangman::isGuessCorrect(char guess) {
    return wordToGuess.find(guess) != std::string::npos;
}

// Private method to check the game state
void Hangman::checkState() {
    if (displayString == wordToGuess) {
        state = playerWin;
    } else if (numberOfGuesses >= maxGuesses) {
        state = playerLose;
    }
}

// Public method to display the game board
void Hangman::displayBoard() {
    std::cout << "Word: " << displayString << std::endl;
    std::cout << "Guesses left: " << maxGuesses - numberOfGuesses << std::endl;
    std::cout << "Letters guessed: " << lettersGuessed << std::endl;
}

// Public method to handle player input
void Hangman::handleInput() {
    char guess;
    std::cout << "Enter a letter to guess: ";
    std::cin >> guess;
    lettersGuessed += guess;
    if (!isGuessCorrect(guess)) {
        numberOfGuesses++;
    }
    updateDisplayString(guess);
    checkState();
}

// Public method for a single turn of the game
void Hangman::turn() {
    displayBoard();
    handleInput();
}

// Public method to start and play the game
void Hangman::play() {
    while (gameRunning) {
        if (state == inPlay) {
            findWord();
            turn();
        } else if (state == playerWin) {
            std::cout << "You win! The word was: " << wordToGuess << std::endl;
            gameRunning = false;
        } else if (state == playerLose) {
            std::cout << "You lose! The word was: " << wordToGuess << std::endl;
            gameRunning = false;
        }
    }
}

// Public method to get the word to guess (for testing purposes)
std::string Hangman::getWordToGuess() {
    return wordToGuess;
}


