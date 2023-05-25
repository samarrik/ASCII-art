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

        if ( m_scale > 0 ){

        } else if ( m_scale < 0 ){

        }

    }
    cout << "Scale was set!" << endl;
}

CFilter * CScale::clone( ){
    return new CScale (*this);
}