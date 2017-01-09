#pragma once
#ifndef _Tokenizer_H_INCLUDED_
#define _Tokenizer_H_INCLUDED_

class Tokenizer;

#include <string>
#include <list>
#include "Token.h"

class Tokenizer
{
private:
	//holds our program in string form
	std::string * program;
	// holds our librar of symbols
	std::string * symbols_library;
	//holds our library of Identity characters
	std::string * ident_library;
	//holds our librar of operators
	std::string * operator_library;
	//holds our number characters
	std::string * number_library;
	//list of tokens
	std::list<Token> * tokens;
public:
	//Default Constructor
	Tokenizer();
	//Constructor
	Tokenizer(std::string in_program);
	//Parse the inputted program
	void ParseString(std::string in_program);
	//Parse an operator
	int parseOperator(std::string in_program, int pos);
	//Parse a number
	int parseNumber(std::string in_program, int pos);
	//Parse an Identity
	int parseIdent(std::string in_program, int pos);
	//Parse a Symbol
	int parseSymbol(std::string in_program, int pos);
	//Parse a String Literal
	int parseStringLit(std::string in_program, int pos);
	//Create a Token object and store the token and type in it. Add to list of Tokens
	void addToken(std::string in_token, std::string in_type);
	//iterate through our list of token objects and call display on each one.
	void displayTokens();
	//destructor
	~Tokenizer();
};
#endif