#include "cscale.h"

using namespace std;

CScale::CScale ( int src )
{
    if ( src != -100 )
        m_scale = src;
}

void CScale::apply( CImage & src ){

    //Check if the scale is in the "valid" range
    if ( m_scale > 10 || m_scale < -10 ) {
        throw out_of_range("The scale value is out of the range");
    } else {
        //Checking if there is a sense in performing an algo at all (if the scale fill be changed)
        if (m_scale != 0) {

            //Calculate how much the image will be scaled
            unsigned scaled_height, scaled_width;
            if (m_scale < 0) {
                scaled_height = src.height() / (-m_scale);
                scaled_width = src.width() / (-m_scale);
            } else {
                scaled_height = src.height() * (m_scale + 1);
                scaled_width = src.width() * (m_scale + 1);
            }

            //Prepare an array for scaled image
            auto * scaled_image = new unsigned char[scaled_height * scaled_width * 4];

            //Load an unscaled image
            unsigned char * src_image = src.getPixels();

            //Scaling
            for (unsigned y = 0; y < scaled_height; y++) {
                for (unsigned x = 0; x < scaled_width; x++) {
                    // Find the corresponding pixel in the source image
                    unsigned src_x, src_y;
                    if (m_scale < 0) {
                        src_x = x * (-m_scale);
                        src_y = y * (-m_scale);
                    } else {
                        src_x = x / (m_scale + 1);
                        src_y = y / (m_scale + 1);
                    }

                    if (src_x < src.width() && src_y < src.height()) {
                        unsigned original = (src_y * src.width() + src_x) * 4;

                        // Copy RGBA values from source to scaled image
                        unsigned scaled = (y * scaled_width + x) * 4;
                        scaled_image[scaled]     = src_image[original];
                        scaled_image[scaled + 1] = src_image[original + 1];
                        scaled_image[scaled + 2] = src_image[original + 2];
                        scaled_image[scaled + 3] = src_image[original + 3];
                    }
                }
            }

            // Delete the previous image
            delete [] src_image;

            // Load the scaled image data
            src.loadScaledData(scaled_image, scaled_width, scaled_height);
        }
    }
}

CFilter * CScale::clone( ){
    return new CScale (*this);
}