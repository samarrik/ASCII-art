#include <iostream>
#include "convertToAscii.h"
#include "presentResults.h"
#include "readConfig.h"

int main(int argc, char *argv[])
{

    // Initialize a storage
    CStorage images;

    try
    {
        /**
         * The function reads the configuration file which was provided to the application
         * @param[in] images A container where images will be stored
         * @exception runtime_error May throw a runtime error if the config file doesn't match the example or files
         * which were provided to the program don't exist/are broken
         */
        readConfig(images);

        /**
         * The function converts images to ASCII-arts, saves results in %name of the image%.txt files
         * @param[in] images A container of images to be converted
         * @exception runtime_error May throw a runtime error if files which were provided to the program don't
         * exist/are broken
         */
        convertToAscii( images );

        /**
         * The function communicates with a user and presents the results of conversion
         * @param[in] images A container of images to be presented
         * @exception runtime_error May throw a runtime error if files with converted images don't exist/ are broken
         */
        presentResults( images );
    }
    //Catches all possible errors the program  may throw
    catch (std::exception & e )
    {
        std::cout << "ERROR: " << e.what() << std::endl;
    }

    return EXIT_SUCCESS;
}