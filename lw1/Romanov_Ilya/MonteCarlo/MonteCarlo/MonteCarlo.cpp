#include "stdafx.h"
#include <iostream>
#include "PiGenerator.h"
#include <String>

void PrintHelpInfo() {
	std::cout << "To run application pass two arguments.\nFormat: MonteCarlo.exe <count of iterations> <count of threads>\n";
}

int main(int argc, char* argv[]) {
	try {
		unsigned int startTime = clock();
		if (argc != 3 || argv[1] == "--help")
		{
			PrintHelpInfo();
			return 1;
		}
		size_t iterations = atoi(std::string(argv[1]).c_str());
		size_t threads = atoi(std::string(argv[2]).c_str());
		PiGenerator generator(iterations, threads);
		std::cout << generator.GetPiValue() << std::endl;
		std::cout << "Runtime: " << clock() - startTime << "(mls)" << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
		return 1;
	}

    return 0;
}

