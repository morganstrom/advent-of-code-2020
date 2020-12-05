#include <iostream>
#include <string>
#include <vector>
#include "utils.h"

unsigned long countTrees(std::vector<std::string> map, int stepsRight, int stepsDown) {
	int numberOfRows = map.size();
	int numberOfCols = map[0].size();
	int col = 0;
	unsigned long numberOfTrees = 0;
	for (int row = 0; row < numberOfRows; ) {
		row += stepsDown;
		col += stepsRight;
		if (col >= numberOfCols) {
			col = col % numberOfCols;
		}
		if (map[row][col] == '#') numberOfTrees++;
	}
	return numberOfTrees;
}

int day3(std::string inputPath) {
	std::vector<std::string> lines = readFileToStringVector(inputPath);
	unsigned long slope1 = countTrees(lines, 3, 1);
	unsigned long slope2 = countTrees(lines, 1, 1);
	unsigned long slope3 = countTrees(lines, 5, 1);
	unsigned long slope4 = countTrees(lines, 7, 1);
	unsigned long slope5 = countTrees(lines, 1, 2);
	unsigned long slopeProduct = slope1 * slope2 * slope3 * slope4 * slope5;
	std::cout << "First task: " << slope1 << std::endl;
	std::cout << "Second task: " << slopeProduct << std::endl;
	return 0;
}
