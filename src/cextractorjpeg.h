#ifndef EXTRACTORJPEG
#define EXTRACTORJPEG

#include "jpeglib.h"
#include "cextractor.h"

class CExtractorJPEG : public CExtractor {

    CExtractorJPEG();

    ~CExtractorJPEG();

    CImage & read() override;
};

#endif //EXTRACTORJPEG