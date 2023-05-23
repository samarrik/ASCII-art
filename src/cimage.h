#ifndef IMAGE
#define IMAGE

#include <string>
#include <vector>

using namespace std;

class CImage;
class CFilter;

class CFilter {
public:
    CFilter() = default;

    virtual ~CFilter() = default;

    /**
     * The function is used to apply the filter on the picture.
     * @param src A CImage object on which the filter will be applied
     */
    virtual void apply ( CImage & src ) = 0;
};

class CGradient : public CFilter {
public:
    CGradient ( string src = "" );

    void apply ( CImage & src ) override;

    CFilter & set_val( const string & src );

private:
    string m_gradient = "`.-':_,^=;><+!rc*/z?sLTv)J7(|Fi{C}fI31tlu[neoZ5Yxjya]2ESwqkP6h9d4VpOGbUAKXHm8RD#$Bg0MNWQ%&@";
};

class CBrightness : public CFilter {
public:
    CBrightness ( int src = -100 );

    void apply ( CImage & src ) override;

    CFilter & set_val( int src );

private:
    int m_brightness = 1;
};

class CContrast : public CFilter {
public:
    CContrast ( int src = -100 );

    void apply ( CImage & src ) override;

    CFilter & set_val( int src );

private:
    int m_contrast = 1;
};

class CNegative : public CFilter {
public:
    CNegative ( int src = -100 );


    void apply ( CImage & src ) override;

    CFilter & set_val( int src );

private:
    int m_negative = 0;
};

class CScale : public CFilter {
public:
    CScale ( int src = -100 );

    void apply ( CImage & src ) override;

    CFilter & set_val( int src );

private:
    int m_scale = 1;
};

class CConvolution : public CFilter {
public:
    CConvolution ( int src = -100 );

    void apply ( CImage & src ) override;

    CFilter & set_val( int src );

private:
    int m_convolution = 0;
};


/**
 * An base class which represents an code
 * provided by a user to be proceed in an ASCII art
*/
class CImage {

public:
    //implicit constructor with default(programmed) parameters
    CImage();

    //Adds a filter to a code
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
    void loadFilters( vector<CFilter *> & src );

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

    void loadNameType ( string & filename, string & filetype);

    unsigned char * getPixels (){
        return m_pixels;
    }

    void setGradient(   const string & src );

    string & getGradient();

    unsigned width () const;

    unsigned height () const;

    void loadConvertedToAscii ( string & src );

    string & getonvertedToAscii ( );

    size_t lengthGradient();



private:
        //A set of filters to be applied
        vector<CFilter*> m_filters;
        //raw pixels data
        unsigned char * m_pixels;
        //ascii converted data
        string m_ascii_data;
        //name of the code file
        string m_filename;
        //name of the file type
        string m_filetype;
        string m_gradient;
        unsigned m_width;
        unsigned m_height;
};

#endif //IMAGE