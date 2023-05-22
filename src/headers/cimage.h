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
    void addFilter( CFilter * filter );

    /**
     * A method applies image to an image
     * @param[in] filters A const reference to image for that image
    */
    void applyFilters();

    /**
     * A method loads filters
     * @param[in] filters A const reference to image for that image
    */
    void loadFilters( std::vector<CFilter *> & src );

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

    void loadExtractedData( unsigned w, unsigned h, unsigned char * p );

    void loadNameType ( std::string & filename, std::string & filetype);

    unsigned char * getPixels (){
        return m_pixels;
    }

    void setGradient(   const std::string & src );

    unsigned width () const;

    unsigned height () const;


private:
        //A set of filters to be applied
        std::vector<CFilter*> m_filters;
        //raw pixels data
        unsigned char * m_pixels;
        //ascii converted data
        char * m_ascii_data;
        //name of the image file
        std::string m_filename;
        //name of the file type
        std::string m_filetype;
        std::string m_gradient;
        unsigned m_width;
        unsigned m_height;
};

#endif //IMAGE