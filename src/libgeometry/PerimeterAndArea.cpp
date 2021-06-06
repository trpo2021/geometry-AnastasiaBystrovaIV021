#include "PerimeterAndArea.h"

#include <math.h>
#include <string>
#include <iostream>
#include <regex>

#define pi 3.14159265358979323846

using namespace std;

float Perimeter (float R)
{
	float Perimeter;
	Per = 2 * pi * R;
	return Perimeter;
}

float Area (float R)
{
	float Area;
	Area = pi * R  * R;
	return Area;
}
