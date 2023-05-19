#include <iostream>
#include "asciiConverter.h"
#include "readConfig.h"

void runPresentation(CStorage &images)
{

}

int main(int argc, char *argv[])
{

    // Initialize a storage
    CStorage images;

    try
    {
        // Process the config.txt file
        readConfig(images);

        // Make a conversion for all files provided, show statistcs
        //  asciiConverter( images );

        // Ask the user if he wants a presentation, if so, show it
        //  runPresentation( images );
    }
    catch (std::exception & e )
    {
        std::cout << "ERROR: " << e.what() << std::endl;
    }

    return EXIT_SUCCESS;
}