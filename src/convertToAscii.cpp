#include "convertToAscii.h"

using namespace std;

void convertToAscii (CStorage & images ) {
    //Apply filters to all images we've saved
    for ( auto image : images.getImages() ){
        image->applyFilters();
        image->grayscale();
    }
    cout << "\033[1;33mProcess: \033[0m" << "\033[1;32m[===      ]\033[0m" << endl;

    //Convert pixel-data to text
    for ( auto image : images.getImages() ){
        image->asciiConversion();
    }
    cout << "\033[1;33mProcess: \033[0m" << "\033[1;32m[======   ]\033[0m" << endl;

    //3. delete previous data
    //TODO:

    //Load ascii arts in files
    for ( auto image : images.getImages() ) {
        ofstream outputFile;
        string output_name;
        for ( auto ch : image->getFileName()){
            if ( ch != '.'){
                output_name.push_back(ch);
            } else break;
        }
        output_name.append(".txt");
        outputFile.open(output_name, ios::out);
        if (outputFile.is_open()) {
            image->saveToFile( outputFile );
        } else {
            throw runtime_error("The output file can't be created");
        }
        outputFile.close();
    }
    cout << "\033[1;33mProcess: \033[0m" << "\033[1;32m[=========]\033[0m" << endl;
    cout << "\033[1;33mDONE!\033[0m" << endl;
}