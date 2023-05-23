#ifndef EXTRACTORPNG
#define EXTRACTORPNG

#include "png.h"
#include "cextractor.h"
#include <string>

class CExtractorPNG : public CExtractor {
    public:
        //Create an instance of the parser, prepare it for reading
        CExtractorPNG( const std::string & filename );

        //Delete an instance of the parser
        ~CExtractorPNG();

        unsigned get_width() const {
            return width;
        }

        unsigned get_height() const {
            return width;
        }

        unsigned char * get_pixels (){
            return pixels;
        }

        //Read data from the code
        void read() override;
    
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