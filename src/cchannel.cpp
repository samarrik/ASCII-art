#include "cchannel.h"

using namespace std;

CChannel::CChannel( string src ){
    if ( src != "" ) {
        m_channel = src;
        cout << "Cha:" << m_channel << "  , src:" << src << endl;
    }
}

void CChannel::apply( CImage & src ){
    cout << "Channel:" << m_channel <<  endl;
    if ( ! (m_channel == "n" || m_channel == "r" || m_channel == "g" || m_channel == "b") ){
        throw logic_error("Non-existing channel have been chosen");
    }

    if ( m_channel != "n" ){
        //Gets an array of pixels from a code
        unsigned char * pixels = src.getPixels();
        for ( unsigned i = 0; i < (src.width()*src.height()*4); i += 4 ) {
            if (m_channel == "r" && m_channel != "g" && m_channel != "b")
                pixels[i];
            else pixels[i] = 0;
            if (m_channel != "r" && m_channel == "g" && m_channel != "b")
                pixels[i + 1];
            else pixels[i + 1] = 0;
            if (m_channel != "r" && m_channel != "g" && m_channel == "b")
                pixels[i + 2];
            else pixels[i + 2] = 0;
        }
    }
    cout << "Channel is set" << endl;
}

CFilter * CChannel::clone( ){
    return new CChannel (*this);
}