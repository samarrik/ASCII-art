#include "handler.h"

using namespace std;

void handler(int signal){
    cout << "\033[1;31mDo you want to end the program before receiving the result? [y/n]\033[0m" << endl;

    string answer;
    while( true ){
        cin >> answer;
        if ( answer == "y" || answer == "Y" || answer == "YES" || answer == "yes" ){
            //TODO;
        } else if ( answer == "n" || answer == "N" || answer == "NO" || answer == "no" ) {
            //TODO;
        } else {
            cout << "\033[1;33mI don't understand you, repeat your message, write [y/Y/yes/YES/n/N/no/NO]\033[0m" << endl;
        }
    }
}