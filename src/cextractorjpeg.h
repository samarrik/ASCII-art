#ifndef EXTRACTORJPEG
#define EXTRACTORJPEG

#include "jpeglib.h"
#include "cextractor.h"

class CExtractorJPEG : public CExtractor {

    CExtractorJPEG();

    ~CExtractorJPEG();

    void read() override;
};

#endif //EXTRACTORJPEG