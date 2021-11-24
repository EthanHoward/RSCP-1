#include <iostream>
#include "Libraries.hpp"

using namespace std;

int main(int argc, char *argv[])
{
	p_dbg_msg("Rosewheels intepreter started");
	if (argc <= 1 || argc == NULL) p_err_msg("No arguments supplied");
	else if (argc == 2) {
		//file supplied
		if (c_chrstr_str(argv[1]).find(".rsw") != std::string::npos) {
			p_dbg_msg(".rsw file supplied");
		} else if (c_chrstr_str(argv[1]).find(".rs") != std::string::npos) {
			p_dbg_msg(".rs file supplied");
		}
		else {
			p_err_msg("This is not a supported file type");
		}
	}
	else {
		p_err_msg("Unknown Error");
	}
}