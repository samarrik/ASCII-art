#ifndef IMAGE
#define IMAGE

#include <string>

/**
 * A structure which will store all information about filters to be applied
*/
struct CFilters {
    //Generate a default set of filters (pre-defined)
    CFilters ();

    //Each filter should be able to be set manually
    void setGradient ( std::string & gradient );

    void setNegative ( bool negative );

    void setSize ( double size );

    void setBrightness ( double brightness );
    
    void setRotation ( double rotation );

    void setConvolution ( bool convolution );

    //Member variables for storing settings of each filter
    std::string m_gradient;
    bool m_negative;
    double m_size;
    double m_brightness;
    int m_rotation;
    bool m_convolution;
};

/**
 * An base class which represents an image
 * provided by a user to be proceed in an ASCII art
*/
class CImage {
    public:
        //implicit constructor with default(programmed) parameters
        CImage( const std::string & = "" );

        // void setGradient ( std::string & gradient );

        // void setNegative ( bool negative );

        // void setSize ( double size );

        // void setBrightness ( double brightness );
        
        // void setRotation ( double rotation );

        // void setConvolution ( bool convolution );

        /**
         * A method saves filters which will be applied to that particular image
         * @param[in] filters A const reference to filters for that image
        */
        void saveFilters( CFilters & filters ) noexcept;

        // void grayscale();

        // void convertToASCII();

        /**
         * A method will save a ASCII art to the file filenameASCII.txt
        */
        void saveToFile( std::string & filename ) const;
        
        /**
         * A method will print out an ASCII art 
        */
        // void showImage() const noexcept;

    private:
        //A set of filters to be applied
        CFilters m_filters;
        //raw pixels data
        char * m_image_data;
        //ascii converted data
        char * m_ascii_data;
        //name of the image file
        std::string m_filename;
};

#endif //IMAGE