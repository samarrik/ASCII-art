#ifndef GRADIENT
#define GRADIENT

#include "cimage.h"

/*
 * A class that represents a filter that changes gradient of an image (used for ASCII conversion)
 */
class CGradient : public CFilter {
public:
    CGradient ( const string & src = "" );

    ~CGradient() override = default;

    void apply ( CImage & src ) override;

    CFilter * clone () override;

private:
    //Standard gradient
    string m_gradient = "`.-':_,^=;><+!rc*/z?sLTv)J7(|Fi{C}fI31tlu[neoZ5Yxjya]2ESwqkP6h9d4VpOGbUAKXHm8RD#$Bg0MNWQ%&@";
};

#endif //GRADIENT
