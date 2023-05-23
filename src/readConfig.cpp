#include "readConfig.h"
#include "cimage.h"
#include "sstorage.h"
#include "cextractor.h"
#include "cextractorpng.h"
#include <fstream>
#include <exception>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

#define CONFIG_PATH "assets/config.txt"

using namespace std;

/**
 * A function which reads settings for images
 * @param[in] configFile An input filestream which carries data read from the config.txt file
 * @param[in] images A storage where data from images should be stored
 * @returns 1   When data was read without any problems && global_end; / image_end; was read
 *          -1  When the end of file was read / other structure violations
 *          -2  When no filename/filetype was read
 *          -3  There is a problem with an code file
 *          //-3
 */
bool readImageSettings(ifstream &configFile, SStorage & images )
{   
    //Strings to save parameter/filename/filetype
    string parameter;
    string filename;
    string filetype;

    //Variables for storing values of parameters
    string str_val;
    int int_val;
    
    //First of all filename and filetype should be read
    configFile >> parameter;
    if ( parameter == "filename" ){
        configFile >> filename;
    } else return false;

    configFile >> parameter;
    if ( parameter == "filetype" ){
        configFile >> filetype;
    } else return false;

    //Add default "code" to the storage
    images.image_files.push_back(new CImage());
    images.image_files.back()->loadFilters(images.default_filters);
    images.image_files.back()->loadNameType(filename, filetype);

    if ( filetype == "jpeg"){
        //TODO
    } else if (filetype == "png") {
        CExtractorPNG png_image = CExtractorPNG(filename);
        png_image.read();
        images.image_files.back()->loadExtractedData(png_image.get_width(),png_image.get_height(),png_image.get_pixels());
    } else {
        return false; //wrong format
    }

    //Read code
    while ( true ){
        configFile >> parameter;
        //If the end of file was reached without the ending sequence (image_end;)
        if ( configFile.eof() ){
            break;
        }
        // '\n' at the end is 100% important
        if ( parameter == "image_end;" ){
            return true;
        }
        else if ( parameter == "gradient"){
            configFile >> str_val;
            images.image_files.back()->addFilter(new CGradient(str_val));
        }
        else if ( parameter == "negative"){
            configFile >> int_val;
            images.image_files.back()->addFilter(new CNegative(int_val));
        }
        else if ( parameter == "scale"){
            configFile >> int_val;
            images.image_files.back()->addFilter(new CScale(int_val));
        }
        else if ( parameter == "brightness"){
            configFile >> int_val;
            images.image_files.back()->addFilter(new CBrightness(int_val));
        }
        else if ( parameter == "contrast"){
            configFile >> int_val;
            images.image_files.back()->addFilter(new CContrast(int_val));
        }
        else if ( parameter == "convolution"){
            configFile >> int_val;
            images.image_files.back()->addFilter(new CConvolution(int_val));
        } else {

            break;
        }
    }

    return false;
}

/**
 * Function reads "global" parameters set in config.txt
 * @param[in] configFile fstream of config.txt
 * @param[in] default_filters code which will be used as default (being changed during this fun.)
 * @param[out] bool value which tells us if the read was successful or not
*/

bool readGlobalSettings(ifstream & configFile, SStorage & images )
{   
    //A string where parameter will be stored
    string parameter;

    //Variables for storing values of parameters
    string str_val;
    int int_val;
    
    //Read configuration
    while ( true ){
        configFile >> parameter;
        //If the end of file was reached without the ending sequence (global_end;)
        if ( configFile.eof() ){
            break;
        }

        if ( parameter == "global_end;"){
            return true;
        }
        else if ( parameter == "gradient"){
            configFile >> str_val;
            images.default_filters.push_back(new CGradient(str_val));
        }
        else if ( parameter == "negative"){
            configFile >> int_val;
            images.default_filters.push_back(new CNegative(int_val));
        }
        else if ( parameter == "scale"){
            configFile >> int_val;
            images.default_filters.push_back(new CScale(int_val));
        }
        else if ( parameter == "brightness"){
            configFile >> int_val;
            images.default_filters.push_back(new CBrightness(int_val));
        }
        else if ( parameter == "contrast"){
            configFile >> int_val;
            images.default_filters.push_back(new CContrast(int_val));
        }
        else if ( parameter == "convolution"){
            configFile >> int_val;
            images.default_filters.push_back(new CConvolution(int_val));
        } else {
            break;
        }
    }

    return false;
}

void readConfig( SStorage &images )
{
    // Opens a config.txt file located in directory assets/ and checks if it is there and readable
    ifstream configFile(CONFIG_PATH, ios::in); // ios::in means that file will be opened in read-only mode
    if (!configFile.is_open())
    {
        throw runtime_error("An invalid config.txt was passed to converter.");
    }

    images.default_filters.push_back(new CGradient());
    images.default_filters.push_back(new CContrast());
    images.default_filters.push_back(new CBrightness());
    images.default_filters.push_back(new CNegative());
    images.default_filters.push_back(new CScale());
    images.default_filters.push_back(new CConvolution());

    //String which will be used for reading the header  
    string header;
    while ( true ){
        configFile >> header;

        //If the end of the file was reached, stop reading
        if ( configFile.eof() )
                break;

        if ( header == "global:" ){
            if ( ! readGlobalSettings(configFile, images ) )
                throw runtime_error("An error in config.txt while reading \"global\" unit");
            else {
                cout << "Global settings were set!" << endl;
                continue;
            }

        } else if ( header == "image:") {
            if ( ! readImageSettings( configFile, images ) ){
                throw runtime_error("An error in config.txt while reading \"image\" unit");
            } else {
                cout << "An Image was loaded!" << endl;
                continue;
            }

        } else {
            throw runtime_error("The structure of config.txt was violated (wrong header)");
        
        }
    }

    configFile.close();
}