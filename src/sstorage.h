#ifndef STORAGE
#define STORAGE

#include <vector>
#include "cimage.h"
#include "cfilter.h"

using namespace std;

struct SStorage {
    vector<CImage*> image_files;
    vector<CFilter*> default_filters;
};

#endif //STORAGE
