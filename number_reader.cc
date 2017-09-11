#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(void) {
	
	// Declare file variables
	std::string filename;
	std::ifstream inFile;
	
	// File open loop
	while (!inFile.is_open()) {
		std::cout << "Enter your file name: ";
		std::getline(std::cin, filename);
		inFile.open(filename);
		if (!inFile.is_open() || inFile.fail()) {
			std::cerr << "Could not open \"" << filename << "\". Please try again." << std::endl;
			inFile.clear();
		}
	}
	
	// Declare and initalize working variables
	auto numberCount = 0;
	double firsts[] = {0.0, 0.0};	// Set to zero in case 0 or 1 doubles found
	double lasts[] = {0.0, 0.0};
	
	// File read loop
	while (!inFile.eof()) {
		
		double currentNumber;
		if (inFile >> currentNumber) {
			
			// If numberCount < 2, then we must be in the first two doubles
			if (numberCount < 2) {
				firsts[numberCount] = currentNumber;
			}
			// For each iteration of this loop, shift the elements of lasts
			lasts[0] = lasts[1];
			lasts[1] = currentNumber;
			
			numberCount++;
		}
	}
	
	inFile.close();
	
	std::cout << "The first two doubles were " << firsts[0] << " and " << firsts[1] << "\n"
			"and the last two were " << lasts[0] << " and " << lasts[1] << "\n"
			"A total of " << numberCount << " doubles were found." << std::endl;
	
	return 0;
}
