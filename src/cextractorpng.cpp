#include "cextractorpng.h"

using namespace std;

void CExtractorPNG::read( const string & filename ) {

    //Open the file for reading
    FILE * fp = fopen(filename.c_str(), "rb");
    if ( fp == nullptr ) {
        throw runtime_error( "PNG Image file can't be opened. Check if the name of the file is valid." );
    }

    /**
     * Read first 8 bytes of the header to check if that file is PNG
     * png_sig_cmp(header, 0, 8) returns 0 if it is png/!=0 if it isn't png
    */
    png_byte header[8];
    if ( fread(header, 1, 8, fp) < 8 ){
        throw runtime_error( "PNG Image file can't be verified. Check if the file is valid." );
    }
    if ( png_sig_cmp(header, 0, 8) != 0) {
        throw runtime_error( string("File '" ).append(filename).append("' isn't truly a png file" ) );
    }

    //Structure which will hold all info of the PNG file
    png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);
    if ( png_ptr == nullptr ) {
        throw runtime_error("Can't create main png structure");
    }

    //Structure which will hold all additional info of the PNG file
    png_infop info_ptr = png_create_info_struct(png_ptr);
    if ( info_ptr == nullptr ) {
        //Don't forget to destroy structure which was already created
        png_destroy_read_struct(&png_ptr, nullptr, nullptr);
        throw runtime_error("Can't create info struct");
    }

    //Connect structure for reading with the code
    png_init_io(png_ptr, fp);

    //Send an info that some bytes were already read (header check)
    png_set_sig_bytes(png_ptr, 8);

    //Read info of the code (up to actual code data)
    png_read_info(png_ptr, info_ptr);

    //Get information from info_ptr
    png_get_IHDR(png_ptr, info_ptr, &m_width
                 , &m_height, nullptr, nullptr, nullptr, nullptr, nullptr);

    // Allocate memory for two-dimensional array of m_pixels
    unsigned char ** pixels_2d = new unsigned char * [m_height];
    for (unsigned i = 0; i < m_height; i++) {
        pixels_2d[i] = new unsigned char [png_get_rowbytes(png_ptr, info_ptr)];
    }

    //Read m_pixels
    png_read_image(png_ptr, pixels_2d);

    //Destroy the structure for reading info
    png_destroy_info_struct( png_ptr, &info_ptr);

    //Destroy the structure for reading image data
    png_destroy_read_struct(&png_ptr, nullptr, nullptr);

    //Close the file, we don't need it anymore
    fclose(fp);

    //Allocate memory for the pixel data array
    m_pixels = new unsigned char [m_width * m_height * 4];
    fill(m_pixels, m_pixels + (m_width * m_height * 4), 0);

    //Copy the data from 2d array to 1d
    for (unsigned i = 0; i < m_height; i++) {
        for (unsigned j = 0; j < m_width; j++) {
            unsigned char *pixel = &(pixels_2d[i][j * 4]);
            unsigned char *to = &(m_pixels[(i * m_width + j) * 4]);
            //copy all RGBA values
            to[0] = pixel[0];
            to[1] = pixel[1];
            to[2] = pixel[2];
            to[3] = pixel[3];
        }
    }

    //Delete the previous 2d structure
    for (png_uint_32 y = 0; y < m_height; y++) {
        delete [] pixels_2d[y];
    }
    delete [] pixels_2d;
}

unsigned CExtractorPNG::get_width
() const {
    return m_width;
}

unsigned CExtractorPNG::get_height() const {
    return m_height;
}

unsigned char * CExtractorPNG::get_pixels()  const{
    return m_pixels;
}