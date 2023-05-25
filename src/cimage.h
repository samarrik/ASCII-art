#ifndef IMAGE
#define IMAGE

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

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

/**
 * An base class which represents an code
 * provided by a user to be proceed in an ASCII-art
*/
class CImage {

public:
    //implicit constructor with default(programmed) parameters
    CImage() = default;

    //Initializes an image using given filters, filename and filetype
    CImage( vector<CFilter*> & src, string & filename, string & filetype, unsigned char * pixels, unsigned width, unsigned height);

    //Adds a filter to a code
    void addFilter( CFilter * filter );

    /**
     * A method applies code to an code
     * @param[in] filters A const reference to code for that code
    */
    void applyFilters();

    /**
     * A method grayscales the image
    */
    void grayscale();

    /**
    * A method converts a code to ASCII
    */
    void asciiConversion();

    /**
     * A method will save a ASCII art to the txt file
    */
    void saveToFile( ofstream & outputFile )  const;

    /**
     * A method will print out an ASCII art
    */
    void print() const noexcept;

    unsigned char * getPixels (){
        return m_pixels;
    }

    void setGradient(   const string & src );

    string & getGradient();

    unsigned width () const;

    unsigned height () const;

    string getFileName () const;

private:
        //A set of filters to be applied
        vector<CFilter*> m_filters;
        //raw pixels data
        unsigned char * m_pixels{};
        //ascii converted data
        string m_ascii_data;
        //name of the code file
        string m_filename;
        //name of the file type
        string m_filetype;
        string m_gradient;
        unsigned m_width{};
        unsigned m_height{};
};

#endif //IMAGE