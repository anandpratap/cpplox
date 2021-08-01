#pragma once
#include <string>
enum TokenType
{
    LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE, COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,
    // One or two character tokens.
    BANG, BANG_EQUAL, EQUAL, EQUAL_EQUAL,
    GREATER, GREATER_EQUAL, LESS, LESS_EQUAL,
    // Literals.
    IDENTIFIER, STRING, NUMBER,
    // Keywords.
    AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NIL, OR,
    PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE,
    EOFF
};

struct LiteralObject{
    float n;
    std::string s;
};
class Token{
    public:
    Token(TokenType type, std::string lexeme, LiteralObject literal, int line)
    : type(type), lexeme(lexeme), literal(literal), line(line){};
    std::string to_str() const;
    private:
    TokenType type;
    std::string lexeme;
    LiteralObject literal;
    int line;
};