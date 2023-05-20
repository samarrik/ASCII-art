#include "../headers/cimage.h"

CImage::CImage(){}

void CImage::addFilter( CFilter & filter ) {
    m_filters.push_back(filter);
}

void CImage::applyFilters() {
    for ( auto filter : m_filters )
        filter.apply();
}

void CImage::grayscale() {
    //TODO
}

void CImage::convert() {
    //TODO
}

void CImage::saveToFile() const{
    //TODO
}

void CImage::print() const noexcept{
    //TODO
}