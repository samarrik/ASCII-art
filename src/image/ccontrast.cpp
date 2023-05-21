#include "../headers/cfilter.h"

CContrast::CContrast ( int src )
        : m_contrast(src)
{}

void CContrast::apply() {
    //TODO
}

CFilter & CContrast::set_val( int src ){
    m_contrast = src;
    return *this;
}