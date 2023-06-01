#include <iostream>
#include <string>
#include <sstream>
#include "Board.h"

int getUserPosition();

int main() {
    Board board = Board();
    bool isRunning = true;
    std::string userInput;

    do {
        board.print();
        board.printBoardPositions();
        int position = getUserPosition();

        try {
            board.playerMove(position);
            if (board.hasWinner()) {
                std::string message = "Player ";
                message += board.getWinnerSymbol();
                message += " is the winner";

                std::cout << message << std::endl;
                isRunning = false;
            } else if (board.hasTie()) {
                std::cout << "The game ended in a tie." << std::endl;
                isRunning = false;
            } else {
                board.computerMove();
            }
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    } while (isRunning);

    return 0;
}

int getUserPosition() {
    std::string userInput;
    int position = 0;

    while (true) {
        std::cout << "You have the symbol \"X\". It's your move [1-9]: ";
        std::getline(std::cin, userInput);
        std::stringstream ss(userInput);
        if (ss >> position) {
            break;
        }
        std::cout << "Only integers in the range [1,9] are accepted.\n";
    }

    return position;
}