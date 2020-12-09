#include <iostream>
#include <string>
#include <stdexcept>
#include "days.h"

int main(int argc, char *argv[]) {
	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " DAY (1-24)" << std::endl;
		return 1;
	}
	std::cout << "Day " << argv[1] << ":\n";
	int day = std::stoi(argv[1]);
	switch (day) {
		case 0:
			std::cout << "Days aren't zero-indexed, nerd!" << std::endl;
			break;
		case 1:
			day1("./data/day1.txt");
			break;
		case 2:
			day2("./data/day2.txt");
			break;
		case 3:
			day3("./data/day3.txt");
			break;
		case 4:
			day4("data/day4_test.txt");
			break;
		case 5:
			day5("data/day5.txt");
			break;
		default:
			std::cout << "No solution (yet)" << std::endl;
	}
	return 0;
}
