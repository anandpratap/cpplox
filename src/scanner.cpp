#include <iostream>
#include "scanner.h"
#include "token.h"
#include "utils.h"

char Scanner::advance()
{
    current += 1;
    return source[current-1];
}

char Scanner::peek()
{
    if(is_at_end()) return '\0';
    return source[current];
}

char Scanner::peek_next()
{
    if(current + 1 >= source.size()) return '\0';
    return source[current+1];
}

void Scanner::add_token(TokenType type)
{
    add_token(type, LiteralObject());
}

bool Scanner::match(char expected)
{
    if(current==source.size()-1) return false;
    if(source[current] != expected) return false;
    current += 1;
    return true;
}
void Scanner::add_token(TokenType type, LiteralObject literal)
{
    auto text = source.substr(start, current - start);
    tokens.push_back(Token(type, text, literal, line));
}

bool Scanner::is_at_end()
{
    return current == source.size();
}

void Scanner::string()
{
    while(peek() != '"' && !is_at_end())
    {
        if (peek() == '\n') line++;
        advance();
    }
    if(is_at_end())
    {
        std::cout<<"string not terminated"<<std::endl;
        return;
    }
    advance();
    LiteralObject literal;
    literal.s = source.substr(start+1, current - start - 2);
    add_token(STRING, literal);
}

void Scanner::number() {
	while(isdigit(peek())) advance();
	if(peek() == '.' && isdigit(peek_next()))
	{
		advance();
		while(isdigit(peek())) advance();
	}
	LiteralObject literal;
	literal.n = std::stod(source.substr(start, current - start));
	add_token(NUMBER, literal);
}

void Scanner::identifier()
{
	while(isalpha_numeric(peek())) advance();
	auto text = source.substr(start, current - start);
	TokenType type;
	try
	{
		type = string_to_token.at(text);
	}
	catch(std::out_of_range e)
	{
		type = IDENTIFIER;
	}
	add_token(type);
}

void Scanner::scan_token()
{
    char current_char = advance();
    switch(current_char)
    {

	case '(': add_token(LEFT_PAREN); break;
	case ')': add_token(RIGHT_PAREN); break;
	case '{': add_token(LEFT_BRACE); break;
	case '}': add_token(RIGHT_BRACE); break;
	case ',': add_token(COMMA); break;
	case '.': add_token(DOT); break;
	case '-': add_token(MINUS); break;
	case '+': add_token(PLUS); break;
	case ';': add_token(SEMICOLON); break;
	case '*': add_token(STAR); break;
	case '!':
        add_token(match('=') ? BANG_EQUAL : BANG); break;
	case '=':
        add_token(match('=') ? EQUAL_EQUAL : EQUAL); break;
	case '<':
        add_token(match('=') ? LESS_EQUAL : LESS); break;
	case '>':
        add_token(match('=') ? GREATER_EQUAL : GREATER); break;
	case '/':
        if (match('/')) {
            // A comment goes until the end of the line.
            while (peek() != '\n' && !is_at_end()) advance();
        }
        else {
            add_token(SLASH);
        }
        break;
	case ' ':
	case '\r':
	case '\t':
        // Ignore whitespace.
        break;
	case '"': string(); break;
	case '\n': line++; break;

	default:
		if(isdigit(current_char))
		{
			number();
		}
		else if(isalpha(current_char))
		{
			identifier();
		}
		else
		{
			std::cout<<"not found line: "<<line<<std::endl; break;
		}
    }
}

void Scanner::scan_tokens()
{
    size_t nchar = source.size();
    while(current < nchar)
    {
        start = current;
        scan_token();
    }
    tokens.push_back(Token(TokenType::EOFF, "", LiteralObject(), line));
}

void Scanner::print_tokens()
{
    for(const auto& token: tokens)
    {
        std::cout<<token.to_str()<<std::endl;
    }
}
