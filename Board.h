#ifndef TICTACTOE_BOARD_H
#define TICTACTOE_BOARD_H

class Board {
private:
    const char OPEN_POSITION = '*';
    const int COLUMNS = 3;
    const int ROWS = 3;
    char _board[9]{'*', '*', '*', '*', '*', '*', '*', '*', '*',};
    char _playerSymbol;
    char _computerSymbol;
    char _winnerSymbol;

    bool isPositionAvailable(int index);
    void ensureValidMove(int position);

public:
    Board() : _playerSymbol('X'), _computerSymbol('O'), _winnerSymbol('\0') {}

    void print();

    void printBoardPositions() const;

    void playerMove(int position);

    void computerMove();

    bool hasWinner();

    bool hasTie();

    [[nodiscard]] char getWinnerSymbol() const {
        return _winnerSymbol;
    }
};


#endif //TICTACTOE_BOARD_H
