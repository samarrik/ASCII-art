#ifndef FILTER
#define FILTER

#include <vector>
#include <string>

class CFilter {
public:
    //An abstract base class won't have a constructor
    CFilter() = delete;

    virtual ~CFilter() = default;

    //Applies a filter to an image
    virtual void apply() = 0;

    //Saves the value of the filter
    virtual void save() = 0;

    virtual void set_default() = 0;
};

class CGradient : public CFilter {
public:
    CGradient ( const char * sequence = "" );

    void apply() override;

    void save() override;

    void set_default() override;

private:
    std::string m_gradient;
};

class CBrightness : public CFilter {
public:
    CBrightness ( int brightness = 0 );

    void apply() override;

    void save() override;

    void set_default() override;

private:
    int m_brightness;
};

class CContrast : public CFilter {
public:
    CContrast ( int contrast = 0 );

    void apply() override;

    void save() override;

    void set_default() override;

private:
    int m_contrast;
};

class CNegative : public CFilter {
public:
    CNegative ( bool is_enabled = false );

    void apply() override;

    void save() override;

    void set_default() override;

private:
    bool m_is_enabled;
};

class CScale : public CFilter {
public:
    CScale ( int scale = 1 );

    void apply() override;

    void save() override;

    void set_default() override;

private:
    int m_scale;
};

class CConvolution : public CFilter {
public:
    CConvolution ( bool is_enabled = false );

    void apply() override;

    void save() override;

    void set_default() override;

private:
    bool m_is_enabled;
};
#endif //FILTER
