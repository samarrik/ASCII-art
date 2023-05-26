#ifndef PRESENTRESULTS
#define PRESENTRESULTS

#include <vector>
#include "cimage.h"
#include "cstorage.h"
#include <cmath>
#include <iostream>

using namespace std;

/**
 * The function communicates with a user and presents the results of conversion
 * @param[in] images A container of images to be presented
 * @exception runtime_error May throw a runtime error if files with converted images don't exist/ are broken
 */
void presentResults( CStorage &images );

#endif //PRESENTRESULTS
