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

int validatePassword1(std::smatch match) {
	int lower = std::stoi(match.str(1));
	int upper = std::stoi(match.str(2));
	char letter = match.str(3)[0];
	std::string password = match.str(4);

	int numberOfLetters = 0;
	for (std::size_t j = 0; j < password.size(); j++) {
		if (password[j] == letter) numberOfLetters++;
	}
	
	if ((numberOfLetters >= lower) && (numberOfLetters <= upper)) {
		return 1;
	} else {
		return 0;
	}
}

int validatePassword2(std::smatch match) {
	int pos1 = std::stoi(match.str(1)) - 1;
	int pos2 = std::stoi(match.str(2)) - 1;
	char letter = match.str(3)[0];
	std::string password = match.str(4);

	int numberOfMatches = 0;
	if (password[pos1] == letter) numberOfMatches++;
	if (password[pos2] == letter) numberOfMatches++;
	if (numberOfMatches == 1) {
		return 1;
	} else {
		return 0;
	}
}

int day2(std::string inputPath) {
	std::vector<std::string> lines = readFileToStringVector(inputPath);
	int numberOfLines = lines.size();
	std::regex regexp("([0-9]+)-([0-9]+) ([a-z]): ([a-z]+)");
	std::smatch m;
	int numberOfValidPasswords1 = 0;
	int numberOfValidPasswords2 = 0;

	for (int i = 0; i < numberOfLines; i++) {
		std::regex_search(lines[i], m, regexp);
		numberOfValidPasswords1 += validatePassword1(m);
		numberOfValidPasswords2 += validatePassword2(m);
	}
	std::cout << "First task: " << numberOfValidPasswords1 << std::endl;
	std::cout << "Second task: " << numberOfValidPasswords2 << std::endl;
	return 0;
}
