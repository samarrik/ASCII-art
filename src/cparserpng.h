#ifndef PARSERPNG
#define PARSERPNG

#include "png.h"
#include "cparser.h"
#include <string>

class CParserPNG : public CParser {
    public:
        //Create an instance of the parser, prepare it for reading
        CParserPNG( std::string filename );

        //Delete an instance of the parser
        ~CParserPNG();

        //Read data from the image
        CImage & read() override;
    
    private:
        std::string filename;
        unsigned char * pixels;
        png_structp png_ptr;
        png_infop info_ptr;
        unsigned width;
        unsigned height;
        int bit_depth;
        int color_type;
        int interlace_method;
        int compression_method;
        int filter_method;
};

#endif //PARSERPNG