#include "Hello.h"

#include <iostream>

Hello::Hello() {}

void Hello::say()
{
	std::cout << "Generated by version: " << HELLO_VERSION << std::endl;
}