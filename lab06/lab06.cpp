#include <iostream>

class TicTacToe {
public:
    TicTacToe(char playerPiece) {
        // Build the board
        for (int i = 0; i < sizeof(board); i++)
            board[i] = char(i + 49);
        player = playerPiece;
        computer = (player == 'X') ? 'O' : 'X';
    }

    void play() {
        while (determineWinner() == '?' && !isFull()) {
            drawBoard();
            playerMove(getPlayerPosition());

            if (determineWinner() == '?' && !isFull()) {
                computerMove();
            }
        }
        char winner = determineWinner();
        drawBoard();

        if (winner == player)
            std::cout << "You won! Congratulations!";
        else if (winner == computer)
            std::cout << "You lost...sorry! Try again!";
        else
            std::cout << "Tie! Great playing!";
    }

private:
    void drawBoard() {
        std::cout << " " << board[0] << " | " << board[1] << " | " << board[2] << std::endl;
        std::cout << " " << board[3] << " | " << board[4] << " | " << board[5] << std::endl;
        std::cout << " " << board[6] << " | " << board[7] << " | " << board[8] << std::endl;
    }

    char determineWinner() {
        // Check rows
        for (int i = 0; i < 3; i++) {
            if (board[i] == board[i + 1] && board[i + 1] == board[i + 2])
                return board[i];
        }

        // Check columns
        for (int i = 0; i < 3; i++) {
            if (board[i] == board[i + 3] && board[i + 3] == board[i + 6])
                return board[i];
        }

        // Check diagonals
        if (board[0] == board[4] && board[4] == board[8])
            return board[0];
        if (board[2] == board[4] && board[4] == board[6])
            return board[2];

        return '?'; // No winner yet
    }

    void computerMove() {
        int bestMove = -1;
        int bestVal = -1000; // Initialize with a small value

        for (int i = 0; i < sizeof(board); i++) {
            if (isAvailable(char(i + 49))) {
                board[i] = computer;
                int moveVal = minimax(board, 0, false);
                board[i] = char(i + 49); // Undo the move

                if (moveVal > bestVal) {
                    bestMove = i;
                    bestVal = moveVal;
                }
            }
        }

        if (bestMove != -1) {
            board[bestMove] = computer;
        }
    }

    int minimax(char board[9], int depth, bool isMaximizingPlayer) {
        char result = determineWinner();

        if (result != '?') {
            if (result == computer) {
                return 1;
            } else if (result == player) {
                return -1;
            } else {
                return 0; // Tie
            }
        }

        if (isMaximizingPlayer) {
            int maxEval = -1000; // Initialize with a small value
            for (int i = 0; i < sizeof(board); i++) {
                if (isAvailable(char(i + 49))) {
                    board[i] = computer;
                    int eval = minimax(board, depth + 1, false);
                    board[i] = char(i + 49); // Undo the move
                    maxEval = std::max(maxEval, eval);
                }
            }
            return maxEval;
        } else {
            int minEval = 1000; // Initialize with a large value
            for (int i = 0; i < sizeof(board); i++) {
                if (isAvailable(char(i + 49))) {
                    board[i] = player;
                    int eval = minimax(board, depth + 1, true);
                    board[i] = char(i + 49); // Undo the move
                    minEval = std::min(minEval, eval);
                }
            }
            return minEval;
        }
    }

    void playerMove(char move) {
        int pos = int(move) - 49;
        board[pos] = player;
    }

    char getPlayerPosition() {
        char move;
        do {
            std::cout << "Enter a move (1-9): ";
            std::cin >> move;
        } while (!isAvailable(move));
        return move;
    }

    bool isAvailable(char pos) {
        int position = int(pos) - 48;
        if (board[position - 1] == pos)
            return true;
        return false;
    }

    bool isFull() {
        for (int i = 0; i < sizeof(board); i++) {
            if (board[i] == char(i + 49))
                return false;
        }
        return true;
    }

    char board[9];
    char player;
    char computer;
};

int main() {
    char piece;
    std::cout << "Do you want to be X or O? ";
    std::cin >> piece;
    TicTacToe gameOn(piece);
    gameOn.play();
    return 0;
}
