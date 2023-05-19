#ifndef STORAGE
#define STORAGE

#include "cimage.h"
#include <vector>

/**
 * A class that represents a storage for images
 * provided by the user
*/
class CStorage 
{
    public:
        
        //Default constructor
        CStorage() = default;

        /**
         * A method adds an image to the storage
         * @param[in] src A const reference to the CImage
         * @param[out] this Returns the same instance of the CStorage
         * @returns A reference to *this
         * @details The method can be chained  
        */
        CStorage & addImage( const CImage & src );
        
        /**
         * A method adds an image to the storage
         * @param[out] CImage & Returns the last image in the storage
         * @exception If storage is empty, logic error is thrown
        */
        CImage & last();

        //Checks if the storage is empty; Yes - true/No - false
        bool isEmpty() const noexcept;

    private:
        //A container where all useful image data will be stored
        std::vector<CImage> m_images;
};

#endif //STORAGE