#include "cchannel.h"

using namespace std;

CChannel::CChannel( const string & src ){

    //If the object was created without passing any data into it, the default value will be set automatically;
    if ( src != "" ) {
        m_channel = src; //If some value was passed into it, set it as value;
    }
}

void CChannel::apply( CImage & src ){

    //Checks if the option is valid
    if ( ! (m_channel == "n" || m_channel == "r" || m_channel == "g" || m_channel == "b") ){
        throw logic_error("Non-existing channel have been chosen");
    }

    //If there is a channel-filter to be applied, apply it
    if ( m_channel != "n" ){

        //Gets an array of pixels from a code
        unsigned char * pixels = src.getPixels();

        //Changes each pixel by filtering channels
        for ( unsigned i = 0; i < (src.width()*src.height()*4); i += 4 ) {

            //Leaves only one channel
            if (m_channel == "r" ) {
                pixels[i + 1] = 0;
                pixels[i + 2] = 0;
            }
            else if (m_channel == "g" ) {
                pixels[i]     = 0;
                pixels[i + 2] = 0;
            }
            else if (m_channel == "b"){
                pixels[i]     = 0;
                pixels[i + 1] = 0;
            }
        }
    }
}

CFilter * CChannel::clone( ){
    return new CChannel (*this);
}