#include "../headers/cfilter.h"

CConvolution::CConvolution ( bool src )
        : m_is_enabled(src)
{}

void CConvolution::apply() {
    //TODO
}

void CConvolution::save( bool src ){
    m_is_enabled = src;
}

CFilter & CConvolution::set_default(){
    m_is_enabled = false;
    return *this;
}