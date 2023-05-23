#include "cfilter.h"

using namespace std;

CConvolution::CConvolution ( int src )
{
    if ( src != -1)
        m_convolution = src;
}


void CConvolution::apply( CImage & src ){
    //TODO:
}

CFilter & CConvolution::set_val(int src) {
    m_convolution = src;
    return *this;
}