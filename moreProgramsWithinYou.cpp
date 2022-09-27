/*
 * A mutation is a mistake that occurs during the creation or copying of a nucleic acid like DNA. The simplest and most common type
 * of nucleic acid mutation is a point mutation, which replaces a single nucleotide with another. The Hamming Distance between two
 * DNA strings is the number of corresponding symbols that differ between the strings.
 *
 * The following two strings have a Hamming distance of 7, meaning that there exist 7 point mutations between the two. The point
 * mutations are shown in red:
 *
 * Write a program that when given two DNA strings returns the Hamming distance between the strings.
 *
 * Sample input:
 * GAGCCTACTAACGGGAT
 * CATCGTAATGACGGCCT
 *
 * Sample Output:
 * Hamming Distance Between DNA Strings: 7
 */

#include "moreProgramsWithinYou.h"

#include <array>
#include <string>

#include "userInput.h"

std::array<std::string, 2> debugVectorAdd()
{
	// Adds data provided in the example
	std::array <std::string, 2> dnaStrings = {"GAGCCTACTAACGGGAT", "CATCGTAATGACGGCCT"};
	return dnaStrings;
}

int determineArrayDifference(std::array<std::string, 2> strings)
{
	int hammingDistance {0};

	// Using the size of the string in the array,
	// we compare both strings. for every difference found,
	// increase the hammingDistance by one
	// (Assumes perfect user)
	for ( int i = 0; i < strings[0].size(); ++i) {
		if (strings[0][i] != strings[1][i]) {
			hammingDistance++;
		}
	}

	return hammingDistance;
}

void programMPWY() {

	std::array <std::string, 2> input;

	if (debugMode()) { input = debugVectorAdd(); }
	else {
		input[0] = cinChar("Input DNA 1: ");
		input[1] = cinChar("Input DNA 2: ");
	}

	conOut(input[0] + "\n" + input[1] + "\n");
	conOut ("Hamming Distance Between DNA Strings: " + std::to_string (
		determineArrayDifference (input)));
}