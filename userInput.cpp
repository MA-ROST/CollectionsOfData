#include <iostream> // for std::cout & std::cin
#include <limits>   // for std::numeric_limits
#include <string>   // for std::string
#include <algorithm>
#include "userInput.h"

using std::string;
using std::cout;
using std::cin;

void clearCin () {
	// No number found so clear the cin error flag:
	cin.clear();
	// Ignore remaining user input to reset stream for the next try.
	cin.ignore (std::numeric_limits <std::streamsize>::max(), '\n');
}

string toUppercase (string input) {
	string output;
	std::transform (output.begin(), output.end(), output.begin(),
	                [](unsigned char c) { return std::toupper (c); });

	return output;
}

bool hasChars (string input) {
	for ( int i{0}; i < input.length(); i++ ) {
		if ( input[i] != 'A' && input[i] != 'T' && input[i] != 'C' && input[i]
			!= 'G' ) {
			clearCin();
			return false;
		}
	}
	return true;
}

bool isValid (const string input) {
	for ( int i{0}; i < input.length(); i++ ) {
		if ( input[i] != '0' && input[i] != '1' ) {
			clearCin();
			return false;
		}
	}
	return true;
}

// Using unicode, clears the console
void clear () {
	cout << "\x1B[2J\x1B[H";
}

string cinChar (const string question) {
	return cinChar (question, WHITE);
}

string cinChar (const string question, int color) {
	string input;

	do {
		conOut (question, color);
		cin >> input;
		toUppercase (input);
		if ( hasChars (input) ) { break; }
	} while ( true );

	return input;
}


string cinStr (const string question) {
	return cinStr (question, WHITE);
}

string cinStr (const string question, int color) {
	string input;

	do {
		conOut (question, color);
		cin >> input;
		if ( isValid (input) ) { break; }
	} while ( true );

	return input;
}

bool cinBool (const string question) {
	return cinBool (question, WHITE);
}

bool cinBool (const string question, int color) {
	char input = 'y';

	do {
		conOut (question, color);
		cin >> input;

		if		( input == 'y' || input == 'Y') { return true; }
		else if ( input == 'n' || input == 'N') { return false; }

		clearCin();
		conOut ("Invalid. Submit y or n\n", BR_RED);
	} while ( true );
}

int cinInt (const string question) {
	return cinInt (question, WHITE);
}

int cinInt (const string question, int color) {
	int input;

	do {
		conOut (question, color);
		if ( cin >> input ) { break; }
		else { conOut ("Please submit a number\n", BR_RED); }

		clearCin();
	} while ( true );

	return input;
}

float cinFloat (const string question) {
	return cinFloat (question, WHITE);
}

float cinFloat (const string question, int color) {
	float input;

	do {
		conOut (question, color);
		if ( cin >> input ) { break; }
		else { conOut ("Please submit a number\n", BR_RED); }

		clearCin();
	} while ( true );

	return input;
}


#include "Windows.h"   // WinApi header

void conOut (const string question) {
	cout << question;
}

void conOut (const string question, int color) {
	changeConsoleColor (color);
	cout << question;
	changeConsoleColor (WHITE);
}

void changeConsoleColor (int color) {
	HANDLE hConsole = GetStdHandle (STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (hConsole, color);
}

bool debugMode () {
	return cinBool ("Would you like Debug mode? (y/n): ", BR_GREEN);
}
