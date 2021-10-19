#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

void log(std::string log){std::cout << "| LOG | " + log << std::endl;}
void err(std::string err){std::cout << "| ERR | " + err << std::endl;}
void dbg(std::string dbg) { std::cout << "| DBG | " + dbg << std::endl;}