#include "token.h"
std::string Token::to_str() const
{
	std::map<TokenType, std::string> token_to_string;
	for(const auto& key_value: string_to_token)
	{
		token_to_string.insert(std::make_pair(key_value.second, key_value.first));
	}

	std::string repr = "token_type: " + token_to_string[type]
		+ " lexeme: " + lexeme
		+ " line: " + std::to_string(line);

	if(type == STRING)
		repr += " value: " + literal.s;
	else if(type == NUMBER)
		repr += " value: " + std::to_string(literal.n);
    return repr;
}
