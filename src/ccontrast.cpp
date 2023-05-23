#include "cimage.h"
#include <iostream>

using namespace std;

CContrast::CContrast ( int src )
        : m_contrast(src)
{}

void CContrast::apply( CImage & src ){
    cout << "Contrast" << endl;
    //TODO:
    cout << "Contrast was set!" << endl;
}

CFilter & CContrast::set_val( int src ){
    m_contrast = src;
    return *this;
}