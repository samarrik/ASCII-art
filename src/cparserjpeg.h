#ifndef PARSERJPEG
#define PARSERJPEG

#include "jpeglib.h"
#include "cparser.h"

class CParserJPEG : public CParser {

    CParserJPEG();

    ~CParserJPEG();

    CImage & read() override;

};

#endif //PARSERJPEG