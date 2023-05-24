#include "cimage.h"
#include "iostream"

using namespace std;

CImage::CImage(){}

void CImage::addFilter( CFilter * filter ) {
    m_filters.push_back(filter);
}

void CImage::applyFilters() {
    for ( auto filter : m_filters )
        filter->apply(*this);
}

void CImage::loadFilters( vector<CFilter *> & src ) {
    m_filters = src;
}

void CImage::loadNameType ( string & filename, string & filetype){
    filename = filename;
    filetype = filetype;
}

void CImage::loadExtractedData( unsigned w, unsigned h, unsigned char * p ){
    m_width = w;
    m_height = h;
    m_pixels = p;
}

void CImage::setGradient( const string & src ) {
    m_gradient = src;
}

unsigned CImage::width () const {
    return m_width;
}

unsigned CImage::height () const {
    return m_height;
}

void CImage::grayscale() {
    cout << m_width * m_height * 4 << ": grayscaled sizes" << endl;
    for ( unsigned i = 0; i < m_width * m_height * 4; i += 4 ) {
        int grayscaled = int(0.2125 * m_pixels[i] + 0.7153 * m_pixels[i+1] + 0.0722 * m_pixels [i+2]);
        if ( m_pixels[i+3] == 0 ){
            grayscaled = 0;
        }
        m_pixels[i] = grayscaled;
        m_pixels[i+1] = grayscaled;
        m_pixels[i+2] = grayscaled;
        //the last pixel is being skipped
    }
}

void CImage::loadConvertedToAscii ( string & src ){
    m_ascii_data = src;
}

string & CImage::getGradient(){
    return m_gradient;
}

size_t CImage::lengthGradient(){
    return m_gradient.size();
}

string & CImage::getonvertedToAscii ( ){
    return m_ascii_data;
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