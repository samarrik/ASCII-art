#ifndef READCONFIG
#define READCONFIG

#include <vector>
#include "cimage.h"

/**
 * The function reads the configuration file which was provided to the application
 * @param[in] images A container where images will be stored
 * @exception runtime_error May throw a runtime error if the config file doesn't match the example or files
 * which were provided to the program don't exist/are broken
 */
void readConfig( std::vector<CImage> &images );

#endif //READCONFIG