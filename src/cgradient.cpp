#include "cimage.h"
#include <iostream>

using namespace std;

CGradient::CGradient ( string src ) {
    //If the object was created without passing any data into it, the default value will be set automatically;
    if (src != "") {
        m_gradient = src; //If some value was passed into it, set it as value;
    }
}

void CGradient::apply( CImage & src ) {
    cout << "Gradient" << endl;
    src.setGradient( m_gradient );
    cout << "Gradient was set!" << endl;
}

CFilter & CGradient::set_val( const string & src ){
    m_gradient = src;
    return *this;
}