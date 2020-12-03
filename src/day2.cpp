#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

std::vector<std::string> readFileToStringVector(std::string path) {
	std::vector<std::string> stringArray;
	std::string line;
	std::ifstream inputfile(path);

	while (std::getline(inputfile, line)) {
		stringArray.push_back(line);
	}
	return stringArray;
}

int day2(std::string inputPath) {
	std::vector<std::string> lines = readFileToStringVector(inputPath);
	int numberOfLines = lines.size();
	std::regex regexp("-");
	std::smatch m;

	for (int i = 0; i < numberOfLines; i++) {
		std::regex_search(lines[i], m, regexp);
		std::cout << m.prefix().str() <<"\n";
		// Todo: extract max number, letter and code
		// Todo: count number of letters
		// Todo: compare number of letters to min and max
	}
	return 0;
}
