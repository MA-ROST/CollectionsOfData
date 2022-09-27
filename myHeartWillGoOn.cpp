#include <iostream>
#include <string>
#include <algorithm>    // std::copy
#include <iterator>
#include <vector>

#include "userInput.h"
#include "vector.h"
#include "misc.h"

/*
 * Create a program that prompts the user for a series of time deltas
 * representing heartbeats and then calculates their integer heart rate per minute.
 * The user will enter positive floating-point values representing the
 * number of seconds since the previous heartbeat. When the user enters -1 that means they are done entering values.
 * Values should be stored in a vector.
 *
 * Once the user has finished entering values your program will calculate the average time between their heartbeats
 * and their approximate number of heartbeats per minute. If they entered fewer than 10 times the program should
 * tell them they haven’t provided enough information.
 *
 * For example, if the user entered the following times, they should be told their heart rate is approximately 66 beats per minute.
 *
 * 0.950 0.925 0.919 0.920 0.915 0.911 0.912 0.913 0.908 0.907 0.905 0.900
 *
 * This is because the average of these numbers is 10.985 / 12 = 0.9154166666666667
 *
 * And the number of beats per minute will be 60 seconds / 0.9154166666666667 = 65.54 (Rounded to 66)
 */

std::vector<float> debugVectorAdd() {
	return {
		0.950, 0.925, 0.919, 0.920, 0.915, 0.911, 0.912, 0.913, 0.908, 0.907, 0.905,
		0.900
	};
}

float beatsPerMin (float number) {
	float seconds = 60;
	return seconds /= number;
}

void writeNum (std::vector<float> vector) {
	clear();

	conOut (
		"Please input a 3 decimal number representing your heartbeat. When you are done, please enter '-1'\n");
	int count = 1;
	do {
		const std::string counter = std::to_string (count) + ": ";
		const float answer = cinFloat (counter);

		if ( answer == -1 ) {
			if ( count < 10 ) {
				conOut ("Not enough info given\n", BR_RED);
			}
			else {
				break;
			}
		}
		else {
			count++;
			addToTail (answer, vector);
		}
	} while ( true );
}

void programMHWGO () {
	std::vector<float> inputtedNumbers;

	if ( debugMode() ) {
		inputtedNumbers = debugVectorAdd();
	}
	else { writeNum(inputtedNumbers); }

	printVector(inputtedNumbers);

	const float average = getAverageVector(inputtedNumbers);
	const float bpm = beatsPerMin (average);

	conOut (std::to_string (average) + "\n", BR_GREEN);

	conOut ("60 / " + std::to_string (average) + " = ", DARK_GRAY);
	conOut (std::to_string (floatToInt (bpm)), BR_GREEN);
}
