#include "../headers/cfilter.h"

CBrightness::CBrightness ( int src )
: m_brightness(src)
{}

void CBrightness::apply() {
    //TODO
}

void CBrightness::save( int src ){
    m_brightness = src;
}

CFilter & CBrightness::set_default(){
    m_brightness = 1;
    return *this;
}