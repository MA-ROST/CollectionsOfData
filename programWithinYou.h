#pragma once

#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include "userInput.h"

namespace bioinfo
{
	const std::array <char, 4> nucleotides = {'A', 'T', 'C', 'G'};
	std::array <std::string, 2> debugStrings ();

	std::array <int, 4> countNucleotides (std::string input);

	int determineArrayDifference (std::array <std::string, 2> strings);

	// Checks if the two strings the same legnth
	bool isSameLegnth (std::array <std::string, 2> strings);
	// Checks if the string only contains the given chars
	bool isValidChar (std::string str);

	void program ();
}


