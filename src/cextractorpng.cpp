#include "cextractorpng.h"
#include <iostream>
#include <exception>
#include <cstring>

using namespace std;

CExtractorPNG::CExtractorPNG( const string & filename ){

    //Open the file for reading
    FILE *fp = fopen(filename.c_str(), "rb");
    if ( fp == nullptr ) {
        throw runtime_error( "Image file can't be opened.\nCheck if the name of the file is valid." );
    }

    /**
     * Read first 8 bytes of the header to check if that file is PNG
     * png_sig_cmp(header, 0, 8) returns 0 if it is png/!=0 if it isn't png
    */
    png_byte header[8];
    fread(header, 1, 8, fp);
    if ( png_sig_cmp(header, 0, 8) != 0) {
        throw runtime_error( string("File '" ).append(filename).append("' has .png at the end, but it isn't truly a png file" ) );
    }

    //Structure which will hold all info of the PNG file
    png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if ( png_ptr == nullptr ) {
        throw runtime_error("Can't create main png structure");
    }

    //Structure which will hold all additional info of the PNG file
    info_ptr = png_create_info_struct(png_ptr);
    if ( info_ptr == nullptr ) {
        //Don't forget to destroy structure which was already created
        png_destroy_read_struct(&png_ptr, NULL, NULL);
        throw runtime_error("Can't create info struct");
    }

    //Connect structure for reading with the code
    png_init_io(png_ptr, fp);

    //Send an info that some bytes were already read (header check)
    png_set_sig_bytes(png_ptr, 8);
}

CExtractorPNG::~CExtractorPNG(){
    //Don't forget to destroy all structures we used for reading the file
    png_destroy_read_struct(&png_ptr, NULL, NULL);
    png_destroy_info_struct( png_ptr, &info_ptr);
}

void CExtractorPNG::read() {
    //Read info of the code (up to actual code data)
    png_read_info(png_ptr, info_ptr);

    //Get information from info_ptr
    png_get_IHDR(png_ptr, info_ptr, &width, &height, &bit_depth, &color_type, &interlace_method, &compression_method, &filter_method);

    // Allocate memory for two-dimensional array of pixels
    png_bytep * pixels_2d = (png_bytep*) malloc(sizeof(png_bytep) * height);
    for (png_uint_32 y = 0; y < height; y++) {
        pixels_2d[y] = (png_byte*) malloc(png_get_rowbytes(png_ptr, info_ptr));
    }

    cout << "2d size: " <<  height * png_get_rowbytes(png_ptr, info_ptr) << endl;

    //Read pixels
    png_read_image(png_ptr, pixels_2d);

    //Allocate memory for the pixel data array
    pixels = (png_byte*) malloc(width * height * 4);

    cout << "1d size: " <<  width * height * 4 << endl;
    cout << "just read w: " << width << endl;
    cout << "just read h: " << height << endl;

    //Copy the data from 2d array to 1d
    for (unsigned i = 0; i < height; i++) {
        for (unsigned j = 0; j < width; j++) {
            unsigned char * pixel = &(pixels_2d[i][j * 4]);
            unsigned char * dst = &(pixels[(i * width + j) * 4]);
            dst[0] = pixel[0]; // Red
            dst[1] = pixel[1]; // Green
            dst[2] = pixel[2]; // Blue
            dst[3] = pixel[3]; // Alpha
        }
    }
//    for (int y = 0; y < height; y++) {
//        memcpy(pixels + (y * width), pixels_2d[y], width);
//    }


}