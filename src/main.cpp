#include <iostream>
#include "convertToAscii.h"
#include "presentResults.h"
#include "readConfig.h"
#include "sstorage.h"

using namespace std;

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
    catch (exception & e )
    {
        cout << "ERROR: " << e.what() << endl;
    }

    return EXIT_SUCCESS;
}