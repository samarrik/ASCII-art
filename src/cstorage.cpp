#include "cstorage.h"

using namespace std;

void CStorage::addImage ( CImage * image ) noexcept {
    image_files.push_back(image);
}

void CStorage::addDefaultFilter( CFilter * filter ) noexcept {
    default_filters.push_back(filter);
}

vector<CImage*> & CStorage::getImages() noexcept {
    return image_files;
}

vector<CFilter*> & CStorage::getFilters() noexcept {
    return default_filters;
}

unsigned CStorage::imagesCount () const noexcept {
    return image_files.size();
}

CImage & CStorage::lastImage () {
    if ( image_files.size() == 0 ){
        throw logic_error("You are trying to get the first image of an empty collection");
    } else {
        image_files.back();
    }
}