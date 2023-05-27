#ifndef EXTRACTOR
#define EXTRACTOR

#include "cimage.h"
#include <algorithm>

using namespace std;
/**
 * An abstract base class for all extractors
*/
class CExtractor {
    public:
        CExtractor() = default;

        //A virtual destructor which ensures deletion of the instance of the right child class
        virtual ~CExtractor() = default;

        /**
         * A virtual method reads code data from the file
        */
        virtual void read( const string & filename ) = 0;

        /**
        * Function gets the width of an image which was extracted
        * @return unsigned Image width
        */
        virtual unsigned get_width() const = 0;

        /**
        * Function gets the height of an image which was extracted
        * @return unsigned Image height
        */
        virtual unsigned get_height() const = 0;

        /**
        * Function gets pixels of an image which was extracted
        * @return unsigned Image pixels
        */
        virtual unsigned char * get_pixels () const = 0;
};
#endif //EXTRACTOR