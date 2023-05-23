#include "cimage.h"
#include <stdexcept>
#include <iostream>

using namespace std;

CBrightness::CBrightness ( int src )
{
    //If the object was created without passing any data into it, the default value will be set automatically;
    if ( src != -100 ) {
        m_brightness = src; //If some value was passed into it, set it as value;
    }
}

void CBrightness::apply( CImage & src ){
    cout << "Brightness:" << endl;
    //Gets an array of pixels from a code
    unsigned char * pixels = src.getPixels();

    //Check if the brightness is in the "valid" range
    if ( m_brightness > 5 || m_brightness < -5 ) {
        throw out_of_range("The brightness value is out of the range");
    } else {
        //Changes the brightness of each pixel
        m_brightness *= 10;
        cout << "brightness size: " << (src.width()*src.height()*4) << endl;
        cout << "brightness w: " << src.width() << endl;
        cout << "brightness h: " << src.height() << endl;
        for ( unsigned i = 0; i < (src.width()*src.height()*4); i += 4 ){
            pixels[i] = min( pixels[i] + m_brightness,255);
            pixels[i+1] = min( pixels[i+1] + m_brightness,255);
            pixels[i+2] = min( pixels[i+2] + m_brightness,255);
            //the fourth pixel is being skipped (A pixel)
        }
    }
    cout << "Brightness was set!" << endl;
}

CFilter & CBrightness::set_val( int src ){
    m_brightness = src;
    return *this;
}