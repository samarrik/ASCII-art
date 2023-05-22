#include "../headers/cimage.h"

CImage::CImage(){}

void CImage::addFilter( CFilter * filter ) {
    m_filters.push_back(filter);
}

void CImage::applyFilters() {
    for ( auto filter : m_filters )
        filter->apply();
}

void CImage::loadFilters( std::vector<CFilter *> & src ) {
    m_filters = src;
}

void CImage::loadNameType ( std::string & filename, std::string & filetype){
    filename = filename;
    filetype = filetype;
}

void CImage::loadExtractedData( unsigned w, unsigned h, unsigned char * p ){
    m_width = w;
    m_height = h;
    m_pixels = p;
}

void CImage::setGradient( const std::string & src ) {
    m_gradient = src;
}

unsigned CImage::width () const {
    return m_width;
}

unsigned CImage::height () const {
    return m_height;
}

void CImage::grayscale() {
    //TODO
}

void CImage::convert() {
    //TODO
}

void CImage::saveToFile() const{
    //TODO
}

void CImage::print() const noexcept{
    //TODO
}