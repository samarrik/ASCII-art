#include "presentResults.h"

using namespace std;

void startPresentation( CStorage &images ) {
    vector<CImage*> images_to_present = images.getImages();
    int image_iterator = 0;
    while ( true ){
        image_iterator = abs(int(image_iterator % images_to_present.size()));
        images_to_present[image_iterator]->print();
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
                cout << "\033[1;32mThanks for using ASCII-converter by samarrik\033[0m" << endl;
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