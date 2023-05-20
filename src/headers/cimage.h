#ifndef IMAGE
#define IMAGE

#include <string>
#include <vector>
#include "cfilter.h"

/**
 * An base class which represents an image
 * provided by a user to be proceed in an ASCII art
*/
class CImage {

public:
    //implicit constructor with default(programmed) parameters
    CImage();

    //Adds a filter to an image
    void addFilter( CFilter & filter );

    /**
     * A method applies image to an image
     * @param[in] filters A const reference to image for that image
    */
    void applyFilters();

    /**
     * A method grayscale the image
    */
    void grayscale();

    /**
    * A method converts an image to ASCII
    */
    void convert();

    /**
     * A method will save a ASCII art to the txt file
    */
    void saveToFile() const;

    /**
     * A method will print out an ASCII art
    */
        void print() const noexcept;

    //!!
    friend class CFilter;

private:
        //A set of image to be applied
        std::vector<CFilter> m_filters;
        //raw pixels data
        char * m_image_data;
        //ascii converted data
        char * m_ascii_data;
        //name of the image file
        std::string m_filename;
        //name of the file type
        std::string m_filetype;
};

#endif //IMAGE