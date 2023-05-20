#include "../headers/cfilter.h"

CContrast::CContrast ( int src )
        : m_contrast(src)
{}

void CContrast::apply() {
    //TODO
}

void CContrast::save( int src ){
    m_contrast = src;
}

CFilter & CContrast::set_default(){
    m_contrast = 1;
    return *this;
}