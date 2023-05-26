#include "cbrightness.h"

#define PIXEL_MAX 255 //max value the pixel's channel can store

using namespace std;

CBrightness::CBrightness ( int src )
{
    //If the object was created without passing any data into it, the default value will be set automatically;
    if ( src != -100 ) {
        m_brightness = src; //If some value was passed into it, set it as value;
    }
}

void CBrightness::apply( CImage & src ){

    //Get an array of pixels from a code
    unsigned char * pixels = src.getPixels();

    //Check if the brightness is in the "valid" range
    if ( m_brightness > 5 || m_brightness < -5 ) {
        throw out_of_range("The brightness value is out of the range");
    } else {

        //Add more weight to the brightness
        m_brightness *= 10;

        //Change the brightness of each pixel
        for ( unsigned i = 0; i < (src.width()*src.height()*4); i += 4 ){
            pixels[i] = min( pixels[i] + m_brightness,PIXEL_MAX);             //min function is used to prevent overflow of pixel value
            pixels[i+1] = min( pixels[i+1] + m_brightness,PIXEL_MAX);
            pixels[i+2] = min( pixels[i+2] + m_brightness,PIXEL_MAX);
            //the fourth pixel is being skipped (A pixel)
        }
    }
}

CFilter * CBrightness::clone( ){
    return new CBrightness (*this);
}