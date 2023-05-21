#ifndef FILTER
#define FILTER

#include <vector>
#include <string>

class CFilter {
public:
    CFilter() = default;

    virtual ~CFilter() = default;

    //Applies a filter to an image
    virtual void apply() = 0;
};

class CGradient : public CFilter {
public:
    CGradient ( std::string src = "" );

    void apply() override;

    CFilter & set_val( const std::string & src );

private:
    std::string m_gradient = "`.-':_,^=;><+!rc*/z?sLTv)J7(|Fi{C}fI31tlu[neoZ5Yxjya]2ESwqkP6h9d4VpOGbUAKXHm8RD#$Bg0MNWQ%&@";
};

class CBrightness : public CFilter {
public:
    CBrightness ( int src = -1 );

    void apply() override;

    CFilter & set_val( int src );

private:
    int m_brightness = 1;
};

class CContrast : public CFilter {
public:
    CContrast ( int src = -1 );

    void apply() override;

    CFilter & set_val( int src );

private:
    int m_contrast = 1;
};

class CNegative : public CFilter {
public:
    CNegative ( int src = -1 );

    void apply() override;

    CFilter & set_val( int src );

private:
    int m_negative = 0;
};

class CScale : public CFilter {
public:
    CScale ( int src = -1 );

    void apply() override;

    CFilter & set_val( int src );

private:
    int m_scale = 1;
};

class CConvolution : public CFilter {
public:
    CConvolution ( int src = -1 );

    void apply() override;

    CFilter & set_val( int src );

private:
    int m_convolution = 0;
};
#endif //FILTER
