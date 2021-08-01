#pragma once

bool isdigit(char c)
{
	return c >= '0' && c <= '9';
}

bool isalpha(char c)
{
	return (c >= 'a' && c <= 'z') ||
		(c >= 'A' && c <= 'Z') || c == '_';
}

bool isalpha_numeric(char c) { return isdigit(c) || isalpha(c); }

