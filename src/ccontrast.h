#ifndef CONTRAST
#define CONTRAST

#include "cimage.h"
#include <iostream>
#include <algorithm>

/*
 * A class that represents a filter that changes contrast of an image
 */
class CContrast : public CFilter {
public:

    //If argument wasn't passed to the constructor, set -100
    CContrast ( int src = -100 );

    ~CContrast() override = default;

    void apply ( CImage & src ) override;

    CFilter * clone () override;

private:
    //Standard contrast value is 0
    int m_contrast = 0;
};

#endif //CONTRAST
