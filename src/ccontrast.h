#ifndef CONTRAST
#define CONTRAST

#include "cimage.h"
#include <iostream>
#include <algorithm>

class CContrast : public CFilter {
public:
    CContrast ( int src = -100 );

    ~CContrast() = default;

    void apply ( CImage & src ) override;

    CFilter * clone () override;

private:
    int m_contrast = 0;
};

#endif //CONTRAST
