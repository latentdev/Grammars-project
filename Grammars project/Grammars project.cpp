// Grammars project.cpp : Defines the entry point for the console application.
// Author: Nick Olson
// Date: 12/5/2016
// Class: CST 229
// Program: Lexical Analyzer for C#. Ruleset can be changed by changing out library files.
//			You can use any program, but there are a few provided test.cs, Program.cs, InOut.cs and SQL.cs
//			Be warned SQL.cs is quite large and is mildly annoying to scroll to the top.
//

#include <iostream>
#include "FileReader.h"
#include "Tokenizer.h"


int main()
{	
	bool quit = false;
	while (!quit)
	{
		std::string filename;
		std::cout << "Please enter a filename to parse or type 'exit' to quit: ";
		std::cin >> filename;
		FileReader * reader = new FileReader(filename);
		reader->ReadProgram();
		Tokenizer * tokenizer = new Tokenizer(reader->getProgram());
		tokenizer->ParseString(reader->getProgram());
		reader->~FileReader();
		tokenizer->displayTokens();
		tokenizer->~Tokenizer();
		if (filename == "exit")
		{
			quit = true;
		}
		filename = "";
		
	}
	
    return 0;
}

