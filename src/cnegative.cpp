#include "cimage.h"
#include <iostream>

using namespace std;

CNegative::CNegative ( int src )
{
    if ( src != -1 )
        m_negative = src;
}

void CNegative::apply( CImage & src ){
    cout << "Negative" << endl;
    //TODO:
    cout << "Negative was set!" << endl;
}

CFilter & CNegative::set_val(int src) {
    m_negative = src;
    return *this;
}