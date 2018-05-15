#include "stdafx.h"
#include <iostream>
#include "PiGenerator.h"
#include <string>
#include <omp.h>

void PrintHelpInfo() {
	std::cout << "To run application pass two arguments.\nFormat: MonteCarlo.exe <count of iterations>\nPrint --one after arguments list for run this application in one thread\n";
}

int main(int argc, char* argv[]) {
	try {
		unsigned int startTime = clock();
		if ((argc != 2 && argc != 3) || !std::string(argv[1]).compare("--help"))
		{
			PrintHelpInfo();
			return 1;
		}
		size_t iterations = atoi(std::string(argv[1]).c_str());
		PiGenerator generator(iterations);
		if (argc == 3 && !std::string(argv[2]).compare("--one")) {
			generator.SetMultithreading(false);
		}
		std::cout << generator.GetPiValue() << std::endl;
		std::cout << "Runtime: " << clock() - startTime << "(ms)" << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
		return 1;
	}

	return 0;
}

