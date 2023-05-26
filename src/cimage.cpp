#include "cimage.h"

#define MAX_PIXEL_VAL 255
#define BLACK_THRESHOLD 5

using namespace std;

CImage::CImage( vector<CFilter*> & src, string & filename, string & filetype, unsigned char * pixels, unsigned width, unsigned height )
: m_pixels(pixels), m_ascii_data(), m_filename( filename ), m_filetype( filetype ), m_gradient(), m_width( width ), m_height( height), is_scaled ( false )
{
    //A deep copy should be made here
    for ( auto source_filter : src){
        m_filters.push_back(source_filter->clone());
    }
}

CImage::~CImage() {
    delete [] m_pixels;
    for ( auto filter : m_filters){
        delete filter;
    }
}

void CImage::addFilter( CFilter * filter ) {
    m_filters.push_back(filter);
}

void CImage::applyFilters() {
    for ( auto filter : m_filters )
        filter->apply(*this);
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
    for ( unsigned i = 0; i < m_width * m_height * 4; i += 4 ) {
        int grayscaled = int(0.2125 * m_pixels[i] + 0.7153 * m_pixels[i+1] + 0.0722 * m_pixels [i+2]);
        if ( m_pixels[i+3] == 0 ){
            grayscaled = 0;
        }
        m_pixels[i] = grayscaled;
        m_pixels[i+1] = grayscaled;
        m_pixels[i+2] = grayscaled;
        //the last pixel is being skipped because it is "opacity"
    }
}

void CImage::reverseGradient(){
    reverse(m_gradient.begin(), m_gradient.end());
}

string CImage::getFileName () const{
    return m_filename;
}

void CImage::loadScaledData ( unsigned char * new_pixels, unsigned new_width, unsigned new_height ){
    m_pixels = new_pixels;
    m_width = new_width;
    m_height = new_height;
    is_scaled = true;
}

void CImage::asciiConversion() {
    cout << "real pixels" << m_width * m_height * 4 << endl;
    for ( unsigned i = 0; i < m_width * m_height * 4; i+= 4 ) {
        /**
         * Calculate which character to use;
         */
        int size = m_gradient.size();
        int weight_per_char = MAX_PIXEL_VAL/size;

        //If pixel bright enough, find an ASCII char for it, if not, just print " "
        if ( m_pixels[i] > BLACK_THRESHOLD ) {
            m_ascii_data.push_back(m_gradient[min(m_pixels[i] / weight_per_char, size - 1)]);
        } else {
            m_ascii_data.push_back(' ');
        }
    }
}

void CImage::saveToFile( ofstream & outputFile ) const{
    int cnt_write = 0; //!
    cout << "ascii string size:" << m_ascii_data.size() << endl;
    for (unsigned i = 0, g = 0; i < m_height; i++, g++) {
        for (unsigned j = 0; j < m_width; g++, j++) {
            if ( j == m_width - 1 ){
                j++; g--;
                continue;
            }
            outputFile << m_ascii_data[g];
            outputFile << m_ascii_data[g];
            if ( ! is_scaled ) {
                outputFile << m_ascii_data[g];
            }
            cnt_write++;
        }
        outputFile << '\n';
    }
    cout << "to_write:" << cnt_write << endl;
}

void CImage::print() const noexcept{
    for (unsigned i = 0, g = 0; i < m_height; i++, g++) {
        for (unsigned j = 0; j < m_width; g++, j++) {
            if ( j == m_width - 1 ){
                j++; g--;
                continue;
            }
            cout << m_ascii_data[g];
            cout << m_ascii_data[g];
//            if ( ! is_scaled ) {
                cout << m_ascii_data[g];
//            }
        }
        cout << '\n';
    }
}