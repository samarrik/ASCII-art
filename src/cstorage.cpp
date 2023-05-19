#include "cimage.h"
#include "cstorage.h"
#include <stdexcept>

CStorage & CStorage::addImage( const CImage & src ) {
    m_images.push_back( src );
    return *this;
}

CImage & CStorage::last(){
    if ( CStorage::isEmpty() )
        throw std::logic_error("Trying to read the last element of an empty storage.");
    return m_images.back();
}

bool CStorage::isEmpty() const noexcept{
    return m_images.empty();
}