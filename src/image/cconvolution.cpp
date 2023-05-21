#include "../headers/cfilter.h"

CConvolution::CConvolution ( int src )
{
    if ( src != -1)
        m_convolution = src;
}


void CConvolution::apply() {
    //TODO
}

CFilter & CConvolution::set_val(int src) {
    m_convolution = src;
    return *this;
}