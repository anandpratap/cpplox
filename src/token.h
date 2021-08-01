#pragma once
#include <string>
#include <map>
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


static std::map<std::string, TokenType> string_to_token = {
														   {"(", LEFT_PAREN},
														   {")", RIGHT_PAREN},
														   {"{", LEFT_BRACE},
														   {"}", RIGHT_BRACE},
														   {",", COMMA},
														   {".", DOT},
														   {"-", MINUS},
														   {"+", PLUS},
														   {";", SEMICOLON},
														   {"/", SLASH},
														   {"*", STAR},
														   {"!", BANG},
														   {"!=", BANG_EQUAL},
														   {"=", EQUAL},
														   {"==", EQUAL_EQUAL},
														   {">", GREATER},
														   {">=", GREATER_EQUAL},
														   {"<", LESS},
														   {"<=", LESS_EQUAL},
														   {"identifier", IDENTIFIER},
														   {"string", STRING},
														   {"number", NUMBER},
														   {"and", AND},
														   {"class", CLASS},
														   {"else", ELSE},
														   {"false", FALSE},
														   {"fun", FUN},
														   {"for", FOR},
														   {"if", IF},
														   {"nil", NIL},
														   {"or", OR},
														   {"print", PRINT},
														   {"return", RETURN},
														   {"super", SUPER},
														   {"this", THIS},
														   {"true", TRUE},
														   {"var", VAR},
														   {"while", WHILE},
														   {"eoff", EOFF}
};


struct LiteralObject{
    double n;
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
