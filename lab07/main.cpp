#include "Evilhangman.h"
#include <iostream>

int main() {
    EvilHangman game;

    std::cout << "Welcome to Evil Hangman!" << std::endl;

    char playAgain;
    do {
        game.play();
        std::cout << "Play again? (y/n): ";
        std::cin >> playAgain;
        if (playAgain == 'y' || playAgain == 'Y') {
            game = EvilHangman();
        }
    } while (playAgain == 'y' || playAgain == 'Y');

    std::cout << "Thank you for playing Evil Hangman!" << std::endl;

    return 0;
}
