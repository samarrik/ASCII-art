#include "cimage.h"
#include <iostream>

using namespace std;

CConvolution::CConvolution ( int src )
{
    if ( src != -1)
        m_convolution = src;
}


void CConvolution::apply( CImage & src ){
    cout << "Convolution" << endl;
    //TODO:
    cout << "Convolution was set!" << endl;
}

CFilter & CConvolution::set_val(int src) {
    m_convolution = src;
    return *this;
}