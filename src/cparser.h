#ifndef PARSER
#define PARSER

#include "cimage.h"

/**
 * An abstract base class for all parsers
*/
class CParser {

    public:
    //Default constructor
        CParser() = default;

        //A vitual destructor which ensures deletion of the instance of the right child class
        virtual ~CParser();

        /**
         * A virtual method reads image data from the file
         * //@param[in] 
         * @param[out] CImage& Returns a newly created instance of CImage filled with image data
        */
        virtual CImage & read() = 0;
};

#endif //PARSER