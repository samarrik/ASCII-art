#ifndef SCALE
#define SCALE

#include "cimage.h"

class CScale : public CFilter {
public:
    CScale ( int src = -100 );

    ~CScale() = default;

    void apply ( CImage & src ) override;

    CFilter * clone () override;

private:
    int m_scale = 0;
};

#endif //SCALE
