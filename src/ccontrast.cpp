#include "ccontrast.h"

using namespace std;

CContrast::CContrast ( int src  )
{
    //If the object was created without passing any data into it, the default value will be set automatically;
    if ( src != -100 ) {
        if ( src > 5 || src < -5 ) {
            throw out_of_range("The contrast value is out of the range");
        }
        m_contrast = src;//If some value was passed into and it is in the range
    }
}

void CContrast::apply( CImage & src ){

   //If the contrast should be changed, perform operations
   if ( m_contrast != 0 ) {

       //Find the biggest difference between pixels
       unsigned char *pixels = src.getPixels();

       //Iterate through all pixels to find global min/max
       int global_max = 0;
       int global_min = 255;
       for (unsigned i = 0; i < src.width() * src.height() * 4; i += 4) {
           //Finding the local extremes ( the value that represents how bright the pixel is )
           int local_max = int(0.2125 * pixels[i] + 0.7153 * pixels[i+1] + 0.0722 * pixels [i+2]);
           int local_min = int(0.2125 * pixels[i] + 0.7153 * pixels[i+1] + 0.0722 * pixels [i+2]);

           //If that value is bigger than the global extreme set before, update it
           if (local_max > global_max) {
               global_max = local_max;
           }
           if (local_min < global_min) {
               global_min = local_min;
           }
       }

       //Find the global difference ( middle point between the brightest and the darkest pixel on the picture)
       int global_difference = (global_max + global_min) / 2;

       //Count the contrast coefficient ( how contrast user want picture to be )
       double contrast_coefficient = abs(0.1 * m_contrast);
       if (m_contrast > 0) {
           contrast_coefficient++;
       } else if (m_contrast < 0) {
           contrast_coefficient = 1 - contrast_coefficient;
       }

       //Update the contrast on each picture
       for (unsigned i = 0; i < src.width() * src.height() * 4; i += 4) {
           //If the pixel is brighter than a middle point (global_difference), make it brighter, if lower - darker
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

CFilter * CContrast::clone( ){
    return new CContrast (*this);
}