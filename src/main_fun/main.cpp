#include <iostream>
#include "../headers/convertToAscii.h"
#include "../headers/presentResults.h"
#include "../headers/readConfig.h"
#include "../headers/sstorage.h"

int main(int argc, char *argv[])
{
    // Initialize a storage
    SStorage images;

    try
    {
        //Read configuration
        readConfig(images);

        //Convert images
        convertToAscii( images );

        //Present converted images
        presentResults( images );
    }
    //Catches all possible errors the program  may throw
    catch (std::exception & e )
    {
        std::cout << "ERROR: " << e.what() << std::endl;
    }

    return EXIT_SUCCESS;
}