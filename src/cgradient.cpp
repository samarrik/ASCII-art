#include "cgradient.h"

using namespace std;

CGradient::CGradient ( const string & src ) {
    //If the object was created without passing any data into it, the default value will be set automatically;
    if (src != "") {
        m_gradient = src; //If some value was passed into it, set it as value;
    }
}

void CGradient::apply( CImage & src ) {
    //Load a new gradient
    src.setGradient( m_gradient );
}

CFilter * CGradient::clone( ){
    return new CGradient(*this);
}