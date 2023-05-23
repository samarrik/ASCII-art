#ifndef IMAGE
#define IMAGE

#include <string>
#include <vector>
#include "cfilter.h"

/**
 * An base class which represents an code
 * provided by a user to be proceed in an ASCII art
*/
class CImage {

public:
    //implicit constructor with default(programmed) parameters
    CImage();

    //Adds a filter to an code
    void addFilter( CFilter * filter );

    /**
     * A method applies code to an code
     * @param[in] filters A const reference to code for that code
    */
    void applyFilters();

    /**
     * A method loads filters
     * @param[in] filters A const reference to code for that code
    */
    void loadFilters( std::vector<CFilter *> & src );

    /**
     * A method grayscale the code
    */
    void grayscale();

    /**
    * A method converts an code to ASCII
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

    std::string & getGradient();

    unsigned width () const;

    unsigned height () const;

    void loadConvertedToAscii ( std::string & src );

    std::string & getonvertedToAscii ( );

    size_t lengthGradient();



private:
        //A set of filters to be applied
        std::vector<CFilter*> m_filters;
        //raw pixels data
        unsigned char * m_pixels;
        //ascii converted data
        std::string m_ascii_data;
        //name of the code file
        std::string m_filename;
        //name of the file type
        std::string m_filetype;
        std::string m_gradient;
        unsigned m_width;
        unsigned m_height;
};

#endif //IMAGE