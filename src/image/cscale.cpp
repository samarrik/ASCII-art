#include "../headers/cfilter.h"

CScale::CScale ( int src )
        : m_scale(src)
{}

void CScale::apply() {
    //TODO
}

void CScale::save( int src ){
    m_scale = src;
}

CFilter & CScale::set_default(){
    m_scale = 1;
    return *this;
}