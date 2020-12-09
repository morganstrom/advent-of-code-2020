#include <iostream>
#include <vector>
#include <string>
#include "utils.h"

int day5(std::string inputPath) {
	std::vector<std::string> lines = readFileToStringVector(inputPath);
	int numberOfBoardingPasses = lines.size();
	int maxSeatID = 0;
	for (int i = 0; i < numberOfBoardingPasses; i++) {
		int rowsLeft = 128;
		int row = 0;
		int colsLeft = 8;
		int col = 0;
		for (int j = 0; j < 10; j++) {
			if (j < 7) rowsLeft = rowsLeft / 2;
			if (lines[i][j] == 'B') row = row + rowsLeft;
			if (j >= 7) colsLeft = colsLeft / 2;
			if (lines[i][j] == 'R') col = col + colsLeft;
		}
		int seatID = row * 8 + col;
		if (seatID > maxSeatID) maxSeatID = seatID;
	}
	std::cout << "First task: " << maxSeatID << std::endl;
	return 0;
}
