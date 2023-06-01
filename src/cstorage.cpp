#include "cstorage.h"

using namespace std;

CStorage::~CStorage() {
    for ( auto filter : m_default_filters ){
        delete filter;
    }
    for ( auto image : m_image_files ){
        delete image;
    }
}

void CStorage::addImage ( CImage * image ) noexcept {
    m_image_files.push_back(image);
}

CStorage & CStorage::addDefaultFilter( CFilter * filter ) noexcept {
    m_default_filters.push_back(filter);
    return *this;
}

vector<CImage*> & CStorage::getImages() noexcept {
    return m_image_files;
}

vector<CFilter*> & CStorage::getFilters() noexcept {
    return m_default_filters;
}

CImage & CStorage::lastImage () {
    if ( m_image_files.empty() ){
        throw logic_error("You are trying to get the first image of an empty collection");
    }
    return *(m_image_files.back());
}

void CStorage::saveConfig ( const string & src ) noexcept {
    m_config_file_name = src;
}

string CStorage::pathConfig() const noexcept {
    return m_config_file_name;
}