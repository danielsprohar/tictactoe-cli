#include "Board.h"
#include "InvalidMove.h"
#include "PositionNotAvailable.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

void Board::print() {
    std::cout << "Game board";

    const int size = this->ROWS * this->COLUMNS;
    for (int i = 0; i < size; ++i) {
        if (i % 3 == 0) {
            std::cout << "\n| ";
        }
        std::cout << this->_board[i] << " | ";
    }

    std::cout << std::endl;
}

void Board::printBoardPositions() const {
    std::cout << "\nPositions";

    const int size = this->ROWS * this->COLUMNS;
    for (int i = 0; i < size; ++i) {
        if (i % 3 == 0) {
            std::cout << "\n| ";
        }
        std::cout << i + 1 << " | ";
    }

    std::cout << std::endl;
}

void Board::playerMove(int position) {
    this->ensureValidMove(position);
    this->_board[position - 1] = this->_playerSymbol;
}

void Board::computerMove() {
    const auto now = std::chrono::system_clock::now();
    const auto seed = now.time_since_epoch().count();
    std::mt19937_64 generator(seed);
    std::uniform_int_distribution<int> distribution(1, 9);
    int position;

    while (true) {
        position = distribution(generator);
        if (this->_board[position - 1] == this->OPEN_POSITION) {
            this->_board[position - 1] = this->_computerSymbol;
            break;
        }
    }
}

bool Board::hasTie() {
    return std::all_of(
            std::begin(this->_board),
            std::end(this->_board),
            [this](char symbol) { return symbol == this->OPEN_POSITION; }
    );
}

bool Board::isPositionAvailable(int index) {
    return this->_board[index] == this->OPEN_POSITION;
}

void Board::ensureValidMove(int position) {
    if (position < 1 || position > 9) {
        std::string message = std::to_string(position) + " is NOT a valid position.";
        throw InvalidMove(message);
    }
    if (this->_board[position - 1] != this->OPEN_POSITION) {
        std::string message = std::to_string(position) + " is not available.";
        throw PositionNotAvailable(message);
    }
}

bool Board::hasWinner() {
    // Check the first row
    if (!this->isPositionAvailable(0) &&
        !this->isPositionAvailable(1) &&
        !this->isPositionAvailable(2) &&
        this->_board[0] == this->_board[1] &&
        this->_board[1] == this->_board[2]) {
        this->_winnerSymbol = this->_board[0];
        return true;
    }
    // Check the seconds row
    if (!this->isPositionAvailable(3) &&
        !this->isPositionAvailable(4) &&
        !this->isPositionAvailable(5) &&
        this->_board[3] == this->_board[4] &&
        this->_board[4] == this->_board[5]) {
        this->_winnerSymbol = this->_board[3];
        return true;
    }
    // Check the third row
    if (!this->isPositionAvailable(6) &&
        !this->isPositionAvailable(7) &&
        !this->isPositionAvailable(8) &&
        this->_board[6] == this->_board[7] &&
        this->_board[7] == this->_board[8]) {
        this->_winnerSymbol = this->_board[6];
        return true;
    }

    // Check the first column
    if (!this->isPositionAvailable(0) &&
        !this->isPositionAvailable(3) &&
        !this->isPositionAvailable(6) &&
        this->_board[0] == this->_board[3] &&
        this->_board[3] == this->_board[6]) {
        this->_winnerSymbol = this->_board[0];
        return true;
    }
    // Check the second column
    if (!this->isPositionAvailable(1) &&
        !this->isPositionAvailable(4) &&
        !this->isPositionAvailable(7) &&
        this->_board[1] == this->_board[4] &&
        this->_board[4] == this->_board[7]) {
        this->_winnerSymbol = this->_board[1];
        return true;
    }
    // Check the third column
    if (!this->isPositionAvailable(2) &&
        !this->isPositionAvailable(5) &&
        !this->isPositionAvailable(8) &&
        this->_board[2] == this->_board[5] &&
        this->_board[5] == this->_board[8]) {
        this->_winnerSymbol = this->_board[2];
        return true;
    }

    // Check the diagonal: top left to bottom right
    if (!this->isPositionAvailable(0) &&
        !this->isPositionAvailable(4) &&
        !this->isPositionAvailable(8) &&
        this->_board[0] == this->_board[4] &&
        this->_board[4] == this->_board[8]) {
        this->_winnerSymbol = this->_board[0];
        return true;
    }
    // Check the diagonal: bottom left to top right
    if (!this->isPositionAvailable(6) &&
        !this->isPositionAvailable(4) &&
        !this->isPositionAvailable(2) &&
        this->_board[6] == this->_board[4] &&
        this->_board[4] == this->_board[2]) {
        this->_winnerSymbol = this->_board[6];
        return true;
    }

    return false;
}