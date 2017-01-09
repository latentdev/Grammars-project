#include "Tokenizer.h"
#include "FileReader.h"

//sets all variables to null
Tokenizer::Tokenizer()
{
	program = nullptr;
	ident_library = nullptr;
	symbols_library = nullptr;
	operator_library = nullptr;
	number_library = nullptr;
	tokens = nullptr;
}

// is passed our program in a string and sets program equal to it. We read in the individual libraries and set them to the correct variables
Tokenizer::Tokenizer(std::string in_program)
{
	program = new std::string(in_program);
	FileReader * reader = new FileReader("ident.txt");
	ident_library = new std::string(reader->getProgram());
	reader->~FileReader();
	reader = new FileReader("symbols.txt");
	symbols_library = new std::string(reader->getProgram());
	reader->~FileReader();
	reader = new FileReader("operators.txt");
	operator_library = new std::string(reader->getProgram());
	reader->~FileReader();
	reader = new FileReader("numbers.txt");
	number_library = new std::string(reader->getProgram());
	reader->~FileReader();
}

//parse through string comparing a character to different libraries and calling appropriate function for further parsing.
void Tokenizer::ParseString(std::string in_program)
{
	int pos = 0;
	tokens = new std::list<Token>();
	while (pos!=in_program.length())
	{
		if (in_program[pos] == '\"'|| in_program[pos] == '\'')
		{
			std::string token;
			token += in_program[pos];
			std::string type = "Symbol";
			Token * temp = new Token(token, type);
			tokens->push_back(*temp);
			
			pos = parseStringLit(in_program, ++pos);
		}
		else if (operator_library->find(in_program[pos]) != std::string::npos)
		{
			pos = parseOperator(in_program, pos);
		}		
		else if (number_library->find(in_program[pos]) != std::string::npos)
		{
			pos = parseNumber(in_program, pos);
		}
		else if (ident_library->find(in_program[pos]) != std::string::npos)
		{
			pos = parseIdent(in_program, pos);
		}
		else if (symbols_library->find(in_program[pos]) != std::string::npos)
		{
			pos = parseSymbol(in_program,pos);
		}
		else if (in_program[pos] == ' ')
		{
			pos++;
		}
		else
		{
			std::string token;
			token += in_program[pos];
			addToken(token, "Not Recognized");
			pos++;
		}
	}
}

//parse an operator
int Tokenizer::parseOperator(std::string in_program, int pos)
{
	std::string Operator;
	while (operator_library->find(in_program[pos]) != std::string::npos)
	{
		Operator += in_program[pos];
		pos++;
	}
	addToken(Operator, "Symbol");
	return pos;
}

//parse a number
int Tokenizer::parseNumber(std::string in_program, int pos)
{
	std::string Number;
	std::string NumberType="Int";
	while (number_library->find(in_program[pos]) != std::string::npos)
	{
		if (in_program[pos] == '.')
		{
			NumberType = "Float";
		}
		Number += in_program[pos];
		pos++;
	}

	addToken(Number, NumberType);
	return pos;
}

//parse an Identity
int Tokenizer::parseIdent(std::string in_program, int pos)
{
	std::string Identifier;
	while (ident_library->find(in_program[pos]) != std::string::npos)
	{
		Identifier+=in_program[pos];
		pos++;
	}
	addToken(Identifier, "Identifier");
	return pos;
}

//parse a Symbol
int Tokenizer::parseSymbol(std::string in_program, int pos)
{
	std::string token;
	token += in_program[pos];
	addToken(token, "Symbol");
	return ++pos;
}

//parse a string literal
int Tokenizer::parseStringLit(std::string in_program, int pos)
{
	std::string type;
	std::string StringLit;
	while (in_program[pos] != '\"')
	{
		StringLit += in_program[pos];
		pos++;
	}
	addToken(StringLit, "String Literal");
	std::string token;
	token += in_program[pos];
	addToken(token, "Symbol");
	return ++pos;
}

// create a new token with a token and type and add it to the list
void Tokenizer::addToken(std::string in_token, std::string in_type)
{
	Token * temp = new Token(in_token, in_type);
	tokens->push_back(*temp);
}

//create iterator and iterate through the list calling the each token's display function
void Tokenizer::displayTokens()
{
	std::cout << std::setw(25) << std::right << "Token" << " | " << std::setw(25) << std::left << "Type" << std::endl;
	std::cout << "-----------------------------------------------------" << std::endl;

	for (std::list<Token>::iterator iterator = tokens->begin(), end = tokens->end(); iterator != end; ++iterator) 
	{
		iterator->Display();
	}
}

//make sure the variables aren't already null and delete if not
Tokenizer::~Tokenizer()
{
	if (program != nullptr)
	{
		delete program;
	}
	if (symbols_library != nullptr)
	{
		delete symbols_library;
	}
	if (ident_library != nullptr)
	{
		delete ident_library;
	}
	if (operator_library != nullptr)
	{
		delete operator_library;
	}
	if (number_library != nullptr)
	{
		delete number_library;
	}
	if (tokens != nullptr)
	{
		for (std::list<Token>::iterator iterator = tokens->begin(), end = tokens->end(); iterator != end; ++iterator)
		{
			iterator->~Token();
		}
	}
}