#ifndef CONVOLUTION
#define CONVOLUTION

#include "cimage.h"

class CConvolution : public CFilter {
public:
    CConvolution ( int src = -100 );

    void apply ( CImage & src ) override;

    CFilter * clone () override;

private:
    int m_convolution = 0;
};

#endif //CONVOLUTION
