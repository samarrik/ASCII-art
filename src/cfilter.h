#ifndef FILTER
#define FILTER

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

class CImage;

/**
 * A base class for all filters
 */
class CFilter {
public:
    CFilter() = default;

    virtual ~CFilter() = default;

    /**
     * The function is used to apply the filter on the picture.
     * @param src A CImage object on which the filter will be applied
     */
    virtual void apply ( CImage & src ) = 0;

    /**
     * Clones a data segment which is linked to the object
     * @return CFilter * to a new allocated data segment
     */
    virtual CFilter * clone () = 0;
};

#endif //FILTER
