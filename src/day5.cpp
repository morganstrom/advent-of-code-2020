#include <iostream>
#include <vector>
#include <string>
#include "utils.h"

int day5(std::string inputPath) {
	std::vector<std::string> lines = readFileToStringVector(inputPath);
	std::sort(lines.begin(), lines.end(), std::less<std::string>());
	int numberOfBoardingPasses = lines.size();
	int maxSeatID = 0;
	int lastCol = 0;
	int missingSeatID;
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
		if ((col - lastCol) > 1) missingSeatID = seatID - 1;
		if (seatID > maxSeatID) maxSeatID = seatID;
		lastCol = col;
	}
	std::cout << "First task: " << maxSeatID << std::endl;
	std::cout << "Second task: " << missingSeatID << std::endl;
	return 0;
}
