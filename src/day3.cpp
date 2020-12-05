#include <iostream>
#include <string>
#include <vector>
#include "utils.h"

long countTrees(std::vector<std::string> map, int stepsRight, int stepsDown) {
	int numberOfRows = map.size();
	int numberOfCols = map[0].size();
	int col = 0;
	long numberOfTrees = 0;
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
	long firstTask = countTrees(lines, 3, 1);
	long secondTask = firstTask * countTrees(lines, 1, 1) * countTrees(lines, 5, 1) * countTrees(lines, 7, 1) * countTrees(lines, 1, 2);
	std::cout << "First task: " << firstTask << std::endl;
	std::cout << "Second task: " << secondTask << std::endl;
	return 0;
}
