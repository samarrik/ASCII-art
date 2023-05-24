#ifndef STORAGE
#define STORAGE

#include <vector>
#include "cimage.h"

using namespace std;

/**
 * A class which represents a storage of all images which will be converted.
 * @details It includes two main containers. One is for images, another one
 *          has default filters in it which will be used to init each image.
 */
class CStorage {
public:
    CStorage() = default;

    /**
     * Adds an image provided as parameter in the storage
     * @param image
     */
    void addImage( CImage * image ) noexcept;

    /**
     * Adds a filter provided as parameter in the storage
     * @param filter
     */
    void addFilter( CFilter * filter ) noexcept;

    /**
     * Allows to extract a container with images
     * @return A reference to the vector of images
     */
    vector<CImage*> & getImages() noexcept;

    /**
     * Allows to extract a container with filters
     * @return A reference to the vector of filters
     */
    vector<CFilter*> & getFilters() noexcept;

private:
    vector<CImage*> image_files;
    vector<CFilter*> default_filters;
};

#endif //STORAGE
