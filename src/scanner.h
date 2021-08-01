#pragma once
#include <string>
#include <vector>
#include "token.h"

class Scanner{
private:
    std::string source;
    std::vector<Token> tokens;

	size_t start = 0;
    size_t current = 0;
    size_t line = 1;

	void scan_token();
    char advance();
    void add_token(TokenType itype);
    void add_token(TokenType type, LiteralObject literal);
    bool match(char expected);
    bool is_at_end();
    char peek();
	char peek_next();
    void string();
	void number();
	void identifier();

public:
    Scanner(std::string source) : source(source){};
    void scan_tokens();
	void print_tokens();
};
