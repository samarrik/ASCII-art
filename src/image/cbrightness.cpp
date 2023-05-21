#include "../headers/cfilter.h"

CBrightness::CBrightness ( int src )
: m_brightness(src)
{}

void CBrightness::apply() {
    //TODO
}

CFilter & CBrightness::set_val( int src ){
    m_brightness = src;
    return *this;
}