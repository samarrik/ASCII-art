#include "../headers/cfilter.h"

CScale::CScale ( int src )
{
    if ( src != -1 )
        m_scale = src;
}

void CScale::apply() {
    //TODO
}

CFilter & CScale::set_val( int src ){
    m_scale = src;
    return *this;
}