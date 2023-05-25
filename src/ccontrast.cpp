#include "ccontrast.h"

using namespace std;

CContrast::CContrast ( int src )
{
    if ( src != -100 )
        m_contrast = src;
}

void CContrast::apply( CImage & src ){
    cout << "Contrast" << endl;
    //Check if the contrast is in the "valid" range
    if ( m_contrast > 5 || m_contrast < -5 ) {
        throw out_of_range("The contrast value is out of the range");
    } else {
        if ( m_contrast != 0 ) {
            //Find the biggest difference between pixels
            unsigned char *pixels = src.getPixels();
            int global_max = 0;
            int global_min = 255;
            for (int i = 0; i < src.width() * src.height() * 4; i += 4) {
                int local_max = max(max(pixels[i], pixels[i + 1]), pixels[i + 2]);
                int local_min = min(min(pixels[i], pixels[i + 1]), pixels[i + 2]);
                if (local_max > global_max) {
                    global_max = local_max;
                }
                if (local_min < global_min) {
                    global_min = local_min;
                }
            }

            int global_difference = (global_max + global_min) / 2;

            double contrast_coefficient = abs(0.1 * m_contrast);


            if (m_contrast > 0) {
                contrast_coefficient++;
            } else if (m_contrast < 0) {
                contrast_coefficient = 1 - contrast_coefficient;
            }

            for (int i = 0; i < src.width() * src.height() * 4; i += 4) {
                if ( (pixels[i] + pixels[i+1] + pixels[i+2]) / 3 >= global_difference  ) {
                    pixels[i] = min(int(pixels[i] * contrast_coefficient), 255);
                    pixels[i + 1] = min(int(pixels[i + 1] * contrast_coefficient), 255);
                    pixels[i + 2] = min(int(pixels[i + 2] * contrast_coefficient), 255);
                } else {
                    pixels[i] = min(int(pixels[i] / contrast_coefficient), 255);
                    pixels[i + 1] = min(int(pixels[i + 1] / contrast_coefficient), 255);
                    pixels[i + 2] = min(int(pixels[i + 2] / contrast_coefficient), 255);
                }
            }
        }
    }
    cout << "Contrast was set!" << endl;
}

CFilter * CContrast::clone( ){
    return new CContrast (*this);
}