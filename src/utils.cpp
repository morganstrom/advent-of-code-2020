#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> readFileToStringVector(std::string path) {
	std::vector<std::string> stringArray;
	std::string line;
	std::ifstream inputfile(path);

	while (std::getline(inputfile, line)) {
		stringArray.push_back(line);
	}
	inputfile.close();
	return stringArray;
}
