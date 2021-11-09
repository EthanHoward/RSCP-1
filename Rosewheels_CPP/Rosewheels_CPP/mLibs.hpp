#pragma once 
#include <Windows.h>

void s_cons_col(int col) {
    HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, col);
}

void p_err_msg(std::string log) {
	s_cons_col(5);
	std::cout << "[ERR] " + log << std::endl;
	s_cons_col(7);
}

std::string c_chrstr_str(char* str) {
	std::string rtstr;
	std::cin >> rtstr >> str;
	return rtstr;
}

LPCWSTR c_str_l(std::string str) {
	std::wstring wdstr = std::wstring(str.begin(), str.end());
	const wchar_t* wdcstr = wdstr.c_str();
	return wdcstr;
}

