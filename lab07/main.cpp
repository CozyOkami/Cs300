#include "Evilhangman.h"  // Include the EvilHangman header instead of Hangman
#include <iostream>

int main() {
    EvilHangman game;  // Create an instance of EvilHangman

    std::cout << "Welcome to Evil Hangman!" << std::endl;  // Update the welcome message

    char playAgain;
    do {
        game.play();
        std::cout << "Play again? (y/n): ";
        std::cin >> playAgain;
        if (playAgain == 'y' || playAgain == 'Y') {
            game = EvilHangman(); // Reset the game (EvilHangman)
        }
    } while (playAgain == 'y' || playAgain == 'Y');

    std::cout << "Thank you for playing Evil Hangman!" << std::endl;  // Update the thank you message

    return 0;
}
