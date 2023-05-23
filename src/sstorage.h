#ifndef STORAGE
#define STORAGE

#include <vector>
#include "cimage.h"
#include "cfilter.h"

struct SStorage {
    std::vector<CImage*> image_files;
    std::vector<CFilter*> default_filters;
};

#endif //STORAGE
