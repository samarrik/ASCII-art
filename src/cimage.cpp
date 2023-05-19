#include "cimage.h"

//Default parameters for filters
CFilters::CFilters ()
:   m_gradient("$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/|()1{}[]?-_+~<>i!lI;:,^`."),
    m_negative(false),
    m_size(1.0),
    m_brightness(1.0),
    m_rotation(0),
    m_convolution(false)
{}

void CFilters:: setGradient ( std::string & gradient ){
    m_gradient = gradient;
}
void CFilters::setNegative ( bool negative ){
    m_negative = negative;
}
void CFilters::setSize ( double size ){
    m_size = size;
}
void CFilters::setBrightness ( double brightness ){
    m_brightness = brightness;
}

void CFilters::setRotation ( double rotation ){
    m_rotation = rotation;
}
void CFilters::setConvolution ( bool convolution ){
    m_convolution = convolution;
}

//Default constructor
CImage::CImage( const std::string & filename )
:   m_filters(),
    m_image_data(nullptr),
    m_ascii_data(nullptr),
    m_filename( filename )
{}

// void CImage:: setGradient ( std::string & gradient ){
//     m_filters.setGradient(gradient);
// }
// void CImage::setNegative ( bool negative ){
//     m_filters.setNegative(negative);
// }
// void CImage::setSize ( double size ){
//     m_filters.setSize(size);
// }
// void CImage::setBrightness ( double brightness ){
//     m_filters.setBrightness(brightness);
// }
// void CImage::setRotation ( double rotation ){
//     m_filters.setRotation(rotation);
// }
// void CImage::setConvolution ( bool convolution ){
//     m_filters.setConvolution(convolution);
// }

// void CImage::grayscale(){

// }
// void CImage::convertToASCII(){
    
// }

// void CImage::saveToFile( std::string & filename ) const{
    
// }
// void CImage::showImage() const noexcept {

// }

void CImage::saveFilters( CFilters & filters ) noexcept{
    m_filters = filters;
}
