#ifndef SCALE
#define SCALE

#include "cimage.h"

/*
 * A class that represents a filter that scales an image
 */
class CScale : public CFilter {
public:
    //If argument wasn't passed to the constructor, set -100
    CScale ( int src = -100 );

    ~CScale() = default;

    void apply ( CImage & src ) override;

    CFilter * clone () override;
private:
    //Standard scale value is 0
    int m_scale = 0;
};
#endif //SCALE
