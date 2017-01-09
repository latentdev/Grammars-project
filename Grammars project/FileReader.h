#pragma once
#ifndef _FileReader_H_INCLUDED_
#define _FileReader_H_INCLUDED_

class FileReader;

#include <fstream>
#include <string>
#include <iostream>
#include <boost/algorithm/string.hpp>

class FileReader
{
private:
	//holds our program in string form
	std::string * program;

public:
	//default constructor
	FileReader();
	//constructor
	FileReader(std::string filename);
	//reads program in from file
	void ReadProgram();
	//reads the string and takes out formatting characters
	void ReplaceStringInPlace(const std::string& search, const std::string& replace);
	//calls ReplaceStringInPlace twice to take out \n and \t
	void CleanseString();
	// getter for program
	std::string getProgram();
	//destructor
	~FileReader();

};

#endif