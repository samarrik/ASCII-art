#include "cimage.h"

using namespace std;

CNegative::CNegative ( int src )
{
    if ( src != -1 )
        m_negative = src;
}

void CNegative::apply( CImage & src ){
    //TODO:
}

CFilter & CNegative::set_val(int src) {
    m_negative = src;
    return *this;
}