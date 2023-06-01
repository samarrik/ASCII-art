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
     * Function gets the last image of a collection
     * @return CImage & to the last image of the collection
     */
    CImage & lastImage ();

    /**
     * The function saves the path to  the config file provided to the application
     * @param src A string containing the name of the config file
     */
    void saveConfig ( const string & src ) noexcept;

    /**
     * The function returns the path to the config file
     * @return string A path to the config file
     */
    string pathConfig() const noexcept;

private:
    vector<CImage*> m_image_files;
    vector<CFilter*> m_default_filters;
    string m_config_file_name;
};

#endif //STORAGE
