#ifndef IMAGE
#define IMAGE

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

class CImage;

//CIMAGE AND CFILTERS ARE LINKED TO EACH OTHER THAT IS WHY THEY ARE LOCATED IN ONE .H FILE

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
    //Implicit constructor with default(programmed) parameters
    CImage() = default;

    //Initializes an image using given filters, filename and filetype
    CImage( vector<CFilter*> & src, string & filename, string & filetype, unsigned char * pixels, unsigned width, unsigned height );

    ~CImage();

    /**
     * A method adds filter to an image
     * @param filter A filter to be added to an image
     */
    void addFilter( CFilter * filter );

    /**
     * A method applies filter on an image
     * @param[in] filters A const reference to code for that code
    */
    void applyFilters();

    /**
     * A method grayscales the image
    */
    void grayscale();

    /**
    * A method converts a image to ASCII
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
    /**
     * A method will update pixels after scaling
     * @param new_pixels new array of pixels
     * @param new_width  width of the new array of pixels
     * @param new_height height of the new array of pixels
     */
    void loadScaledData ( unsigned char * new_pixels, unsigned new_width, unsigned new_height );

    /**
    * A method gets the weight of an image
    * @return unsigned Image height
    */
    unsigned width () const;

    /**
    * A method gets the height of an image
    * @return unsigned Image height
    */
    unsigned height () const;

    /**
     * A method gets pixels of the image
     * @return A pointer to the array of pixels
     */
    unsigned char * getPixels (){
        return m_pixels;
    }

    /**
     * A method sets gradient
     * @param src new gradient
     */
    void setGradient(   const string & src );

    /**
     * A method reverses the gradient
     */
    void reverseGradient();

    /**
     * A method gets a filename of an image
     * @return string Which is a filename of the image
     */
    string getFileName () const;

private:
        //A set of filters to be applied
        vector<CFilter*> m_filters;
        //raw pixels data
        unsigned char * m_pixels;
        //ascii converted data
        string m_ascii_data;
        //name of the image
        string m_filename;
        //name of the file type
        string m_filetype;
        //gradient which will be applied to this picture
        string m_gradient;
        unsigned m_width;
        unsigned m_height;
        //Flag
        bool is_scaled;
};
#endif //IMAGE