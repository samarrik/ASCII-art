#ifndef BRIGHTNESS
#define BRIGHTNESS

#include "cimage.h"
#include <stdexcept>
#include <iostream>

/*
 * A class that represents a filter that changes brightness of an image
 */
class CBrightness : public CFilter {
public:

    //If argument wasn't passed to the constructor, set -100
    CBrightness ( int src = -100 );

    ~CBrightness() override = default;

    void apply ( CImage & src ) override;

    CFilter * clone () override;

private:
    //Standard brightness value is 0
    int m_brightness = 0;
};

#endif //BRIGHTNESS
