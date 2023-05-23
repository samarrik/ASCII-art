#include "convertToAscii.h"
#include <fstream>

void convertToAscii (SStorage & images ) {
    //Apply filters to all images we've saved
    for ( auto image : images.image_files ){
        image->applyFilters();
        image->grayscale();
    }

    //Convert pixel-data to text
    for ( auto image : images.image_files ){
        unsigned char * pixels = image->getPixels();
        std::string ascii;
        for ( int i = 0; i < image->width()*image->height(); i+= 4 ) {
            ascii.push_back((image->getGradient())[pixels[i] % image->lengthGradient()]);
        }
        image->loadConvertedToAscii(ascii);
    }

    //3. delete previous data

    //4. Load to the file !!TEST
    std::ofstream outputFile;
    outputFile.open("output.txt", std::ios::out);
    CImage * image = images.image_files[0];
    if (outputFile.is_open()) {
        for ( unsigned i = 0; i < image->height(); i++ ){
            for ( unsigned j = 0; j < image->width(); j++ ){
                outputFile << image->getonvertedToAscii()[j];
            }
            outputFile << '\n';
        }
    } else {

    }
    outputFile.close();
}