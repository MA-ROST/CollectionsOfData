#include <array>
#include <iostream>
#include <cfenv>
#include <cmath>
#include "misc.h"

int floatToInt(float number) {
	std::fesetround(FE_UPWARD);
	int toInt = std::nearbyintf (number);
	return toInt;
}