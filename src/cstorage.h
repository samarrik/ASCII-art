#ifndef STORAGE
#define STORAGE

#include <vector>
#include "cimage.h"
#include <stdexcept>

using namespace std;

/**
 * A class which represents a storage of all images which will be converted.
 * @details It includes two main containers. One is for images, another one
 *          has default filters in it which will be used to init each image.
 */
class CStorage {
public:
    CStorage() = default;

    ~CStorage();

    /**
     * Adds an image provided as parameter in the storage
     * @param image
     */
    void addImage( CImage * image ) noexcept;

    /**
     * Adds a filter provided as parameter in the storage
     * @param filter
     * @return CStorage & instance (for chaining)
     */
    CStorage & addDefaultFilter( CFilter * filter ) noexcept;

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

    /**
     * Function to figure the number of images stored in
     * the storage
     * @return unsigned Number of images stored
     */
    unsigned imagesCount () const noexcept;

    /**
     * Function gets the last image of a collection
     * @return CImage & to the last image of the collection
     */
    CImage & lastImage ();

private:
    vector<CImage*> image_files;
    vector<CFilter*> default_filters;
};

#endif //STORAGE
