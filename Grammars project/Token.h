#pragma once
#ifndef _Token_H_INCLUDED_
#define _Token_H_INCLUDED_

class Token;

#include <string>
#include <iostream>
#include <iomanip>


class Token
{
private:
	//holds a token
	std::string * token;
	//holds the type of token
	std::string * type;
public:
	//default constructor
	Token();
	//constructor
	Token(std::string in_token, std::string in_type);
	//displays the token and the type in proper format
	void Display();
	//destructor
	~Token();
};

#endif