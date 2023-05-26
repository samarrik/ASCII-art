#include "handler.h"
#include "cstorage.h"

using namespace std;

void handler(int signal){
    cout << "\033[1;31m\nThe application was closed forcibly\033[0m" << endl;

    //Clear all possible data allocated
    static CStorage images;
    images.~CStorage();
    exit(0);
}