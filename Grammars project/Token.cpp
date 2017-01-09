#include "Token.h"

//sets token and type to null
Token::Token()
{
	token = nullptr;
	type = nullptr;
}
//sets token and type to the passed in variables
Token::Token(std::string in_token, std::string in_type)
{
	token = new std::string(in_token);
	type = new std::string(in_type);
}
//formats the stream and outputs the token and type
void Token::Display()
{

	std::cout << std::setw(25)<<std::right<< *token << " | " << std::setw(25)<<std::left<< *type << std::endl;
}
//checks to make sure the pointers aren't null. if not delete them.
Token::~Token()
{
	if (token != nullptr)
	{
		delete token;
	}
	if (type != nullptr)
	{
		delete type;
	}
}