#include <iostream>

#include "ProgramWithinYou.h"

namespace bioinfo
{
	std::array <std::string, 2> debugStrings ()
	{
		return {"GAGCCTACTAACGGGAT", "CATCGTAATGACGGCCT"};
	}


	std::array <int, 4> countNucleotides (std::string input)
	{
		// 0:A 1:T 2:C 3:G
		std::array <int, 4> count{0, 0, 0, 0};

		for ( int i = 0; i < nucleotides.size(); ++i ) {
			count[i] = std::count (input.begin(), input.end(), nucleotides[i]);
		}

		return count;
	}

	int determineArrayDifference (std::array <std::string, 2> strings)
	{
		int hammingDistance{0};

		// Using the size of the string in the array,
		// we compare both strings. for every difference found,
		// increase the hammingDistance by one
		// (Assumes perfect user)
		for ( int i = 0; i < strings[0].size(); ++i ) {
			if ( strings[0][i] != strings[1][i] ) { hammingDistance++; }
		}

		return hammingDistance;
	}

	bool isSameLegnth (std::array <std::string, 2> strings)
	{
		if ( strings[0].size() == strings[1].size() ) { return true; }
		return false;
	}

	bool isValidChar (std::string str)
	{
		for ( int i = 0; i < str.size(); ++i ) {
			if ( str[i] != 'A' || str[i] != 'T' || str[i] != 'C' || str[i] !=
				'G' ) { return false; }
		}
		return true;
	}

	bool isValidChars (std::array <std::string, 2> strings)
	{
		for ( auto index : strings ) {
			if ( !isValidChar (index) ) { return false; }
		}
		return true;
	}

	void program ()
	{
		std::array <std::string, 2> userIn;

		if ( debugMode() ) { userIn = debugStrings(); }
		else {
			do {
				userIn[0] = cinChar("Input DNA 1: ");
				userIn[1] = cinChar("Input DNA 2: ");

				if ( isSameLegnth (userIn) && isValidChars (userIn) ) { break; }
				else {
					conOut (
						"Badly formatted input! Make sure input is valid and strings are the same length!\n",
						BR_RED);
				}
			} while ( true );
			
		}

		std::array <std::array <int, 4>, 2> out{0, 0, 0, 0};
		out[0] = countNucleotides (userIn[0]);
		out[1] = countNucleotides (userIn[1]);

		conOut (userIn[0] + "\n" + userIn[1] + "\n");

		for ( int i = 0; i < out.size(); ++i ) {
			for ( int j = 0; j < out[i].size(); ++j ) {
				std::cout << nucleotides[j];
				conOut (" = " + std::to_string (out[i][j]) + ", ");
			}
			conOut ("\n");
		}

		conOut ("Hamming Distance Between DNA Strings: " + std::to_string (
			determineArrayDifference (userIn)));
	}
}
