#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<int> readFileToIntVector(std::string path) {
	std::vector<int> intArray;
	std::string line;
	std::ifstream inputfile(path);

	for (int result; std::getline(inputfile, line); result = std::stoi(line)) {
		intArray.push_back(result);
	}
	return intArray;
}

int productOfTwo(std::vector<int> integers) {
	int numberOfIntegers = integers.size();
	int product;
	for (int i = 0; i < numberOfIntegers; i++) {
		for (int j = i + 1; j < numberOfIntegers; j++) {
			int sum;
			sum = integers[i] + integers[j];
			if (sum == 2020) {
				product = integers[i] * integers[j];
				break;
			}
		}
	}
	return product;
}

int productOfThree(std::vector<int> integers) {
	int numberOfIntegers = integers.size();
	int product;
	for (int i = 0; i < numberOfIntegers; i++) {
		for (int j = i + 1; j < numberOfIntegers; j++) {
			for (int k = j + 1; k < numberOfIntegers; k++) {
				int sum;
				sum = integers[i] + integers[j] + integers[k];
				if (sum == 2020) {
					product = integers[i] * integers[j] * integers[k];
					break;
				}
			}
		}
	}
	return product;
} 

int day1(std::string inputPath){
	std::vector<int> integers = readFileToIntVector(inputPath);
	int firstTask = productOfTwo(integers);
	std::cout << "First task: " << firstTask << "\n";
	int secondTask = productOfThree(integers);
	std:: cout << "Second task: " << secondTask << "\n";
	return 0;
}
