#ifndef READCONFIG
#define READCONFIG

#include <vector>
#include "cimage.h"
#include "cstorage.h"
#include "cextractorpng.h"
#include "cextractorjpeg.h"
#include <fstream>
#include <stdexcept>
#include <string>
#include <iostream>
#include "cbrightness.h"
#include "ccontrast.h"
#include "cgradient.h"
#include "cchannel.h"
#include "cscale.h"
#include "cnegative.h"

using namespace std;

/**
 * The function reads the configuration file which was provided to the application
 * @param[in] images A container where images will be stored
 * @exception runtime_error May throw a runtime error if the config file doesn't match the example or files
 * which were provided to the program don't exist/are broken
 */
void readConfig( CStorage &images );

/**
 * Function reads "global" parameters set in config.txt
 * @param[in] configFile fstream of config.txt
 * @param[in] default_filters code which will be used as default (being changed during this fun.)
 * @returns false When the end of file was read | other structure violations
*/
bool readGlobalSettings(ifstream & configFile, CStorage & images );

/**
 * A function which reads settings for images
 * @param[in] configFile An input filestream which carries data read from the config.txt file
 * @param[in] images A storage where data from images should be stored
 * @returns false When the end of file was read | other structure violations
 */
bool readImageSettings(ifstream &configFile, CStorage & images );

#endif //READCONFIG