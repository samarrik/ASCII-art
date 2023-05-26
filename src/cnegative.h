#ifndef NEGATIVE
#define NEGATIVE

#include "cimage.h"
#include <algorithm>

/*
 * A class that represents a filter that changes negative of an image
 */
class CNegative : public CFilter {
public:

    //If argument wasn't passed to the constructor, set -100
    CNegative ( int src = -100 );

    ~CNegative() = default;

    void apply ( CImage & src ) override;

    CFilter * clone () override;

private:
    //Standard negative value is 0 (not used)
    int m_negative = 0;
};

#endif //NEGATIVE
