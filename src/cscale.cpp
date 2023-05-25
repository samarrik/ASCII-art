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
    if ( m_scale > 5 || m_scale < -5 ) {
        throw out_of_range("The scale value is out of the range");
    } else {
        //Checking if there is a sense in performing an algo at all
        if ( m_scale != 0 ) {

            //Scaling using nearest neighbour :)

            //Finding the scale factor
            double scale_factor;
            if ( m_scale >= 0 ) {
                scale_factor = (0.1 * m_scale) + 1;
            } else {
                scale_factor = 1 - (0.1 * m_scale);
            }

            auto scaled_height = static_cast<unsigned>(src.height() * scale_factor);
            auto scaled_width = static_cast<unsigned>(src.height() * scale_factor);

            auto * scaled_image = new unsigned char [ scaled_height * scaled_width * 4 ];
            unsigned char * src_image = src.getPixels();

            for ( unsigned i = 0; i < scaled_height * scaled_width * 4; i += 4 ){
                unsigned j = i/scale_factor;
                scaled_image[ i ] =     src_image[ j ];
                scaled_image[ i + 1 ] = scaled_image[ j + 1 ];
                scaled_image[ i + 2 ] = scaled_image[ j + 2 ];
                scaled_image[ i + 3 ] = scaled_image[ j + 3 ];
            }
            //delete the previous image; !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            src.loadScaledData( scaled_image, scaled_width, scaled_height );
        }
    }
    cout << "Scale was set!" << endl;
}

CFilter * CScale::clone( ){
    return new CScale (*this);
}