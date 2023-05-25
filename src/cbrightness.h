#ifndef BRIGHTNESS
#define BRIGHTNESS

#include "cimage.h"
#include <stdexcept>
#include <iostream>

class CBrightness : public CFilter {
public:
    CBrightness ( int src = -100 );

    void apply ( CImage & src ) override;

    CFilter * clone () override;

private:
    int m_brightness = 0;
};

#endif //BRIGHTNESS
