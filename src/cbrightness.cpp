#include "cfilter.h"
#include <stdexcept>

using namespace std;

CBrightness::CBrightness ( int src )
{
    //If the object was created without passing any data into it, the default value will be set automatically;
    if ( src != -100 ) {
        m_brightness = src; //If some value was passed into it, set it as value;
    }
}

void CBrightness::apply( CImage & src ){
    //Gets an array of pixels from a code
    unsigned char * pixels = src.getPixels();

    //Check if the brightness is in the "valid" range
    if ( m_brightness > 5 || m_brightness < -5 ) {
        throw out_of_range("The brightness value is out of the range");
    } else {
        //Changes the brightness of each pixel
        m_brightness *= 10;
        for ( unsigned i = 0; i < (src.width()*src.height()); i += 4 ){
            pixels[i] += m_brightness;
            pixels[i+1] += m_brightness;
            pixels[i+2] += m_brightness;
            //the fourth pixel is being skipped (A pixel)
        }
    }
}

CFilter & CBrightness::set_val( int src ){
    m_brightness = src;
    return *this;
}