#ifndef EXTRACTORPNG
#define EXTRACTORPNG

#include "png.h"
#include "cextractor.h"
#include <string>

class CExtractorPNG : public CExtractor {
    public:
        //Create an instance of the parser, prepare it for reading
        CExtractorPNG( std::string filename );

        //Delete an instance of the parser
        ~CExtractorPNG();

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

#endif //EXTRACTORPNG