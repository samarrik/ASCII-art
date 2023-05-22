#include "../headers/convertToAscii.h"

void convertToAscii (SStorage & images ) {
    //Apply filters to all images we've saved
    for ( auto image : images.image_files ){
        image->applyFilters();
    }

    //2. covert to text
    //3. delete previous data
    //4. Load to the file
}