#ifndef NEGATIVE
#define NEGATIVE

#include "cimage.h"
#include <algorithm>

class CNegative : public CFilter {
public:
    CNegative ( int src = -100 );

    void apply ( CImage & src ) override;

    CFilter * clone () override;

private:
    int m_negative = 0;
};

#endif //NEGATIVE
