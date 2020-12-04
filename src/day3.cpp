#include <iostream>
#include <string>
#include <vector>
#include "utils.h"

int day3(std::string inputPath) {
	std::vector<std::string> lines = readFileToStringVector(inputPath);
	int numberOfRows = lines.size();
	int numberOfCols = lines[0].size();
	int row = 0;
	int col = 0;
	int numberOfTrees = 0;
	for (int i = 0; i < numberOfRows; i++) {
		row += 1;
		col += 3;
		if (col >= numberOfCols) {
			col = col % numberOfCols;
		}
		if (lines[row][col] == '#') numberOfTrees++;
	}
	std::cout << "First task: " << numberOfTrees << std::endl;
	return 0;
}
