#include <iostream>
#include <fstream>
#include <string>

int day4(std::string inputPath) {
	std::ifstream inputFile(inputPath);
	if (inputFile.is_open()) {
		std::string line;
		while (std::getline(inputFile, line)) {
			// match keys with expected fields (byr, iyr, eyr, hgt, hcl, ecl, pid)
			// if line.size() == 0, then new passport
			std::cout << line.size() << std::endl;	
		}
		inputFile.close();
	}
	return 0;
}
