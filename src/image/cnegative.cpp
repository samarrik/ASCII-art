#include "../headers/cfilter.h"

CNegative::CNegative ( bool src )
        : m_is_enabled(src)
{}

void CNegative::apply() {
    //TODO
}

void CNegative::save( bool src ){
    m_is_enabled = src;
}

CFilter & CNegative::set_default(){
    m_is_enabled = false;
    return *this;
}