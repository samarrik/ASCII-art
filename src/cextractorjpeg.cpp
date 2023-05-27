
#include "cextractorjpeg.h"

using namespace std;

void CExtractorJPEG ::read( const string & filename ) {

    //Open the file for reading
    FILE * file = fopen(filename.c_str(), "rb");
    if ( file == nullptr ) {
        throw runtime_error( "JPEG Image file can't be opened. Check if the name of the file is valid." );
    }

    //Library structs
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;
    cinfo.err = jpeg_std_error(&jerr);
    jmp_buf setjmp_buffer;
    if (setjmp(setjmp_buffer)) {
        jpeg_destroy_decompress(&cinfo);
        fclose(file);
        throw runtime_error( "JPEG Image processing error" );
    }
    cinfo.client_data = &setjmp_buffer;
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, file);

    //Read header
    jpeg_read_header(&cinfo, TRUE);

    //Start decompression
    jpeg_start_decompress(&cinfo);

    //Get width and height
    m_width = cinfo.output_width;
    m_height = cinfo.output_height;

    //Allocate memory for pixel data
    m_pixels = new unsigned char[m_width * m_height * 4];
    fill(m_pixels, m_pixels + (m_width * m_height * 4), 0);

    //Read pixels
    JSAMPROW row;
    while (cinfo.output_scanline < cinfo.output_height) {
        row = &m_pixels[cinfo.output_scanline * m_width * 4];
        jpeg_read_scanlines(&cinfo, &row, 1);
    }

    //Finish and delete allocated structs
    jpeg_finish_decompress(&cinfo);
    jpeg_destroy_decompress(&cinfo);

    // Close the file
    fclose(file);
}

unsigned CExtractorJPEG::get_width() const {
    return m_width;
}

unsigned CExtractorJPEG::get_height() const {
    return m_height;
}

unsigned char * CExtractorJPEG::get_pixels () const {
    return m_pixels;
}
