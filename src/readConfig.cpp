#include "readConfig.h"
#include "cfilter.h"
#include <fstream>
#include <exception>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

#define CONFIG_PATH "assets/config.txt"

/**
 * A function which reads settings for images
 * @param[in] configFile An input filestream which carries data read from the config.txt file
 * @param[in] images A storage where data from images should be stored
 * @returns 1   When data was read without any problems && global_end; / image_end; was read
 *          -1  When the end of file was read / other structure violations
 *          -2  When no filename/filetype was read
 *          -3  There is a problem with an image file
 *          //-3
 */
bool readImageSettings(std::ifstream &configFile, std::vector<CImage> & images, std::vector<CFilter> & default_filters )
{   
    //Strings to save parameter/filename/filetype
    std::string parameter;
    std::string filename;
    std::string filetype;

    //Variables for storing values of parameters
    std::string str_val;
    double db_val;
    int int_val;

    //Local filters which will be applied to that particular image
    CFilters local_filters;
    CImage * added_image = nullptr;
    
    //First of all filename and filetype should be read
    configFile >> parameter;
    if ( parameter == "filename" ){
        configFile >> filename;
    } else return false;

    configFile >> parameter;
    if ( parameter == "filetype" ){
        configFile >> filetype;
    } else return false;

    //Add deafult "image" to the storage
    images.addImage(CImage(filename));

    if ( filetype == "jpeg"){
        //jpegparser
    } else if (filetype == "png") {
        //pngParser
    } else {
        return false; //wrong format
    }

    //Read filters
    while ( 1 ){
        configFile >> parameter;
        if ( parameter == "image_end;"){
            added_image->saveFilters(local_filters);
            return true;
        }
        else if ( parameter == "gradient"){
            configFile >> str_val;
            local_filters.setGradient(str_val);
        }
        else if ( parameter == "negative"){
            configFile >> int_val;
            local_filters.setNegative(int_val);
        }
        else if ( parameter == "size"){
            configFile >> db_val;
            local_filters.setSize(db_val);
            continue;
        }
        else if ( parameter == "brightness"){
            configFile >> db_val;
            local_filters.setBrightness(db_val);
        }
        else if ( parameter == "rotation"){
            configFile >> int_val;
            local_filters.setRotation(int_val);
        }
        else if ( parameter == "convolution"){
            configFile >> int_val;
            local_filters.setConvolution(int_val);
        }

        //If the end of file was reched without the ending sequence (image_end;)
        if ( configFile.eof() )
            break;
    }

    return false;
}

/**
 * Function reads "global" parameters set in config.txt
 * @param[in] configFile fstream of config.txt
 * @param[in] default_filters filters which will be used as default (being changed during this fun.)
 * @param[out] bool value which tells us if the read was successful or not
*/
bool readGlobalSettings(std::ifstream & configFile, CFilters & default_filters)
{   
    //A string where parameter will be stored
    std::string parameter;

    //Variables for storing values of parameters
    std::string str_val;
    double db_val;
    int int_val;
    
    //Read configuration
    while ( 1 ){
        configFile >> parameter;
        //If the end of file was reched without the ending sequence (global_end;)
        if ( configFile.eof() ){
            break;
        }

        if ( parameter == "global_end;"){
            return true;
        }
        else if ( parameter == "gradient"){
            configFile >> str_val;
            default_filters.setGradient(str_val);
        }
        else if ( parameter == "negative"){
            configFile >> int_val;
            default_filters.setNegative(int_val);
        }
        else if ( parameter == "size"){
            configFile >> db_val;
            default_filters.setSize(db_val);
        }
        else if ( parameter == "brightness"){
            configFile >> db_val;
            default_filters.setBrightness(db_val);
        }
        else if ( parameter == "rotation"){
            configFile >> int_val;
            default_filters.setRotation(int_val);
        }
        else if ( parameter == "convolution"){
            configFile >> int_val;
            default_filters.setConvolution(int_val);
        }
    }

    return false;
}

void readConfig( std::vector<CImage> &images )
{
    // Opens a config.txt file located in directory assets/ and checks if it is there and readable
    std::ifstream configFile(CONFIG_PATH, std::ios::in); // std::ios::in means that file will be opened in read-only mode
    if (!configFile.is_open())
    {
        throw std::runtime_error("An invalid config.txt was passed to converter.");
    }

    //Default filters will be set, if nothing will be changed
    std::vector<CFilter> default_filters;
    default_filters.push_back(CGradient().set_default());
    default_filters.push_back(CContrast().set_default());
    default_filters.push_back(CBrightness().set_default());
    default_filters.push_back(CNegative().set_default());
    default_filters.push_back(CScale().set_default());
    default_filters.push_back(CConvolution().set_default());

    //String which will be used for reading the header  
    std::string header;
    while ( true ){
        configFile >> header;

        //If the end of the file was reached, stop reading
        if ( configFile.eof() )
                break;

        if ( header == "global:" ){
            if ( ! readGlobalSettings(configFile, default_filters) )
                throw std::runtime_error("The structure of config.txt was violated in a block \"global\"");
            else {
                std::cout << "Global settings were set!" << std::endl;
                continue;
            }

        } else if ( header == "image:"){
            if ( ! readImageSettings(configFile, images, default_filters) )
                throw std::runtime_error("The structure of config.txt was violated in a block \"image\"");
            else {
                std::cout << "An image was loaded!" << std::endl;
                continue;
            }

        } else {
            throw std::runtime_error("The structure of config.txt was violated (wrong header)");
        
        }
    }

    configFile.close();
    return;
}