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
	std::regex regexp("([0-9]+)-([0-9]+) ([a-z]): ([a-z]+)");
	std::smatch m;
	int numberOfValidPasswords = 0;

	for (int i = 0; i < numberOfLines; i++) {
		std::regex_search(lines[i], m, regexp);
		int lower = std::stoi(m.str(1));
		int upper = std::stoi(m.str(2));
		char letter = m.str(3)[0];
		std::string password = m.str(4);
		int numberOfLetters = 0;
		for (std::size_t j = 0; j < password.size(); j++) {
			if (password[j] == letter) numberOfLetters++;
		}

		if ((numberOfLetters >= lower) && (numberOfLetters <= upper)) {
			numberOfValidPasswords++;
		}
	}
	std::cout << "First task: " << numberOfValidPasswords << std::endl;
	return 0;
}
