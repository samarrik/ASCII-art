#include "cfilter.h"

using namespace std;

CContrast::CContrast ( int src )
        : m_contrast(src)
{}

void CContrast::apply( CImage & src ){
    //TODO:
}

CFilter & CContrast::set_val( int src ){
    m_contrast = src;
    return *this;
}