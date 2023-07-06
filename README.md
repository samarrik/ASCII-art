## Disclamer
This repository contains the code for the semester project of the subject [Programming and Algorithms 2](https://courses.fit.cvut.cz/BI-PA2/) studied during the second semester at the Czech Technical University in Prague.

The objective of the semester work was to make a fully working project on a given theme, which each student received personally. There were also some rules, such as required functionality, restrictions on the amount of memory our programs could use or a limited number of libraries we were allowed to use while writing the program.

# ASCII-art
The goal of mine semester project was to create an ASCII-art generator, which also allows user apply filters on the art
## Requirements for the functionality:
ASCII-art generator should:
- [X] be able to process images of JPEG and PNG formats;
- [X] implement at least 5 filters (exmp: brigtness, negative ... );
- [X] save results of the conversion into files and present them to the user
- [X] give user an ability to manipulate the presentation
- [X] be configured from the file

## Description
Converter will process a config.txt file, added as a parameter to the application, where all information for conversion
will be provided. This file should be filled by a user according to the template^. As a result converter will receive a
file with default filters for ASCII conversion, image files and filters for the conversion of each file. After that application
will convert each image according to filter. Results will be saved in .txt files in the same folder as source images.
Then the user will be able to run presentation^^ of the results in the terminal, or exit the application.

![](screenshots/description_additional.png)

## Work examples:
### Sample configfile:
![](screenshots/configfile.png)

### Image processing
![](screenshots/processing_images.png)

### Result (generated ASCII-art)
![](screenshots/art.png)


## Comile and run:
- You should have libjpeg installed (`sudo apt install libjpeg-dev`);
- You should have libpng installed (`sudo apt install libpng-dev`);
- To generate the documentation, you need to have doxygen installed (`sudo apt-get install doxygen`);
- `make all` - Compile the application and generate documentation;
- `make run` - Launch the application with the showcase;
- `./asciiart path_to_the_configfile` - Convert to ASCII-art your own images
- `make clean` - Removing all compiled files;