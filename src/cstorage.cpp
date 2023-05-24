#include "cstorage.h"

using namespace std;

void CStorage::addImage ( CImage * image ) noexcept {
    image_files.push_back(image);
}

void CStorage::addFilter( CFilter * filter ) noexcept {
    default_filters.push_back(filter);
}

vector<CImage*> & CStorage::getImages() noexcept {
    return image_files;
}

vector<CFilter*> & CStorage::getFilters() noexcept {
    return default_filters;
}