#include "token.h"
std::string Token::to_str() const
{
    std::string repr = "token: " + std::to_string(int(type)) + " " + lexeme + " " + std::to_string(line) + " " + literal.s;
    return repr;
}
