#include <iostream>
#include "Libraries.hpp"
#include "Tokeniser.hpp"

using namespace std;
using namespace Parser;

int main(int argc, char* argv[])
{
	p_dbg_msg("Rosewheels intepreter started");

	
	FILE* fh = fopen("C:\\Users\\Ethan\\Desktop\\code\\Rosewheels\\Rosewheels_samples\\test.rsw", "r");
	if (!fh) { p_err_msg(" Could not open file "); }
	fseek(fh, 0, SEEK_END);
	size_t fileSize = ftell(fh);
	fseek(fh, 0, SEEK_SET);
	string fileContents(fileSize, ' ');
	fread((void*)fileContents.data(), 1, fileSize, fh);

	p_dbg_msg("File contents: \n|\n" + fileContents + " \n|");

	Tokeniser tokeniser;
	vector<Token> tokens = tokeniser.parse(fileContents);

	for (Token currentToken : tokens) {
		currentToken.DebugPrint();
	}

	return 0;
}