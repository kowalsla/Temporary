#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <thread>
#include <fstream>
#include <cstring>
#include <vector>

enum operations_t
{
    START = 0,
    SUM,                           //any number of input args
    MULTIPLICATION,                // any number of input args
    XOR,                           // 2 parameters
    POWER,                         // 2 param[in], param1 ^ param2
    FACTORIAL,                     // 1 param
    FIBONACCI,                     // 1 param
    FIRST_PRIME_NUMBER,            // 1 param, find first prime number
    HIGHEST_PRIME_NUMBER_LT_PARAM, // the highest pm lower than given parameter
    DISTANCE_AXIS,                 // distance between two points on coordinate axis, 4 param in (x1, y1, x2, y2)
    COUNT_BINARY_ONES,             // count ones in binary representation of given parameter
    CHECKSUM                       //checksum of given parameter
};

#endif //COMMON_H