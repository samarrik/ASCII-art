#ifndef IMAGE
#define IMAGE

#include <string>
#include <vector>

/**
 * An base class which represents an image
 * provided by a user to be proceed in an ASCII art
*/
class CImage {

private:
private:

    class CFilter {
    public:
        //An abstract base class won't have a constructor
        CFilter() = delete;

        virtual ~CFilter() = default;

        //Applies a filter to an image
        virtual void apply() = 0;
    };

    class CGradient : public CFilter {
    public:
        CGradient ( const char * sequence = "" );

        void apply() override;

    private:
        std::string m_gradient;
    };

    class CBrightness : public CFilter {
    public:
        CBrightness ( int brightness );

        void apply() override;

    private:
        int m_brightness;
    };

    class CContrast : public CFilter {
    public:
        CContrast ( int contrast );

        void apply() override;

    private:
        int m_contrast;
    };

    class CNegative : public CFilter {
    public:
        CNegative ( bool is_enabled );

        void apply() override;

    private:
        bool m_is_enabled;
    };

    class CScale : public CFilter {
    public:
        CScale ( int scale );

        void apply() override;

    private:
        int m_scale;
    };

    class CConvolution : public CFilter {
    public:
        CConvolution ( bool is_enabled );

        void apply() override;

    private:
        bool m_is_enabled;
    };

public:
    //implicit constructor with default(programmed) parameters
    CImage();

    //Adds a filter to an image
    void addFilter( CFilter & filter );

    /**
     * A method applies filters to an image
     * @param[in] filters A const reference to filters for that image
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
private:

        //A set of filters to be applied
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