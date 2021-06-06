#include <string>
#include <iostream>
#include <regex>

#include "Radius.h"
using namespace std;

float Radius(string Figure)
{
		float R = 0;
		if ((strstr(Figure.c_str(), "C")) || (strstr(Figure.c_str(), "c"))) {
        cmatch result;
        regex regular(
                "(\\s*)"
                "(c|C)"
                "(i|I)"
                "(r|R)"
                "(c|C)"
                "(l|L)"
                "(e|E)"
                "([\\s]*)"
                "(\\()"
                "(\\s*)"
                "([0-9]*[.]?[0-9]+)"
                "(\\s*)"
                "([0-9]*[.]?[0-9]+)"
                "(\\s*)"
                "(\\,)"
                "(\\s*)"
                "([0-9]*[.]?[0-9]+)"
                "(\\s*)"
                "(\\))");
        if (regex_match(Figure.c_str(), result, regular)){
        	R = stof(result.str(17));
		}
	}
	return R;
}
