#include "readConfig.h"

#define CONFIG_PATH "assets/config.txt"

using namespace std;

bool readImageSettings(ifstream &configFile, CStorage & images )
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

    if ( filetype == "jpeg"){
        //TODO:
    } else if (filetype == "png") {
        CExtractorPNG png_image = CExtractorPNG( filename );
        png_image.read();
        //Initialize an image using received data
        images.addImage(new CImage( images.getFilters(), filename, filetype, png_image.get_pixels(), png_image.get_width(),png_image.get_height()));
    } else {
        return false; //wrong format
    }

    //Read "image" block
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
            images.lastImage().addFilter(new CGradient(str_val));
        }
        else if ( parameter == "negative"){
            configFile >> int_val;
            images.lastImage().addFilter(new CNegative(int_val));
        }
        else if ( parameter == "scale"){
            configFile >> int_val;
            images.lastImage().addFilter(new CScale(int_val));
        }
        else if ( parameter == "brightness"){
            configFile >> int_val;
            images.lastImage().addFilter(new CBrightness(int_val));
        }
        else if ( parameter == "contrast"){
            configFile >> int_val;
            images.lastImage().addFilter(new CContrast(int_val));
        }
        else if ( parameter == "channel"){

            configFile >> str_val;
            images.lastImage().addFilter(new CChannel(str_val));
        } else {
            //Wrong parameter's header was passed
            break;
        }
    }

    return false;
}

bool readGlobalSettings(ifstream & configFile, CStorage & images )
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

        //The block was ended properly
        if ( parameter == "global_end;"){
            return true;
        }
        else if ( parameter == "gradient"){
            configFile >> str_val;
            images.addDefaultFilter(new CGradient(str_val));
        }
        else if ( parameter == "negative"){
            configFile >> int_val;
            images.addDefaultFilter(new CNegative(int_val));
        }
        else if ( parameter == "scale"){
            configFile >> int_val;
            images.addDefaultFilter(new CScale(int_val));
        }
        else if ( parameter == "brightness"){
            configFile >> int_val;
            images.addDefaultFilter(new CBrightness(int_val));
        }
        else if ( parameter == "contrast"){
            configFile >> int_val;
            images.addDefaultFilter(new CContrast(int_val));
        }
        else if ( parameter == "channel"){
            configFile >> str_val;
            images.addDefaultFilter(new CChannel(str_val));
        } else {
            //Wrong parameter's header was passed
            break;
        }
    }

    return false;
}

void readConfig( CStorage & images )
{
    // Opens a config.txt file located in directory assets/ and checks if it is there and readable
    ifstream configFile(CONFIG_PATH, ios::in); // ios::in means that file will be opened in read-only mode
    if (!configFile.is_open())
    {
        throw runtime_error("An invalid config.txt was passed to converter or it doesn't exist. (check assets/ folder)");
    }

    //Set up default filters for all images
    images.addDefaultFilter(new CGradient())
          .addDefaultFilter(new CContrast())
          .addDefaultFilter(new CBrightness())
          .addDefaultFilter(new CNegative())
          .addDefaultFilter(new CScale())
          .addDefaultFilter(new CChannel());

    //String which will be used for reading the header  
    string header;
    while ( true ){

        //Read header from the config file
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
                cout << "An image number " << images.imagesCount() << " was loaded!" << endl;
                continue;
            }

        } else {
            throw runtime_error("The structure of config.txt was violated (wrong header)");
        }
    }

    configFile.close();
}