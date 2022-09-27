#ifndef USERINPUT_H
#define USERINPUT_H

#include <string>   // for std::string
#include <vector>

#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define YELLOW 6
#define LIGHT_GRAY 7
#define DARK_GRAY 8
#define BR_BLUE 9
#define BR_GREEN 10
#define BR_CYAN 11
#define BR_RED 12
#define BR_MAGENTA 13
#define BR_YELLOW 14
#define WHITE 15
#define BG_BLACK 16
#define BG_BLUE 17
#define BG_GREEN 18
#define BG_CYAN 19
#define BG_RED 20
#define BG_MAGENTA 21
#define BG_YELLOW 22
#define BG_WHITE 23
#define BG_GRAY 24
#define BG_BR_BLUE 25

void clearCin();
void clear();
void clearLine();
void clearPrevLine();

std::string toUppercase(std::string input);
std::string toLowercase(std::string input);

bool isValid(const std::string input);
bool hasChars(std::string input);
std::string cinChar(const std::string question);
std::string cinChar(const std::string question, int color);

std::string cinStr(const std::string question);
std::string cinStr(const std::string question, int color);

int cinInt(const std::string question);
int cinInt(const std::string question, int color);

float cinFloat(const std::string question);
float cinFloat(const std::string question, int color);

bool cinBool(const std::string question);
bool cinBool(const std::string question, int color);

void conOut(const std::string question);
void conOut(const std::string question, int color);
void changeConsoleColor(int color);


bool debugMode();

#endif
