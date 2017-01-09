#include "FileReader.h"

//default constructor. sets variable to null
FileReader::FileReader()
{
	*program = nullptr;
}
//constructor. takes a filname. opens file and reads it into a string. set program equal to the string read in.
FileReader::FileReader(std::string filename)
{
	std::ifstream ifs(filename);
	program = new std::string((std::istreambuf_iterator<char>(ifs)),
						(std::istreambuf_iterator<char>()));
}
//outputs the program for user verification then cleanses the string of formatting
void FileReader::ReadProgram()
{
	std::cout << *program<<std::endl;
	CleanseString();
}

//takes a string to look for and a string to replace the found term with
void FileReader::ReplaceStringInPlace(const std::string& search, const std::string& replace) {
	boost::replace_all(*program, search, replace);
}

//cleanses the string of formatting
void FileReader::CleanseString()
{
	ReplaceStringInPlace("\n", "");
	ReplaceStringInPlace("\t", "");
}

//getter for program
std::string FileReader::getProgram()
{
	return *program;
}

//destructor checks if the variable is null. if not delete it.
FileReader::~FileReader()
{
	if (program != nullptr)
	{
		delete program;
	}
}
