#ifndef TICTACTOE_INVALID_POSITION_H
#define TICTACTOE_INVALID_POSITION_H

#include <string>
#include <exception>

class PositionNotAvailable : public std::exception {
private:
    std::string _message;
public:
    explicit PositionNotAvailable(std::string &message) : _message(message) {}

    [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return this->_message.c_str();
    }
};


#endif //TICTACTOE_INVALID_POSITION_H
