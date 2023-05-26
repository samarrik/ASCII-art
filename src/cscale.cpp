#include "cscale.h"

using namespace std;

CScale::CScale ( int src )
{
    if ( src != -100 )
        m_scale = src;
}

void CScale::apply( CImage & src ){
    cout << "Scale" << endl;
    //Check if the scale is in the "valid" range
    if ( m_scale > 10 || m_scale < -10 ) {
        throw out_of_range("The scale value is out of the range");
    } else {
        //Checking if there is a sense in performing an algo at all
        if (m_scale != 0) {
            // Scaling using nearest neighbor

            // Calculate scaled dimensions
            unsigned scaled_height, scaled_width;
            if (m_scale < 0) {
                scaled_height = src.height() / (-m_scale);
                scaled_width = src.width() / (-m_scale);
            } else {
                scaled_height = src.height() * (m_scale + 1);
                scaled_width = src.width() * (m_scale + 1);
            }

            auto * scaled_image = new unsigned char[scaled_height * scaled_width * 4];
            unsigned char * src_image = src.getPixels();

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
                        unsigned src_index = (src_y * src.width() + src_x) * 4;

                        // Copy RGBA values from source to scaled image
                        unsigned scaled_index = (y * scaled_width + x) * 4;
                        scaled_image[scaled_index] = src_image[src_index];
                        scaled_image[scaled_index + 1] = src_image[src_index + 1];
                        scaled_image[scaled_index + 2] = src_image[src_index + 2];
                        scaled_image[scaled_index + 3] = src_image[src_index + 3];
                    }
                }
            }

            // Delete the previous image
            delete [] src_image;

            // Load the scaled image data
            src.loadScaledData(scaled_image, scaled_width, scaled_height);
        }
    }
    cout << "Scale was set!" << endl;
}

CFilter * CScale::clone( ){
    return new CScale (*this);
}