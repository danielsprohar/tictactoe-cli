#ifndef TICTACTOE_INVALIDMOVE_H
#define TICTACTOE_INVALIDMOVE_H

#endif //TICTACTOE_INVALIDMOVE_H

#include <string>
#include <exception>

class InvalidMove : public std::exception {
private:
    std::string _message;
public:
    explicit InvalidMove(std::string &message) : _message(message) {}

    [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return this->_message.c_str();
    }
};