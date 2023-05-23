#include "cimage.h"
#include <iostream>

using namespace std;

CScale::CScale ( int src )
{
    if ( src != -1 )
        m_scale = src;
}

void CScale::apply( CImage & src ){
    cout << "Scale" << endl;
    //TODO:
    cout << "Scale was set!" << endl;
}

CFilter & CScale::set_val( int src ){
    m_scale = src;
    return *this;
}