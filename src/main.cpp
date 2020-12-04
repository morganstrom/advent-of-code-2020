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
		case 1:
			day1("data/day1.txt");
			break;
		case 2:
			day2("data/day2.txt");
			break;
	}
	return 0;
}
