#include <vector>
#include "vector.h"
#include "userInput.h"

#include <array>
#include <iostream>
#include <string>

using std::vector;

vector<float> addToTail (const float input, vector<float> vector) {
	vector.insert(vector.end(), input);
	return vector;
}

void breakUpString(const std::string input) {
	std::string delimiter = " ";
}

void printVector(std::vector<float> vector) {
	changeConsoleColor(3);
	for ( const auto num : vector) {
		std::cout << std::to_string(num) << " ";
	}
	std::cout << "\n";
	changeConsoleColor(15);
}

float getAverageVector(std::vector<float> vector) {
	float number = 0;
	for ( auto num : vector) {
		number += num;
	}
	float averageNum = number / vector.size();
	conOut(std::to_string(number) + " / " + std::to_string(vector.size()) + " = ", DARK_GRAY);
	return averageNum;
}

