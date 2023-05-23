#include "convertToAscii.h"
#include <fstream>
#include <iostream>

using namespace std;

void convertToAscii (SStorage & images ) {
    //Apply filters to all images we've saved
    for ( auto image : images.image_files ){
        image->applyFilters();
        image->grayscale();
    }


    //Convert pixel-data to text
    for ( auto image : images.image_files ){
        unsigned char * pixels = image->getPixels();
        string ascii;
        cout << "showGradient: " << image->getGradient() << endl;
        cout << "lengthGradient: " << image->lengthGradient() << endl;
        int cnt_store = 0; //!
        for ( int i = 0; i < image->width()*image->height()*4; i+= 4 ) {
            ascii.push_back((image->getGradient())[pixels[i] % image->lengthGradient()]);
//            cout << "char to store:" << (image->getGradient())[pixels[i] % image->lengthGradient()] << endl;
            cnt_store++;
        }
        cout << "to_store:" << cnt_store << endl;
        image->loadConvertedToAscii(ascii);
    }

    //3. delete previous data

    //4. Load to the file !!TEST
    ofstream outputFile;
    outputFile.open("output.txt", ios::out);
    CImage * image = images.image_files[0];
    if (outputFile.is_open()) {
        int cnt_write = 0; //!
        cout << "ascii string size:" << image->getonvertedToAscii().size() << endl;
        for ( unsigned i = 0, g = 0; i < image->height(); i++, g++ ){
            for ( unsigned j = 0; j < image->width(); j++, g++){
                outputFile << image->getonvertedToAscii()[g];
                outputFile << image->getonvertedToAscii()[g];
//                cout << "char to show:" << image->getonvertedToAscii()[g] << endl;
            cnt_write ++;
            }
            outputFile << '\n';
        }
        cout << "to_write:" << cnt_write << endl;
    } else {

    }
    outputFile.close();
}