#include <iostream>
#include "convertToAscii.h"
#include "presentResults.h"
#include "readConfig.h"
#include "cstorage.h"
#include "handler.h"
#include <csignal>

using namespace std;

int main(int argc, char *argv[])
{
    //Setting up a handler for Ctrl+C
    std::signal(SIGINT, handler);

    // Initialing storage
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

    //Catches all possible errors the program may throw
    catch (exception & e )
    {
        cout << "\033[1;31mERROR: " << string(e.what()).append("\033[0m") << endl;
    }

    return EXIT_SUCCESS;
}