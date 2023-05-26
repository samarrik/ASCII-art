#ifndef CHANNEL
#define CHANNEL

#include "cimage.h"

/*
 * A class that represents a filter that changes the showed RGB channel of an image
 */
class CChannel : public CFilter {
public:

    //If argument wasn't passed to the constructor, set ""
    CChannel ( const string & src = "" );

    ~CChannel() override = default;

    void apply ( CImage & src ) override;

    CFilter * clone () override;

private:
    //Standard brightness value is "n", which means NO changes
    string m_channel = "n";
};

#endif //CHANNEL