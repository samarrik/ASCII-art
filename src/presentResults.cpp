#include "presentResults.h"

using namespace std;
/**
 * The function basically runs the presentation, communicates with the user,
 * moves pictures
 * @param images A CStorage with all image which were converted
 * @details Function asks user if he/she wants to move to the next/ prev picture or stop the presentation
 */
void startPresentation( CStorage & images ) {
    //Get image data
    int image_iterator = 0; //An iterator to control "slides"
    while ( true ){
        //If the presentation is on its end, show from the beginning
        image_iterator = abs(int(image_iterator % images.getImages().size()));

        //Print the image
        images.getImages()[image_iterator]->print();

        //Communication with the user
        string answer;
        while( true ){
            cout << "\033[1;33mNext image -> 'n', Prev image -> 'p', Quit -> 'q'\033[0m" << endl;
            cin >> answer;
            if ( answer == "n" || answer == "N" ){
                image_iterator++;
                break;
            } else if ( answer == "p" || answer == "P"  ) {
                image_iterator--;
               break;
            } else if ( answer == "q" || answer == "Q" ) {
                cout << "\033[1;32mOK! Results are already saved in files :)\033[0m" << endl;
                cout << "\033[1;32mThank you for using ASCII-converter by @samarrik\033[0m" << endl;
                return;
            } else {
                cout << "\033[1;33mI don't understand you, repeat your message, write:\033[0m" << endl;
                continue;
            }
        }
    }
}

void presentResults( CStorage &images ){
    cout << "\033[1;33mDo you want see the results of the conversion? [y/n]\033[0m" << endl;

    //Communication with the user
    string answer;
    while( true ){
        cin >> answer;
        if ( answer == "y" || answer == "Y" || answer == "YES" || answer == "yes" ){
            startPresentation( images );
            return;
        } else if ( answer == "n" || answer == "N" || answer == "NO" || answer == "no" ) {
            cout << "\033[1;32mOK! Results are already saved in files :)\033[0m" << endl;
            cout << "\033[1;32mThanks for using ASCII-converter by samarrik\033[0m" << endl;
            return;
        } else {
            cout << "\033[1;33mI don't understand you, repeat your message, write [y/Y/yes/YES/n/N/no/NO]\033[0m" << endl;
            continue;
        }
    }
}