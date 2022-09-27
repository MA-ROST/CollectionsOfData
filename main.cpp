// CollectionsOfData.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "myHeartWillGoOn.h"
#include "theProgramWithinYou.h"
#include "moreProgramsWithinYou.h"
#include "programWithinYou.h"
#include "userInput.h"

int main ()
{
    do {
        switch ( cinInt (
            "Which program would you like to run?\n"
            "(myHeartWillGoOn = 1, theProgramWithinYou = 2, "
            "moreProgramsWithinYou = 3, programsWithinYou = 4): \n", BR_GREEN) ) {
            case 1: programMHWGO(); // myHeartWillGoOn
                break;
            case 2: programTPWY(); // theProgramWithinYou
                break;
            case 3: programMPWY(); // moreProgramsWithinYou
                break;
            case 4: bioinformatics::program(); // programsWithinYou
                break;
            default: conOut("Invalid input", BR_RED);
                break;
        }
        conOut ("\n\n");
    } while ( true );
}
