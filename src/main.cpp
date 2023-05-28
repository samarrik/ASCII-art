#include <iostream>
#include "convertToAscii.h"
#include "presentResults.h"
#include "readConfig.h"
#include "cstorage.h"

using namespace std;

int main( int argc, char* argv[] )
{
    // Initialing storage
    static CStorage images;

    if ( argc < 2 ) {
        cerr << "\033[1;31mThe config file wasn't provided to the converter\033[0m" << endl;
        return EXIT_FAILURE;
    } else if ( argc > 2 ){
        cerr << "\033[1;31mToo many arguments were provided to the converter\033[0m" << endl;
        return EXIT_FAILURE;
    } else {
        //Save the name of the config file
        images.saveConfig( argv[1] );
    }

    try
    {
        //Read configuration
        readConfig(images);

        //Convert images
        convertToAscii( images );

        //Present converted images
        presentResults( images );
    }

    //Catches all possible errors the program may throw
    catch (exception & e )
    {
        cout << "\033[1;31mERROR: " << string(e.what()).append("\033[0m") << endl;
    }

    return EXIT_SUCCESS;
}