#ifndef EXTRACTOR
#define EXTRACTOR

#include "cimage.h"

using namespace std;

/**
 * An abstract base class for all extractors
*/
class CExtractor {

    public:
        //An abstract base class won't have a constructor
        CExtractor() = default;

        //A virtual destructor which ensures deletion of the instance of the right child class
        virtual ~CExtractor() = default;

//        /**
//         * A virtual method reads code data from the file
//        */
//        virtual void read() = 0;
};
#endif //EXTRACTOR