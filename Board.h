#ifndef TICTACTOE_BOARD_H
#define TICTACTOE_BOARD_H

class Board {
private:
    const char OPEN_POSITION = '*';
    char _board[9]{'*', '*', '*', '*', '*', '*', '*', '*', '*',};
    char _playerSymbol;
    char _computerSymbol;
    char _winnerSymbol;

    [[nodiscard]] bool isPositionAvailable(int index) const;
    void ensureValidMove(int position) const;

public:
    Board() : _playerSymbol('X'), _computerSymbol('O'), _winnerSymbol('\0') {}

    void print() const;

    void printBoardPositions() const;

    void playerMove(int position);

    void computerMove();

    bool hasWinner();

    [[nodiscard]] bool hasTie() const;

    [[nodiscard]] char getWinnerSymbol() const {
        return _winnerSymbol;
    }
};


#endif //TICTACTOE_BOARD_H
