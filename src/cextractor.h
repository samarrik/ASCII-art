#ifndef EXTRACTOR
#define EXTRACTOR

#include "cimage.h"

using namespace std;

/**
 * An abstract base class for all parsers
*/
class CExtractor {

    public:
        //An abstract base class won't have a constructor
        CExtractor(){}

        //A vitual destructor which ensures deletion of the instance of the right child class
        virtual ~CExtractor(){}

        /**
         * A virtual method reads code data from the file
        */
        virtual void read() = 0;
};
#endif //EXTRACTOR