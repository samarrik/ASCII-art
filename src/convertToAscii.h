#ifndef ASCIICONVERTER
#define ASCIICONVERTER

#include "cimage.h"
#include <vector>
#include "cstorage.h"

using namespace std;

/**
 * The function converts images to ASCII-arts, saves results in %name of the code%.txt files
 * @param[in] images A container of images to be converted
 * @exception runtime_error May throw a runtime error if files which were provided to the program don't
 * exist/are broken
 */
void convertToAscii ( SStorage & images );

#endif //ASCIICONVERTER