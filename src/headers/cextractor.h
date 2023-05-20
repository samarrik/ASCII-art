#ifndef EXTRACTOR
#define EXTRACTOR

#include "cimage.h"

/**
 * An abstract base class for all parsers
*/
class CExtractor {

    public:
        //An abstract base class won't have a constructor
        CExtractor() = delete;

        //A vitual destructor which ensures deletion of the instance of the right child class
        virtual ~CExtractor();

        /**
         * A virtual method reads image data from the file
         * //@param[in] 
         * @param[out] CImage& Returns a newly created instance of CImage filled with image data
        */
        virtual CImage & read() = 0;
};
#endif //EXTRACTOR