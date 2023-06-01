#include "cnegative.h"

using namespace std;

CNegative::CNegative ( int src )
{
    //If the object was created without passing any data into it, the default value will be set automatically;
    if ( src != -100 ) {
        if ( src != 0 && src != 1  ) {
            throw out_of_range("The negative value is out of the range");
        }
        m_negative = src;//If some value was passed into and it is in the range
    }
}

void CNegative::apply( CImage & src ){
    //If negative will be applied, apply it by reversing the gradient
    if ( m_negative == 1 ) {
        src.reverseGradient();
    }
}

CFilter * CNegative::clone( ){
    return new CNegative (*this);
}