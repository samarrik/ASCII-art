#ifndef GRADIENT
#define GRADIENT

#include "cimage.h"

class CGradient : public CFilter {
public:
    CGradient ( string src = "" );

    void apply ( CImage & src ) override;

    CFilter * clone () override;

private:
    string m_gradient = "`.-':_,^=;><+!rc*/z?sLTv)J7(|Fi{C}fI31tlu[neoZ5Yxjya]2ESwqkP6h9d4VpOGbUAKXHm8RD#$Bg0MNWQ%&@";
};

#endif //GRADIENT
