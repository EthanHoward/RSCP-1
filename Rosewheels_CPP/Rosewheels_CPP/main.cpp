#include <iostream>
#include <Windows.h>
#include "mLibs.hpp"

using namespace std;

int main(int argc, char *argv[]) {
	
	if (argv[1]) {
		cout << "@[0.8.3] Rosewheels .rs .rsw interpreter" << endl;
		string arguments = argv[1];
		if (arguments.find(".rsw", 3) != string::npos) {cout << "[   ] .rsw file supplied" << endl;}
		else if (arguments.find(".rs", 3) != string::npos) {cout << "[   ] .rs file supplied" << endl;}
		else  {
			p_err_msg("File does not have a Rosewheels extension, .rs or .rsw");
			MessageBox(0, L"File does not have a Rosewheels extension, .rs or .rsw", L"Rosewheels Interpreter Error", MB_ICONERROR);
		}
	} else {
		cout << "@[ERR] Please supply some arguments" << endl;
		abort();
	}
}