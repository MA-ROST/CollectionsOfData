#include <algorithm>
#include <vector>
#include "theProgramWithinYou.h"
#include "userInput.h"

/*
 * DNA or Deoxyribonucleic Acid is the molecule inside of your cells carrying your genetic code. DNA has a double helix shape,
 * which is like a ladder twisted into a spiral. Each step of the ladder is a pair of nucleotides.
 * There are four types of nucleotides (called bases), Adenine (A), Thymine (T), Cytosine (C), Guanine (G).
 * In the world of bioinformatics (the computational processing of DNA information) DNA strands are often represented by
 * strings comprised of only the characters A, T, C, and G.
 *
 * Write a program that when a user types in a DNA string it returns the count for each type of nucleotide found in the string.
 *
 * Example input: AGCTTTTCATTCTGACTGCAACGGGCAATATGTCTCTGTGTGGATTAAAAAAAGAGTGTCTGATAGCAGC
 *
 * Example output: The Base Counts Are A:20 C:12 G:17 T:21
 */

int count (std::string input, char value)
{
	return std::count (input.begin(), input.end(), value);
}

std::string debugVectorAdd ()
{
	return "AGCTTTTCATTCTGACTGCAACGGGCAATATGTCTCTGTGTGGATTAAAAAAAGAGTGTCTGATAGCAGC";
}

void programTPWY ()
{
	std::string input;
	std::vector <char> nucleotides = {'A', 'T', 'C', 'G'};

	if ( debugMode() ) { input = debugVectorAdd(); }
	else { input = cinChar ("Input a string: "); }

	const int adenine  = count (input, 'A');
	const int cytosine = count (input, 'C');
	const int guanine  = count (input, 'G');
	const int thymine  = count (input, 'T');

	conOut (
		"A = " + std::to_string (adenine) + ", C = " + std::to_string (cytosine) +
		", G = " + std::to_string (guanine) + ", T = " + std::to_string (thymine));
}
