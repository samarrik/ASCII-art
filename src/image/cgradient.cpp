#include "../headers/cfilter.h"

CGradient::CGradient ( std::string src )
        : m_gradient( std::move(src) )
{}

void CGradient::apply() {
    //TODO
}

void CGradient::save( const std::string & src ){
    m_gradient = src;
}

CFilter & CGradient::set_default(){
    m_gradient = "`.-':_,^=;><+!rc*/z?sLTv)J7(|Fi{C}fI31tlu[neoZ5Yxjya]2ESwqkP6h9d4VpOGbUAKXHm8RD#$Bg0MNWQ%&@";
    return *this;
}