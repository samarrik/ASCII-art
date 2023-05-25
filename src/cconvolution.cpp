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

CFilter * CConvolution::clone( ){
    return new CConvolution (*this);
}