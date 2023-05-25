#include "cnegative.h"

using namespace std;

CNegative::CNegative ( int src )
{
    if ( src != -100 )
        m_negative = src;
}

void CNegative::apply( CImage & src ){
    cout << "Negative: " << m_negative << endl;

    if ( m_negative != 0 && m_negative != 1 ) {
        throw out_of_range("The negative value is out of the range");
    } else {
        if ( m_negative == 1 ) {
            string inverted_gradient = src.getGradient();
            reverse(inverted_gradient.begin(), inverted_gradient.end());
            src.setGradient(inverted_gradient);
        }
    }
    cout << "Negative was set!" << endl;
}

CFilter * CNegative::clone( ){
    return new CNegative (*this);
}