#ifndef SCALE
#define SCALE

#include "cimage.h"

class CScale : public CFilter {
public:
    CScale ( int src = -100 );

    void apply ( CImage & src ) override;

    CFilter * clone () override;

private:
    int m_scale = 1;
};

#endif //SCALE
