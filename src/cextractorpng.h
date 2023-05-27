#ifndef EXTRACTORPNG
#define EXTRACTORPNG

#include "png.h"
#include "cextractor.h"
#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

class CExtractorPNG : public CExtractor {
    public:
        CExtractorPNG() = default;

        ~CExtractorPNG() = default;

        /**
         * Function gets the width of an image which was extracted
         * @return unsigned Image width
         */
        unsigned get_width() const override ;

        /**
        * Function gets the height of an image which was extracted
        * @return unsigned Image height
        */
        unsigned get_height() const override;

        /**
        * Function gets pixels of an image which was extracted
        * @return unsigned Image pixels
        */
        unsigned char * get_pixels () const override;

        /**
        * Function reads data from the image
        */
        void read( const string & filename ) override;
    
    private:
        unsigned char * m_pixels;
        unsigned m_width;
        unsigned m_height;
};

#endif //EXTRACTORPNG