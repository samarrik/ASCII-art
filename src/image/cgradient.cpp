#include "../headers/cfilter.h"

CGradient::CGradient ( std::string src )
{
    if ( src != "")
        m_gradient = src;
}

void CGradient::apply() {
    //TODO
}

CFilter & CGradient::set_val( const std::string & src ){
    m_gradient = src;
    return *this;
}