#include "CheckCircle.h"

#include <iostream>
#include <regex>
#include <string>

using namespace std;

bool CheckCircle(string Figure)
{
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
        if (regex_match(Figure.c_str(), result, regular))
            return true;

        else
            return false;

    } else
        return false;
}

